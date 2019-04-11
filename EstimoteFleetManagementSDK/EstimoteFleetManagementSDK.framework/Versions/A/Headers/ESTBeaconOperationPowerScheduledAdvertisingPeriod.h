//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingPowerScheduledAdvertisingPeriod.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerScheduledAdvertisingPeriod allows to create read/write operations for Power ScheduledAdvertisingPeriod setting of a device.
 */
@interface ESTBeaconOperationPowerScheduledAdvertisingPeriod : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Power ScheduledAdvertisingPeriod setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerScheduledAdvertisingPeriodCompletionBlock)completion;

/**
 *  Method allows to create write operation for Power ScheduledAdvertisingPeriod setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingPowerScheduledAdvertisingPeriod *)setting completion:(ESTSettingPowerScheduledAdvertisingPeriodCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
