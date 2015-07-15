//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.3.1
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

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
 * Battery Level in Milivolts [mV]
 */
@property (nonatomic, strong) NSNumber *battery;

/**
 * Sensor ambient temperature (Provided in Celsius)
 */
@property (nonatomic, strong) NSNumber *temperature;

/**
 * Count of packet sent by the device since last power up.
 */
@property (nonatomic, strong) NSNumber *pocketCount;

/**
 * Time the device is running since last power up.
 */
@property (nonatomic, strong) NSNumber *awakeTime;

@end
