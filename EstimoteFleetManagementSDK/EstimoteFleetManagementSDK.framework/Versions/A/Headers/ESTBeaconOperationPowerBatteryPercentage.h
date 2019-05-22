//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerBatteryPercentage.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerBatteryPercentage allows to create read operations for Power BatteryPercentage setting of a device.
 */
@interface ESTBeaconOperationPowerBatteryPercentage : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Power BatteryPercentage setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerBatteryPercentageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
