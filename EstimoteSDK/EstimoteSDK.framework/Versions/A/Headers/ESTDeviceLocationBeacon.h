//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceConnectable.h"
#import "ESTBeaconSettingsManager.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTDeviceLocationBeaconErrorDomain @"ESTDeviceLocationBeaconErrorDomain"

/**
 *  Possible errors reported by this class.
 */
typedef NS_ENUM(NSInteger, ESTDeviceLocationBeaconError) {
    /**
     *  Cloud verification during connection failed.
     */
    ESTDeviceLocationBeaconErrorCloudVerificationFailed,
    /**
     *  Bluetooth connection during connection failed.
     */
    ESTDeviceLocationBeaconErrorBluetoothConnectionFailed,
    /**
     *  Bluetooth services discovery during connection failed.
     */
    ESTDeviceLocationBeaconErrorServicesDiscoveryFailed,
    /**
     *  Estimote Cloud Authorization during connection failed.
     */
    ESTDeviceLocationBeaconErrorAuthorizationFailed,
    /**
     *  Connection was not established before firmware update.
     */
    ESTDeviceLocationBeaconErrorFirmwareUpdateDeviceNotConnected,
    /**
     *  Connection was not established before firmware update.
     */
    ESTDeviceLocationBeaconErrorFirmwareUpdateCloudResponseFailed,
    /**
     *  No update is available for this device.
     */
    ESTDeviceLocationBeaconErrorFirmwareUpdateNoUpdate,
    /**
     *  Firmware update is already in progress.
     */
    ESTDeviceLocationBeaconErrorFirmwareUpdateInProgress
};


/**
 *  ESTDeviceLocationBeacon represents Next Generation beacon device. It allows to to establish
 *  connection to the device and change its settings.
 *
 *  Object of this class is returned as a result of ESTUtilityManager scanning.
 *  It is not intended to be initialized manually.
 */
@interface ESTDeviceLocationBeacon : ESTDeviceConnectable

/**
 *  Object allows to access and interact with device settings.
 *  
 *  Object expose convenience API where you can access and change individual
 *  settings of the device (e.g.. `[device.settings.ibeacon.major getValue]`).
 *  You can also register for settings change notifications (e.g. motion state) 
 *  provided during connection using `registerForNotification:` method.
 *
 *  Advanced API allows to define group of settings read/write operations 
 *  that should be performed on the device and then perform them using
 *  `performOperation:` kind of methods.
 */
@property (nullable, nonatomic, strong, readonly) ESTBeaconSettingsManager *settings;

@end

NS_ASSUME_NONNULL_END
