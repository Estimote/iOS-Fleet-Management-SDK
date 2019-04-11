//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingStorageBlockType.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingOperationStorageBlockType allows to create read/write operations for Storage BlockType setting of a device.
 */
@interface ESTSettingOperationStorageBlockType : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Storage BlockType setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingStorageBlockTypeCompletionBlock)completion;

/**
 *  Method allows to create write operation for Storage BlockType setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingStorageBlockType *)setting completion:(ESTSettingStorageBlockTypeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
