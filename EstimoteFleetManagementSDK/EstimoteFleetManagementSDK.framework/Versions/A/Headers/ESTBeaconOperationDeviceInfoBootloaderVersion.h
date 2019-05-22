//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoBootloaderVersion.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationDeviceInfoBootloaderVersion allows to create read operations for Device BootloaderVersion setting of a device.
 */
@interface ESTBeaconOperationDeviceInfoBootloaderVersion : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Device BootloaderVersion setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoBootloaderVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
