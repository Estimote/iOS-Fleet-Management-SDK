//
//  ESTNotificationDemoVC.m
//  Examples
//
//  Created by Grzegorz Krukiewicz-Gacek on 18.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTNotificationDemoVC.h"
#import "ESTBeaconManager.h"

@interface ESTNotificationDemoVC () <ESTBeaconManagerDelegate>

@property (nonatomic, strong) ESTBeacon         *beacon;
@property (nonatomic, strong) ESTBeaconManager  *beaconManager;
@property (nonatomic, strong) ESTBeaconRegion   *beaconRegion;

@property (nonatomic, strong) UISwitch          *enterRegionSwitch;
@property (nonatomic, strong) UISwitch          *exitRegionSwitch;

@end

@implementation ESTNotificationDemoVC

- (id)initWithBeacon:(ESTBeacon *)beacon
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
    
    self.view.backgroundColor = [UIColor whiteColor];

    /*
     * UI setup
     */
    self.enterRegionSwitch = [UISwitch new];
    [self.enterRegionSwitch setOn:YES animated:NO];
    [self.enterRegionSwitch setCenter:CGPointMake(self.view.frame.size.width - 40, self.view.center.y - 20)];
    [self.enterRegionSwitch addTarget:self action:@selector(switchValueChanged) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.enterRegionSwitch];
    
    self.exitRegionSwitch = [UISwitch new];
    [self.exitRegionSwitch setOn:YES animated:NO];
    [self.exitRegionSwitch setCenter:CGPointMake(self.view.frame.size.width - 40, self.view.center.y + 20)];
    [self.exitRegionSwitch addTarget:self action:@selector(switchValueChanged) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.exitRegionSwitch];
    
    UILabel *enterRegionLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, self.enterRegionSwitch.center.y - 20, self.view.frame.size.width, 40)];
    enterRegionLabel.text = @"Enter region notification";
    [self.view addSubview:enterRegionLabel];
    
    UILabel *exitRegionLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, self.exitRegionSwitch.center.y - 20, self.view.frame.size.width, 40)];
    exitRegionLabel.text = @"Exit region notification";
    [self.view addSubview:exitRegionLabel];
    
    UITextView *infoTextView = [[UITextView alloc] initWithFrame:CGRectMake(20, self.view.frame.size.height - 160, self.view.frame.size.width - 40, 140)];
    infoTextView.editable = NO;
    infoTextView.font = [UIFont systemFontOfSize:16];
    infoTextView.text = @"Lock the screen and go far away from the beacon until you get the exit region notification. If you come back, you will see an enter region notification.";
    [self.view addSubview:infoTextView];
    
     
    /*
     * BeaconManager setup.
     */
    self.beaconManager = [[ESTBeaconManager alloc] init];
    self.beaconManager.delegate = self;
    
    self.beaconRegion = [[ESTBeaconRegion alloc] initWithProximityUUID:self.beacon.proximityUUID
                                                                 major:[self.beacon.major unsignedIntValue]
                                                                 minor:[self.beacon.minor unsignedIntValue]
                                                            identifier:@"RegionIdentifier"];
    self.beaconRegion.notifyOnEntry = self.enterRegionSwitch.isOn;
    self.beaconRegion.notifyOnExit = self.exitRegionSwitch.isOn;
    
    [self.beaconManager startMonitoringForRegion:self.beaconRegion];
}

#pragma mark - ESTBeaconManager delegate

- (void)beaconManager:(ESTBeaconManager *)manager didEnterRegion:(ESTBeaconRegion *)region
{
    UILocalNotification *notification = [UILocalNotification new];
    notification.alertBody = @"Enter region notification";
    
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

- (void)beaconManager:(ESTBeaconManager *)manager didExitRegion:(ESTBeaconRegion *)region
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
