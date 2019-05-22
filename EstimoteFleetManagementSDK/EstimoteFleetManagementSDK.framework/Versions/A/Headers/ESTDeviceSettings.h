//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTBaseVO.h"

@class ESTDeviceSettingsGeneral,
ESTDeviceSettingsAdvertiserConnectivity,
ESTDeviceSettingsAdvertiserIBeacon,
ESTDeviceSettingsAdvertiserEddystoneUID,
ESTDeviceSettingsAdvertiserEddystoneURL,
ESTDeviceSettingsAdvertiserEddystoneTLM,
ESTDeviceSettingsAdvertiserEstimoteLocation,
ESTDeviceSettingsAdvertiserEstimoteTLM,
ESTDeviceSettingsAdvertiserEddystoneEID,
ESTDeviceSettingsAdvertiserMesh,
ESTDeviceSettingsAdvertiserUWB,
ESTDeviceSettingsAdvertiserGeneric,
ESTDeviceSettingsGPIO;

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents device settings fetched from the Estimote Cloud.
 */
@interface ESTDeviceSettings : ESTBaseVO <NSCopying>

/**
 *  General device settings independent from packets.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettingsGeneral *general;

/**
 *  Advertiser settings for Estimote Service packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserConnectivity *> *connectivity;

/**
 *  Advertiser settings for iBeacon packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserIBeacon *> *iBeacon;


/**
 *  Advertiser settings for Eddystone UID packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserEddystoneUID *> *eddystoneUID;

/**
 *  Advertiser settings for Eddystone URL packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserEddystoneURL *> *eddystoneURL;

/**
 *  Advertiser settings for Eddystone TLM packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserEddystoneTLM *> *eddystoneTLM;

/**
 *  Advertiser settings for Eddystone EID packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserEddystoneEID *> *eddystoneEID;

/**
 *  Advertiser settings for Generic Advertiser packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserGeneric *> *generic;

/**
 *  Advertiser settings for Estimote Location packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserEstimoteLocation *> *estimoteLocation;

/**
 *  Advertiser settings for Estimote TLM packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserEstimoteTLM *> *estimoteTLM;

/**
 *  Advertiser settings for UWB packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserUWB *> *uwb;

/**
 *  Advertiser settings for Mesh packets.
 */
@property (nonatomic, strong, readonly) NSArray<ESTDeviceSettingsAdvertiserMesh *> *mesh;

/**
 *  Settings related to GPIO.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettingsGPIO *gpio;

/**
 *  Designated initializer.
 *
 *  @param dictionary Settings dictionary delivered from Estimote Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

/**
 *  Method allows to update settings by overriding their values 
 *  using provided device settings object.
 *
 *  @param deviceSettings Device settings should be used to override.
 */
- (ESTDeviceSettings *)settingsUpdatedWithDeviceSettings:(ESTDeviceSettings *)deviceSettings;

/**
 *  Method for returning dictionary represantation of device's settings.
 */
- (NSDictionary *)cloudDictionary;

@end

NS_ASSUME_NONNULL_END
