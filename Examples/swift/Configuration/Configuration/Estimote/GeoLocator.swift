//
// Please report any problems with this app template to contact@estimote.com
//

enum GeoLocatorError: ErrorType {
    case InsufficientPermissions, NoLocationFound
}

protocol GeoLocatorDelegate: class {

    func geoLocator(geoLocator: GeoLocator, didDetermineLocation location: CLLocation)

    func geoLocator(geoLocator: GeoLocator, didFailWithError error: GeoLocatorError)

}

class GeoLocator: NSObject, CLLocationManagerDelegate {

    unowned var delegate: GeoLocatorDelegate
    var requestInProgress: Bool {
        return authRequestInProgress || locationUpdatesInProgress
    }

    private let locationManager = CLLocationManager()
    private var currentLocation: CLLocation?
    private var timeoutTimer: NSTimer!

    private var authRequestInProgress = false
    private var locationUpdatesInProgress = false

    init(delegate: GeoLocatorDelegate) {
        self.delegate = delegate

        super.init()

        locationManager.desiredAccuracy = kCLLocationAccuracyHundredMeters
        locationManager.delegate = self
    }

    func requestLocation() {
        switch CLLocationManager.authorizationStatus() {
        case .NotDetermined:
            authRequestInProgress = true
            locationManager.requestWhenInUseAuthorization()
        case .AuthorizedWhenInUse, .AuthorizedAlways:
            locationUpdatesInProgress = true
            locationManager.startUpdatingLocation()
            timeoutTimer = NSTimer.scheduledTimerWithTimeInterval(10, target: self, selector: #selector(finishWithCurrentLocation), userInfo: nil, repeats: false)
        default:
            delegate.geoLocator(self, didFailWithError: .InsufficientPermissions)
        }
    }

    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location = locations.filter({ $0.horizontalAccuracy >= 0 }).minElement({ $0.horizontalAccuracy < $1.horizontalAccuracy }) else { return }
        NSLog(location.debugDescription)
        if currentLocation == nil || currentLocation!.horizontalAccuracy > location.horizontalAccuracy {
            currentLocation = location

            if currentLocation!.horizontalAccuracy <= locationManager.desiredAccuracy {
                finishWithCurrentLocation()
            }
        }
    }

    func locationManager(manager: CLLocationManager, didChangeAuthorizationStatus status: CLAuthorizationStatus) {
        if authRequestInProgress {
            authRequestInProgress = false
            requestLocation()
        }
    }

    func locationManager(manager: CLLocationManager, didFailWithError error: NSError) {
        locationUpdatesInProgress = false
    }

    @objc private func finishWithCurrentLocation() {
        timeoutTimer.invalidate()

        locationUpdatesInProgress = false
        locationManager.stopUpdatingLocation()

        if let location = currentLocation {
            delegate.geoLocator(self, didDetermineLocation: location)
        } else {
            delegate.geoLocator(self, didFailWithError: .NoLocationFound)
        }
    }

}
