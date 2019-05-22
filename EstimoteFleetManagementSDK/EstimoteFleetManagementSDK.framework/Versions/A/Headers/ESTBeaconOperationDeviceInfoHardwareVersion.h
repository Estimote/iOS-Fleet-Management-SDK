//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoHardwareVersion.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationDeviceInfoHardwareVersion allows to create read operations for Device HardwareVersion setting of a device.
 */
@interface ESTBeaconOperationDeviceInfoHardwareVersion : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Device HardwareVersion setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoHardwareVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
