//  FleetManagementSDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTNearableRule.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The `ESTProximityRule` class defines single rule related to proximity from the Estimote nearable device.
 */

@interface ESTProximityRule : ESTNearableRule

@property (nonatomic, assign) BOOL inRange;

+ (instancetype)inRangeOfNearableIdentifier:(NSString *)identifier;
+ (instancetype)inRangeOfNearableType:(ESTNearableType)type;

+ (instancetype)outsideRangeOfNearableIdentifier:(NSString *)identifier;
+ (instancetype)outsideRangeOfNearableType:(ESTNearableType)type;

@end

NS_ASSUME_NONNULL_END
