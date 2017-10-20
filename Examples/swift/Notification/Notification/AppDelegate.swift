//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    let notificationManager = NotificationManager()

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        /** TODO: Replace with your App ID and App Token.
         You can get them by adding a new app at https://cloud.estimote.com/#/apps
         */
        ESTConfig.setupAppID("<#App ID#>", andAppToken: "<#App Token#>")
        
        /** TODO: Make sure your beacons have Estimote Monitoring feature set enabled:
         https://community.estimote.com/hc/en-us/articles/226144728
         */
        
        /** TODO: Replace with an identifier of your beacon.
         You can find identifiers of your beacon at https://cloud.estimote.com/#/beacons
         */
        self.notificationManager.enableNotifications(deviceIdentifier: "B34C0N-1-CL0UD-1D3NT1F13R",
                                                      enterMessage: "Hello, world! ✌️",
                                                      exitMessage: "Goodbye! 👋")
        
        return true
    }
}
