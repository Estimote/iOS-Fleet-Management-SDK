//
//  ESTTimeRule.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTRule.h"

/**
 * The ESTDateRule class defines single rule related to time during the day.
 */
@interface ESTDateRule : ESTRule 

@property (nonatomic, strong) NSNumber *afterHour;
@property (nonatomic, strong) NSNumber *beforeHour;

/**
 *  Initialization method creating rule when targeted hour is later then.
 *
 *  @param hour hour after which rule should be fulfilled
 *
 *  @return create rule object
 */
+ (instancetype)hourLaterThan:(int)hour;

/**
 *  Initialization method creating rule when targeted hour is earlier then.
 *
 *  @param hour hour before which rule should be fulfilled
 *
 *  @return create rule object
 */
+ (instancetype)hourEarlierThan:(int)hour;

/**
 *  Initialization method creating rule when targeted hour is between hours.
 *
 *  @param firstHour  hour after which rule should be fulfilled
 *  @param secondHour hour before which rule should be fulfilled
 *
 *  @return create rule object
 */
+ (instancetype)hourBetween:(int)firstHour and:(int)secondHour;

@end
