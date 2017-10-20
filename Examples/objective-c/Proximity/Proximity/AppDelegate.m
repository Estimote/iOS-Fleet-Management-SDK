//
// Please report any problems with this app template to contact@estimote.com
//

#import "AppDelegate.h"

#import <EstimoteSDK/EstimoteSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    /** TODO: Replace with your App ID and App Token.
     You can get them by adding a new app at https://cloud.estimote.com/#/apps
     */
    [ESTConfig setupAppID:@"<#App ID#>" andAppToken:@"<#App Token#>"];

    return YES;
}

@end
