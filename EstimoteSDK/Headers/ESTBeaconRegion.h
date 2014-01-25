//
//  ESTBeaconRegion.h
//  EstimoteSDK
//
//  Version : 1.3.0
//  Created by Marcin Klimek on 9/21/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>



/**
 
 A ESTBeaconRegion object defines a type of region that is based on the device’s proximity to a Bluetooth beacon, as opposed to a geographic location. A beacon region looks for devices whose identifying information matches the information you provide. When that device comes in range, the region triggers the delivery of an appropriate notification.
 
 You can monitor beacon regions in two ways. To receive notifications when a device enters or exits the vicinity of a beacon, use the startMonitoringForRegion: method of your location manager object. While a beacon is in range, you can also call the startRangingBeaconsInRegion: method to begin receiving notifications when the relative distance to the beacon changes.
 
 ESTBeaconRegion extends basic CLBeaconRegion Core Location object, allowing to directly initialize region that is supported by Estimote Cloud platform.
 
 */
@interface ESTBeaconRegion : CLBeaconRegion


@end
