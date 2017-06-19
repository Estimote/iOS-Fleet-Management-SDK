//
// Please report any problems with this app to contact@estimote.com
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, ESTBeaconManagerDelegate {

    var window: UIWindow?
    
    let beaconManager = ESTBeaconManager()

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        self.beaconManager.delegate = self
        self.beaconManager.requestAlwaysAuthorization()
        ESTConfig.setupAppID(<#AppID#>, andAppToken: <#AppToken#>)
        UIApplication.shared.statusBarStyle = UIStatusBarStyle.lightContent
        return true
    }

}
