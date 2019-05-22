//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingEddystoneEIDRotationScalerErrorDomain @"ESTSettingEddystoneEIDRotationScalerErrorDomain"

/**
 *  Describes EddystoneEID RotationScaler validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneEIDRotationScalerError)
{
     /**
     *  Provided value is out of range. Should be <0, 15>.
     */
    ESTSettingEddystoneEIDRotationScalerErrorOutOfRange = 1
};

@class ESTSettingEddystoneEIDRotationScaler;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting RotationScaler operation for EddystoneEID packet.
 *  Eddystone EID rotation period is equal to 2^scaler seconds.
 *
 *  @param rotationScalerSetting RotationScaler setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneEIDRotationScalerCompletionBlock)(ESTSettingEddystoneEIDRotationScaler * _Nullable rotationScalerSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneEIDRotationScaler represents EddystoneEID RotationScaler value.
 */
@interface ESTSettingEddystoneEIDRotationScaler : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEddystoneEIDRotationScaler validationErrorForValue:]
 *
 *  @param rotationScaler EddystoneEID RotationScaler value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (_Nullable instancetype)initWithValue:(uint8_t)rotationScaler;

/**
 *  Returns current value of EddystoneEID RotationScaler setting.
 *
 *  @return EddystoneEID RotationScaler value.
 */
- (uint8_t)getValue;

/**
 *  Method allows to read value of initialized EddystoneEID RotationScaler setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneEIDRotationScalerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized EddystoneEID RotationScaler setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param rotationScaler RotationScaler value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint8_t)rotationScaler completion:(ESTSettingEddystoneEIDRotationScalerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param rotationScaler RotationScaler value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint8_t)rotationScaler;

@end

NS_ASSUME_NONNULL_END
