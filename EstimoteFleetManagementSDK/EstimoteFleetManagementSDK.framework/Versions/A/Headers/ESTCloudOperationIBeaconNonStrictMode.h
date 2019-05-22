//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconNonStrictMode.h"
#import "ESTCloudOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationIBeaconNonStrictMode allows to create read/write operations for iBeacon NonStrictMode setting of a device.
 */
@interface ESTCloudOperationIBeaconNonStrictMode : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for iBeacon NonStrictMode setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconNonStrictModeCompletionBlock)completion;

/**
 *  Method allows to create write operation for iBeacon NonStrictMode setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconNonStrictMode *)setting completion:(ESTSettingIBeaconNonStrictModeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
