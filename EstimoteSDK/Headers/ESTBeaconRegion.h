//
//  ESTBeaconRegion.h
//  EstimoteSDK
//
//  Version: 2.0.0
//  Created by Marcin Klimek on 9/21/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 
 A ESTBeaconRegion object defines a type of region that is based on the device’s proximity to a Bluetooth beacon, as opposed to a geographic location. A beacon region looks for devices whose identifying information matches the information you provide. When that device comes in range, the region triggers the delivery of an appropriate notification.

**/

@interface ESTBeaconRegion : CLBeaconRegion


@end
