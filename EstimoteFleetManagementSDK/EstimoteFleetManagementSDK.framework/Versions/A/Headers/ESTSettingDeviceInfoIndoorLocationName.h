//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingDeviceInfoIndoorLocationName;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting IndoorLocationName operation for DeviceInfo packet.
 *
 *  @param nameSetting IndoorLocationName setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoIndoorLocationNameCompletionBlock)(ESTSettingDeviceInfoIndoorLocationName * _Nullable nameSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoIndoorLocationName represents DeviceInfo IndoorLocationName value.
 */
@interface ESTSettingDeviceInfoIndoorLocationName : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param name DeviceInfo IndoorLocationName value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)name;

/**
 *  Returns current value of DeviceInfo IndoorLocationName setting.
 *
 *  @return DeviceInfo IndoorLocationName value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized DeviceInfo IndoorLocationName setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoIndoorLocationNameCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
