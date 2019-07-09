//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTRequestDelete.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTRequestCancelPendingSettingsBlock)(NSError *_Nullable error);

/**
 *  This request is deleting the device's pending settings from the Estimote Cloud for authorized user.
 */

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please use ESTRequestDeletePendingSettings.")
@interface ESTRequestCancelPendingSettings : ESTRequestDelete

@property (nonatomic, readonly) NSString *macAddress;

/**
 *  Initialise request with MAC address.
 *
 *  @param macAddress MAC address of device provided as NSString
 *
 *  @return instance of request
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with optional NSError object.
 */
- (void)sendRequestWithCompletion:(ESTRequestCancelPendingSettingsBlock)completion;

@end

NS_ASSUME_NONNULL_END
