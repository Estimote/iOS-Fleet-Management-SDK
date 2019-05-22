//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingGPIONotificationEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationGPIONotificationEnable allows to create read/write operations for GPIO NotificationEnable setting of a device.
 */
@interface ESTBeaconOperationGPIONotificationEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for GPIO NotificationEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingGPIONotificationEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for GPIO NotificationEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingGPIONotificationEnable *)setting completion:(ESTSettingGPIONotificationEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
