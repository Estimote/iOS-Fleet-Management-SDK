//
//  BeaconManager.h
//  estimoteBLElib
//
//  Created by Grzegorz Krukiewicz-Gacek on 10.09.2013.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZoneName) {
    Immediate,
    Near,
    Far,
    Unknown
};

@protocol BeaconManagerDelegate
@optional
- (void)managerDidConnectToBeacon;
- (void)managerDidDisconnectBeacon;
- (void)beaconDidUpdateRSSI:(int)RSSI;
- (void)enteredBeaconZone:(ZoneName)zone;

@end

@interface BeaconManager : NSObject
{
    __unsafe_unretained id <BeaconManagerDelegate> _delegate;
}

@property (assign, nonatomic) id <BeaconManagerDelegate> delegate;

- (void)startLookingForBeacons;
- (void)startUpdatingRSSI;
- (void)stopUpdatingRSSI;

- (void)startMonitoringZones;
- (void)stopMonitoringZones;

@end
