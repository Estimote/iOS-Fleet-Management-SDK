//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryInfoTemperature.h"
#import "ESTTelemetryNotificationProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTTelemetryNotificationTemperatureNotificationBlock)(ESTTelemetryInfoTemperature *temperature);

/**
 * ESTTelemetryNotificationTemperature class is used to
 * initialize block that will be fired everytime
 * new telemetry packet was ranged.
 * As a parameter of ESTTelemetryNotificationTemperatureCompletionBlock
 * expect ESTTelemetryInfoTemperature object that transmits
 * current temperature readings from beacon.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryNotificationTemperature : NSObject <ESTTelemetryNotificationProtocol>

/**
 * This init takes notificationBlock as a parameter, which will be fired
 * with every telemetry packet discovered.
 *
 * @param block ESTTelemetryNotificationTemperatureCompletionBlock
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationTemperatureNotificationBlock)block;

@end

NS_ASSUME_NONNULL_END
