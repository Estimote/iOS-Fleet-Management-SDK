//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryInfoMotion.h"
#import "ESTTelemetryNotificationProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTTelemetryNotificationMotionCompletionBlock)(ESTTelemetryInfoMotion *motion);

/**
 * ESTTelemetryNotificationMotion class is used to
 * initialize block that will be fired everytime
 * new telemetry packet was ranged.
 * As a parameter of ESTTelemetryNotificationMotionCompletionBlock
 * expect ESTTelemetryInfoMotion object that transmits
 * axises X,Y,Z of beacon position and
 * current and previous motion state duration.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryNotificationMotion : NSObject <ESTTelemetryNotificationProtocol>

/**
 * This init takes notificationBlock as a parameter, which will be fired
 * with every telemetry packet discovered.
 *
 * @param block ESTTelemetryNotificationMotionCompletionBlock
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationMotionCompletionBlock)block;

@end

NS_ASSUME_NONNULL_END
