//
//  PushNotificationsDemoViewController.m
//  Estimote Simulator
//
//  Created by Grzegorz Krukiewicz-Gacek on 25.07.2013.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "PushNotificationsDemoViewController.h"

@interface PushNotificationsDemoViewController ()

@property (nonatomic, strong) BeaconManager *beaconManager;
@property (nonatomic, strong) UIImageView *bgImageView;
@property (nonatomic, assign) BOOL notificationShown;

@end

@implementation PushNotificationsDemoViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    self.title = @"Notification Demo";
    
    _notificationShown = NO;
    
    /*
     after the view appeared we should ask the beaconManager
     to search for beacons
     */
    _beaconManager = [BeaconManager new];
    _beaconManager.delegate = self;
    [_beaconManager startLookingForBeacons];
        
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenHeight = screenRect.size.height;

    _bgImageView = [[UIImageView alloc] initWithFrame:self.view.bounds];
    
    /*
     This is the image or any other type of info you can display to the user before he locks the phone
     */
    if (screenHeight > 480)
        _bgImageView.image = [UIImage imageNamed:@"beforeNotificationBig"];
    else
        _bgImageView.image = [UIImage imageNamed:@"beforeNotificationSmall"];
    
    _bgImageView.contentMode = UIViewContentModeTop;
    [self.view addSubview:_bgImageView];
}

#pragma mark
#pragma mark - CoreBluetooth delegate methods

- (void)managerDidConnectToBeacon
{
    [_beaconManager startUpdatingRSSI];
}

- (void)beaconDidUpdateRSSI:(int)RSSI
{
    /*
     Simmiliarly to the distance demo, we notify the user about leaving the range before 
     he realy exits the beacons range. You can only use the managerDidDisconnectBeacon method or change 
     the RSSI limit to -80 or -90 to delay the notification
     */    
    NSLog(@"RSSI: %d", RSSI);
    if (RSSI < -75 && !_notificationShown) {
        
        _notificationShown = YES;
        
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        notification.alertBody = @"The shoes you'd tried on are now 20%% off for you with this coupon";
        notification.soundName = UILocalNotificationDefaultSoundName;
        
        [self presentAfterNotificationInfo];
        
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
}

- (void)managerDidDisconnectBeacon
{
    NSLog(@"Did disconnect beacon");
    
    if (!_notificationShown) {
        
        _notificationShown = YES;
        
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        notification.alertBody = @"The shoes you'd tried on are now 20%% off for you with this coupon";
        notification.soundName = UILocalNotificationDefaultSoundName;
        
        [self presentAfterNotificationInfo];
        
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
}

- (void)presentAfterNotificationInfo
{
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenHeight = screenRect.size.height;
    
    /*
     This is the image or any other type of info you can display to the user
     after he opens the app from notification
     */
    if (screenHeight > 480)
        _bgImageView.image = [UIImage imageNamed:@"afterNotificationBig"];
    else
        _bgImageView.image = [UIImage imageNamed:@"afterNotificationSmall"];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
