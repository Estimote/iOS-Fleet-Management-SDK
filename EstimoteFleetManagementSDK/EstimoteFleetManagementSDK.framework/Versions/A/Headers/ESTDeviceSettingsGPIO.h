//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import "ESTBaseVO.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Value object representing GPIO settings.
 */
@interface ESTDeviceSettingsGPIO : ESTBaseVO <NSCopying>

/**
 *  Indicates if GPIO Interrupt feature is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *notificationEnabled;

/**
 *  GPIO Config value for Port 0.
 */
@property (nonatomic, strong, readonly) NSNumber *configPort0;

/**
 *  GPIO Config value for Port 1.
 */
@property (nonatomic, strong, readonly) NSNumber *configPort1;

/**
 *  Current GPIO ports state value. 
 *  Note this is a combined value for config ports 0 and 1 (two least significant bytes represents ports 0 and 1).
 */
@property (nonatomic, strong, readonly) NSNumber *portsData;

/**
 *  Indicates if relfecting GPIO sate 0 on LED is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *gpio0StateReflectingOnLEDEnabled;

/**
 *  Designated initializer.
 *
 *  @param dictionary Dictionary provided by the Estimote cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

/**
 *  Method for returning dictionary represantation of GPIO settings.
 */
- (NSDictionary *)cloudDictionary;

@end

NS_ASSUME_NONNULL_END
