//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconMajor.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconMajor allows to create read/write operations for iBeacon Major setting of beacon device.
 */
@interface ESTBeaconOperationIBeaconMajor : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for iBeacon Major setting.
 *
 *  @param completion Block invoked when read operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconMajorCompletionBlock)completion;

/**
 *  Method allows to create write operation for iBeacon Major setting.
 *
 *  @param value      Value should be written to the device.
 *  @param completion Block invoked when read operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconMajor *)value completion:(ESTSettingIBeaconMajorCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
