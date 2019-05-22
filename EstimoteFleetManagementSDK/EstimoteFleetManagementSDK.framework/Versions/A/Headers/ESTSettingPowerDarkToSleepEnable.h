//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingPowerDarkToSleepEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting DarkToSleepEnable operation for Power packet.
 *
 *  @param enabledSetting DarkToSleepEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerDarkToSleepEnableCompletionBlock)(ESTSettingPowerDarkToSleepEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerDarkToSleepEnable represents Power DarkToSleepEnable value.
 */
@interface ESTSettingPowerDarkToSleepEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingPowerDarkToSleepEnable validationErrorForValue:]
 *
 *  @param enabled Power DarkToSleepEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of Power DarkToSleepEnable setting.
 *
 *  @return Power DarkToSleepEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Power DarkToSleepEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingPowerDarkToSleepEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Power DarkToSleepEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled DarkToSleepEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingPowerDarkToSleepEnableCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param enabled DarkToSleepEnable value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
