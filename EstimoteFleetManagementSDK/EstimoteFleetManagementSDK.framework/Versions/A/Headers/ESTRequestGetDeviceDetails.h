//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

@class ESTDeviceDetails;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param deviceDetails Details of the device wrapped in ESTDeviceDetails class object.
 *  @param error Error of request. No error means success.
 */
typedef void(^ESTRequestGetDeviceDetailsBlock)(ESTDeviceDetails * _Nullable deviceDetails, NSError * _Nullable error);


/**
 *  Allows to get device details from the Estimote Cloud.
 */
@interface ESTRequestGetDeviceDetails : ESTRequestGetJSON

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Designated initializer of the class.
 *
 *  @param deviceIdentifier Device identifier.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier NS_DESIGNATED_INITIALIZER;

/**
 *  Sends a request to the Estimote Cloud.
 *
 *  @param completion Request completion block with response and error information. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestGetDeviceDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END
