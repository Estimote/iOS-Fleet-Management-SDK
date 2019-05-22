//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerMotionOnlyBroadcastingDelay.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerMotionOnlyBroadcastingDelay allows to create read/write operations for Power MotionOnlyBroadcastingDelay setting of a device.
 */
@interface ESTBeaconOperationPowerMotionOnlyBroadcastingDelay : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Power MotionOnlyBroadcastingDelay setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerMotionOnlyBroadcastingDelayCompletionBlock)completion;

/**
 *  Method allows to create write operation for Power MotionOnlyBroadcastingDelay setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingPowerMotionOnlyBroadcastingDelay *)setting completion:(ESTSettingPowerMotionOnlyBroadcastingDelayCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
