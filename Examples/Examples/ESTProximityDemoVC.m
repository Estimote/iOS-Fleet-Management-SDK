//
//  ESTProximityDemoVC.m
//  Examples
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTProximityDemoVC.h"
#import "ESTBeaconManager.h"

@interface ESTProximityDemoVC () <ESTBeaconManagerDelegate>

@property (nonatomic, strong) ESTBeacon         *beacon;
@property (nonatomic, strong) ESTBeaconManager  *beaconManager;
@property (nonatomic, strong) ESTBeaconRegion   *beaconRegion;

@property (nonatomic, strong) UIImageView       *imageView;
@property (nonatomic, strong) UILabel           *zoneLabel;

@end

@implementation ESTProximityDemoVC

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
    
    self.title = @"Proximity Demo";
    
    /*
     * UI setup.
     */
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.zoneLabel = [[UILabel alloc] initWithFrame:CGRectMake(0,
                                                               100,
                                                               self.view.frame.size.width,
                                                               40)];
    self.zoneLabel.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:self.zoneLabel];
    
    self.imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0,
                                                                   64,
                                                                   self.view.frame.size.width,
                                                                   self.view.frame.size.height - 64)];
    self.imageView.contentMode = UIViewContentModeCenter;
    [self.view addSubview:self.imageView];
    
    /*
     * BeaconManager setup.
     */
    self.beaconManager = [[ESTBeaconManager alloc] init];
    self.beaconManager.delegate = self;
    
    self.beaconRegion = [[ESTBeaconRegion alloc] initWithProximityUUID:self.beacon.proximityUUID
                                                                 major:[self.beacon.major unsignedIntValue]
                                                                 minor:[self.beacon.minor unsignedIntValue]
                                                            identifier:@"RegionIdentifier"];
    [self.beaconManager startRangingBeaconsInRegion:self.beaconRegion];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [self.beaconManager stopRangingBeaconsInRegion:self.beaconRegion];

    [super viewDidDisappear:animated];
}

#pragma mark - ESTBeaconManager delegate

- (void)beaconManager:(ESTBeaconManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(ESTBeaconRegion *)region
{
    if (beacons.count > 0)
    {
        ESTBeacon *firstBeacon = [beacons firstObject];
        
        self.zoneLabel.text     = [self textForProximity:firstBeacon.proximity];
        self.imageView.image    = [self imageForProximity:firstBeacon.proximity];
    }
}

#pragma mark - 

- (NSString *)textForProximity:(CLProximity)proximity
{
    switch (proximity) {
        case CLProximityFar:
            return @"Far";
            break;
        case CLProximityNear:
            return @"Near";
            break;
        case CLProximityImmediate:
            return @"Immediate";
            break;
            
        default:
            return @"Unknown";
            break;
    }
}

- (UIImage *)imageForProximity:(CLProximity)proximity
{
    switch (proximity) {
        case CLProximityFar:
            return [UIImage imageNamed:@"far_image"];
            break;
        case CLProximityNear:
            return [UIImage imageNamed:@"near_image"];
            break;
        case CLProximityImmediate:
            return [UIImage imageNamed:@"immediate_image"];
            break;
            
        default:
            return [UIImage imageNamed:@"unknown_image"];
            break;
    }
}

@end
