//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingGPIOConfigPort0.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationGPIOConfigPort0 allows to create read/write operations for GPIO ConfigPort0 setting of a device.
 */
@interface ESTBeaconOperationGPIOConfigPort0 : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for GPIO ConfigPort0 setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingGPIOConfigPort0CompletionBlock)completion;

/**
 *  Method allows to create write operation for GPIO ConfigPort0 setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingGPIOConfigPort0 *)setting completion:(ESTSettingGPIOConfigPort0CompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
