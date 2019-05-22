//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

@class ESTDeviceDetails;

NS_ASSUME_NONNULL_BEGIN

/**
 Completion block fired when request is complete

 @param devices Array of user's devices details, each wrapped in ESTDeviceDetails class object.
 @param error Error of request. No error means success.
 */
typedef void(^ESTRequestV2GetMultipleDeviceDetailsBlock)(NSArray <ESTDeviceDetails *> *_Nullable devices, NSError * _Nullable error);


/**
 *  ESTRequestV2GetMultipleDeviceDetails allows to get user's device details for the given device identifiers from the Estimote Cloud API v2.
 */
@interface ESTRequestV2GetMultipleDeviceDetails : ESTRequestGetJSON

/**
 *  Initialize request with multiple device identifiers.
 *
 *  @param deviceIdentifiers Identifiers of the devices.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifiers:(NSArray<NSString *> *)deviceIdentifiers;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV2GetMultipleDeviceDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END
