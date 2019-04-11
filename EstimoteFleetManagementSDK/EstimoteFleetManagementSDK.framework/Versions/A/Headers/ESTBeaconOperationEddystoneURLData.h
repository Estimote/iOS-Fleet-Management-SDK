//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEddystoneURLData.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEddystoneURLData allows to create read/write operations for Eddystone URL Data setting of a device.
 */
@interface ESTBeaconOperationEddystoneURLData : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Eddystone URL Data setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEddystoneURLDataCompletionBlock)completion;

/**
 *  Method allows to create write operation for Eddystone URL Data setting.
 *
 *  @param setting   Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEddystoneURLData *)setting completion:(ESTSettingEddystoneURLDataCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
