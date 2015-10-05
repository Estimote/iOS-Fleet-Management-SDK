//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTEddystoneTelemetry.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ESTEddystoneProximity)
{
    ESTEddystoneProximityUnknown,
    ESTEddystoneProximityImmediate,
    ESTEddystoneProximityNear,
    ESTEddystoneProximityFar
};

/**
 *  Object of this class represents single Eddystone device, with all its available properties.
 *  `ESTEddystone` object should not be created manually. Instances are created by ESTEddystoneManager
*   with discovery process and return in `eddystoneManager:didDiscoverEddystones:withFilter:` delegate method.
 */

@interface ESTEddystone : NSObject <NSCopying>

/**
 *  MAC address of device advertising Eddystone packets
 */
@property (nonatomic, strong) NSString *macAddress;

/**
 *  Signal strength detected on the phone (-100 to 0))
 */
@property (nonatomic, strong) NSNumber *rssi;

/**
 *  One sigma horizontal accuracy in meters.
 */
@property (nonatomic, strong) NSNumber *accuracy;

/**
 * Proximity of the device.
 */
@property (nonatomic) ESTEddystoneProximity proximity;

/**
 *  Last time device was seen.
 */
@property (nonatomic, strong) NSDate *discoveryDate;

/**
 *  Telemetry information delivered in separate packet packet every 10 seconds.
 */
@property (nonatomic, strong) NSNumber *measuredPower;

/**
 *  Namespace ID required for device identification. 
 *  Value usually defined on the company level.
 */
@property (nonatomic, strong) NSString * _Nullable namespaceID;

/**
 *  Instance ID required for device identification.
 *  Value defined per device.
 */
@property (nonatomic, strong) NSString * _Nullable instanceID;

/**
 *  URL address advertised by the beacon device
 *  packet type is set to ESTBeaconPacketTypeEddystoneURL
 */
@property (nonatomic, strong) NSString * _Nullable url;

/**
 *  Telemetry information delivered in separate packet packet every 10 seconds.
 *  Availability of this information can be delayed.
 */
@property (nonatomic, strong) ESTEddystoneTelemetry * _Nullable telemetry;

- (void)updateWithEddystone:(ESTEddystone *)eddystone;

@end

NS_ASSUME_NONNULL_END
