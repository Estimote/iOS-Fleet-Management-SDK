//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"
#import "ESTNearable.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestGetNearablesErrorDomain @"ESTRequestGetNearablesErrorDomain"

/**
 *  Errors occurring for request.
 */
typedef NS_ENUM(NSInteger, ESTRequestGetNearablesError)
{
    /**
     *  Unknown request error.
     */
    ESTRequestGetNearablesUnknown
};

typedef void(^ESTRequestGetNearablesBlock)(NSArray<ESTNearable *> * _Nullable nearables, NSError * _Nullable error);

/**
 *  ESTRequestGetNearables is used to fetch details about all user nearables.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please use ESTGetDevices instead.")
@interface ESTRequestGetNearables : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (NSArray containing ESTNearable objects).
 */
- (void)sendRequestWithCompletion:(ESTRequestGetNearablesBlock)completion;

@end

NS_ASSUME_NONNULL_END
