//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTCloudOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingDeviceInfoGeoLocation.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationDeviceInfoGeoLocation allows to create read/write operations for Cloud GeoLocation setting of a device.
 */
@interface ESTCloudOperationDeviceInfoGeoLocation : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for Cloud GeoLocation setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoGeoLocationCompletionBlock)completion;

/**
 *  Method allows to create write operation for Cloud GeoLocation setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingDeviceInfoGeoLocation *)setting completion:(ESTSettingDeviceInfoGeoLocationCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
