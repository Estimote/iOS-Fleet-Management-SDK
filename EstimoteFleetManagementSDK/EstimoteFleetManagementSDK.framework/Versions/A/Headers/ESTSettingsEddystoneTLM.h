//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ESTSettingEddystoneTLMEnable, ESTSettingEddystoneTLMInterval, ESTSettingEddystoneTLMPower, ESTDeviceSettingsCollection;


/**
 *  ESTSettingsEddystoneTLM represents a group of settings related to Eddystone Telemetry packet.
 */
@interface ESTSettingsEddystoneTLM : NSObject

/**
 *  Eddystone Telemetry enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneTLMEnable *enable;

/**
 *  Eddystone Telemetry advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneTLMInterval *interval;

/**
 *  Eddystone Telemetry power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneTLMPower *power;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing Eddystone Telemetry related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
