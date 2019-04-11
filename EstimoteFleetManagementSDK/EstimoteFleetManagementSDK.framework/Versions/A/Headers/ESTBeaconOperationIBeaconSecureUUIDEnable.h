//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconSecureUUIDEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconSecureUUIDEnable allows to create read/write operations for iBeacon SecureUUIDEnable setting of a device.
 */
@interface ESTBeaconOperationIBeaconSecureUUIDEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for iBeacon SecureUUIDEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconSecureUUIDEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for iBeacon SecureUUIDEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconSecureUUIDEnable *)setting completion:(ESTSettingIBeaconSecureUUIDEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
