//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMagnetometerCalibrationDataErrorDomain @"ESTSettingMagnetometerCalibrationDataErrorDomain"

/**
 *  Describes Sensors CalibrationData validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMagnetometerCalibrationDataError)
{
    /**
     *  Provided data is too short.
     */
    ESTSettingMagnetometerCalibrationDataErrorTooShort = 1,
    
    /**
     *  Provided value is too long.
     */
    ESTSettingMagnetometerCalibrationDataErrorTooLong
};

@class ESTSettingMagnetometerCalibrationData;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting CalibrationData operation for Sensors packet.
 *
 *  @param calibrationDataSetting CalibrationData setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMagnetometerCalibrationDataCompletionBlock)(ESTSettingMagnetometerCalibrationData * _Nullable calibrationDataSetting, NSError * _Nullable error);


/**
 *  ESTSettingMagnetometerCalibrationData represents Sensors CalibrationData value.
 */
@interface ESTSettingMagnetometerCalibrationData : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMagnetometerCalibrationData validationErrorForValue:]
 *
 *  @param calibrationData Sensors CalibrationData value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSArray <NSNumber *> *)calibrationData;

/**
 *  Returns current value of Sensors CalibrationData setting.
 *
 *  @return Sensors CalibrationData value.
 */
- (NSArray <NSNumber *> *)getValue;

/**
 *  Method allows to read value of initialized Sensors CalibrationData setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMagnetometerCalibrationDataCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Sensors CalibrationData setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param calibrationData CalibrationData value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSArray <NSNumber *> *)calibrationData completion:(ESTSettingMagnetometerCalibrationDataCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param calibrationData CalibrationData value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSArray <NSNumber *> *)calibrationData;

@end

NS_ASSUME_NONNULL_END
