//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryNotificationProtocol.h"
#import "ESTTelemetryInfoSystemStatus.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTTelemetryNotificationSystemStatusNotificationBlock)(ESTTelemetryInfoSystemStatus *systemStatus);

/**
 * ESTTelemetryNotificationSystemStatus class is used to
 * initialize block that will be fired everytime
 * new telemetry packet was ranged.
 * As a parameter of ESTTelemetryNotificationSystemStatusNotificationBlock
 * expect ESTTelemetryInfoSystemStatus object that transmits
 * system status information (battery voltage and OS uptime)
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryNotificationSystemStatus : NSObject <ESTTelemetryNotificationProtocol>

/**
 * This init takes notificationBlock as a parameter, which will be fired
 * with every telemetry packet discovered.
 *
 * @param block ESTTelemetryNotificationSystemStatusNotificationBlock
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationSystemStatusNotificationBlock)block;

@end

NS_ASSUME_NONNULL_END
