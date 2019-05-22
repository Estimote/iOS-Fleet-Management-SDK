//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEstimoteLocationPower.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEstimoteLocationPower allows to create read/write operations for Estimote Location BroadcastingPower setting of a device.
 */
@interface ESTBeaconOperationEstimoteLocationPower : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Estimote Location BroadcastingPower setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEstimoteLocationPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation for Estimote Location BroadcastingPower setting.
 *
 *  @param setting   Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEstimoteLocationPower *)setting completion:(ESTSettingEstimoteLocationPowerCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
