//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingDeviceInfoUptime;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting Uptime operation for DeviceInfo packet.
 *
 *  @param uptimeSetting Uptime setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoUptimeCompletionBlock)(ESTSettingDeviceInfoUptime * _Nullable uptimeSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoUptime represents DeviceInfo Uptime value.
 */
@interface ESTSettingDeviceInfoUptime : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param uptime DeviceInfo Uptime value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(int)uptime;

/**
 *  Returns current value of DeviceInfo Uptime setting.
 *
 *  @return DeviceInfo Uptime value.
 */
- (int)getValue;

/**
 *  Method allows to read value of initialized DeviceInfo Uptime setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoUptimeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
