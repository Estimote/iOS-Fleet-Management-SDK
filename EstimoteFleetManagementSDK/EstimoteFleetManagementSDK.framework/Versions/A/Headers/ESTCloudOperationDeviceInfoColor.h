//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoColor.h"
#import "ESTCloudOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationDeviceInfoColor allows to create read/write operations for DeviceInfo color setting of a device.
 */
@interface ESTCloudOperationDeviceInfoColor : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo color setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoColorCompletionBlock)completion;

/**
 *  Method allows to create write operation for DeviceInfo color setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingDeviceInfoColor *)setting completion:(ESTSettingDeviceInfoColorCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
