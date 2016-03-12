//
//  MonitoringDetailsViewController.m
//  MonitoringExample
//
//  Created by Marcin Klimek on 09/01/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "MonitoringDetailsViewController.h"

@interface MonitoringDetailsViewController ()

@property (nonatomic, strong) IBOutlet UISwitch *enterSwitch;
@property (nonatomic, strong) IBOutlet UISwitch *exitSwitch;

@end

@implementation MonitoringDetailsViewController

- (void)viewDidLoad
{
    /**
     *  Setup title of the screen based on nearable type.
     */
    self.title = [NSString stringWithFormat:@"Nearable: %@", [ESTNearableDefinitions nameForType:self.nearable.type]];
    
    /**
     *  Create Estimote Nearable Manager and start looking for
     *  the nearable device selected on previous screen and keept
     *  as self.nearable property.
     */
    self.nearableManager = [ESTNearableManager new];
    self.nearableManager.delegate = self;
    
    [self.nearableManager startMonitoringForIdentifier:self.nearable.identifier];
}



#pragma mark - ESTNearableManager delegate

- (void)nearableManager:(ESTNearableManager *)manager didEnterIdentifierRegion:(NSString *)identifier
{
    /**
     *  Verify if Enter switch is on, show local notification if ON.
     */
    if (self.enterSwitch.isOn)
    {
        UILocalNotification *notification = [UILocalNotification new];
        notification.alertBody = @"Enter region notification";
        
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
}

- (void)nearableManager:(ESTNearableManager *)manager didExitIdentifierRegion:(NSString *)identifier
{
    /**
     *  Verify if Exit switch is on, show local notification if ON.
     */
    if (self.exitSwitch.isOn)
    {
        UILocalNotification *notification = [UILocalNotification new];
        notification.alertBody = @"Exit region notification";
        
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
}

@end
