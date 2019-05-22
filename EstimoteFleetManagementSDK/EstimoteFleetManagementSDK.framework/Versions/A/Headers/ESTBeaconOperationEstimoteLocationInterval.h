//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEstimoteLocationInterval.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEstimoteLocationInterval allows to create read/write operations for Estimote Location AdvertisingInterval setting of a device.
 */
@interface ESTBeaconOperationEstimoteLocationInterval : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Estimote Location AdvertisingInterval setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEstimoteLocationIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation for Estimote Location AdvertisingInterval setting.
 *
 *  @param setting      Value to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEstimoteLocationInterval *)setting completion:(ESTSettingEstimoteLocationIntervalCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
