//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTNearableOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingNearableBroadcastingScheme.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationBroadcastingScheme allows to create read/write operations for Settings BroadcastingScheme setting of a device.
 */
@interface ESTNearableOperationBroadcastingScheme : ESTSettingOperation <ESTNearableOperationProtocol>

/**
 *  Method allows to create read operation for Settings BroadcastingScheme setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingNearableBroadcastingSchemeCompletionBlock)completion;

/**
 *  Method allows to create write operation for Settings BroadcastingScheme setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingNearableBroadcastingScheme *)setting completion:(ESTSettingNearableBroadcastingSchemeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
