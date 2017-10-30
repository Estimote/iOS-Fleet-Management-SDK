//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

        /** TODO: Replace with your App ID and App Token.
         You can get them by adding a new app at https://cloud.estimote.com/#/apps
         */
        ESTConfig.setupAppID("<#App ID#>", andAppToken:"<#App Token#>");
        
        self.setupNavigationBarAppearance()
        
        return true
    }
    
    func setupNavigationBarAppearance() {
        let navigationBarAppearance = UINavigationBar.appearance()
        navigationBarAppearance.tintColor = UIColor.lightGray
        navigationBarAppearance.setBackgroundImage(UIImage(), for: UIBarMetrics.default)
        navigationBarAppearance.shadowImage = UIImage()
    }
}
