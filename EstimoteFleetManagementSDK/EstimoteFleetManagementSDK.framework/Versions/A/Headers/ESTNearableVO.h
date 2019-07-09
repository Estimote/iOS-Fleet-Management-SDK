//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTNearable.h"

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTNearableVO : NSObject <NSCoding>

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, assign) ESTNearableType type;
@property (nonatomic, assign) ESTColor color;
@property (nonatomic, strong) NSString *_Nullable indoorLocationName;
@property (nonatomic, strong) NSString *_Nullable indoorLocationIdentifier;
@property (nonatomic, strong) NSNumber *advInterval;
@property (nonatomic, strong) NSNumber *power;
@property (nonatomic, strong) NSString *hardware;
@property (nonatomic, strong) NSString *firmware;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *motionOnly;
@property (nonatomic, strong) NSNumber *broadcastingScheme;
@property (nonatomic, strong) NSString *proximityUUID;
@property (nonatomic, strong) NSNumber *major;
@property (nonatomic, strong) NSNumber *minor;
@property (nonatomic, strong) NSString *eddystoneURL;

- (instancetype)initWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
