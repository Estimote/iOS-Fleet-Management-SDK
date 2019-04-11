//  FleetManagementSDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"
#import "ESTDeviceUpdateInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ESTRequestV2DevicesUpdateBlock)(NSArray<ESTDeviceUpdateInfo *> * _Nullable result, NSError * _Nullable error);


/**
 *  ESTRequestV2DevicesUpdate allows to fetch information about all devices having pending changes to be applied. 
 *  List includes both settings and firmware update.
 */
@interface ESTRequestV2DevicesUpdate : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV2DevicesUpdateBlock)completion;

@end

NS_ASSUME_NONNULL_END
