//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingGPIOConfigPort1.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationGPIOConfigPort1 allows to create read/write operations for GPIO ConfigPort1 setting of a device.
 */
@interface ESTBeaconOperationGPIOConfigPort1 : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for GPIO ConfigPort1 setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingGPIOConfigPort1CompletionBlock)completion;

/**
 *  Method allows to create write operation for GPIO ConfigPort1 setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingGPIOConfigPort1 *)setting completion:(ESTSettingGPIOConfigPort1CompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
