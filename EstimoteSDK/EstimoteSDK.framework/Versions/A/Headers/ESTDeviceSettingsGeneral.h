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

#import "ESTBaseVO.h"

@class ESTDeviceSchedule;

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents device settings.
 */
@interface ESTDeviceSettingsGeneral : ESTBaseVO <NSCopying>

/**
 *  Indicates if motion detection during connection is enabled as BOOL value.
 */
@property (nonatomic, strong, readonly) NSNumber *motionDetectionEnabled;

/**
 *  Indicates if dark-to-sleep is enabled as BOOL value.
 */
@property (nonatomic, strong, readonly) NSNumber *darkToSleepEnabled;

/**
 *  Dark-to-sleep threshold in Lux.
 */
@property (nonatomic, strong, readonly) NSNumber *darkToSleepThresholdInLux;

/**
 *  Conditional broadcasting mode (off, flip to sleep or motion only).
 */
@property (nonatomic, strong, readonly) NSNumber *conditionalBroadcasting;

/**
 *  Temperature offset applied to sensor in celsius.
 */
@property (nonatomic, strong, readonly) NSNumber *temperatureOffsetInCelsius;

/**
 *  Indicates if Smart Power Mode is enabled as BOOL value. 
 */
@property (nonatomic, strong, readonly) NSNumber *smartPowerModeEnabled;

/**
 *  Schedule value object for scheduled advertising.
 */
@property (nonatomic, strong, readonly) ESTDeviceSchedule *schedule;

/**
 *  Designated initializer.
 *
 *  @param data Dictionary provided by the Estimote cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

/**
 *  Method allows to update all fields of general settings using
 *  other object of the same class. When field exists settings is overwritten
 *  if nil nothing happens.
 *
 *  @param generalSettings Object should be used to update settings.
 */
- (void)updateWithGeneralSettings:(ESTDeviceSettingsGeneral *)generalSettings;

@end

NS_ASSUME_NONNULL_END
