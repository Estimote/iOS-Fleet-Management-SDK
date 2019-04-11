//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEddystoneEIDInterval.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEddystoneEIDInterval allows to create read/write operations for EddystoneEID Interval setting of a device.
 */
@interface ESTBeaconOperationEddystoneEIDInterval : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for EddystoneEID Interval setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEddystoneEIDIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation for EddystoneEID Interval setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEddystoneEIDInterval *)setting completion:(ESTSettingEddystoneEIDIntervalCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
