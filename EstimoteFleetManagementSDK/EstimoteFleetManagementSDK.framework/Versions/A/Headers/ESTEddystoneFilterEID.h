//  FleetManagementSDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTEddystoneFilter.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Eddystone-EID based filter used by `ESTEddystoneManager` in discovery process.
 */
@interface ESTEddystoneFilterEID : ESTEddystoneFilter

/**
 * Initialize Eddystone EID filter object.
 */
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
