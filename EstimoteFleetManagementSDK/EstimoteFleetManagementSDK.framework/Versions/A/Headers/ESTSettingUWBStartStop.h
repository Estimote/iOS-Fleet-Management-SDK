//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBStartStopErrorDomain @"ESTSettingUWBStartStopErrorDomain"


@class ESTSettingUWBStartStop;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of write only setting StartStop operation for UWB packet.
 *
 *  @param startStopSetting Start stop setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBStartStopCompletionBlock)(ESTSettingUWBStartStop * _Nullable startStopSetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBStartStop represents UWB StartStop value.
 */
@interface ESTSettingUWBStartStop : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBStartStop validationErrorForValue:]
 *
 *  @param startStop UWB StartStop value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)startStop;

/**
 *  Returns current value of UWB StartStop setting.
 *
 *  @return UWB StartStop value.
 */
- (BOOL)getValue;

/**
 *  Returns date when settings was applied.
 *
 *  @return UWB StartStop applied date.
 */
- (uint32_t)getApplyTimestamp;

/**
 *  Method allows to create write only operation from already initialized UWB StartStop setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param startStop StartStop value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)startStop completion:(ESTSettingUWBStartStopCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param startStop StartStop value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)startStop;

@end

NS_ASSUME_NONNULL_END
