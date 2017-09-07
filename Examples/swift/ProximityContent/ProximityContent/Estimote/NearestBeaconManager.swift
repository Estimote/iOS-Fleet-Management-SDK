//
// Please report any problems with this app template to contact@estimote.com
//

protocol NearestBeaconManagerDelegate: class {

    func nearestBeaconManager(_ nearestBeaconManager: NearestBeaconManager, didUpdateNearestBeacon nearestBeacon: CLBeacon?)

}

class NearestBeaconManager: NSObject, ESTBeaconManagerDelegate {

    weak var delegate: NearestBeaconManagerDelegate?

    private let beaconRegions: [CLBeaconRegion]

    private let beaconManager = ESTBeaconManager()

    private var nearestBeacon: CLBeacon?
    private var firstEventSent = false

    init(beaconRegions: [CLBeaconRegion]) {
        self.beaconRegions = beaconRegions

        super.init()

        self.beaconManager.delegate = self
        self.beaconManager.requestWhenInUseAuthorization()
        self.beaconManager.returnAllRangedBeaconsAtOnce = true
    }

    func startNearestBeaconUpdates() {
        for beaconRegion in self.beaconRegions {
            self.beaconManager.startRangingBeacons(in: beaconRegion)
        }
    }

    func stopNearestBeaconUpdates() {
        for beaconRegion in self.beaconRegions {
            self.beaconManager.stopRangingBeacons(in: beaconRegion)
        }
    }

    func beaconManager(_ manager: Any, didRangeBeacons beacons: [CLBeacon], in region: CLBeaconRegion) {
        let nearestBeacon = beacons.first

        if !(nearestBeacon?.beaconID == nil && self.nearestBeacon == nil) ||
            !(nearestBeacon?.beaconID == self.nearestBeacon?.beaconID) ||
            !firstEventSent {
            self.nearestBeacon = nearestBeacon
            self.delegate?.nearestBeaconManager(self, didUpdateNearestBeacon: self.nearestBeacon)
            self.firstEventSent = true
        }
    }

    func beaconManager(_ manager: Any, didChange status: CLAuthorizationStatus) {
        if status == .denied || status == .restricted {
            NSLog("Location Services are disabled for this app, which means it won't be able to detect beacons.")
        }
    }

    func beaconManager(_ manager: Any, rangingBeaconsDidFailFor region: CLBeaconRegion?, withError error: Error) {
        print("Ranging failed for region: \(region?.identifier ?? "(unknown)"). Make sure that Bluetooth and Location Services are on, and that Location Services are allowed for this app. Beacons require a Bluetooth Low Energy compatible device: <http://www.bluetooth.com/Pages/Bluetooth-Smart-Devices-List.aspx>. Note that the iOS simulator doesn't support Bluetooth at all. The error was: \(error)")
    }

}
