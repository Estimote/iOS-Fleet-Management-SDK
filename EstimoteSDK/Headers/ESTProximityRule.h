//
//  ESTProximityRule.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTNearableRule.h"

/**
 * The ESTProximityRule class defines single rule related to proximity from the Estimote nearable device.
 */
@interface ESTProximityRule : ESTNearableRule

@property (nonatomic, assign) BOOL inRange;

+ (instancetype)inRangeOfNearableIdentifier:(NSString *)identifier;
+ (instancetype)inRangeOfNearableType:(ESTNearableType)type;

+ (instancetype)outsideRangeOfNearableIdentifier:(NSString *)identifier;
+ (instancetype)outsideRangeOfNearableType:(ESTNearableType)type;

@end
