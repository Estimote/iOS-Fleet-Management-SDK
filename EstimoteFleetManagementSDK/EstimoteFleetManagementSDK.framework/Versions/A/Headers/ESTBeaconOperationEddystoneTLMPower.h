//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEddystoneTLMPower.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEddystoneTLMPower allows to create read/write operations for Eddystone Telemetry Power setting of a device.
 */
@interface ESTBeaconOperationEddystoneTLMPower : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Eddystone Telemetry Power setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEddystoneTLMPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation for Eddystone Telemetry Power setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEddystoneTLMPower *)setting completion:(ESTSettingEddystoneTLMPowerCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
