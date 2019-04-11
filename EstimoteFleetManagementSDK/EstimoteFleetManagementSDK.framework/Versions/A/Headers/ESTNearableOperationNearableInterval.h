//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTNearableOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingNearableInterval.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationNearableInterval allows to create read/write operations for Nearable Interval setting of a device.
 */
@interface ESTNearableOperationNearableInterval : ESTSettingOperation <ESTNearableOperationProtocol>

/**
 *  Method allows to create read operation for Nearable Interval setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingNearableIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation for Nearable Interval setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingNearableInterval *)setting completion:(ESTSettingNearableIntervalCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
