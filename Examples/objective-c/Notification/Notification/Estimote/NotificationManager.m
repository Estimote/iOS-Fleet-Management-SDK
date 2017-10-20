//
// Please report any problems with this app template to contact@estimote.com
//

#import "NotificationManager.h"
#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>


@interface NotificationManager () <ESTMonitoringV2ManagerDelegate>

@property (nonatomic) ESTMonitoringV2Manager *monitoringManager;
@property (nonatomic) NSString *enterMessage;
@property (nonatomic) NSString *exitMessage;

@end

@implementation NotificationManager

- (instancetype)init {
    self = [super init];
    if (self) {
        _monitoringManager = [[ESTMonitoringV2Manager alloc] initWithDesiredMeanTriggerDistance:1.5
                                                                                       delegate:self];
    }
    
    return self;
}

- (void)enableNotificationsForDeviceIdentifier:(NSString *)beaconIdentifier
                                  enterMessage:(NSString *)enterMessage
                                   exitMessage:(NSString *)exitMessage {
    // Set up local notifications
    UIUserNotificationType notificationTypes = (UIUserNotificationTypeAlert | UIUserNotificationTypeSound);
    UIUserNotificationSettings *notificationSettings = [UIUserNotificationSettings settingsForTypes:notificationTypes
                                                                                         categories:nil];
    [[UIApplication sharedApplication] registerUserNotificationSettings:notificationSettings];
    
    // Remember messages to show
    self.enterMessage = enterMessage;
    self.exitMessage = exitMessage;
    
    // Start monitoring
    [self.monitoringManager startMonitoringForIdentifiers:@[beaconIdentifier]];
}

#pragma mark - Private

- (void)showNotificationWithMessage:(NSString *)message {
    UILocalNotification *notification = [UILocalNotification new];
    notification.alertBody = message;
    notification.soundName = UILocalNotificationDefaultSoundName;
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

- (NSString *)nameForState:(ESTMonitoringState)state {
    switch (state) {
        case ESTMonitoringStateUnknown:
            return @"Unknown";
        case ESTMonitoringStateInsideZone:
            return @"Inside";
        case ESTMonitoringStateOutsideZone:
            return @"Outside";
    }
}

#pragma mark ESTMonitoringV2ManagerDelgate

- (void)monitoringManagerDidStart:(ESTMonitoringV2Manager *)manager {
    NSLog(@"Started monitoring successfully.");
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didDetermineInitialState:(ESTMonitoringState)state forBeaconWithIdentifier:(NSString *)identifier {
    NSLog(@"Determined initial state for %@ - %@.", identifier, [self nameForState:state]);
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didEnterDesiredRangeOfBeaconWithIdentifier:(NSString *)identifier {
    NSLog(@"Entered desired range of %@.", identifier);
    [self showNotificationWithMessage:self.enterMessage];
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didExitDesiredRangeOfBeaconWithIdentifier:(NSString *)identifier {
    NSLog(@"Exited desired range of %@.", identifier);
    [self showNotificationWithMessage:self.exitMessage];
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didFailWithError:(NSError *)error {
    NSLog(@"Monitoring failed. Error: %@.", error);
}

@end
