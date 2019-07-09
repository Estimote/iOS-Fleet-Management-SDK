//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTTelemetryInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This class contains data read from telemetry packet from beacon device.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryInfoSystemStatus : ESTTelemetryInfo

/**
 * Battery voltage in millivolts.
 */
@property (nonatomic, strong, readonly) NSNumber *batteryVoltageInMillivolts;

/**
 * Uptime since last reboot in seconds.
 */
@property (nonatomic, strong, readonly) NSNumber *uptimeInSeconds;

/**
 * Designated initializer of this class.
 *
 * @param batteryVoltageInMillivolts Battery voltage, read from telemetry packet.
 * @param uptimeInSeconds Beacon OS uptime, read from telemetry packet.
 * @param shortIdentifier Short identifier of device that sent telemetry packet.
 *
 * @return Instance of this class.
 */
- (instancetype)initWithBatteryVoltageInMillivolts:(NSNumber *)batteryVoltageInMillivolts
                                   uptimeInSeconds:(NSNumber *)uptimeInSeconds
                                   shortIdentifier:(NSString *)shortIdentifier;

@end

NS_ASSUME_NONNULL_END
