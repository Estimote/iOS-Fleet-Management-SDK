//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 Represents range of a proximity where enter/exit events should occur.
 
 Note:
 Due to BLE signal instability the actual place where notifications occur will differ.
 The `meanTriggerDistance` value defines the desired mean of distance at which events occur.
 
 The distance is rounded up to decimeters. Don't expect decimeter accuracy; this is only for simplification
 of ESTProximityRange objects comparison.
 */
@interface ESTProximityRange : NSObject

/**
 Distance in meters where enter/exit events should occur passed in initializer rounded to decimeters (to 0.1).
 */
@property (nonatomic, assign, readonly) double meanTriggerDistance;

/**
 Convenience factory for near range. It's a class property instead of class method to enable good-looking Swift code.
 */
@property (nonatomic, copy, readonly, class) ESTProximityRange *nearRange;

/**
 Convenience factory for far range. It's a class property instead of class method to enable good-looking Swift code.
 */
@property (nonatomic, copy, readonly, class) ESTProximityRange *farRange;

/**
 Init is disabled for this class.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 New is disabled for this class.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initializer.

 @param meanTriggerDistance Distance in meters where enter/exit events should occur rounded to decimeters (to 0.1)
 */
- (nullable instancetype)initWithMeanTriggerDistance:(double)meanTriggerDistance NS_DESIGNATED_INITIALIZER;

/**
 Convenience factory method. Calls `-initWithMeanTriggerDistance:`.

 @param meanTriggerDistance Distance in meters where enter/exit events should occur rounded to decimeters (to 0.1)
 */
+ (nullable instancetype)customRangeWithMeanTriggerDistance:(double)meanTriggerDistance
NS_SWIFT_NAME(custom(meanTriggerDistance:));

#pragma mark isEqual overrides
- (BOOL)isEqualToRange:(ESTProximityRange *)otherRange;
- (BOOL)isEqual:(nullable id)otherObject;
- (NSUInteger)hash;

@end

NS_ASSUME_NONNULL_END
