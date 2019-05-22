//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBStartDelayErrorDomain @"ESTSettingUWBStartDelayErrorDomain"

@class ESTSettingUWBStartDelay;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting StartDelay operation for UWB packet.
 *
 *  @param startDelaySetting Start delay setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBStartDelayCompletionBlock)(ESTSettingUWBStartDelay * _Nullable startDelaySetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBStartDelay represents UWB StartDelay value (in seconds).
 *  After this time since getting activation signal the device will start ranging.
 */
@interface ESTSettingUWBStartDelay : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBStartDelay validationErrorForValue:]
 *
 *  @param startDelay UWB StartDelay value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint16_t)startDelay;

/**
 *  Returns current value of UWB StartDelay setting.
 *
 *  @return UWB StartDelay value.
 */
- (uint16_t)getValue;

/**
 *  Method allows to read value of initialized UWB StartDelay setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBStartDelayCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB StartDelay setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param startDelay StartDelay value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint16_t)startDelay completion:(ESTSettingUWBStartDelayCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param startDelay StartDelay value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint16_t)startDelay;

@end

NS_ASSUME_NONNULL_END
