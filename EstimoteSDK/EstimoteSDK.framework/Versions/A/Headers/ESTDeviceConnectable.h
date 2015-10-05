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
#import "ESTDevice.h"
#import "ESTDefinitions.h"
#import "ESTDeviceSettingProtocol.h"
#import "ESTCloudSettingProtocol.h"
#import "ESTNotificationSettingProtocol.h"

@class ESTDeviceConnectable;

@protocol ESTDeviceConnectableDelegate <NSObject>

@optional

- (void)estDeviceConnectionDidSucceed:(ESTDeviceConnectable *)device;

- (void)estDevice:(ESTDeviceConnectable *)device didDisconnectWithError:(NSError *)error;

- (void)estDevice:(ESTDeviceConnectable *)device didFailConnectionWithError:(NSError *)error;

@end


@interface ESTDeviceConnectable : ESTDevice

@property (nonatomic, weak) id <ESTDeviceConnectableDelegate> delegate;

@property (nonatomic, assign, readonly) ESTConnectionStatus connectionStatus;

/*
 * Perform connection to the device.
 */
- (void)connect;

/*
 * Cancel connection to the device.
 */
- (void)disconnect;

/*
 * Read single setting.
 */
- (void)readSetting:(id <ESTSettingProtocol>)setting;

/*
 * Reads array of settings defined by objects implementing <ESTSettingProtocol> protocol.
 */
- (void)readSettings:(NSArray *)settings;

/*
 * Write single setting.
 */
- (void)writeSetting:(id <ESTSettingProtocol>)setting;

/*
 * Writes array of settings defined by objects implementing <ESTSettingProtocol> protocol.
 */
- (void)writeSettings:(NSArray *)settings;

/*
 * Allows to register for setting with notification type, implementing <ESTNotificationSettingProtocol> protocol.
 */
- (void)registerForNotificationSetting:(id <ESTNotificationSettingProtocol>)setting;

/*
 * Allows to register for settings with notification type, implementing <ESTNotificationSettingProtocol> protocol.
 */
- (void)registerForNotificationSettings:(NSArray *)settings;

@end
