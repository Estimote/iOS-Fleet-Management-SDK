//
//  ESTVirtualBeaconDemoVC.m
//  Examples
//
//  Created by Marcin Klimek on 23/04/15.
//  Copyright (c) 2015 com.estimote. All rights reserved.
//

#import "ESTVirtualBeaconDemoVC.h"
#import <EstimoteSDK/EstimoteSDK.h>

@interface ESTVirtualBeaconDemoVC () <ESTBeaconManagerDelegate>

@property (nonatomic, strong) ESTBeaconManager *beaconManager;

@end

@implementation ESTVirtualBeaconDemoVC

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Vritual Beacon";
    
    // Create beacon manager
    self.beaconManager = [ESTBeaconManager new];
    self.beaconManager.delegate = self;
}

- (void)viewWillAppear:(BOOL)animated
{
    // Start advertising as ibeacon by providing required information
    // when view appears on the screen
    [self.beaconManager startAdvertisingWithProximityUUID:ESTIMOTE_PROXIMITY_UUID
                                                    major:1111
                                                    minor:2222
                                               identifier:@"VirtualBeacon"];
}

- (void)viewDidDisappear:(BOOL)animated
{
    // stop advertising when leaving screen
    [self.beaconManager stopAdvertising];
}

#pragma mark - ESTBeaconManager delegate handling

- (void)beaconManagerDidStartAdvertising:(id)manager error:(NSError *)error
{
    // Advertising failed - usually when you try
    // to advertise when previous advertising wasn't stopped.
    if (error)
    {
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Advertising error!"
                                                            message:error.localizedDescription
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles: nil];
        [alertView show];
    }
}

@end
