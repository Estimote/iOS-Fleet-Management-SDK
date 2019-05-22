//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTRequestPostJSON : ESTRequestBase

- (void)setParams:(id)params forRequest:(NSMutableURLRequest *)request;

@end

NS_ASSUME_NONNULL_END
