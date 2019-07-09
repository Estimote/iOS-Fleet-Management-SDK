//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTNearableRule.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The `ESTTemperatureRule` class defines single rule related to ambient temperature of the Estimote nearable device.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTTemperatureRule : ESTNearableRule

@property (nonatomic, strong) NSNumber *_Nullable maxValue;
@property (nonatomic, strong) NSNumber *_Nullable minValue;

+ (instancetype)temperatureGraterThan:(double)value forNearableIdentifier:(NSString *)identifier;
+ (instancetype)temperatureLowerThan:(double)value forNearableIdentifier:(NSString *)identifier;
+ (instancetype)temperatureBetween:(double)minValue and:(double)maxValue forNearableIdentifier:(NSString *)identifier;

+ (instancetype)temperatureGraterThan:(double)value forNearableType:(ESTNearableType)type;
+ (instancetype)temperatureLowerThan:(double)value forNearableType:(ESTNearableType)type;
+ (instancetype)temperatureBetween:(double)minValue and:(double)maxValue forNearableType:(ESTNearableType)type;

@end

NS_ASSUME_NONNULL_END
