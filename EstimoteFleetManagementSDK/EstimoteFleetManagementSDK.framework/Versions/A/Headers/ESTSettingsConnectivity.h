//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

@class ESTDeviceSettingsCollection;
@class ESTSettingConnectivityInterval;
@class ESTSettingConnectivityPower;
@class ESTSettingNearToConnectEnable;
@class ESTSettingShakeToConnectEnable;

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingsConnectivity all settings related to connectivity packet;
 */
@interface ESTSettingsConnectivity : NSObject

/**
 *  Setting for connectivity packet advertising interval.
 */
@property (nonatomic, strong, readonly) ESTSettingConnectivityInterval *interval;

/**
 *  Setting for connectivity packet broadcasting power.
 */
@property (nonatomic, strong, readonly) ESTSettingConnectivityPower *power;

/**
 *  Shake To Connect enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingShakeToConnectEnable *shakeToConnectEnable;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing connectivity packet related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
