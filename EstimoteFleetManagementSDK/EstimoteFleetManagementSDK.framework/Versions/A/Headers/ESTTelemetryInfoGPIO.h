//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTelemetryInfo.h"
#import "ESTGPIOPortsData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ESTTelemetryInfoGPIO contains information about GPIO ports value
 *  delivered from telemetry packet.

 *  Instance of this class is created automatically by `ESTUtilityManager`
 *  when new telemetry packet containing GPIO information is ranged. Object
 *  is delivered in `ESTTelemetryNotificationGPIONotificationBlock`
 *  provided using `ESTTelemetryNotificationGPIO` class.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTelemetryInfoGPIO : ESTTelemetryInfo

/**
 *  Object containing values for all available GPIO ports.
 */
@property (nonatomic, strong, readonly) ESTGPIOPortsData *portsData;

/**
 *  Method allows to initialize object with GPIO ports data.
 *
 *  @param portsData GPIO ports data taken from telemetry packet.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithGPIOPortsData:(ESTGPIOPortsData *)portsData
                      shortIdentifier:(NSString *)shortIdentifier;

@end

NS_ASSUME_NONNULL_END
