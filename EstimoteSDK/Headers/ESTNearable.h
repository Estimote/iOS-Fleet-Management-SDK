//
//  ESTNearable.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTNearableDefinitions.h"

/**
 * The ESTNearable class defines the interface for interacting with a single Estimote nearable. It enables you to retrieve properties of the nearable. You do not create instances of this class directly. The ESTNearableManager object reports encountered beacons to its associated delegate object.
 *
 * The identity of a nearable is defined by its identifier` property. Identifier of the device is unique among all the Estimote nearables and can not be changed.
 *
 */
@interface ESTNearable : NSObject <NSCopying>

/**
 *  Unique device identifier.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  Zone indicating distance from the device.
 */
@property (nonatomic, assign, readonly) ESTNearableZone zone;

/**
 *  Type of the nearable device.
 */
@property (nonatomic, assign, readonly) ESTNearableType type;

/**
 *  Color of the nearable device.
 */
@property (nonatomic, assign, readonly) ESTNearableColor color;

/**
 *  Revision of nearable hardware.
 */
@property (nonatomic, strong, readonly) NSString *hardwareVersion;

/**
 *  Version of nearable firmware.
 */
@property (nonatomic, strong, readonly) NSString *firmwareVersion;

/**
 *  Bluetooth signal strength. It can take value from -100 to 0. 127 value means RSSI reading error.
 */
@property (nonatomic, assign, readonly) NSInteger rssi;

/**
 *  Battery voltage when nearable is in idle state defined in Volts.
 */
@property (nonatomic, strong, readonly) NSNumber *idleBatteryVoltage;

/**
 *  Battery voltage when nearable is under stress (sending packet) defined in Volts.
 */
@property (nonatomic, strong, readonly) NSNumber *stressBatteryVoltage;

/**
 *  Time since last change of motion state (isMoving value change) returned in seconds.
 */
@property (nonatomic, assign, readonly) unsigned long long currentMotionStateDuration;

/**
 *  Time of nearable's previous motion state returned in seconds.
 */
@property (nonatomic, assign, readonly) unsigned long long previousMotionStateDuration;

/**
 *  Flag indicates if nearable is moving or not.
 */
@property (nonatomic, assign, readonly) BOOL isMoving;

/**
 *  Physical orientation of nearable in space.
 */
@property (nonatomic, assign, readonly) ESTNearableOrientation orientation;

/**
 *  X axis acceleration data.
 */
@property (nonatomic, assign, readonly) NSInteger xAcceleration;

/**
 *  Y axis acceleration data.
 */
@property (nonatomic, assign, readonly) NSInteger yAcceleration;

/**
 *  Z axis acceleration data.
 */
@property (nonatomic, assign, readonly) NSInteger zAcceleration;

/**
 *  Ambient temperature of nearable.
 */
@property (nonatomic, assign, readonly) double temperature;

/**
 * The power of the nearable's radio signal in dBm.
 */
@property (nonatomic, strong, readonly) NSNumber *power;

/**
 * Indicates if nearable is in Boot or App state.
 */
@property (nonatomic, assign, readonly) ESTNearableFirmwareState firmwareState;

@end
