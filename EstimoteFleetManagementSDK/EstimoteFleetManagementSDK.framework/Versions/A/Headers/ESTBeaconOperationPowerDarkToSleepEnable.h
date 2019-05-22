//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerDarkToSleepEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerDarkToSleepEnable allows to create read/write operations for Power DarkToSleepEnable setting of a device.
 */
@interface ESTBeaconOperationPowerDarkToSleepEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Power DarkToSleepEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerDarkToSleepEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for Power DarkToSleepEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingPowerDarkToSleepEnable *)setting completion:(ESTSettingPowerDarkToSleepEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
