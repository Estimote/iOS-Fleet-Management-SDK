//
//  ESTAppDelegate.m
//  Examples
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTAppDelegate.h"
#import "ESTViewController.h"
#import <EstimoteSDK/EstimoteSDK.h>

@implementation ESTAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // App ID and App Token should be provided using method below
    // to allow beacons connection and Estimote Cloud requests possible.
    // Both values can be found in Estimote Cloud ( http://cloud.estimote.com )
    // in Account Settings tab.
    
    NSLog(@"ESTAppDelegate: APP ID and APP TOKEN are required to connect to your beacons and make Estimote API calls.");
    [ESTCloudManager setupAppID:nil andAppToken:nil];
    
    // Estimote Analytics allows you to log activity related to monitoring mechanism.
    // At the current stage it is possible to log all enter/exit events when monitoring
    // Particular beacons (Proximity UUID, Major, Minor values needs to be provided).
    
    NSLog(@"ESTAppDelegate: Analytics are turned OFF by defaults. You can enable them changing flag");
    [ESTCloudManager enableMonitoringAnalytics:NO];
    [ESTCloudManager enableGPSPositioningForAnalytics:NO];
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    ESTViewController* demoList = [[ESTViewController alloc] initWithStyle:UITableViewStyleGrouped];
    
    self.mainNavigation = [[UINavigationController alloc] initWithRootViewController:demoList];
    self.window.rootViewController = self.mainNavigation;
    
    [self.window makeKeyAndVisible];
    
    [[UINavigationBar appearance] setBarTintColor:[UIColor colorWithRed:0.490 green:0.631 blue:0.549 alpha:1.000]];
    [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
    [[UINavigationBar appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName: [UIColor whiteColor],
                                                           NSFontAttributeName: [UIFont systemFontOfSize:18]}];
    
    // Register for remote notificatons related to Estimote Remote Beacon Management.
    if (IS_OS_8_OR_LATER)
    {
        [[UIApplication sharedApplication] registerForRemoteNotifications];
        
        UIUserNotificationType userNotificationTypes = (UIUserNotificationTypeNone);
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:userNotificationTypes
                                                                                 categories:nil];
        
        [application registerUserNotificationSettings:settings];
    }
    else
    {
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes: UIRemoteNotificationTypeNone];
    }
    
    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    // After device is registered in iOS to receive Push Notifications,
    // device token has to be sent to Estimote Cloud.
    self.cloudManager = [ESTCloudManager new];
    [self.cloudManager registerDeviceForRemoteManagement:deviceToken
                                              completion:^(NSError *error) {
                                                  
                                              }];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
{
    // Verify if push is comming from Estimote Cloud and is related
    // to remote beacon management
    if ([ESTBulkUpdater verifyPushNotificationPayload:userInfo])
    {
        // pending settings are fetched and performed automatically
        // after startWithCloudSettingsAndTimeout: method call
        [[ESTBulkUpdater sharedInstance] startWithCloudSettingsAndTimeout:60 * 60];
    }
    
    completionHandler(UIBackgroundFetchResultNewData);
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
