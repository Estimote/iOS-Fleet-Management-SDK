//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import "ESTDeviceSettingsAdvertiser.h"

/**
 *  This Value Object represents settings structure for Estimote EID advertiser.
 */

@interface ESTDeviceSettingsAdvertiserEddystoneEID : ESTDeviceSettingsAdvertiser

/**
 *  Eddystone EID identity key value.
 */
@property (nonatomic, strong, readonly) NSString *identityKey;

/**
 *  Eddystone EID rotation scaler value.
 */
@property (nonatomic, strong, readonly) NSNumber *rotationScaler;

/**
 *  Eddystone EID registered namespace identifier.
 */
@property (nonatomic, strong, readonly) NSString *registeredNamespaceID;

/**
 *  Eddystone EID registered instance identifier.
 */
@property (nonatomic, strong, readonly) NSString *registeredInstanceID;

@end
