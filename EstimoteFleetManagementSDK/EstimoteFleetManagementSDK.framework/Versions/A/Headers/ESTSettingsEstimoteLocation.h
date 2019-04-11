//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ESTSettingEstimoteLocationEnable, ESTSettingEstimoteLocationInterval, ESTSettingEstimoteLocationPower, ESTDeviceSettingsCollection;


/**
 *  ESTSettingsEstimoteLocation represents group of settings related to Estimote Location packet.
 */
@interface ESTSettingsEstimoteLocation : NSObject

/**
 *  Estimote enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteLocationEnable *enable;

/**
 *  Estimote advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteLocationInterval *interval;

/**
 *  Estimote broadcasting power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteLocationPower *power;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing Estimote related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
