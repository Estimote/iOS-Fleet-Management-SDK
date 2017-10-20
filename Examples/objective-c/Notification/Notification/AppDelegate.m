//
// Please report any problems with this app template to contact@estimote.com
//

#import "AppDelegate.h"

#import <EstimoteSDK/EstimoteSDK.h>
#import "NotificationManager.h"

@interface AppDelegate ()

@property (nonatomic) NotificationManager *notificationManager;

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    /** TODO: Replace with your App ID and App Token.
     You can get them by adding a new app at https://cloud.estimote.com/#/apps
     */
    [ESTConfig setupAppID:@"<#App ID#>" andAppToken:@"<#App Token#>"];

    /** TODO: Make sure your beacons have Estimote Monitoring feature set enabled:
     https://community.estimote.com/hc/en-us/articles/226144728
     */
    
    self.notificationManager = [[NotificationManager alloc] init];
    
    /** TODO: Replace with an identifier of your beacon.
     You can find identifiers of your beacons at https://cloud.estimote.com/#/beacons
     */
    [self.notificationManager enableNotificationsForDeviceIdentifier:@"B34C0N-1-CL0UD-1D3NT1F13R"
                                                         enterMessage:@"Hello, world!"
                                                          exitMessage:@"Goodbye, world."];

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
