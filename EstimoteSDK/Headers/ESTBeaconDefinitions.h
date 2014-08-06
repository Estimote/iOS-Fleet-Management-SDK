//
//  ESTBeaconDefinitions.h
//  EstimoteSDK
//
//  Version : 2.0.0
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconFirmwareInfoVO.h"

#define ESTIMOTE_PROXIMITY_UUID             [[NSUUID alloc] initWithUUIDString:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D"]
#define ESTIMOTE_MACBEACON_PROXIMITY_UUID   [[NSUUID alloc] initWithUUIDString:@"08D4A950-80F0-4D42-A14B-D53E063516E6"]
#define ESTIMOTE_IOSBEACON_PROXIMITY_UUID   [[NSUUID alloc] initWithUUIDString:@"8492E75F-4FD6-469D-B132-043FE94921D8"]

#define SAVED_UUIDS_KEY @"SAVED_UUIDS_KEY"

////////////////////////////////////////////////////////////////////
// Type and class definitions


typedef NS_ENUM(char, ESTBeaconPower)
{
    ESTBeaconPowerLevel1 = -30,
    ESTBeaconPowerLevel2 = -20,
    ESTBeaconPowerLevel3 = -16,
    ESTBeaconPowerLevel4 = -12,
    ESTBeaconPowerLevel5 = -8,
    ESTBeaconPowerLevel6 = -4,
    ESTBeaconPowerLevel7 = 0,
    ESTBeaconPowerLevel8 = 4
};

typedef NS_ENUM(int, ESTBeaconBatteryType)
{
    ESTBeaconBatteryTypeUnknown = 0,
    ESTBeaconBatteryTypeCR2450,
    ESTBeaconBatteryTypeCR2477
};


typedef NS_ENUM(int, ESTBeaconFirmwareState)
{
    ESTBeaconFirmwareStateBoot,
    ESTBeaconFirmwareStateApp
};

typedef NS_ENUM(int, ESTEvent)
{
    ESTEventEnterRegion,
    ESTEventExitRegion
};

typedef NS_ENUM(int, ESTProximity)
{
    ESTProximityImmediate,
    ESTProximityNear,
    ESTProximityFar
};

typedef NS_ENUM(int, ESTBeaconColor)
{
    ESTBeaconColorUnknown = 0,
    ESTBeaconColorMint = 1,
    ESTBeaconColorIce,
    ESTBeaconColorBlueberry,
    ESTBeaconColorWhite,
    ESTBeaconColorTransparent
};

typedef NS_ENUM(int, ESTBeaconFirmwareUpdate)
{
    ESTBeaconFirmwareUpdateNone,
    ESTBeaconFirmwareUpdateAvailable,
    ESTBeaconFirmwareUpdateNotAvailable
};

typedef NS_ENUM(int, ESTBeaconConnectionStatus)
{
    ESTBeaconConnectionStatusConnecting,
    ESTBeaconConnectionStatusConnected,
    ESTBeaconConnectionStatusDisconnected
};

typedef void(^ESTCompletionBlock)(NSError* error);
typedef void(^ESTObjectCompletionBlock)(id result, NSError* error);
typedef void(^ESTDataCompletionBlock)(NSData* result, NSError* error);
typedef void(^ESTNumberCompletionBlock)(NSNumber* value, NSError* error);
typedef void(^ESTUnsignedShortCompletionBlock)(unsigned short value, NSError* error);
typedef void(^ESTPowerCompletionBlock)(ESTBeaconPower value, NSError* error);
typedef void(^ESTBoolCompletionBlock)(BOOL value, NSError* error);
typedef void(^ESTStringCompletionBlock)(NSString* value, NSError* error);
typedef void(^ESTProgressBlock)(NSInteger value, NSString* description, NSError* error);
typedef void(^ESTArrayCompletionBlock)(NSArray* value, NSError* error);
typedef void(^ESTFirmwareInfoCompletionBlock)(ESTBeaconFirmwareInfoVO *result, NSError* error);
typedef void(^ESTCsRegisterCompletonBlock)(NSError* error);

////////////////////////////////////////////////////////////////////
// Interface definition

@interface ESTBeaconDefinitions : NSObject

@end
