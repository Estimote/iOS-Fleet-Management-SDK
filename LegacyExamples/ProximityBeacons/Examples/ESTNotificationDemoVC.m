//
//  ESTNotificationDemoVC.m
//  Examples
//
//  Created by Grzegorz Krukiewicz-Gacek on 18.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTNotificationDemoVC.h"

@interface ESTNotificationDemoVC () <ESTBeaconManagerDelegate>


@property (nonatomic, strong) CLBeacon *beacon;
@property (nonatomic, strong) ESTBeaconManager *beaconManager;
@property (nonatomic, strong) CLBeaconRegion *beaconRegion;

@property (nonatomic, strong) IBOutlet UIView *mainView;
@property (nonatomic, strong) IBOutlet UISwitch *enterRegionSwitch;
@property (nonatomic, strong) IBOutlet UISwitch *exitRegionSwitch;

@end

@implementation ESTNotificationDemoVC

- (id)initWithBeacon:(CLBeacon *)beacon
{
    self = [super init];
    if (self)
    {
        self.beacon = beacon;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Notification Demo";
    self.view.backgroundColor = [UIColor whiteColor];
    
    CGRect frame = self.mainView.frame;
    frame.origin.y = [UIScreen mainScreen].bounds.size.height - frame.size.height;
    self.mainView.frame = frame;

    /*
     * Persmission to show Local Notification.
     */
    UIApplication *application = [UIApplication sharedApplication];
    if ([application respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }

    /*
     * BeaconManager setup.
     */
    
    self.beaconManager = [[ESTBeaconManager alloc] init];
    self.beaconManager.delegate = self;
    
    self.beaconRegion = [[CLBeaconRegion alloc] initWithProximityUUID:self.beacon.proximityUUID
                                                                 major:[self.beacon.major unsignedIntValue]
                                                                 minor:[self.beacon.minor unsignedIntValue]
                                                            identifier:@"RegionIdentifier"];

    self.beaconRegion.notifyOnEntry = self.enterRegionSwitch.isOn;
    self.beaconRegion.notifyOnExit = self.exitRegionSwitch.isOn;
    
    [self.beaconManager startMonitoringForRegion:self.beaconRegion];
}

#pragma mark - ESTBeaconManager delegate

- (void)beaconManager:(id)manager monitoringDidFailForRegion:(CLBeaconRegion *)region withError:(NSError *)error
{
    UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Monitoring error"
                                                        message:error.localizedDescription
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
    
    [errorView show];
}

- (void)beaconManager:(id)manager didEnterRegion:(CLBeaconRegion *)region
{
    UILocalNotification *notification = [UILocalNotification new];
    notification.alertBody = @"Enter region notification";
    
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

- (void)beaconManager:(id)manager didExitRegion:(CLBeaconRegion *)region
{
    UILocalNotification *notification = [UILocalNotification new];
    notification.alertBody = @"Exit region notification";
    
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

#pragma mark -

- (void)switchValueChanged
{
    [self.beaconManager stopMonitoringForRegion:self.beaconRegion];
    
    self.beaconRegion.notifyOnEntry = self.enterRegionSwitch.isOn;
    self.beaconRegion.notifyOnExit = self.exitRegionSwitch.isOn;
    
    [self.beaconManager startMonitoringForRegion:self.beaconRegion];
}

@end
