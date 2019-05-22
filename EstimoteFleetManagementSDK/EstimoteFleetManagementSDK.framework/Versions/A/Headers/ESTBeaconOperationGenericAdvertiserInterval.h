//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingGenericAdvertiserInterval.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationGenericAdvertiserInterval allows to create read/write operations for GenericAdvertiser GenericAdvertiserInterval setting of a device.
 */
@interface ESTBeaconOperationGenericAdvertiserInterval : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for GenericAdvertiser GenericAdvertiserInterval setting.
 *
 *  @param advertiserID Advertiser ID.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation for GenericAdvertiser GenericAdvertiserInterval setting.
 *
 *  @param advertiserID Advertiser ID.
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                    setting:(ESTSettingGenericAdvertiserInterval *)setting
                                 completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
