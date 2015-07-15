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

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"

@interface ESTBeaconVO : NSObject <NSCoding>

@property (nonatomic, strong) NSString *proximityUUID;
@property (nonatomic, strong) NSNumber *major;
@property (nonatomic, strong) NSNumber *minor;
@property (nonatomic, strong) NSString *macAddress;
@property (nonatomic, assign) ESTBroadcastingScheme broadcastingScheme;

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *batteryLifeExpectancy;
@property (nonatomic, strong) NSString *hardware;
@property (nonatomic, strong) NSString *firmware;
@property (nonatomic, assign) ESTBeaconPower power;
@property (nonatomic, assign) NSInteger advInterval;

@property (nonatomic, strong) NSNumber *basicPowerMode;
@property (nonatomic, strong) NSNumber *smartPowerMode;
@property (nonatomic, strong) NSNumber *batteryLevel;

@property (nonatomic, strong) NSNumber *latitude;
@property (nonatomic, strong) NSNumber *longitude;
@property (nonatomic, strong) NSString *location;

@property (nonatomic, strong) NSString *eddystoneNamespaceID;
@property (nonatomic, strong) NSString *eddystoneInstanceID;
@property (nonatomic, strong) NSString *eddystoneURL;

@property (nonatomic, strong) NSNumber *motionDetection;
@property (nonatomic, assign) ESTBeaconConditionalBroadcasting conditionalBroadcasting;

@property (nonatomic, assign) BOOL isSecured;
@property (nonatomic) ESTColor color;

- (instancetype)initWithCloudData:(NSDictionary *)data;

@end
