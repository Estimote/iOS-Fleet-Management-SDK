//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingPowerDarkToSleepThreshold;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting DarkToSleepThreshold operation for Power packet.
 *
 *  @param thresholdSetting DarkToSleepThreshold setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerDarkToSleepThresholdCompletionBlock)(ESTSettingPowerDarkToSleepThreshold * _Nullable thresholdSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerDarkToSleepThreshold represents Power DarkToSleepThreshold value.
 */
@interface ESTSettingPowerDarkToSleepThreshold : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingPowerDarkToSleepThreshold validationErrorForValue:]
 *
 *  @param threshold Power DarkToSleepThreshold value in lx.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSUInteger)threshold;

/**
 *  Returns current value of Power DarkToSleepThreshold setting.
 *
 *  @return DarkToSleepThreshold value in lx.
 */
- (NSUInteger)getValue;

/**
 *  Method allows to read value of initialized Power DarkToSleepThreshold setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingPowerDarkToSleepThresholdCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Power DarkToSleepThreshold setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param threshold DarkToSleepThreshold value in lx to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSUInteger)threshold completion:(ESTSettingPowerDarkToSleepThresholdCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param threshold DarkToSleepThreshold value in lx.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSUInteger)threshold;

@end

NS_ASSUME_NONNULL_END
