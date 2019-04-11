//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingStorageMaximumSize.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingOperationStorageMaximumSize allows to create read/write operations for Storage MaximumSize setting of a device.
 */
@interface ESTSettingOperationStorageMaximumSize : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Storage MaximumSize setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingStorageMaximumSizeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
