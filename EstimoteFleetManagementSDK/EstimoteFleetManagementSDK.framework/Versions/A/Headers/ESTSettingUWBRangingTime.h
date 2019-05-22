//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBRangingTimeErrorDomain @"ESTSettingUWBRangingTimeErrorDomain"


@class ESTSettingUWBRangingTime;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting RangingTime operation for UWB packet.
 *
 *  @param rangingTimeSetting Ranging time setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBRangingTimeCompletionBlock)(ESTSettingUWBRangingTime * _Nullable rangingTimeSetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBRangingTime represents UWB RangingTime value (in seconds).
 *  It specifies how long UWB devices will be ranging (measuring distance between each other).
 */
@interface ESTSettingUWBRangingTime : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBRangingTime validationErrorForValue:]
 *
 *  @param rangingTime UWB RangingTime value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint16_t)rangingTime;

/**
 *  Returns current value of UWB RangingTime setting.
 *
 *  @return UWB RangingTime value.
 */
- (uint16_t)getValue;

/**
 *  Method allows to read value of initialized UWB RangingTime setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBRangingTimeCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB RangingTime setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param rangingTime RangingTime value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint16_t)rangingTime completion:(ESTSettingUWBRangingTimeCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param rangingTime RangingTime value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint16_t)rangingTime;

@end

NS_ASSUME_NONNULL_END
