//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTTelemetryInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This class contains data read from telemetry packet from beacon device.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryInfoPressure : ESTTelemetryInfo

/**
 *  Atmospheric pressure in pascals.
 */
@property (nonatomic, strong, readonly) NSNumber *pressureInPascals;

/**
 * Designated initializer of this class.
 *
 * @param pressureInPascals Atmospheric pressure, read from telemetry packet.
 * @param shortIdentifier Short identifier of device that sent telemetry packet.
 *
 * @return Instance of this class.
 */
- (instancetype)initWithPressureInPascals:(NSNumber *)pressureInPascals
                          shortIdentifier:(NSString *)shortIdentifier;

@end

NS_ASSUME_NONNULL_END
