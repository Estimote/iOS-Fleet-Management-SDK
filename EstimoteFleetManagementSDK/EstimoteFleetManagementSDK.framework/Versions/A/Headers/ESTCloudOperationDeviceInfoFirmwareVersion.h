//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTCloudOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoFirmwareVersion.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationFirmwareVersion allows to create read operations for DeviceInfo FirmwareVersion setting of a device.
 */
@interface ESTCloudOperationDeviceInfoFirmwareVersion : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo FirmwareVersion setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoFirmwareVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
