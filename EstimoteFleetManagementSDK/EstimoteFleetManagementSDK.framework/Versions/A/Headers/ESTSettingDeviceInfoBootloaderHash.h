//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingDeviceInfoBootloaderHash;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting BootloaderHash operation for Device Info packet.
 *
 *  @param bootloaderHashSetting BootloaderHash setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoBootloaderHashCompletionBlock)(ESTSettingDeviceInfoBootloaderHash * _Nullable bootloaderHashSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoBootloaderHash represents Device Info BootloaderHash value.
 */
@interface ESTSettingDeviceInfoBootloaderHash : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param bootloaderHash Device Info BootloaderHash value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)bootloaderHash;

/**
 *  Returns current value of Device Info BootloaderHash setting.
 *
 *  @return Device Info BootloaderHash value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Device Info BootloaderHash setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoBootloaderHashCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
