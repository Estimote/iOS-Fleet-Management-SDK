//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEstimoteLocationEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEstimoteLocationEnable allows to create read/write operations for Estimote Location Enable setting of a device.
 */
@interface ESTBeaconOperationEstimoteLocationEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Estimote Location Enable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEstimoteLocationEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for Estimote Location Enable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEstimoteLocationEnable *)setting completion:(ESTSettingEstimoteLocationEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
