//
// Please report any problems with this app to contact@estimote.com
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, ESTBeaconManagerDelegate {

    var window: UIWindow?
    
    let beaconManager = ESTBeaconManager()

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // TODO: put your App ID and App Token here
        // You can get them by adding your app on https://cloud.estimote.com/#/apps
        ESTConfig.setupAppID(<#AppID#>, andAppToken: <#AppToken#>)
        
        self.beaconManager.delegate = self
        self.beaconManager.requestAlwaysAuthorization()

        UIApplication.shared.statusBarStyle = UIStatusBarStyle.lightContent
        return true
    }

}
