//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

@class ESTDeviceDetails;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param deviceDetails  Details of the device wrapped in ESTDeviceDetails class object.
 *  @param error          Error of request. No error means success.
 */
typedef void(^ESTRequestV2GetDeviceDetailsBlock)(ESTDeviceDetails * _Nullable deviceDetails, NSError * _Nullable error);


/**
 *  ESTRequestV2GetDeviceDetails allows to get device details from the Estimote Cloud API v2.
 */
DEPRECATED_MSG_ATTRIBUTE("Please use `ESTRequestGetDeviceDetails` class for fetching device's details from Estimote Cloud.")
@interface ESTRequestV2GetDeviceDetails : ESTRequestGetJSON

/**
 *  Initialize request with device identifier.
 *
 *  Object will not be initialized if provided identifier will be an empty string.
 *
 *  @param deviceIdentifier Identifier of the device. Identifier should not be an empty string.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV2GetDeviceDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END
