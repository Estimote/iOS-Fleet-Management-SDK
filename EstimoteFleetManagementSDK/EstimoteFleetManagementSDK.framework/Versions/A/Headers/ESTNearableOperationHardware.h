//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoHardwareVersion.h"
#import "ESTNearableOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationHardware allows to create read operation for Settings Hardware setting of a device.
 */
@interface ESTNearableOperationHardware : ESTSettingOperation <ESTBeaconOperationProtocol, ESTNearableOperationProtocol>

/**
 *  Method allows to create read operation for Settings Hardware setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoHardwareVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
