//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ESTDeviceSettingsCollection,
ESTSettingMeshSettingsSyncEnable,
ESTSettingMeshNetworkIdentifier,
ESTSettingMeshInterval;

/**
 *  ESTSettingsMesh represents settings group related to Estimote Mesh.
 */
@interface ESTSettingsMesh : NSObject

/**
 *  Estimote Mesh enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingMeshSettingsSyncEnable *enable;

/**
 *  Estimote Mesh interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingMeshInterval *interval;

/**
 *  Estimote Mesh network identifier setting.
 */
@property (nonatomic, strong, readonly) ESTSettingMeshNetworkIdentifier *networkIdentifier;

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
