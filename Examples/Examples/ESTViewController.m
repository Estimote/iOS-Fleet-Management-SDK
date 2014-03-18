//
//  ESTViewController.m
//  Examples
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTViewController.h"
#import "ESTBeaconTableVC.h"
#import "ESTDistanceDemoVC.h"
#import "ESTProximityDemoVC.h"
#import "ESTNotificationDemoVC.h"

@implementation ESTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.

}

- (IBAction)showDistanceDemo:(id)sender
{
    ESTBeaconTableVC *beaconTableVC = [[ESTBeaconTableVC alloc] initWithCompletionHandler:^(ESTBeacon *beacon) {
        
        ESTDistanceDemoVC *distanceDemoVC = [[ESTDistanceDemoVC alloc] initWithBeacon:beacon];
        [self.navigationController pushViewController:distanceDemoVC animated:YES];
    }];
    
    [self presentViewController:[[UINavigationController alloc] initWithRootViewController: beaconTableVC]
                       animated:YES
                     completion:nil];
}

- (IBAction)showProximityDemo:(id)sender
{
    ESTBeaconTableVC *beaconTableVC = [[ESTBeaconTableVC alloc] initWithCompletionHandler:^(ESTBeacon *beacon) {
        
        ESTProximityDemoVC *proximityDemoVC = [[ESTProximityDemoVC alloc] initWithBeacon:beacon];
        [self.navigationController pushViewController:proximityDemoVC animated:YES];
    }];
    
    [self presentViewController:[[UINavigationController alloc] initWithRootViewController: beaconTableVC]
                       animated:YES
                     completion:nil];
}

- (IBAction)showNotificationDemo:(id)sender
{
    ESTBeaconTableVC *beaconTableVC = [[ESTBeaconTableVC alloc] initWithCompletionHandler:^(ESTBeacon *beacon) {
        
        ESTNotificationDemoVC *notificationDemoVC = [[ESTNotificationDemoVC alloc] initWithBeacon:beacon];
        [self.navigationController pushViewController:notificationDemoVC animated:YES];
    }];
    
    [self presentViewController:[[UINavigationController alloc] initWithRootViewController: beaconTableVC]
                       animated:YES
                     completion:nil];
}

@end
