//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
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
typedef void(^ESTRequestV3GetDeviceOwnerBlock)(NSString * _Nullable emailAddress, NSError * _Nullable error);

/**
 *  Allows to get email address of device's owner from the Estimote Cloud.
 */
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
