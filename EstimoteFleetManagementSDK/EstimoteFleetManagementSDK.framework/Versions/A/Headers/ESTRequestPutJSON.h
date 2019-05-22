//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTRequestPostJSON.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTRequestPutJSON : ESTRequestPostJSON

- (void)setParams:(id)params forRequest:(NSMutableURLRequest *)request;

@end

NS_ASSUME_NONNULL_END
