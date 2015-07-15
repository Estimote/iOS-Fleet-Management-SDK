//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.3.1
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTNearableRule.h"

/**
 * The `ESTOrientationRule` class defines single rule related to physical orientation of the Estimote nearable device.
 */
@interface ESTOrientationRule : ESTNearableRule

@property (nonatomic, assign) ESTNearableOrientation orientation;

+ (instancetype)orientationEquals:(ESTNearableOrientation)orientation forNearableIdentifier:(NSString *)identifier;
+ (instancetype)orientationEquals:(ESTNearableOrientation)orientation forNearableType:(ESTNearableType)type;

@end
