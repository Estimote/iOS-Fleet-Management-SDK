//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEddystoneUIDInterval.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEddystoneUIDInterval allows to create read/write operations for Eddystone UID AdvertisingInterval setting of a device.
 */
@interface ESTBeaconOperationEddystoneUIDInterval : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Eddystone UID AdvertisingInterval setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEddystoneUIDIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation for Eddystone UID AdvertisingInterval setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEddystoneUIDInterval *)setting completion:(ESTSettingEddystoneUIDIntervalCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
