//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  This Value Object represents settings structure for Mesh advertiser.
 */
@interface ESTDeviceSettingsAdvertiserMesh : ESTDeviceSettingsAdvertiser

/**
 *  Mesh network name.
 */
@property (nonatomic, strong, readonly) NSString *networkName;

/**
 *  Version of last applied settings via Mesh.
 */
@property (nonatomic, strong, readonly) NSNumber *settingsVersion;

/**
 *  List of settings that were synchronised via Mesh.
 */
@property (nonatomic, strong, readonly) NSArray *synchronisationList;

/**
 *  Identifier of Mesh network.
 */
@property (nonatomic, strong, readonly) NSNumber *networkIdentifier;

/**
 *  Network key needed for Mesh authorisation.
 */
@property (nonatomic, strong, readonly) NSString *networkKey;

/**
 *  Flag indicating if settings synchronisation is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *settingsSyncEnabled;

/**
 *  Flag indicating if firmware synchronisation is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *firmwareSyncEnabled;

/**
 *  Flag indicating if scanning for nearables is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *scanNearablesEnabled;

@end

NS_ASSUME_NONNULL_END
