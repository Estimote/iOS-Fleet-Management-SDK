//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTBeaconVO : NSObject <NSCoding>

@property (nonatomic, strong) NSString * proximityUUID;
@property (nonatomic, strong) NSNumber * major;
@property (nonatomic, strong) NSNumber * minor;
@property (nonatomic, strong) NSString * macAddress;
@property (nonatomic, strong) NSString * publicIdentifier;
@property (nonatomic, assign) ESTBroadcastingScheme broadcastingScheme;
@property (nonatomic, assign) ESTBeaconMotionUUID motionUUIDState;

@property (nonatomic, strong) NSString * _Nullable name;
@property (nonatomic, strong) NSNumber * _Nullable batteryLifeExpectancy;
@property (nonatomic, strong) NSString * _Nullable hardware;
@property (nonatomic, strong) NSString * _Nullable firmware;
@property (nonatomic, assign) ESTBeaconPower power;
@property (nonatomic, assign) NSInteger advInterval;

@property (nonatomic, strong) NSNumber * _Nullable basicPowerMode;
@property (nonatomic, strong) NSNumber * _Nullable smartPowerMode;
@property (nonatomic, strong) NSNumber * _Nullable batteryLevel;

@property (nonatomic, strong) NSNumber * _Nullable latitude;
@property (nonatomic, strong) NSNumber * _Nullable longitude;
@property (nonatomic, strong) NSDictionary * _Nullable location;
@property (nonatomic) NSString * _Nullable city;
@property (nonatomic) NSString * _Nullable country;
@property (nonatomic) NSString * _Nullable formattedAddress;
@property (nonatomic) NSString * _Nullable stateName;
@property (nonatomic) NSString * _Nullable stateCode;
@property (nonatomic) NSString * _Nullable streetName;
@property (nonatomic) NSString * _Nullable streetNumber;
@property (nonatomic) NSString * _Nullable zipCode;

@property (nonatomic) NSString * _Nullable indoorLocationIdentifier;
@property (nonatomic) NSString * _Nullable indoorLocationName;

@property (nonatomic, strong) NSString * _Nullable eddystoneNamespaceID;
@property (nonatomic, strong) NSString * _Nullable eddystoneInstanceID;
@property (nonatomic, strong) NSString * _Nullable eddystoneURL;

@property (nonatomic, strong) NSNumber * _Nullable motionDetection;
@property (nonatomic, assign) ESTBeaconConditionalBroadcasting conditionalBroadcasting;

@property (nonatomic, strong) NSNumber * _Nullable security;
@property (nonatomic, assign) BOOL isSecured __attribute__ ((deprecated(("Starting from SDK 3.7.0 use security property instead"))));

@property (nonatomic) ESTColor color;

- (instancetype)initWithCloudData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
