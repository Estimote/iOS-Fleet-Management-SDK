//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTEddystoneFilter.h"

NS_ASSUME_NONNULL_BEGIN

/**
*  Eddystone-URL based filter used by `ESTEddystoneManager` in discovery process.
*  Filter should be initialized with URL string that is matching device(s)
*  should be discovered.
*
*  Default domain used by Estimote Devices is http://go.esti.be
*/
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTEddystoneFilterURL : ESTEddystoneFilter

@property (nonatomic, strong, readonly) NSString *eddystoneURL;

/**
* Initialize filter object with URL provided as NSString;
*/
- (instancetype)initWithURL:(NSString *)eddystoneURL;

@end

NS_ASSUME_NONNULL_END
