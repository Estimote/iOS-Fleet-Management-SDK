//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconEnable allows to create read/write operations for iBeacon IBeaconEnable setting of a device.
 */
@interface ESTBeaconOperationIBeaconEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for iBeacon IBeaconEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for iBeacon IBeaconEnable setting.
 *
 *  @param setting      Value to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconEnable *)setting completion:(ESTSettingIBeaconEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
