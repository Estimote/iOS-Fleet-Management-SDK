//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

@class ESTDeviceSettingsCollection;
@class ESTSettingSensorsAmbientLight;
@class ESTSettingSensorsMotionNotificationEnable;
@class ESTSettingSensorsTemperature;
@class ESTSettingSensorsTemperatureOffset;
@class ESTSettingSensorsPressure;

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingsSensors
 */
@interface ESTSettingsSensors : NSObject

/**
 *  Ambient Light sensor value.
 */
@property (nonatomic, strong, readonly) ESTSettingSensorsAmbientLight *ambientLight;

/**
 *  Ambient temperature setting.
 */
@property (nonatomic, strong, readonly) ESTSettingSensorsTemperature *temperature;

/**
 *  Ambient temperature offset setting.
 *
 *  You can use this setting to calibrate the beacon's temperature sensor.
 *
 *  For example, if you measure that the sensor in the beacon is off by 1.2 degree C (shows 21.2 instead of 20.0), set the temperature offset to -1.2.
 */
@property (nonatomic, strong, readonly) ESTSettingSensorsTemperatureOffset *temperatureOffset;

/**
 *  Atmospheric pressure setting.
 */
@property (nonatomic, strong, readonly) ESTSettingSensorsPressure *pressure;

/**
 *  Enable Motion Notification (AKA Motion Detection).
 */
@property (nonatomic, strong, readonly) ESTSettingSensorsMotionNotificationEnable *motionNotificationEnable;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing sensors related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
