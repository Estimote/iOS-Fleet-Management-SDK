//
//  ESBeaconUpdateConfig.h
//  EstimoteSDK
//
//  Config object for |ESBulkUpdater|. It describes what needs to be updated
//  in each beacon. If the value is nil, that beacon's property won't be changed.
//
//  Version: 2.4.0
//  Created by Marcin Klimek on 06/03/14.
//  Copyright (c) 2014 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"

@interface ESTBeaconUpdateConfig : NSObject <NSCoding, NSCopying>

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
@property (nonatomic, strong) NSNumber *estimoteSecureUUID;

@end
