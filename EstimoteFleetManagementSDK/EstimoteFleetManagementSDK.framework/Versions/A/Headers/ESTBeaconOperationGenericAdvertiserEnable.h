//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingGenericAdvertiserEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationGenericAdvertiserEnable allows to create read/write operations for GenericAdvertiser GenericAdvertiserEnable setting of a device.
 */
@interface ESTBeaconOperationGenericAdvertiserEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for GenericAdvertiser GenericAdvertiserEnable setting.
 *
 *  @param advertiserID Advertiser ID.
 *  @param completion   Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for GenericAdvertiser GenericAdvertiserEnable setting.
 *
 *  @param advertiserID Advertiser ID.
 *  @param setting      Setting to be written to a device.
 *  @param completion   Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                    setting:(ESTSettingGenericAdvertiserEnable *)setting
                                 completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
