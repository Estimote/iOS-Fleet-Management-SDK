//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingStorageBlockSize.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingOperationStorageBlockSize allows to create read/write operations for Storage BlockSize setting of a device.
 */
@interface ESTSettingOperationStorageBlockSize : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Storage BlockSize setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingStorageBlockSizeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
