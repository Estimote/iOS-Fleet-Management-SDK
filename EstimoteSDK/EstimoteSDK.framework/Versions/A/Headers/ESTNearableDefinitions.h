//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.2.4
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTDefinitions.h"

/**
 *  Type of the device marked on enclosure.
 */
typedef NS_ENUM(NSInteger, ESTNearableType)
{
    ESTNearableTypeUnknown = 0,
    ESTNearableTypeDog,
    ESTNearableTypeCar,
    ESTNearableTypeFridge,
    ESTNearableTypeBag,
    ESTNearableTypeBike,
    ESTNearableTypeChair,
    ESTNearableTypeBed,
    ESTNearableTypeDoor,
    ESTNearableTypeShoe,
    ESTNearableTypeGeneric,
    ESTNearableTypeAll
};

/**
 *  Physical orientation of the device in 3D space.
 */
typedef NS_ENUM(NSInteger, ESTNearableOrientation)
{
    ESTNearableOrientationUnknown = 0,
    ESTNearableOrientationHorizontal,
    ESTNearableOrientationHorizontalUpsideDown,
    ESTNearableOrientationVertical,
    ESTNearableOrientationVerticalUpsideDown,
    ESTNearableOrientationLeftSide,
    ESTNearableOrientationRightSide
};

/**
 *  Proximity zone related to distance from the device.
 */
typedef NS_ENUM(NSInteger, ESTNearableZone)
{
    ESTNearableZoneUnknown = 0,
    ESTNearableZoneImmediate,
    ESTNearableZoneNear,
    ESTNearableZoneFar
};

/**
 *  Type of firmware running on the device.
 */
typedef NS_ENUM(NSInteger, ESTNearableFirmwareState)
{
    ESTNearableFirmwareStateBoot = 0,
    ESTNearableFirmwareStateApp
};


@interface ESTNearableDefinitions : ESTDefinitions

/**
 *  Returns NSString representation of nearable type.
 *
 *  @param type type of nearable
 *
 *  @return name of type
 */
+ (NSString *)nameForType:(ESTNearableType)type;


@end
