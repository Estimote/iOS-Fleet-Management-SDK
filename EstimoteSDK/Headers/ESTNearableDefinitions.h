//
//  ESTNearableDefinitions.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 16/01/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "ESTDefinitions.h"

/**
 *  Color of the device enclosure.
 */
typedef NS_ENUM(NSInteger, ESTNearableColor)
{
    ESTNearableColorUnknown = 0,
    ESTNearableColorMintCocktail = 1,
    ESTNearableColorIcyMarshmallow,
    ESTNearableColorBlueberryPie,
    ESTNearableColorSweetBeetroot,
    ESTNearableColorCandyFloss,
    ESTNearableColorLemonTart
};

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

/**
 *  Returns NSString representation of nearable color.
 *
 *  @param color color of nearable
 *
 *  @return name of color
 */
+ (NSString *)nameForColor:(ESTNearableColor)color;

@end
