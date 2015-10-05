//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.7.0
//  Copyright (c) 2015 Estimote. All rights reserved.

/**
 *  Apple frameworks
 */
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <SystemConfiguration/SystemConfiguration.h>

/**
 *  Utility tools
 */
#import "ESTUtilityManager.h"
#import "ESTBluetoothBeacon.h"

/**
 *  Beacons
 */
#import "ESTBeaconManager.h"
#import "ESTSecureBeaconManager.h"
#import "ESTBeaconConnection.h"
#import "ESTBeaconDefinitions.h"

/**
 *  Nearables
 */
#import "ESTNearable.h"
#import "ESTNearableManager.h"
#import "ESTSimulatedNearableManager.h"
#import "ESTNearableDefinitions.h"

#import "ESTDeviceNearable.h"
#import "ESTNearableSettingBootVersion.h"
#import "ESTNearableSettingAppVersion.h"
#import "ESTNearableSettingHardwareVersion.h"
#import "ESTNearableSettingAdvertisingIntervalStill.h"
#import "ESTNearableSettingBroadcastingPower.h"

/**
 *  Bulk updater
 */
#import "ESTBulkUpdater.h"

/**
 *  Trigger engine
 */
#import "ESTTriggerManager.h"


/**
 *  Apple Watch support
 */
#import "ESTNotificationTransporter.h"

/**
 *  Eddystone Support
 */
#import "ESTEddystoneManager.h"
#import "ESTEddystoneFilterUID.h"
#import "ESTEddystoneFilterURL.h"
#import "ESTEddystoneFilterURLDomain.h"

/**
 *  Cloud API handling
 */
#import "ESTConfig.h"
#import "ESTCloudManager.h"

#import "ESTRequestGetBeacons.h"
#import "ESTRequestBeaconDetails.h"
#import "ESTRequestGetBeaconsDetails.h"
#import "ESTRequestBeaconColor.h"
#import "ESTRequestBeaconMac.h"
#import "ESTRequestAssignGPSLocation.h"

#import "ESTRequestRegisterDevice.h"
#import "ESTRequestGetPendingSettings.h"
#import "ESTRequestCancelPendingSettings.h"
#import "ESTRequestGetSettingsHistory.h"

#import "ESTRequestGetNearables.h"

#import "ESTBeaconVO.h"
#import "ESTNearableVO.h"
