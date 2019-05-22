//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingShakeToConnectEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationShakeToConnectEnable allows to create read/write operations for Connectivity ShakeToConnectEnable setting of a device.
 */
@interface ESTBeaconOperationShakeToConnectEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Connectivity ShakeToConnectEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingShakeToConnectEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for Connectivity ShakeToConnectEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingShakeToConnectEnable *)setting completion:(ESTSettingShakeToConnectEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
