//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTRequestGetJSON.h"
#import "ESTBeaconUpdateInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTRequestGetPendingSettingsBlock)(NSArray<ESTBeaconUpdateInfo *> *_Nullable beaconUpdateInfos, NSError *_Nullable error);

/**
 *  This request is fetching all the pending settings from the Estimote Cloud for authorized user.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please use ESTRequestGetDeviceDetails instead.")
@interface ESTRequestGetPendingSettings : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (NSArray containing ESTBeaconUpdateInfo objects).
 */
- (void)sendRequestWithCompletion:(ESTRequestGetPendingSettingsBlock)completion;

@end

NS_ASSUME_NONNULL_END
