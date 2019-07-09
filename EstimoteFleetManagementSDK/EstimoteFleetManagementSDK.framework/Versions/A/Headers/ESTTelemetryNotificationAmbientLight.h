//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryNotificationProtocol.h"
#import "ESTTelemetryInfoAmbientLight.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTTelemetryNotificationAmbientLightNotificationBlock)(ESTTelemetryInfoAmbientLight *ambientLight);

/**
 * ESTTelemetryNotificationAmbientLight class is used to
 * initialize block that will be fired everytime
 * new telemetry packet was ranged.
 * As a parameter of ESTTelemetryNotificationAmbientLightCompletionBlock
 * expect ESTTelemetryInfoAmbientLight object that transmits
 * ambient light value (in lux) read by beacon.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryNotificationAmbientLight : NSObject <ESTTelemetryNotificationProtocol>

/**
 * This init takes notificationBlock as a parameter, which will be fired
 * with every telemetry packet discovered.
 *
 * @param block ESTTelemetryNotificationAmbientLightCompletionBlock
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationAmbientLightNotificationBlock)block;

@end

NS_ASSUME_NONNULL_END
