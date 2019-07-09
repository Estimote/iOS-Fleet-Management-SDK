//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryInfoMagnetometer.h"
#import "ESTTelemetryNotificationProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTTelemetryNotificationMagnetometerNotificationBlock)(ESTTelemetryInfoMagnetometer *magnetometer);

/**
 * ESTTelemetryNotificationMagnetometer class is used to
 * initialize block that will be fired everytime
 * new telemetry packet was ranged.
 * As a parameter of ESTTelemetryNotificationMagnetometerNotificationBlock
 * expect ESTTelemetryInfoMagnetometer object that transmits
 * magnetometer values in X, Y, Z axises, read by beacon device.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryNotificationMagnetometer : NSObject <ESTTelemetryNotificationProtocol>

/**
 * This init takes notificationBlock as a parameter, which will be fired
 * with every telemetry packet discovered.
 *
 * @param block ESTTelemetryNotificationMagnetometerNotificationBlock
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationMagnetometerNotificationBlock)block;

@end

NS_ASSUME_NONNULL_END
