//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class BeaconNotificationsManager: NSObject, ESTBeaconManagerDelegate {

    private let beaconManager = ESTBeaconManager()

    private var enterMessages = [String: String]()
    private var exitMessages = [String: String]()

    override init() {
        super.init()

        self.beaconManager.delegate = self
        self.beaconManager.requestAlwaysAuthorization()

        UIApplication.shared.registerUserNotificationSettings(UIUserNotificationSettings(types: [.sound, .alert], categories: nil))
    }

    func enableNotifications(for beaconID: BeaconID, enterMessage: String?, exitMessage: String?) {
        let beaconRegion = beaconID.asBeaconRegion
        self.enterMessages[beaconRegion.identifier] = enterMessage
        self.exitMessages[beaconRegion.identifier] = exitMessage
        self.beaconManager.startMonitoring(for: beaconRegion)
    }

    func beaconManager(_ manager: Any, didEnter region: CLBeaconRegion) {
        if let message = self.enterMessages[region.identifier] {
            self.showNotificationWithMessage(message)
        }
    }

    func beaconManager(_ manager: Any, didExitRegion region: CLBeaconRegion) {
        if let message = self.exitMessages[region.identifier] {
            self.showNotificationWithMessage(message)
        }
    }

    fileprivate func showNotificationWithMessage(_ message: String) {
        let notification = UILocalNotification()
        notification.alertBody = message
        notification.soundName = UILocalNotificationDefaultSoundName
        UIApplication.shared.presentLocalNotificationNow(notification)
    }

    func beaconManager(_ manager: Any, didChange status: CLAuthorizationStatus) {
        if status == .denied || status == .restricted {
            NSLog("Location Services are disabled for this app, which means it won't be able to detect beacons.")
        }
    }

    func beaconManager(_ manager: Any, monitoringDidFailFor region: CLBeaconRegion?, withError error: Error) {
        print("Monitoring failed for region: \(region?.identifier ?? "(unknown)"). Make sure that Bluetooth and Location Services are on, and that Location Services are allowed for this app. Beacons require a Bluetooth Low Energy compatible device: <http://www.bluetooth.com/Pages/Bluetooth-Smart-Devices-List.aspx>. Note that the iOS simulator doesn't support Bluetooth at all. The error was: \(error)")
    }

}
