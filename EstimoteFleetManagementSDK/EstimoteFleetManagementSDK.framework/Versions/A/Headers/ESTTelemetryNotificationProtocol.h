//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This protocol is used to determine methods
 * for implementation by classes that
 * want to read telemetry settings from device.
 */
@protocol ESTTelemetryNotificationProtocol <NSObject>

@required

/**
 *  Method invoked after every scanned and parsed telemetry packet.
 *
 *  @param info info object with data about specific telemetry packet.
 */
- (void)fireNotificationBlockWithTelemetryInfo:(ESTTelemetryInfo *)info;

/**
 * Returns Class type of object returned in fireSuccessBlockWithTelemetryInfo.
 *
 * @return Class type of object returned in fireSuccessBlockWithTelemetryInfo.
 */
- (Class)getInfoClass;

@end

NS_ASSUME_NONNULL_END
