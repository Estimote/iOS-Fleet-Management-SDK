//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryNotificationProtocol.h"
#import "ESTTelemetryInfoPressure.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTTelemetryNotificationPressureNotificationBlock)(ESTTelemetryInfoPressure *pressure);

/**
 * ESTTelemetryNotificationPressure class is used to
 * initialize block that will be fired everytime
 * new telemetry packet was ranged.
 * As a parameter of ESTTelemetryNotificationPressureCompletionBlock
 * expect ESTTelemetryInfoPressure object that transmits
 * atmospheric pressure value (in pascals) read by beacon.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryNotificationPressure : NSObject <ESTTelemetryNotificationProtocol>

/**
 * This init takes notificationBlock as a parameter, which will be fired
 * with every telemetry packet discovered.
 *
 * @param block ESTTelemetryNotificationPressureCompletionBlock
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationPressureNotificationBlock)block;

@end

NS_ASSUME_NONNULL_END
