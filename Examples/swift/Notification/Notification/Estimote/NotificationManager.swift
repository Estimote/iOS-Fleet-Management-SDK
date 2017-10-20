//
// Please report any problems with this app template to contact@estimote.com
//

import Foundation
import UIKit

extension NotificationManager {
    fileprivate struct Parameters {
        
        /// Desired distance from a beacon from which enter/exit events should be triggered, in meters.
        static let desiredZoneRadius = 2.0
    }
}

class NotificationManager: NSObject {
    
    fileprivate lazy var monitoringManager: ESTMonitoringV2Manager = ESTMonitoringV2Manager(desiredMeanTriggerDistance: Parameters.desiredZoneRadius, delegate: self)
    fileprivate var enterMessage: String?
    fileprivate var exitMessage: String?
    
    internal func enableNotifications(deviceIdentifier: String, enterMessage: String, exitMessage: String) {
        
        // Set up local notifications
        let notificationSettings = UIUserNotificationSettings(types: [.alert, .sound], categories: nil)
        UIApplication.shared.registerUserNotificationSettings(notificationSettings)
        
        // Remember messages to show on enter/exit events
        self.enterMessage = enterMessage
        self.exitMessage = exitMessage
        
        self.monitoringManager.startMonitoring(forIdentifiers: [deviceIdentifier])
    }
    
    fileprivate func presentNotification(message: String) {
        let notification = UILocalNotification()
        notification.alertBody = message
        notification.soundName = UILocalNotificationDefaultSoundName
        UIApplication.shared.presentLocalNotificationNow(notification)
    }
    
    fileprivate func name(_ state: ESTMonitoringState) -> String {
        switch state {
        case .unknown: return "Unknown"
        case .insideZone: return "Inside"
        case .outsideZone: return "Outside"
        }
    }
}

extension NotificationManager: ESTMonitoringV2ManagerDelegate {
    
    func monitoringManagerDidStart(_ manager: ESTMonitoringV2Manager) {
        print("Monitoring started successfully.")
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didFailWithError error: Error) {
        print("Monitoring failed: \(error.localizedDescription)")
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didDetermineInitialState state: ESTMonitoringState, forBeaconWithIdentifier identifier: String) {
        print("Determined initial state: for \(identifier) - \(self.name(state)).")
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didEnterDesiredRangeOfBeaconWithIdentifier identifier: String) {
        print("Entered range of \(identifier).")
        self.presentNotification(message: self.enterMessage!)
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didExitDesiredRangeOfBeaconWithIdentifier identifier: String) {
        print("Exited range of \(identifier).")
        self.presentNotification(message: self.exitMessage!)
    }
}
