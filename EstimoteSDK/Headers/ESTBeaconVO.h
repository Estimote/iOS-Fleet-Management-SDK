//
//  ESTBeaconVO.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 24/12/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"

@interface ESTBeaconVO : NSObject <NSCoding>

@property (nonatomic, strong) NSString* UUID;
@property (nonatomic, strong) NSNumber* major;
@property (nonatomic, strong) NSNumber* minor;
@property (nonatomic, strong) NSString* macAddress;
@property (nonatomic, strong) NSNumber *batteryLifeExpectancy;
@property (nonatomic, strong) NSString *hardware;
@property (nonatomic, strong) NSString *firmware;
@property (nonatomic, assign) ESTBeaconPower power;
@property (nonatomic, assign) NSInteger advInterval;

@property (nonatomic, strong) NSString* name;
@property (nonatomic) ESTBeaconColor color;

@end
