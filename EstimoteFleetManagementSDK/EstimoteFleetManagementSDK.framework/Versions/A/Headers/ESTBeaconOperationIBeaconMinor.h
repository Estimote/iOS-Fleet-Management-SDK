//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconMinor.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconMinor allows to create read/write operations for iBeacon Minor setting of a device.
 */
@interface ESTBeaconOperationIBeaconMinor : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for iBeacon Minor setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconMinorCompletionBlock)completion;

/**
 *  Method allows to create write operation for iBeacon Minor setting.
 *
 *  @param setting      Value to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconMinor *)setting completion:(ESTSettingIBeaconMinorCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
