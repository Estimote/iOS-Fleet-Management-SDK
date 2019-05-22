//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTNearableOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoApplicationVersion.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationApplicationVersion allows to create read operations for Application Version setting of a nearable.
 */
@interface ESTNearableOperationApplicationVersion : ESTSettingOperation <ESTNearableOperationProtocol>

/**
 *  Method allows to create read operation for Application Version setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoApplicationVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
