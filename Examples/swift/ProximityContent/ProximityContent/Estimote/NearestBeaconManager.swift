//
// Please report any problems with this app template to contact@estimote.com
//

protocol NearestBeaconManagerDelegate: class {

    func nearestBeaconManager(nearestBeaconManager: NearestBeaconManager, didUpdateNearestBeaconID nearestBeaconID: BeaconID?)

}

class NearestBeaconManager: NSObject, ESTBeaconManagerDelegate {

    weak var delegate: NearestBeaconManagerDelegate?

    private let beaconRegions: [CLBeaconRegion]

    private let beaconManager = ESTBeaconManager()

    private var nearestBeaconID: BeaconID?
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
            self.beaconManager.startRangingBeaconsInRegion(beaconRegion)
        }
    }

    func stopNearestBeaconUpdates() {
        for beaconRegion in self.beaconRegions {
            self.beaconManager.stopRangingBeaconsInRegion(beaconRegion)
        }
    }

    func beaconManager(manager: AnyObject, didRangeBeacons beacons: [CLBeacon], inRegion region: CLBeaconRegion) {
        let nearestBeacon = beacons.first

        if nearestBeacon?.beaconID != self.nearestBeaconID || !firstEventSent {
            self.nearestBeaconID = nearestBeacon?.beaconID
            self.delegate?.nearestBeaconManager(self, didUpdateNearestBeaconID: self.nearestBeaconID)
            self.firstEventSent = true
        }
    }

    func beaconManager(manager: AnyObject, didChangeAuthorizationStatus status: CLAuthorizationStatus) {
        if status == .Denied || status == .Restricted {
            NSLog("Location Services are disabled for this app, which means it won't be able to detect beacons.")
        }
    }

    func beaconManager(manager: AnyObject, rangingBeaconsDidFailForRegion region: CLBeaconRegion?, withError error: NSError) {
        NSLog("Ranging failed for region: %@. Make sure that Bluetooth and Location Services are on, and that Location Services are allowed for this app. Beacons require a Bluetooth Low Energy compatible device: <http://www.bluetooth.com/Pages/Bluetooth-Smart-Devices-List.aspx>. Note that the iOS simulator doesn't support Bluetooth at all. The error was: %@", region?.identifier ?? "(unknown)", error);
    }

}
