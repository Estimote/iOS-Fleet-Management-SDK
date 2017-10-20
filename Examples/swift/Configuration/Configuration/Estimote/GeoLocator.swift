//
// Please report any problems with this app template to contact@estimote.com
//

enum GeoLocatorError: Error {
    case insufficientPermissions, noLocationFound
}

protocol GeoLocatorDelegate: class {

    func geoLocator(_ geoLocator: GeoLocator, didDetermineLocation location: CLLocation)

    func geoLocator(_ geoLocator: GeoLocator, didFailWithError error: GeoLocatorError)

}

class GeoLocator: NSObject, CLLocationManagerDelegate {

    unowned var delegate: GeoLocatorDelegate
    @objc var requestInProgress: Bool {
        return authRequestInProgress || locationUpdatesInProgress
    }

    fileprivate let locationManager = CLLocationManager()
    fileprivate var currentLocation: CLLocation?
    fileprivate var timeoutTimer: Timer!

    fileprivate var authRequestInProgress = false
    fileprivate var locationUpdatesInProgress = false

    init(delegate: GeoLocatorDelegate) {
        self.delegate = delegate

        super.init()

        locationManager.desiredAccuracy = kCLLocationAccuracyHundredMeters
        locationManager.delegate = self
    }

    @objc func requestLocation() {
        switch CLLocationManager.authorizationStatus() {
        case .notDetermined:
            authRequestInProgress = true
            locationManager.requestWhenInUseAuthorization()
        case .authorizedWhenInUse, .authorizedAlways:
            locationUpdatesInProgress = true
            locationManager.startUpdatingLocation()
            timeoutTimer = Timer.scheduledTimer(timeInterval: 10, target: self, selector: #selector(finishWithCurrentLocation), userInfo: nil, repeats: false)
        default:
            delegate.geoLocator(self, didFailWithError: .insufficientPermissions)
        }
    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location = locations.filter({ $0.horizontalAccuracy >= 0 }).min(by: { $0.horizontalAccuracy < $1.horizontalAccuracy }) else { return }
        NSLog(location.debugDescription)
        if currentLocation == nil || currentLocation!.horizontalAccuracy > location.horizontalAccuracy {
            currentLocation = location

            if currentLocation!.horizontalAccuracy <= locationManager.desiredAccuracy {
                finishWithCurrentLocation()
            }
        }
    }

    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if authRequestInProgress {
            authRequestInProgress = false
            requestLocation()
        }
    }

    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        locationUpdatesInProgress = false
    }

    @objc fileprivate func finishWithCurrentLocation() {
        timeoutTimer.invalidate()

        locationUpdatesInProgress = false
        locationManager.stopUpdatingLocation()

        if let location = currentLocation {
            delegate.geoLocator(self, didDetermineLocation: location)
        } else {
            delegate.geoLocator(self, didFailWithError: .noLocationFound)
        }
    }

}
