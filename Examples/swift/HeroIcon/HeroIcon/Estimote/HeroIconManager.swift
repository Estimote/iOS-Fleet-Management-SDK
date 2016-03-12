//
//  HeroIconManager.swift
//  HeroIcon
//

class HeroIconManager: NSObject, ESTBeaconManagerDelegate {

    private let beaconManager = ESTBeaconManager()

    override init() {
        super.init()

        self.beaconManager.delegate = self
        self.beaconManager.requestAlwaysAuthorization()
    }

    func enableHeroIconForBeaconID(beaconID: BeaconID) {
        self.beaconManager.startMonitoringForRegion(beaconID.asBeaconRegion)
    }

    func beaconManager(manager: AnyObject, didChangeAuthorizationStatus status: CLAuthorizationStatus) {
        if status == .Denied || status == .Restricted {
            NSLog("Location Services are disabled for this app, which means it won't be able to detect beacons.")
        }
    }

    func beaconManager(manager: AnyObject, monitoringDidFailForRegion region: CLBeaconRegion?, withError error: NSError) {
        NSLog("Monitoring failed for region: %@. Make sure that Bluetooth and Location Services are on, and that Location Services are allowed for this app. Beacons require a Bluetooth Low Energy compatible device: <http://www.bluetooth.com/Pages/Bluetooth-Smart-Devices-List.aspx>. Note that the iOS simulator doesn't support Bluetooth at all. The error was: %@", region?.identifier ?? "(unknown)", error);
    }

}
