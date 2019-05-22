//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoApplicationVersion.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationDeviceInfoApplicationVersion allows to create read operations for Device Info ApplicationVersion setting of a device.
 */
@interface ESTBeaconOperationDeviceInfoApplicationVersion : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Device Info ApplicationVersion setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoApplicationVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
