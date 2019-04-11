//
//  ESTSettingsDeviceUtility.h
//  EstimoteSDK
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"


@interface ESTDeviceTypeUtilitySettings : NSObject <NSCopying>

@property (nonatomic, strong, readonly) NSString *publicID;

#pragma mark - iBeacon settings


@property (nonatomic, strong, readonly) NSUUID *proximityUUID;
@property (nonatomic, strong, readonly) NSUUID *motionProximityUUID;

@property (nonatomic, strong, readonly) NSNumber *major;
@property (nonatomic, strong, readonly) NSNumber *minor;

@property (nonatomic, strong, readonly) NSNumber *secureUUIDRotationScaler;

#pragma mark - Broadcasting settings

@property (nonatomic, strong, readonly) NSNumber *power;
@property (nonatomic, strong, readonly) NSNumber *advInterval;

#pragma mark - Power settings


@property (nonatomic, strong, readonly) NSNumber *batteryLevel;
@property (nonatomic, strong, readonly) NSNumber *batteryLifeExpectancy;

#pragma mark - System settings

@property (nonatomic, assign, readonly) ESTColor color;
@property (nonatomic, strong, readonly) NSString *name;

@property (nonatomic, strong, readonly) NSString *hardware;
@property (nonatomic, strong, readonly) NSString *firmware;

@property (nonatomic, strong, readonly) NSString *applicationVersion;
@property (nonatomic, strong, readonly) NSString *bootloaderVersion;

#pragma mark - Location settings

@property (nonatomic, strong, readonly) NSNumber *latitude;
@property (nonatomic, strong, readonly) NSNumber *longitude;
@property (nonatomic, strong, readonly) NSString *location;

#pragma mark - Sensors settings

@property (nonatomic, strong, readonly) NSNumber *temperature;
@property (nonatomic, strong, readonly) NSNumber *illuminance;
@property (nonatomic, assign, readonly) BOOL darkToSleep;
@property (nonatomic, assign, readonly) NSNumber *darkToSleepThreshold;

@end
