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
- (void)managerDidConnectToBeaconWithID:(NSString *)beaconID;
- (void)managerDidDisconnectBeaconWithID:(NSString *)beaconID;
- (void)didUpdateRSSI:(int)RSSI forBeaconWithID:(NSString *)beaconID;
- (void)enteredZone:(ZoneName)zone forBeaconWithID:(NSString *)beaconID;

@end

@interface BeaconManager : NSObject
{
    __weak id <BeaconManagerDelegate> _delegate;
}

@property (weak, nonatomic) id <BeaconManagerDelegate> delegate;

- (void)startLookingForBeacons;
- (void)startUpdatingRSSI;
- (void)stopUpdatingRSSI;

- (void)startMonitoringZones;
- (void)stopMonitoringZones;

@end
