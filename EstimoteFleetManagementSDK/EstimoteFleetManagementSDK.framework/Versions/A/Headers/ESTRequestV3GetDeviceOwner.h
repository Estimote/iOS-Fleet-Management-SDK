//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when ESTRequestV3GetDeviceOwner request is complete.
 *
 *  @param emailAddress Email address of the device's owner.
 *  @param error Request error object. No error means success.
 */
typedef void (^ESTRequestV3GetDeviceOwnerBlock)(NSString *_Nullable emailAddress, NSError *_Nullable error);

/**
 *  Allows to get email address of device's owner from the Estimote Cloud.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Will be renamed to ESTRequestGetDeviceOwner")
@interface ESTRequestV3GetDeviceOwner : ESTRequestGetJSON

/**
 *  Designated initializer of the class.
 *
 *  @param deviceIdentifier Device identifier.
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier;

/**
 *  Sends a request to the Estimote Cloud.
 *
 *  @param completion Request completion block with response and error information. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV3GetDeviceOwnerBlock)completion;

@end

NS_ASSUME_NONNULL_END
