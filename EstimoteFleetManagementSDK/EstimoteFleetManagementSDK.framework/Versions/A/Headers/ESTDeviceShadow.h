//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTBaseVO.h"
#import "ESTDeviceGeoLocation.h"
#import "ESTDeviceIndoorLocation.h"


/**
 *  This Value Object represents Device shadow as a high level object
 *  representing particular context.
 */
@interface ESTDeviceShadow : ESTBaseVO

/**
 *  Shadow identifier.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  Shadow name.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 *  Tags array.
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *tags;

/**
 *  Development mode enables anyone to connect and configure 
 *  devices without ownership verification.
 */
@property (nonatomic, strong, readonly) NSNumber *developmentMode;

/**
 *  Physical location of the device.
 */
@property (nonatomic, strong, readonly) ESTDeviceGeoLocation *geoLocation;

/**
 *  Indoor Location location the device is assigned to.
 */
@property (nonatomic, strong, readonly) ESTDeviceIndoorLocation *indoorLocation;

/**
 *  Designated initializer.
 *
 *  @param dictionary Dictionary provided by the Estimote cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

@end
