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

#import <Foundation/Foundation.h>
#import "ESTFirmwareInfoVO.h"

typedef NS_ENUM(int, ESTColor)
{
    ESTColorUnknown,
    ESTColorMintCocktail,
    ESTColorIcyMarshmallow,
    ESTColorBlueberryPie,
    ESTColorSweetBeetroot,
    ESTColorCandyFloss,
    ESTColorLemonTart,
    ESTColorVanillaJello,
    ESTColorLiquoriceSwirl,
    ESTColorWhite,
    ESTColorTransparent
};

typedef NS_ENUM(int, ESTFirmwareUpdate)
{
    ESTFirmwareUpdateNone,
    ESTFirmwareUpdateAvailable,
    ESTFirmwareUpdateUnsupported
};

typedef NS_ENUM(int, ESTConnectionStatus)
{
    ESTConnectionStatusDisconnected,
    ESTConnectionStatusConnecting,
    ESTConnectionStatusConnected
};

typedef void(^ESTCompletionBlock)(NSError* error);
typedef void(^ESTObjectCompletionBlock)(id result, NSError* error);
typedef void(^ESTDataCompletionBlock)(NSData* result, NSError* error);
typedef void(^ESTNumberCompletionBlock)(NSNumber* value, NSError* error);
typedef void(^ESTUnsignedShortCompletionBlock)(unsigned short value, NSError* error);
typedef void(^ESTBoolCompletionBlock)(BOOL value, NSError* error);
typedef void(^ESTStringCompletionBlock)(NSString* value, NSError* error);
typedef void(^ESTProgressBlock)(NSInteger value, NSString* description, NSError* error);
typedef void(^ESTArrayCompletionBlock)(NSArray* value, NSError* error);
typedef void(^ESTFirmwareInfoCompletionBlock)(ESTFirmwareInfoVO *result, NSError* error);
typedef void(^ESTCsRegisterCompletonBlock)(NSError* error);

@interface ESTDefinitions : NSObject

+ (NSString *)nameForEstimoteColor:(ESTColor)color;

@end
