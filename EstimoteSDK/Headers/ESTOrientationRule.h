//
//  ESTOrientationRule.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTNearableRule.h"

/**
 * The ESTOrientationRule class defines single rule related to physical orientation of the Estimote nearable device.
 */
@interface ESTOrientationRule : ESTNearableRule

@property (nonatomic, assign) ESTNearableOrientation orientation;

+ (instancetype)orientationEquals:(ESTNearableOrientation)orientation forNearableIdentifier:(NSString *)identifier;
+ (instancetype)orientationEquals:(ESTNearableOrientation)orientation forNearableType:(ESTNearableType)type;

@end
