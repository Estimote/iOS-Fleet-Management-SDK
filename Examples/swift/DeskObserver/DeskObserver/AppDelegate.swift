//
// Please report any problems with this app template to contact@estimote.com
//


import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // TODO: put your App ID and App Token here
        // You can get them by adding your app on https://cloud.estimote.com/#/apps
        ESTCloudCredentials.setUpSharedInstance(appID: "<#App ID#>", appToken: "<#App Token#>")
        
        return true
    }

}

