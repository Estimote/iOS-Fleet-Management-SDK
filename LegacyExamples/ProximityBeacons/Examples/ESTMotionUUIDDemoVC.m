//
//  ESTMotionUUIDDemoVC.m
//  Examples
//
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTMotionUUIDDemoVC.h"
#import <AudioToolbox/AudioToolbox.h>
#import <EstimoteSDK/EstimoteSDK.h>
#import "ESTMotionUUIDSettingsDemoVC.h"

@interface ESTMotionUUIDDemoVC () <ESTBeaconManagerDelegate>

@property (nonatomic, assign) BOOL shouldVibrate;

@property (nonatomic, strong) CLBeacon *beacon;
@property (nonatomic, strong) ESTBeaconManager *beaconManager;

//UI properties
@property (nonatomic, strong) IBOutlet UILabel *motionLabel;
@property (nonatomic, strong) IBOutlet UIImageView *beaconImage;

@end

@implementation ESTMotionUUIDDemoVC

- (id)initWithBeacon:(CLBeacon *)beacon
{
    self = [self init];
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
    self.title = @"Motion UUID Demo";
    
    self.beaconManager = [ESTBeaconManager new];
    self.beaconManager.delegate = self;
    
    NSUUID *motionUUID = [ESTBeaconManager motionProximityUUIDForProximityUUID:self.beacon.proximityUUID];
    
    CLBeaconRegion *motionRegion = [[CLBeaconRegion alloc] initWithProximityUUID:motionUUID
                                                                           major:[self.beacon.major unsignedShortValue]
                                                                           minor:[self.beacon.minor unsignedShortValue]
                                                                      identifier:@"MotionBeaconRegion"];
    
    
    [self.beaconManager startRangingBeaconsInRegion:motionRegion];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

#pragma mark - Other Methods

- (void)startVibrate
{
    if (!self.shouldVibrate)
    {
        self.motionLabel.text = @"Beacon in motion";
        
        self.shouldVibrate = YES;
        [self animateVibration];
    }
}

- (void)stopVibrate
{
    self.shouldVibrate = NO;
    
    self.motionLabel.text = @"Beacon not in motion";
}

- (void)animateVibration
{
    if (self.shouldVibrate)
    {
        AudioServicesPlayAlertSound(kSystemSoundID_Vibrate);
        
        CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"transform.translation.x"];
        animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionLinear];
        animation.duration = 0.6;
        animation.values = @[ @(-20), @(20), @(-20), @(20), @(-10), @(10), @(-5), @(5), @(0) ];
        [self.beaconImage.layer addAnimation:animation forKey:@"shake"];
        
        [self performSelector:@selector(animateVibration) withObject:nil afterDelay:0.6];
    }
}



#pragma mark - ESTBeaconDelegate

- (void)beaconManager:(id)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(CLBeaconRegion *)region
{
    
    /**
     *  You can simply verify if ranged region is the inMotion one
     *  using simple condition as below.
     */
    if(beacons.count > 0)
    {
        [self startVibrate];
    }
    else
    {
        [self stopVibrate];
    }
}


- (IBAction)showSettings
{
    /**
     *  Access settings to check how enable and disble motion UUID feature.
     */
    ESTMotionUUIDSettingsDemoVC *settingsDemoVC = [[ESTMotionUUIDSettingsDemoVC alloc] initWithBeacon:self.beacon];
    [self.navigationController pushViewController:settingsDemoVC animated:YES];
}



@end
