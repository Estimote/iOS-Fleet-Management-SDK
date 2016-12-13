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

NS_ASSUME_NONNULL_BEGIN

@class ESTDeviceSettingsCollection,
ESTSettingMeshEnable,
ESTSettingMeshNetworkIdentifier,
ESTSettingMeshInterval;

/**
 *  ESTSettingsMesh represents settings group related to Estimote Mesh.
 */
@interface ESTSettingsMesh : NSObject

/**
 *  Estimote Mesh enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingMeshEnable *enable;

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
