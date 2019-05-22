//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTCloudOperationProtocol.h"
#import "ESTSettingDeviceInfoIndoorLocationIdentifier.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationDeviceInfoIndoorLocationIdentifier allows to create read operations for DeviceInfo IndoorLocationIdentifier setting of a device.
 */
@interface ESTCloudOperationDeviceInfoIndoorLocationIdentifier : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo IndoorLocationIdentifier setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoIndoorLocationIdentifierCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
