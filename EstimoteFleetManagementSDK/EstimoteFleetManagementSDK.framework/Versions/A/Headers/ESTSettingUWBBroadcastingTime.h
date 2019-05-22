//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBBroadcastingTimeErrorDomain @"ESTSettingUWBBroadcastingTimeErrorDomain"


@class ESTSettingUWBBroadcastingTime;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting BroadcastingTime operation for UWB packet.
 *
 *  @param broadcastingTimeSetting Broadcasting time setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBBroadcastingTimeCompletionBlock)(ESTSettingUWBBroadcastingTime * _Nullable broadcastingTimeSetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBBroadcastingTime represents UWB BroadcastingTime value (in seconds).
 *  It specifies time during which devices will broadcast the distance between devices.
 */
@interface ESTSettingUWBBroadcastingTime : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBBroadcastingTime validationErrorForValue:]
 *
 *  @param broadcastingTime UWB BroadcastingTime value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint16_t)broadcastingTime;

/**
 *  Returns current value of UWB BroadcastingTime setting.
 *
 *  @return UWB BroadcastingTime value.
 */
- (uint16_t)getValue;

/**
 *  Method allows to read value of initialized UWB BroadcastingTime setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBBroadcastingTimeCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB BroadcastingTime setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param broadcastingTime BroadcastingTime value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint16_t)broadcastingTime completion:(ESTSettingUWBBroadcastingTimeCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param broadcastingTime BroadcastingTime value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint16_t)broadcastingTime;

@end

NS_ASSUME_NONNULL_END
