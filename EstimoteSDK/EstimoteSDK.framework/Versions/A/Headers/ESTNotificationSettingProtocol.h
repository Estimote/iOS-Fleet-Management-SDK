//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>


@protocol ESTNotificationSettingProtocol <NSObject>

@required

/**
 *  ID of register should be used to deliver value of the setting.
 *
 *  @return NSInteger value representing register ID
 */
- (NSInteger)notificationRegisterID;

/**
 *  Method invoked when notification is delivered from the device.
 *
 *  @param result NSData object representing value delivered
 */
- (void)fireNotificationBlockWithData:(NSData *)result;

/**
 *  Method updates setting value based on NSData object delivered from the device.
 *  Parsing is done during the operation.
 *
 *  @param data NSData delivered from the device.
 */
- (void)updateNotificationValueWithData:(NSData *)data;

/**
 *  Decorator method that should update particular field in settings object
 *  with proper value it is carrying.
 *
 *  @param settings Settings object that should be decorated
 */
- (void)updateValueInSettings:(id)settings;

/**
 *  Allows to validate if particular settings is available for firmware
 *  in version running on the device.
 *
 *  @param firmware Version of firmware running on the device
 *
 *  @return BOOL value indicating availability
 */
- (BOOL)isAvailableForFirmwareVersion:(NSString *)firmware;

@end
