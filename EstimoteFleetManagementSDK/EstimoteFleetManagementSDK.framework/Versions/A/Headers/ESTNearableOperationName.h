//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTNearableOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoName.h"
#import "ESTCloudOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationName allows to create read/write operations for Nearable name setting of a device.
 */
@interface ESTNearableOperationName : ESTSettingOperation <ESTNearableOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for Device Info Name setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoNameCompletionBlock)completion;

/**
 *  Method allows to create write operation for Device Info Name setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingDeviceInfoName *)setting completion:(ESTSettingDeviceInfoNameCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
