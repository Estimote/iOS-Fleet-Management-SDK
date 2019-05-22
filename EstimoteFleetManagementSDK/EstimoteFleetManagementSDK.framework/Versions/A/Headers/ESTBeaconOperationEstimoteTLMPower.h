//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEstimoteTLMPower.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEstimoteTLMPower allows to create read/write operations for Estimote Telemetry Power setting of a device.
 */
@interface ESTBeaconOperationEstimoteTLMPower : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Estimote Telemetry Power setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEstimoteTLMPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation for Estimote Telemetry Power setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEstimoteTLMPower *)setting completion:(ESTSettingEstimoteTLMPowerCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
