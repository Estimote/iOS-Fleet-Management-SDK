//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEddystoneTLMEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEddystoneTLMEnable allows to create read/write operations for Eddystone Telemetry Enable setting of a device.
 */
@interface ESTBeaconOperationEddystoneTLMEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Eddystone Telemetry Enable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEddystoneTLMEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for Eddystone Telemetry Enable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEddystoneTLMEnable *)setting completion:(ESTSettingEddystoneTLMEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
