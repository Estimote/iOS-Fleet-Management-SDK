//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshSettingsSyncEnableErrorDomain @"ESTSettingMeshSettingsSyncEnableErrorDomain"

@class ESTSettingMeshSettingsSyncEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Enable operation for Mesh packet.
 *
 *  @param enableSetting Enable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshSettingsSyncEnableCompletionBlock)(ESTSettingMeshSettingsSyncEnable * _Nullable enableSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshSettingsSyncEnable represents Mesh Enable value.
 */
@interface ESTSettingMeshSettingsSyncEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshSettingsSyncEnable validationErrorForValue:]
 *
 *  @param enable Mesh Enable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enable;

/**
 *  Returns current value of Mesh Enable setting.
 *
 *  @return Mesh Enable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Mesh Enable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshSettingsSyncEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Mesh Enable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enable Enable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enable completion:(ESTSettingMeshSettingsSyncEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
