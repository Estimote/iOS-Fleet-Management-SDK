//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconProximityUUID.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconProximityUUID allows to create read/write operations for iBeacon ProximityUUID setting of a device.
 */
@interface ESTBeaconOperationIBeaconProximityUUID : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for iBeacon ProximityUUID setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconProximityUUIDCompletionBlock)completion;

/**
 *  Method allows to create write operation for iBeacon ProximityUUID setting.
 *
 *  @param setting      Value to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconProximityUUID *)setting completion:(ESTSettingIBeaconProximityUUIDCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
