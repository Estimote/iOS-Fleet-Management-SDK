//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerBatteryVoltage.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerBatteryVoltage allows to create read operations for DeviceInfo BatteryVoltage setting of a device.
 */
@interface ESTBeaconOperationPowerBatteryVoltage : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo BatteryVoltage setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerBatteryVoltageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
