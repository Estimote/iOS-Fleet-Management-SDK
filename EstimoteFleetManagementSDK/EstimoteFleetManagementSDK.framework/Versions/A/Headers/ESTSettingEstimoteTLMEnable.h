//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingEstimoteTLMEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Enable operation for Estimote Telemetry packet.
 *
 *  @param enabledSetting Enable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEstimoteTLMEnableCompletionBlock)(ESTSettingEstimoteTLMEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingEstimoteTLMEnable represents Estimote Telemetry Enable value.
 */
@interface ESTSettingEstimoteTLMEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param enabled Estimote Telemetry Enable value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of Estimote Telemetry Enable setting.
 *
 *  @return Estimote Telemetry Enable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Estimote Telemetry Enable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEstimoteTLMEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Estimote Telemetry Enable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled Enable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingEstimoteTLMEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
