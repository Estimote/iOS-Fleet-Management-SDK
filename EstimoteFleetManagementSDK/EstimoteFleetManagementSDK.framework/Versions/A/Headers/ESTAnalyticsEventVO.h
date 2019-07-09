//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM (NSInteger, ESTAnalyticsEventType) {
    ESTAnalyticsEventTypeEnterRegion,
    ESTAnalyticsEventTypeExitRegion,
    ESTAnalyticsEventTypeInFar,
    ESTAnalyticsEventTypeInNear,
    ESTAnalyticsEventTypeInImmediate,
    ESTAnalyticsEventTypeInUnknown
};

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTAnalyticsEventVO : NSObject <NSCoding, NSCopying>

@property (nonatomic, strong, readonly) CLBeaconRegion *region;
@property (nonatomic, strong, readonly) CLLocation *location;
@property (nonatomic, strong, readonly) NSNumber *eventType;
@property (nonatomic, strong, readonly) NSNumber *timestamp;
@property (nonatomic, strong, readonly) NSNumber *inForeground;

- (instancetype)initWithBeaconRegion:(CLBeaconRegion *)region
                            location:(CLLocation *)location
                           eventType:(ESTAnalyticsEventType)eventType;

+ (NSNumber *)getCurrentTimestamp;

@end
