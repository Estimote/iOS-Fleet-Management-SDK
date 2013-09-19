//
//  DistanceDemoViewController.m
//  Estimote Simulator
//
//  Created by Estimote Inc. on 24.07.2013.
//  Copyright (c) 2013 Estimote Inc. All rights reserved.
//

#import "DistanceDemoViewController.h"

@interface DistanceDemoViewController ()

@property (nonatomic, strong) BeaconManager *beaconManager;
@property (nonatomic, strong) NSMutableArray *lastFiveRSSI;
@property (nonatomic, assign) int arrayInsertIndex;

@property (nonatomic, assign) int aEq;
@property (nonatomic, assign) int bEq;
@property (nonatomic, strong) UIImageView *positionDot;

@property (nonatomic, assign) BOOL isShowingAlertView;

+ (BOOL)amplitudeInNumbersArray:(NSArray *)array isLowerThan:(float)floatNumber;

@end

@implementation DistanceDemoViewController

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
    
    _isShowingAlertView = NO;
    
    /*
     we will use this array and the amplitudeInNumbersArray: isLowerThan: method 
     to check if the user hasn't stopped,
     if so, we can display proper info, for example to continue moving
     */
    _lastFiveRSSI = [[NSMutableArray alloc] initWithArray:@[@0, @0, @0, @0, @0]];
    _arrayInsertIndex = 0;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    self.title = @"Distance demo";

    /*
     after the view appeared we should ask the beaconManager
     to search for beacons
     */
    _beaconManager = [BeaconManager new];
    _beaconManager.delegate = self;
    [_beaconManager startLookingForBeacons];
            
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenHeight = screenRect.size.height;
        
    UIImageView *bgImageView = [[UIImageView alloc] initWithFrame:self.view.bounds];
    
    if (screenHeight > 480)
        bgImageView.image = [UIImage imageNamed:@"backgroundBig"];
    else
        bgImageView.image = [UIImage imageNamed:@"backgroundSmall"];
    
    bgImageView.contentMode = UIViewContentModeScaleToFill;
    [self.view addSubview:bgImageView];
    
    _positionDot = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"dotImage"]];
    [_positionDot setCenter:self.view.center];
    _positionDot.alpha = 0.0;
    [self.view addSubview:_positionDot];
    
    /*
     here we count the factors for the equation, that we will use to count the dot position
     this is a simple linear equation y = aEq * RSSI + bEq
     */
    int y1 = 150;
    int y2 = screenHeight - 70;
    
    _aEq = (y2 - y1)/ - 50;
    _bEq = y1 + 35 * _aEq; // -35 maximum RSSI signal
}

+ (BOOL)amplitudeInNumbersArray:(NSArray *)array isLowerThan:(float)floatNumber
{
    float bigest = [[array objectAtIndex:0] floatValue];
    float smallest = [[array objectAtIndex:0] floatValue];
    
    for (NSNumber *aNumber in array) {
        
        if ([aNumber floatValue] > bigest)
            bigest = [aNumber floatValue];
        else if ([aNumber floatValue] < smallest)
            smallest = [aNumber floatValue];
    }
        
    if (bigest-smallest < floatNumber && array.count > 4)
        return YES;
    else
        return NO;
}

#pragma mark - BeaconManager delegate methods

- (void)managerDidConnectToBeaconWithID:(NSString *)beaconID
{
    [_beaconManager startUpdatingRSSI];
    _positionDot.alpha = 1.0;
}

- (void)managerDidDisconnectBeaconWithID:(NSString *)beaconID
{
    [_beaconManager startLookingForBeacons];
}

- (void)didUpdateRSSI:(int)RSSI forBeaconWithID:(NSString *)beaconID
{    
    [_lastFiveRSSI replaceObjectAtIndex:_arrayInsertIndex withObject:[NSNumber numberWithInt:RSSI]];
    _arrayInsertIndex ++;
    
    if (_arrayInsertIndex > 4)
        _arrayInsertIndex = 0;
    
    if ([DistanceDemoViewController amplitudeInNumbersArray:_lastFiveRSSI isLowerThan:2] && !_isShowingAlertView) {
       
        _isShowingAlertView = YES;
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Hey!" message:@"You stopped moving" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alertView show];
    }
    
    /*
     we can inform the user that the signal is lost a moment before he will actually leave the range of the beacon
     */
    if (RSSI < -89 && !_isShowingAlertView) {
       
        RSSI = -89;
        
        _isShowingAlertView = YES;
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Hey!" message:@"You left the beacon range" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alertView show];
    }

    /*
     counting the new position for the dot
     */
    int targetY = _aEq * RSSI + _bEq;
    [UIView animateWithDuration:0.2 animations:^{
    
        [_positionDot setCenter:CGPointMake(self.view.center.x,
                                          targetY)];
    }];
}

#pragma mark - UIAlertView delegate methods

- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    _isShowingAlertView = NO;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
