//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

@class ESTDeviceSettingsCollection;
@class ESTSettingEddystoneConfigurationServiceEnable;

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingsEddystoneConfigurationService represents settings group related to Eddystone Configuration Service.
 */
@interface ESTSettingsEddystoneConfigurationService : NSObject

/**
 *  Eddystone Configuration Service enable setting.
 */
@property (nonatomic, readonly) ESTSettingEddystoneConfigurationServiceEnable *enabled;

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
