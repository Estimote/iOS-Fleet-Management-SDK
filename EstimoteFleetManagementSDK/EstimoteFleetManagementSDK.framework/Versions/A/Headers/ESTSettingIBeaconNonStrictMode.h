//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingIBeaconNonStrictMode;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting NonStrictMode operation for iBeacon packet.
 *
 *  @param nonStrictModeSetting NonStrictMode setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconNonStrictModeCompletionBlock)(ESTSettingIBeaconNonStrictMode * _Nullable nonStrictModeSetting, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconNonStrictMode represents iBeacon NonStrictMode value.
 */
@interface ESTSettingIBeaconNonStrictMode : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingIBeaconNonStrictMode validationErrorForValue:]
 *
 *  @param nonStrictMode iBeacon NonStrictMode value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)nonStrictMode;

/**
 *  Returns current value of iBeacon NonStrictMode setting.
 *
 *  @return iBeacon NonStrictMode value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized iBeacon NonStrictMode setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconNonStrictModeCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon NonStrictMode setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param nonStrictMode NonStrictMode value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)nonStrictMode completion:(ESTSettingIBeaconNonStrictModeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
