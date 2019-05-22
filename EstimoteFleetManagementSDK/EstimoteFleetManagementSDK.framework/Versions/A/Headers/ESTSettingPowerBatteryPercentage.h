//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingPowerBatteryPercentage;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting BatteryPercentage operation for Power packet.
 *
 *  @param batteryPercentageSetting BatteryPercentage setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerBatteryPercentageCompletionBlock)(ESTSettingPowerBatteryPercentage * _Nullable batteryPercentageSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerBatteryPercentage represents Power BatteryPercentage value.
 */
@interface ESTSettingPowerBatteryPercentage : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param batteryPercentage Power BatteryPercentage value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(uint8_t)batteryPercentage;

/**
 *  Returns current value of Power BatteryPercentage setting.
 *
 *  @return Power BatteryPercentage value.
 */
- (uint8_t)getValue;

/**
 *  Method allows to read value of initialized Power BatteryPercentage setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingPowerBatteryPercentageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
