//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconInterval.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconInterval allows to create read/write operations for iBeacon AdvertisingInterval setting of a device.
 */
@interface ESTBeaconOperationIBeaconInterval : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for iBeacon AdvertisingInterval setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation for iBeacon AdvertisingInterval setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconInterval *)setting completion:(ESTSettingIBeaconIntervalCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
