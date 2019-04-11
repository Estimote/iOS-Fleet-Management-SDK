//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

@class ESTDeviceDetails;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param devicesDetails  Array of user's devices details, each wrapped in ESTDeviceDetails class object.
 *  @param error    Error of request. No error means success.
 */
typedef void(^ESTRequestV2GetDevicesBlock)(NSArray <ESTDeviceDetails *> *_Nullable devicesDetails, NSError * _Nullable error);


/**
 *  ESTRequestV2GetDeviceDetails allows to get user's devices details from the Estimote Cloud API v2.
 */
DEPRECATED_MSG_ATTRIBUTE("Please use `ESTRequestGetDevices` class for fetching user's from Estimote Cloud.")
@interface ESTRequestV2GetDevices : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV2GetDevicesBlock)completion;

@end

NS_ASSUME_NONNULL_END
