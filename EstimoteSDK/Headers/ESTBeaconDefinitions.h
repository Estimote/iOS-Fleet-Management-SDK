//
//  ESTBeaconDefinitions.h
//  EstimoteSDK7
//
//  Version : 1.0.0
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

////////////////////////////////////////////////////////////////////
// Type and class definitions


typedef void(^ESTCompletionBlock)(NSError* error);
typedef void(^ESTUnsignedCompletionBlock)(unsigned value, NSError* error);
typedef void(^ESTBoolCompletionBlock)(BOOL value, NSError* error);
typedef void(^ESTStringCompletionBlock)(NSString* value, NSError* error);

typedef enum : char
{
    ESTBeaconPowerLevel1 = -30,
    ESTBeaconPowerLevel2 = -20,
    ESTBeaconPowerLevel3 = -16,
    ESTBeaconPowerLevel4 = -12,
    ESTBeaconPowerLevel5 = -8,
    ESTBeaconPowerLevel6 = -4,
    ESTBeaconPowerLevel7 = 0,
    ESTBeaconPowerLevel8 = 4
} ESTBeaconPower;

typedef enum : int
{
    ESTBeaconFirmwareStateBoot,
    ESTBeaconFirmwareStateApp
} ESTBeaconFirmwareState;


////////////////////////////////////////////////////////////////////
// Interface definition

@interface ESTBeaconDefinitions : NSObject

@end
