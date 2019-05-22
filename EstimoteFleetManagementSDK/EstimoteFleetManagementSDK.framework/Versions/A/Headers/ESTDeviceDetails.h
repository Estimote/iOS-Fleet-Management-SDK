//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTBaseVO.h"
#import "ESTDefinitions.h"

@class ESTDeviceShadow, ESTDeviceSettings, ESTDeviceStatusReport, ESTDeviceDetailsMeta;

NS_ASSUME_NONNULL_BEGIN

/**
 *  This Value Object represents complete information about particular
 *  beacon or nearable device including status, settings and pending settings.
 */
@interface ESTDeviceDetails : ESTBaseVO

/**
 *  Device identifier.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  Type of hardware.
 */
@property (nonatomic, strong, readonly) NSString *hardwareType;

/**
 *  Revision of hardware.
 */
@property (nonatomic, strong, readonly) NSString *hardwareRevision;
/**
 *  Footprint of hardware.
 */
@property (nonatomic, strong, readonly) NSString *hardwareFootprint;

/**
 *  Color of the device.
 */
@property (nonatomic, readonly) ESTColor color;

/**
 *  Form-factor of the device.
 */
@property (nonatomic, strong, readonly) NSString *formFactor;

/**
 *  Shadow object representing high level context device belongs to.
 */
@property (nonatomic, strong, readonly) ESTDeviceShadow *shadow;

/**
 *  Object containing all settings of the device.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettings *settings;

/**
 *  Object containing all pending settings of the device applied from both
 *  Estimote Cloud and SDK.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettings *pendingSettings;

/**
 *  Object containing all status information like battery level.
 */
@property (nonatomic, strong, readonly) ESTDeviceStatusReport *statusReport;

/**
 *  Metadata returned by Estimote Cloud together with this device's details JSON.
 *  Nil if metadata wasn't present in the parsed response.
 */
@property (nonatomic, strong, readonly, nullable) ESTDeviceDetailsMeta *meta;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 *  Method allows to initialize value object with data
 *  coming from Estimote Cloud request ESTRequestGetDeviceDetails.
 *
 *  @param dictionary Dictionary containing parsed JSON data coming from cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *) dictionary DEPRECATED_MSG_ATTRIBUTE("Use initWithDataDictionary:metaDictionary;");

/**
 Designated initializer.

 @param dataDictionary Dictionary stored usually under "data" key in response returned by Estimote Cloud.
 @param metaDictionary Metadata stored usually under "meta" key in response returned by Estimote Cloud.
 @return Initialized value object of device's details.
 */
- (instancetype)initWithDataDictionary:(NSDictionary *)dataDictionary metaDictionary:(NSDictionary *)metaDictionary NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
