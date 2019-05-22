//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerBatteryLifetime.h"
#import "ESTCloudOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationPowerBatteryLifetime allows to create read operations for Power BatteryLifetime setting of a device.
 */
@interface ESTCloudOperationPowerBatteryLifetime : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for Power BatteryLifetime setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerBatteryLifetimeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
