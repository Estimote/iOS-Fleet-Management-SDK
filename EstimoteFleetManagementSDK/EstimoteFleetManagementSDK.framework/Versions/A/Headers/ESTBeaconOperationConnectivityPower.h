//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingConnectivityPower.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationConnectivityPower allows to create read/write operations for Connectivity Power setting of a device.
 */
@interface ESTBeaconOperationConnectivityPower : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Connectivity Power setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingConnectivityPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation for Connectivity Power setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingConnectivityPower *)setting completion:(ESTSettingConnectivityPowerCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
