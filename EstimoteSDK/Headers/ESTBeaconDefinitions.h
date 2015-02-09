//
//  ESTBeaconDefinitions.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDefinitions.h"

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

typedef NS_ENUM(int, ESTBeaconColor)
{
    ESTBeaconColorUnknown = 0,
    ESTBeaconColorMint = 1,
    ESTBeaconColorIce,
    ESTBeaconColorBlueberry,
    ESTBeaconColorWhite,
    ESTBeaconColorTransparent
};

typedef NS_ENUM(int, ESTBeaconPowerSavingMode)
{
    ESTBeaconPowerSavingModeUnknown,
    ESTBeaconPowerSavingModeOn,
    ESTBeaconPowerSavingModeOff,
    ESTBeaconPowerSavingModeNotAvailable
};

typedef NS_ENUM(int, ESTBeaconEstimoteSecureUUID)
{
    ESTBeaconEstimoteSecureUUIDUnknown,
    ESTBeaconEstimoteSecureUUIDOn,
    ESTBeaconEstimoteSecureUUIDOff,
    ESTBeaconEstimoteSecureUUIDNotAvailable
};

typedef NS_ENUM(int, ESTBeaconCharInfoType)
{
    ESTBeaconCharInfoTypeWriteRead,
    ESTBeaconCharInfoTypeWriteOnly
};

typedef void(^ESTPowerCompletionBlock)(ESTBeaconPower value, NSError* error);

////////////////////////////////////////////////////////////////////
// Interface definition

@interface ESTBeaconDefinitions : NSObject

@end
