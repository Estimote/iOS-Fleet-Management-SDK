//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBAdvertisingIntervalErrorDomain @"ESTSettingUWBAdvertisingIntervalErrorDomain"

/**
 *  Describes UWB Advertising Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingUWBAdvertisingIntervalError)
{
    /**
     *  Provided value is too small.
     */
    ESTSettingUWBAdvertisingIntervalErrorValueTooSmall = 1,
    
    /**
     *  Provided value is too big.
     */
    ESTSettingUWBAdvertisingIntervalErrorValueTooBig
};


@class ESTSettingUWBAdvertisingInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting AdvertisingInterval operation for UWB packet.
 *
 *  @param AdvertisingIntervalSetting Advertising interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBAdvertisingIntervalCompletionBlock)(ESTSettingUWBAdvertisingInterval * _Nullable AdvertisingIntervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBAdvertisingInterval represents UWB AdvertisingInterval value.
 */
@interface ESTSettingUWBAdvertisingInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBAdvertisingInterval validationErrorForValue:]
 *
 *  @param advertisingInterval UWB AdvertisingInterval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint16_t)advertisingInterval;

/**
 *  Returns current value of UWB AdvertisingInterval setting.
 *
 *  @return UWB AdvertisingInterval value.
 */
- (uint16_t)getValue;

/**
 *  Method allows to read value of initialized UWB AdvertisingInterval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBAdvertisingIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB AdvertisingInterval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param advertisingInterval AdvertisingInterval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint16_t)advertisingInterval completion:(ESTSettingUWBAdvertisingIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param advertisingInterval advertisingInterval value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint16_t)advertisingInterval;

@end

NS_ASSUME_NONNULL_END
