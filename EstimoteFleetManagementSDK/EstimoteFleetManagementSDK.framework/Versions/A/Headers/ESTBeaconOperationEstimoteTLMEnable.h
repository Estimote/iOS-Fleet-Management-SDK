//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEstimoteTLMEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEstimoteTLMEnable allows to create read/write operations for Estimote Telemetry Enable setting of a device.
 */
@interface ESTBeaconOperationEstimoteTLMEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Estimote Telemetry Enable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEstimoteTLMEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for Estimote Telemetry Enable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEstimoteTLMEnable *)setting completion:(ESTSettingEstimoteTLMEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
