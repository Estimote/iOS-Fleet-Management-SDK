//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTEddystone.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTEddystoneTLM represents Eddystone Telemetry packet coming from `ESTEddystoneManager` class.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTEddystoneTLM : ESTEddystone

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
 *  Designated initializer.
 *
 *  @param batteryVoltage Voltage of device battery
 *  @param temperature    Ambient temperature of device
 *  @param packetCont     Count of packets sent from device
 *  @param uptimeMillis Uptime of the device
 *
 *  @return Initialized object.
 */
- (instancetype)initWithBatteryVoltage:(NSNumber *)batteryVoltage
                           temperature:(NSNumber *)temperature
                           packetCount:(NSNumber *)packetCont
                          uptimeMillis:(NSNumber *)uptimeMillis;

@end

NS_ASSUME_NONNULL_END
