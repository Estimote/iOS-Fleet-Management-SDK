//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshFirmwareSyncEnableErrorDomain @"ESTSettingMeshFirmwareSyncEnableErrorDomain"

@class ESTSettingMeshFirmwareSyncEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting FirmwareSyncEnable operation for Mesh packet.
 *
 *  @param firmwareSyncEnableSetting FirmwareSyncEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshFirmwareSyncEnableCompletionBlock)(ESTSettingMeshFirmwareSyncEnable * _Nullable firmwareSyncEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshFirmwareSyncEnable represents Mesh FirmwareSyncEnable value.
 */
@interface ESTSettingMeshFirmwareSyncEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshFirmwareSyncEnable validationErrorForValue:]
 *
 *  @param firmwareSyncEnable Mesh FirmwareSyncEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)firmwareSyncEnable;

/**
 *  Returns current value of Mesh FirmwareSyncEnable setting.
 *
 *  @return Mesh FirmwareSyncEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Mesh FirmwareSyncEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshFirmwareSyncEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Mesh FirmwareSyncEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param firmwareSyncEnable FirmwareSyncEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)firmwareSyncEnable completion:(ESTSettingMeshFirmwareSyncEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
