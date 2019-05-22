//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 ESTMeshNearablesScanResultVO represents single sticker discovery recorded in delivered Mesh scan report.
 */
@interface ESTMeshNearablesScanResultVO : NSObject


/**
 Identifier of discovered nearable.
 */
@property (nonatomic, strong, readonly) NSString *nearableIdentifier;

/**
 RSSI (Strength of the signal) of discovered device.
 */
@property (nonatomic, strong, readonly) NSNumber *rssi;

/**
 Measured Power (Strength of the signal from 1m) of discovered device.
 Default value is -45 dBm.
 */
@property (nonatomic, strong, readonly) NSNumber *measuredPower;

/**
 Distance calculated from the RSSI and measured power.
 */
@property (nonatomic, strong, readonly, getter = getDistance) NSNumber *distance;

/**
 Designated initializer parsing provided data to properties.

 @param data Data of single result.
 @return Initialized result object.
 */
- (instancetype)initWithData:(NSData *)data;

/**
 Initializer of class taking actual values of properties.

 @param deviceIdentifier Identifier of discovered device.
 @param rssi Strength of the signal of discovered device.
 @return Initialized object
 */
- (instancetype)initWithIdentifier:(NSString *)deviceIdentifier
                              rssi:(NSNumber *)rssi;

/**
 Raw scan report's result reading from device.

 @return NSData object.
 */
- (NSData *)data;

@end

NS_ASSUME_NONNULL_END
