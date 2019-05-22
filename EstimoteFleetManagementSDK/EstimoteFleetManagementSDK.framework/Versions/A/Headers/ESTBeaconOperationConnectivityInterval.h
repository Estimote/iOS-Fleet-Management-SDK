//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingConnectivityInterval.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationConnectivityInterval allows to create read/write operations for Connectivity Interval setting of a device.
 */
@interface ESTBeaconOperationConnectivityInterval : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Connectivity Interval setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingConnectivityIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation for Connectivity Interval setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingConnectivityInterval *)setting completion:(ESTSettingConnectivityIntervalCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
