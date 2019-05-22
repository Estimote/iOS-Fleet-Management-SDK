//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBPowerErrorDomain @"ESTSettingUWBPowerErrorDomain"

/**
 *  Describes UWB Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingUWBPowerError)
{
    /**
     *  Provided value does not belong to the ESTSettingUWBPowerError enum.
     */
    ESTSettingUWBPowerErrorValueNotAllowed = 1
};

@class ESTSettingUWBPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting TxPower operation for UWB packet.
 *
 *  @param powerSetting Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBPowerCompletionBlock)(ESTSettingUWBPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available power levels for UWB packet.
 */
typedef NS_ENUM(int8_t, ESTUWBPower)
{
    ESTUWBPowerLevel1 = -40,
    ESTUWBPowerLevel2 = -20,
    ESTUWBPowerLevel3 = -16,
    ESTUWBPowerLevel4 = -12,
    ESTUWBPowerLevel5 = -8,
    ESTUWBPowerLevel6 = -4,
    ESTUWBPowerLevel7 = 0,
    ESTUWBPowerLevel8 = 4,
    ESTUWBPowerLevel9 = 20
};


/**
 *  ESTSettingUWBPower represents UWB power value.
 */
@interface ESTSettingUWBPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBPower validationErrorForValue:]
 *
 *  @param power UWB power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTUWBPower)power;

/**
 *  Returns current value of UWB power setting.
 *
 *  @return UWB power value.
 */
- (ESTUWBPower)getValue;

/**
 *  Method allows to read value of initialized UWB power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTUWBPower)power completion:(ESTSettingUWBPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTUWBPower)power;

@end

NS_ASSUME_NONNULL_END
