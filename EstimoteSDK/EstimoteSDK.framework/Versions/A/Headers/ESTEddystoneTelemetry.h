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

NS_ASSUME_NONNULL_BEGIN

/**
 * Telemetry is a set of utility information showing state
 * of broadcasting device. According to Google documentation
 * it provides following information:
 *
 * - battery level
 * - sensor ambient temperature
 * - number of packet sent during up-time
 * - time device was awake since last power on
 *
 * Telemetry is included in separate BLE packet so it can be
 * accessible with small time delay.
 *
 */

@interface ESTEddystoneTelemetry : NSObject <NSCopying>

/**
 * Battery Level in millivolts [mV]
 */
@property (nonatomic, strong) NSNumber * battery __attribute ((deprecated(("Starting from SDK 3.2.2 use batteryVoltage instead."))));

/**
 * Battery Level in millivolts [mV]
 */
@property (nonatomic, strong) NSNumber *batteryVoltage;

/**
 * Sensor ambient temperature provided in Celsius degrees.
 */
@property (nonatomic, strong) NSNumber *temperature;

/**
 * Count of packet sent by the device since last power-up.
 */
@property (nonatomic, strong) NSNumber *packetCount;

/**
 * Uptime of the device since last power-up provided in milliseconds.
 */
@property (nonatomic, strong) NSNumber *uptimeMillis;

/**
 * Uptime of the device since last power-up provided in seconds.
 */
@property (nonatomic, strong) NSNumber * awakeTime __attribute ((deprecated(("Starting from SDK 3.2.2 use uptimeMillis instead."))));

@end

NS_ASSUME_NONNULL_END
