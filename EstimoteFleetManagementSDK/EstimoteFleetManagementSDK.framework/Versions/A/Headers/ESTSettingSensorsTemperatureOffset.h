//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingSensorsTemperatureOffsetErrorDomain @"ESTSettingSensorsTemperatureOffsetErrorDomain"

/**
 *  Describes Sensors TemperatureOffset validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingSensorsTemperatureOffsetError)
{
    /**
     *  Provided data is out of range.
     */
    ESTSettingSensorsTemperatureOffsetErrorOutOfRange = 1
};

@class ESTSettingSensorsTemperatureOffset;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting TemperatureOffset operation for Sensors packet.
 *
 *  @param temperatureOffsetSetting TemperatureOffset setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingSensorsTemperatureOffsetCompletionBlock)(ESTSettingSensorsTemperatureOffset * _Nullable temperatureOffsetSetting, NSError * _Nullable error);


/**
 *  ESTSettingSensorsTemperatureOffset represents Sensors TemperatureOffset value.
 *
 *  You can use this setting to calibrate the beacon's temperature sensor.
 *
 *  For example, if you measure that the sensor in the beacon is off by 1.2 degree C (shows 21.2 instead of 20.0), set the temperature offset to -1.2.
 */
@interface ESTSettingSensorsTemperatureOffset : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingSensorsTemperatureOffset validationErrorForValue:]
 *
 *  @param temperatureOffset Sensors TemperatureOffset value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(float)temperatureOffset;

/**
 *  Returns current value of Sensors TemperatureOffset setting.
 *
 *  @return Sensors TemperatureOffset value.
 */
- (float)getValue;

/**
 *  Method allows to read value of initialized Sensors TemperatureOffset setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingSensorsTemperatureOffsetCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Sensors TemperatureOffset setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param temperatureOffset TemperatureOffset value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(float)temperatureOffset completion:(ESTSettingSensorsTemperatureOffsetCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param temperatureOffset TemperatureOffset value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(float)temperatureOffset;

@end

NS_ASSUME_NONNULL_END
