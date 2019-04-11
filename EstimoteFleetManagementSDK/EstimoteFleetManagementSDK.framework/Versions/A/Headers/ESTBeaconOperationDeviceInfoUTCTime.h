//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoUTCTime.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationDeviceInfoUTCTime allows to create read/write operations for UTCTime setting of a device.
 */
@interface ESTBeaconOperationDeviceInfoUTCTime : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for UTCTime setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoUTCTimeCompletionBlock)completion;

/**
 *  Method allows to create write operation for UTCTime setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingDeviceInfoUTCTime *)setting completion:(ESTSettingDeviceInfoUTCTimeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
