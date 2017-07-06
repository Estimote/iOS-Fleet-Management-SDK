//
//  WeatherRule.h
//  CustomTriggerExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 07.01.2015.
//  Copyright (c) 2015 Estimote Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>


@interface WeatherRule : ESTRule

@property (nonatomic, strong) NSNumber *maxValue;
@property (nonatomic, strong) NSNumber *minValue;

+ (instancetype)currentLocationTemperatureGraterThan:(double)value;
+ (instancetype)currentLocationTemperatureLowerThan:(double)value;

@end
