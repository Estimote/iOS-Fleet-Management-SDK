//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTNearableRule.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The `ESTOrientationRule` class defines single rule related to physical orientation of the Estimote nearable device.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTOrientationRule : ESTNearableRule

@property (nonatomic, assign) ESTNearableOrientation orientation;

+ (instancetype)orientationEquals:(ESTNearableOrientation)orientation forNearableIdentifier:(NSString *)identifier;
+ (instancetype)orientationEquals:(ESTNearableOrientation)orientation forNearableType:(ESTNearableType)type;

@end

NS_ASSUME_NONNULL_END
