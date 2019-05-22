//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshPowerErrorDomain @"ESTSettingMeshPowerErrorDomain"

/**
 *  Describes Mesh Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMeshPowerError)
{
    /**
     *  Provided value does not belong to the ESTSettingMeshPower enum.
     */
    ESTSettingMeshPowerErrorValueNotAllowed = 1
};

@class ESTSettingMeshPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Mesh packet.
 *
 *  @param powerSetting Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshPowerCompletionBlock)(ESTSettingMeshPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available Tx Power levels for Mesh packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTMeshPower)
{
    ESTMeshPowerLevel1  = -30,
    ESTMeshPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTMeshPowerLevel2  = -20,
    ESTMeshPowerLevel3  = -16,
    ESTMeshPowerLevel4  = -12,
    ESTMeshPowerLevel5  =  -8,
    ESTMeshPowerLevel6  =  -4,
    ESTMeshPowerLevel7  =   0,
    ESTMeshPowerLevel8  =   4,
    ESTMeshPowerLevel9  =  10, // for Location Beacons with long-range support (e.g., F3.3 and later)
    ESTMeshPowerLevel9A =  20  // +20 replaced +10 in Location Beacons I1.2 (i.e., with UWB)
};


/**
 *  ESTSettingMeshPower represents Mesh Power value.
 */
@interface ESTSettingMeshPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshPower validationErrorForValue:]
 *
 *  @param power Mesh Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(ESTMeshPower)power;

/**
 *  Returns current value of Mesh Power setting.
 *
 *  @return Mesh Power value.
 */
- (ESTMeshPower)getValue;

/**
 *  Method allows to read value of initialized Mesh Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Mesh Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTMeshPower)power completion:(ESTSettingMeshPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTMeshPower)power;

@end

NS_ASSUME_NONNULL_END
