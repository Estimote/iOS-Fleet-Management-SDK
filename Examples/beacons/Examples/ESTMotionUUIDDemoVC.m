//
//  ESTMotionUUIDDemoVC.m
//  Examples
//
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTMotionUUIDDemoVC.h"
#import <AudioToolbox/AudioToolbox.h>
#import <ESTBeaconManager.h>
#import "ESTMotionUUIDSettingsDemoVC.h"

@interface ESTMotionUUIDDemoVC () <ESTBeaconManagerDelegate>

@property (nonatomic, assign) BOOL shouldVibrate;

@property (nonatomic, strong) ESTBeacon *beacon;
@property (nonatomic, strong) ESTBeaconManager *beaconManager;

//UI properties
@property (nonatomic, strong) IBOutlet UILabel *motionLabel;
@property (nonatomic, strong) IBOutlet UIImageView *beaconImage;

@end

@implementation ESTMotionUUIDDemoVC

- (id)initWithBeacon:(ESTBeacon*)beacon
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
    self.title = @"Accelerometer Demo";
    
    self.beaconManager = [ESTBeaconManager new];
    self.beaconManager.delegate = self;
    
    ESTBeaconRegion *motionRegion = [[ESTBeaconRegion alloc] initWithProximityUUID:self.beacon.proximityUUID
                                                                       major:[self.beacon.major unsignedShortValue]
                                                                       minor:[self.beacon.minor unsignedShortValue]
                                                                  identifier:@"RegularBeaconRegion"];
    
    
    /**
     *  Motion UUID mechanism is simple. When beacon is in motion
     *  it's Proximiy UUID value changes to the one that is different
     *  then original (First bit of it is flipped). The best thing is tha
     *  you don't need to bother how changed proximity UUID looks like.
     *
     *  Just set region inMotion flag to YES and let ESTBeaconManager do 
     *  the rest.
     */
    motionRegion.inMotion = YES;
    
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

- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region
{
    
    /**
     *  You can simply verify if ranged region is the inMotion one
     *  using simple condition as below.
     */
    if(beacons.count > 0 && region.inMotion)
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
