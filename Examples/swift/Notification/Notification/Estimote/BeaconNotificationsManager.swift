//
//  BeaconNotificationsManager.swift
//  Notification
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

        UIApplication.sharedApplication().registerUserNotificationSettings(UIUserNotificationSettings(forTypes: [.Sound, .Alert], categories: nil))
    }

    func enableNotificationsForBeaconID(beaconID: BeaconID, enterMessage: String?, exitMessage: String?) {
        let beaconRegion = beaconID.asBeaconRegion
        self.enterMessages[beaconRegion.identifier] = enterMessage
        self.exitMessages[beaconRegion.identifier] = exitMessage
        self.beaconManager.startMonitoringForRegion(beaconRegion)
    }

    func beaconManager(manager: AnyObject, didEnterRegion region: CLBeaconRegion) {
        if let message = self.enterMessages[region.identifier] {
            self.showNotificationWithMessage(message)
        }
    }

    func beaconManager(manager: AnyObject, didExitRegion region: CLBeaconRegion) {
        if let message = self.exitMessages[region.identifier] {
            self.showNotificationWithMessage(message)
        }
    }

    private func showNotificationWithMessage(message: String) {
        let notification = UILocalNotification()
        notification.alertBody = message
        notification.soundName = UILocalNotificationDefaultSoundName
        UIApplication.sharedApplication().presentLocalNotificationNow(notification)
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
