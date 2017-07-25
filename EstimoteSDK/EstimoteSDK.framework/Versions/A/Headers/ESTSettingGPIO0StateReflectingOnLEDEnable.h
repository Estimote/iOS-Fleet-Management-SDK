//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingGPIO0StateReflectingOnLEDErrorDomain @"ESTSettingGPIO0StateReflectingOnLEDErrorDomain"

@class ESTSettingGPIO0StateReflectingOnLEDEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting  operation for GPIO packet.
 *
 *  @param gpio0StateReflectingOnLEDEnableSetting GPIO Config 0 state reflecting on LED setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingGPIO0StateReflectingOnLEDCompletionBlock)(ESTSettingGPIO0StateReflectingOnLEDEnable * _Nullable gpio0StateReflectingOnLEDEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingGPIO0StateReflectingOnLED represents GPIO0StateReflectingOnLEDEnable value.
 */
@interface ESTSettingGPIO0StateReflectingOnLEDEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGPIO0StateReflectingOnLED validationErrorForValue:]
 *
 *  @param gpio0StateReflectingOnLEDEnable GPIO0StateReflectingOnLEDEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)gpio0StateReflectingOnLEDEnable;

/**
 *  Returns current value of GPIO0StateReflectingOnLEDEnable setting.
 *
 *  @return GPIO0StateReflectingOnLEDEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized GPIO0StateReflectingOnLEDEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingGPIO0StateReflectingOnLEDCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GPIO0StateReflectingOnLEDEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param gpio0StateReflectingOnLEDEnable GPIO Config 0 state reflecting on LED value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)gpio0StateReflectingOnLEDEnable completion:(ESTSettingGPIO0StateReflectingOnLEDCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param gpio0StateReflectingOnLEDEnable GPIO Config 0 StateReflectingOnLEDEnable value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)gpio0StateReflectingOnLEDEnable;

@end

NS_ASSUME_NONNULL_END
