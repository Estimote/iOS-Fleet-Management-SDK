//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBMedianWidthErrorDomain @"ESTSettingUWBMedianWidthErrorDomain"

/**
 *  Describes UWB median width validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingUWBMedianWidthError)
{
    /**
     *  Provided value is too small.
     */
    ESTSettingUWBMedianWidthErrorValueTooSmall = 1,
    
    /**
     *  Provded value is too big.
     */
    ESTSettingUWBMedianWidthErrorValueTooBig
};


@class ESTSettingUWBMedianWidth;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting MedianWidth operation for UWB packet.
 *
 *  @param medianWidthSetting Median width setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBMedianWidthCompletionBlock)(ESTSettingUWBMedianWidth * _Nullable medianWidthSetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBMedianWidth represents UWB MedianWidth value.
 *  It is number of measurements which will be taken in order to calculate distance between two  devices
 */
@interface ESTSettingUWBMedianWidth : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBMedianWidth validationErrorForValue:]
 *
 *  @param medianWidth UWB MedianWidth value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint8_t)medianWidth;

/**
 *  Returns current value of UWB MedianWidth setting.
 *
 *  @return UWB MedianWidth value.
 */
- (uint8_t)getValue;

/**
 *  Method allows to read value of initialized UWB MedianWidth setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBMedianWidthCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB MedianWidth setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param medianWidth MedianWidth value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint8_t)medianWidth completion:(ESTSettingUWBMedianWidthCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param medianWidth MedianWidth value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint8_t)medianWidth;

@end

NS_ASSUME_NONNULL_END
