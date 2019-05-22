//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconMotionUUID.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconMotionUUIDWrite allows to create write operation for iBeacon MotionUUID setting of a device.
 */
@interface ESTBeaconOperationIBeaconMotionUUIDWrite : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create write operation for iBeacon MotionUUIDEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconMotionUUID *)setting completion:(nullable ESTSettingIBeaconMotionUUIDCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
