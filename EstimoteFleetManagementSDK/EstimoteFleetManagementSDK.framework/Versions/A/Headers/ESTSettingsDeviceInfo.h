//  FleetManagementSDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

@class ESTSettingDeviceInfoFirmwareVersion;
@class ESTSettingDeviceInfoHardwareVersion;
@class ESTSettingDeviceInfoUTCTime;
@class ESTDeviceSettingsCollection;
@class ESTSettingDeviceInfoTags;
@class ESTSettingDeviceInfoGeoLocation;
@class ESTSettingDeviceInfoColor;
@class ESTSettingDeviceInfoName;
@class ESTSettingDeviceInfoIndoorLocationIdentifier;
@class ESTSettingDeviceInfoIndoorLocationName;
@class ESTSettingDeviceInfoDevelopmentMode;
@class ESTSettingDeviceInfoUptime;

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingsDeviceInfo represents group of settings related to device information.
 */
@interface ESTSettingsDeviceInfo : NSObject

/**
 *  Color setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoColor *color;

/**
 *  Firmware version setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoFirmwareVersion *firmwareVersion;

/**
 *  Hardware version setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoHardwareVersion *hardwareVersion;

/**
 *  UTC Time setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoUTCTime *utcTime;

/**
 *  Seconds since last device reboot setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoUptime *uptime;

/**
 *  Tags setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoTags *tags;

/**
 *  Geo Location setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoGeoLocation *geoLocation;

/**
 *  Device name setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoName *name;

/**
 *  Development mode setting.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoDevelopmentMode *developmentMode;

/**
 *  Indoor Location identifer, that this device is assigned to.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoIndoorLocationIdentifier *indoorLocationIdentifier;

/**
 *  Indoor Location name, that this device is assigned to.
 */
@property (nonatomic, strong, readonly) ESTSettingDeviceInfoIndoorLocationName *indoorLocationName;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing device related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
