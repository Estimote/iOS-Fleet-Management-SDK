//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTCloudOperationProtocol.h"
#import "ESTSettingDeviceInfoDevelopmentMode.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationDeviceInfoDevelopmentMode allows to create read/write operations for DeviceInfo DevelopmentMode setting of a device.
 */
@interface ESTCloudOperationDeviceInfoDevelopmentMode : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo DevelopmentMode setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoDevelopmentModeCompletionBlock)completion;

/**
 *  Method allows to create write operation for DeviceInfo DevelopmentMode setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingDeviceInfoDevelopmentMode *)setting completion:(ESTSettingDeviceInfoDevelopmentModeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
