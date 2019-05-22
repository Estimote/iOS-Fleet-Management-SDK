//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerMotionOnlyBroadcastingEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerMotionOnlyBroadcastingEnable allows to create read/write operations for DeviceInfo MotionOnlyBroadcastingEnable setting of a device.
 */
@interface ESTBeaconOperationPowerMotionOnlyBroadcastingEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo MotionOnlyBroadcastingEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerMotionOnlyBroadcastingEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for DeviceInfo MotionOnlyBroadcastingEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingPowerMotionOnlyBroadcastingEnable *)setting completion:(ESTSettingPowerMotionOnlyBroadcastingEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
