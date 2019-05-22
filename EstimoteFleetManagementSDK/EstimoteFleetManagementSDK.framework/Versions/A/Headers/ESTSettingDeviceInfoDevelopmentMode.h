//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingDeviceInfoDevelopmentModeErrorDomain @"ESTSettingDeviceInfoDevelopmentModeErrorDomain"

@class ESTSettingDeviceInfoDevelopmentMode;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting DevelopmentMode operation for Device packet.
 *
 *  @param developmentModeSetting developmentMode setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoDevelopmentModeCompletionBlock)(ESTSettingDeviceInfoDevelopmentMode * _Nullable developmentModeSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoDevelopmentMode represents Device DevelopmentMode value.
 */
@interface ESTSettingDeviceInfoDevelopmentMode : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingDeviceInfoDevelopmentMode validationErrorForValue:]
 *
 *  @param developmentMode Device DevelopmentMode value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)developmentMode;

/**
 *  Returns current value of Device DevelopmentMode setting.
 *
 *  @return Device DevelopmentMode value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Device DevelopmentMode setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoDevelopmentModeCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Device DevelopmentMode setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param developmentMode DevelopmentMode value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)developmentMode completion:(ESTSettingDeviceInfoDevelopmentModeCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param developmentMode DevelopmentMode value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)developmentMode;

@end

NS_ASSUME_NONNULL_END
