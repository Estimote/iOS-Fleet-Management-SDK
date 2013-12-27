//
//  ESTViewController_Testing.m
//  DistanceDemo
//
//  Created by Rui Peres on 21/12/2013.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "ESTViewController.h"
#import <ESTBeaconManager.h>

@interface ESTViewController_Testing : XCTestCase

@end

@implementation ESTViewController_Testing

- (void)testESTViewControllerShouldComplyWithBeaconManagerDelegate
{
    XCTAssertTrue([ESTViewController conformsToProtocol:@protocol(ESTBeaconManagerDelegate)], @"It should comply with the protocol");
}

- (void)testESTViewControllerShouldRespondToBeaconManagerDidRangeBeaconsInRegionSelectors
{
    ESTViewController *viewController = [[ESTViewController alloc] init];
    
    XCTAssertTrue([viewController respondsToSelector:@selector(beaconManager:didRangeBeacons:inRegion:)], @"It should responds to selector");
}



@end
