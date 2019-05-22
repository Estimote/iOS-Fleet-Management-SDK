//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEddystoneEIDPower.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEddystoneEIDPower allows to create read/write operations for EddystoneEID Power setting of a device.
 */
@interface ESTBeaconOperationEddystoneEIDPower : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for EddystoneEID Power setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEddystoneEIDPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation for EddystoneEID Power setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEddystoneEIDPower *)setting completion:(ESTSettingEddystoneEIDPowerCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
