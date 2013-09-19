//
//  ProximityDemoViewController.m
//  Estimote Simulator
//
//  Created by Grzegorz Krukiewicz-Gacek on 24.07.2013.
//  Copyright (c) 2013 Grzegorz Krukiewicz-Gacek. All rights reserved.
//

#import "ProximityDemoViewController.h"

@interface ProximityDemoViewController ()

@property (nonatomic, strong) BeaconManager *beaconManager;

@property (nonatomic, strong) UILabel *infoLabel;

@property (nonatomic, assign) ZoneName currentZone;

@end

@implementation ProximityDemoViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    self.title = @"Proximity demo";
    self.view.backgroundColor = [UIColor whiteColor];
    
    /*
     after the view appeared we should ask the beaconManager
     to search for beacons
     */
    _beaconManager = [BeaconManager new];
    _beaconManager.delegate = self;
    [_beaconManager startLookingForBeacons];
    
    _currentZone = Unknown;
    
    /*
     this is the label in which we will put info about changing beacon zones.
     */
    _infoLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height/2 - 30, self.view.bounds.size.width, 60)];
    _infoLabel.font = [UIFont systemFontOfSize:22.0f];
    _infoLabel.textAlignment = NSTextAlignmentCenter;
    _infoLabel.backgroundColor = [UIColor clearColor];
    _infoLabel.text = @"PROXIMITY DEMO";
    
    [self.view addSubview:_infoLabel];
}

#pragma mark 
#pragma mark - BeaconManager delegate methods

- (void)managerDidConnectToBeaconWithID:(NSString *)beaconID
{
    [_beaconManager startMonitoringZones];
}

- (void)managerDidDisconnectBeaconWithID:(NSString *)beaconID
{
    [_beaconManager startLookingForBeacons];
}

/*
 The beacon zones are simply determined by the RSSI which is already stabilised and processed by BeaconManager
 */
- (void)enteredZone:(ZoneName)zone forBeaconWithID:(NSString *)beaconID
{
    if (zone == Immediate && _currentZone != Immediate) {
    
        _currentZone = Immediate;
        
        _infoLabel.text = @"IMMEDIATE region info/image";
    }
    
    else if (zone == Near && _currentZone != Near) {
        
        _currentZone = Near;
        
        _infoLabel.text = @"NEAR region info/image";
    }
    
    else if (zone == Far && _currentZone != Far) {

        _currentZone = Far;
       
        _infoLabel.text = @"FAR region info/image";
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
