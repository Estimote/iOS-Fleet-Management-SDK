//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshSettingsVersionErrorDomain @"ESTSettingMeshSettingsVersionErrorDomain"

@class ESTSettingMeshSettingsVersion;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting SettingsVersion operation for Mesh packet.
 *
 *  @param settingsVersionSetting SettingsVersion setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshSettingsVersionCompletionBlock)(ESTSettingMeshSettingsVersion * _Nullable settingsVersionSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshSettingsVersion represents Mesh SettingsVersion value.
 */
@interface ESTSettingMeshSettingsVersion : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshSettingsVersion validationErrorForValue:]
 *
 *  @param settingsVersion Mesh SettingsVersion value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint32_t)settingsVersion;

/**
 *  Returns current value of Mesh SettingsVersion setting.
 *
 *  @return Mesh SettingsVersion value.
 */
- (uint32_t)getValue;

/**
 *  Method allows to read value of initialized Mesh SettingsVersion setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshSettingsVersionCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Mesh SettingsVersion setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param settingsVersion SettingsVersion value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint32_t)settingsVersion completion:(ESTSettingMeshSettingsVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
