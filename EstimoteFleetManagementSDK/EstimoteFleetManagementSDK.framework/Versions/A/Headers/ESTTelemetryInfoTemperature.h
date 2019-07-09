//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTTelemetryInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This class contains data read from telemetry packet from beacon device.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryInfoTemperature : ESTTelemetryInfo

/**
 * Temperature readings from beacon device telemetry packet.
 */
@property (nonatomic, strong, readonly) NSNumber *temperatureInCelsius;

/**
 * Designated initializer of this class.
 *
 * @param temperature Tempereature readings, read from telemetry packet.
 * @param shortIdentifier Short identifier of device that sent telemetry packet.
 *
 * @return Instance of this class.
 */
- (instancetype)initWithTemperature:(NSNumber *)temperature
                    shortIdentifier:(NSString *)shortIdentifier;

@end

NS_ASSUME_NONNULL_END
