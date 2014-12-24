//
//  ESTDefinitions.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 27/11/14.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTFirmwareInfoVO.h"

typedef NS_ENUM(int, ESTFirmwareUpdate)
{
    ESTFirmwareUpdateNone,
    ESTFirmwareUpdateAvailable,
    ESTFirmwareUpdateNotAvailable
};

typedef NS_ENUM(int, ESTConnectionStatus)
{
    ESTConnectionStatusConnecting,
    ESTConnectionStatusConnected,
    ESTConnectionStatusDisconnected
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

@end
