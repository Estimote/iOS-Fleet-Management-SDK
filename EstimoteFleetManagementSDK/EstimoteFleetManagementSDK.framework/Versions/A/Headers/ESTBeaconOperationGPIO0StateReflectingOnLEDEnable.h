//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingGPIO0StateReflectingOnLEDEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationGPIO0StateReflectingOnLEDEnable allows to create read/write operations for GPIO0StateReflectingOnLEDEnable setting of a device.
 */
@interface ESTBeaconOperationGPIO0StateReflectingOnLEDEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for GPIO0StateReflectingOnLEDEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingGPIO0StateReflectingOnLEDCompletionBlock)completion;

/**
 *  Method allows to create write operation for GPIO0StateReflectingOnLEDEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingGPIO0StateReflectingOnLEDEnable *)setting completion:(ESTSettingGPIO0StateReflectingOnLEDCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
