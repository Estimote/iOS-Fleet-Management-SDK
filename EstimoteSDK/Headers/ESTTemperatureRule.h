//
//  ESTTemperatureRule.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTNearableRule.h"

/**
 * The ESTTemperatureRule class defines single rule related to ambient temperature of the Estimote nearable device.
 */
@interface ESTTemperatureRule : ESTNearableRule

@property (nonatomic, strong) NSNumber *maxValue;
@property (nonatomic, strong) NSNumber *minValue;

+ (instancetype)temperatureGraterThan:(double)value forNearableIdentifier:(NSString *)identifier;
+ (instancetype)temperatureLowerThan:(double)value forNearableIdentifier:(NSString *)identifier;
+ (instancetype)temperatureBetween:(double)minValue and:(double)maxValue forNearableIdentifier:(NSString *)identifier;

+ (instancetype)temperatureGraterThan:(double)value forNearableType:(ESTNearableType)type;
+ (instancetype)temperatureLowerThan:(double)value forNearableType:(ESTNearableType)type;
+ (instancetype)temperatureBetween:(double)minValue and:(double)maxValue forNearableType:(ESTNearableType)type;

@end
