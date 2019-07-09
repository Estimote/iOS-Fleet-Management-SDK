//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTNearableRule.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The `ESTMotionRule` class defines single rule related to motion state of the Estimote nearable device.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTMotionRule : ESTNearableRule

@property (nonatomic, assign) BOOL motionState;

+ (instancetype)motionStateEquals:(BOOL)motionState forNearableIdentifier:(NSString *)identifier;
+ (instancetype)motionStateEquals:(BOOL)motionState forNearableType:(ESTNearableType)type;

@end

NS_ASSUME_NONNULL_END
