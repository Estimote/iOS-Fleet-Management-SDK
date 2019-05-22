//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerDarkToSleepThreshold.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerDarkToSleepThreshold allows to create read/write operations for Power DarkToSleepThreshold setting of a device.
 */
@interface ESTBeaconOperationPowerDarkToSleepThreshold : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Power DarkToSleepThreshold setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerDarkToSleepThresholdCompletionBlock)completion;

/**
 *  Method allows to create write operation for Power DarkToSleepThreshold setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingPowerDarkToSleepThreshold *)setting completion:(ESTSettingPowerDarkToSleepThresholdCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
