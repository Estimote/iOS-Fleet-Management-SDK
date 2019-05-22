//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingScanNearablesEnableErrorDomain @"ESTSettingScanNearablesEnableErrorDomain"

@class ESTSettingScanNearablesEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of write setting Scan Nearables Enable operation for Mesh packet.
 *
 *  @param assetTrackingEnableSetting Scan Nearables Enable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingScanNearablesEnableCompletionBlock)(ESTSettingScanNearablesEnable * _Nullable assetTrackingEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingScanNearablesEnable represents Scan Nearables Enable value.
 */
@interface ESTSettingScanNearablesEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingScanNearablesEnable validationErrorForValue:]
 *
 *  @param enableAssetTracking  Value of Scan Nearables Enable to be used.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enableAssetTracking;

/**
 *  Returns current value of Scan Nearables Enable setting.
 *
 *  @return Scan Nearables Enable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to create write operation from already initialized Mesh ESTSettingScanNearablesEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enableAssetTracking  ESTSettingScanNearablesEnable value to be written to the device.
 *  @param completion   Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enableAssetTracking completion:(ESTSettingScanNearablesEnableCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param enableAssetTracking Enable Asset Tracking value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)enableAssetTracking;

@end

NS_ASSUME_NONNULL_END

