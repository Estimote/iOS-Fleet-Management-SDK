//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerScheduledAdvertisingEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerScheduledAdvertisingEnable allows to create read/write operations for Power ScheduledAdvertisingEnable setting of a device.
 */
@interface ESTBeaconOperationPowerScheduledAdvertisingEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Power ScheduledAdvertisingEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerScheduledAdvertisingEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for Power ScheduledAdvertisingEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingPowerScheduledAdvertisingEnable *)setting completion:(ESTSettingPowerScheduledAdvertisingEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
