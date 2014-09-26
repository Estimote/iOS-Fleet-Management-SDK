//
//  ESTBeaconRegion.h
//  EstimoteSDK
//
//  Version: 2.1.5
//  Created by Marcin Klimek on 9/21/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 * An ESTBeaconRegion object defines a single beacon or a group of beacons that can be used with ESTBeaconManager to range, monitor and discover beacons.
 *
 * There are three ways to define a region:
 *
 * 1. By providing proximityUUID, major and minor - i.e. initWithProximityUUID:major:minor:identifier: - this defines a region consisting of a single beacon that matches all three of these properties.
 *
 * 2. By providing proximityUUID and major - i.e. initWithProximityUUID:major:identifier: - this defines a region that can consist of multiple beacons, as long as their proximityUUID and major match those of the region.
 *
 * 3. By providing proximityUUID only - i.e. initWithProximityUUID:identifier: - this defines a region that can consist of multiple beacons, as long as their proximityUUID matches this of the region.
 *
 * For more details, consult Apple's CLBeaconRegion documentation:
 *
 * https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLBeaconRegion_class/Reference/Reference.html
 */

@interface ESTBeaconRegion : CLBeaconRegion

@end
