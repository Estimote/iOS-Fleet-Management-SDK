//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

#define ESTSettingDeviceInfoBootloaderVersionErrorDomain @"ESTSettingDeviceInfoBootloaderVersionErrorDomain"

/**
 *  Describes bootloader version validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingDeviceInfoBootloaderVersionError)
{
    /**
     *  Provided bootloader version value is equal to nil.
     */
    ESTSettingDeviceInfoBootloaderVersionErrorNilValue,
    /**
     *  Provided bootloader version value is empty string.
     */
    ESTSettingDeviceInfoBootloaderVersionErrorEmptyString
};

@class ESTSettingDeviceInfoBootloaderVersion;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting BootloaderVersion operation for Device packet.
 *
 *  @param bootloaderVersionSetting BootloaderVersion setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoBootloaderVersionCompletionBlock)(ESTSettingDeviceInfoBootloaderVersion * _Nullable bootloaderVersionSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoBootloaderVersion represents Device BootloaderVersion value.
 */
@interface ESTSettingDeviceInfoBootloaderVersion : ESTSettingReadOnly <NSCopying>

/**
 *  Returns current value of Device BootloaderVersion setting.
 *
 *  @return Device BootloaderVersion value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Device BootloaderVersion setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoBootloaderVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
