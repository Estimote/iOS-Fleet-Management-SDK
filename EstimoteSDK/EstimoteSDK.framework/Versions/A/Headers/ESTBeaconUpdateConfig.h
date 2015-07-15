//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.3.1
//  Copyright (c) 2015 Estimote. All rights reserved.

//  Config object for |ESBulkUpdater|. It describes what needs to be updated
//  in each beacon. If the value is nil, that beacon's property won't be changed.

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"

/**
 *  Object of this class contains all settings that should be applied to the Estimote beacon device. 
 *  It's used by `ESTBulkUpdater` class as a part of `ESTBeaconUpdateInfo` object.
 */
@interface ESTBeaconUpdateConfig : NSObject <NSCoding, NSCopying>

/**
 *  To what proximity UUID beacon should be changed.
 */
@property (nonatomic, strong) NSString *proximityUUID;

/**
 *  To what major beacon should be changed.
 */
@property (nonatomic, strong) NSNumber *major;

/**
 *  To what minor beacon should be changed.
 */
@property (nonatomic, strong) NSNumber *minor;

/**
 *  To what advertising interval beacon should be changed.
 */
@property (nonatomic, strong) NSNumber *advInterval;

/**
 *  To what broadcasting power beacon should be changed.
 */
@property (nonatomic, strong) NSNumber *power;

/**
 *  Flag for switching state of basic power mode.
 *  Recommended use: [NSNumber numberWithInt:ESTBeaconPowerSavingMode].
 */
@property (nonatomic, strong) NSNumber *basicPowerMode;

/**
 *  Flag for switching state of smart power mode.
 *  Recommended use: [NSNumber numberWithInt:ESTBeaconPowerSavingMode].
 */
@property (nonatomic, strong) NSNumber *smartPowerMode;

/**
 *  Flag for switching state of Estimote Secure UUID.
 *  Recommended use: [NSNumber numberWithInt:ESTBeaconPowerSavingMode].
 */
@property (nonatomic, strong) NSNumber *estimoteSecureUUIDState;

@end
