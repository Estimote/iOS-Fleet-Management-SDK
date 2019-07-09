//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTEddystone.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Generic Eddystone based filter used by `ESTEddystoneManager` in discovery process.
 *  Instance of `ESTEddystoneFilter` can be used as a base for other filters.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTEddystoneFilter : NSObject

/**
 *  Method allows to check if provided eddystones belong to filter.
 *
 *  @param eddystones Eddystones to validate.
 *
 *  @return Properly validated eddystones.
 */
- (NSArray<ESTEddystone *> *)filterEddystones:(NSArray<ESTEddystone *> *)eddystones;

@end

NS_ASSUME_NONNULL_END
