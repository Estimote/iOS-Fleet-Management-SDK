//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents settings structure for UWB advertiser.
 */
@interface ESTDeviceSettingsAdvertiserUWB : ESTDeviceSettingsAdvertiser

/**
 *  Initial delay after whitch UWB radio start ranging.
 */
@property (nonatomic, strong, readonly) NSNumber *startDelayInSeconds;

/**
 *  Time period used for raning other UWB enabled estimote devices .
 */
@property (nonatomic, strong, readonly) NSNumber *rangingTimeInSeconds;

/**
 *  Time period used for broadcasting distances between devices.
 */
@property (nonatomic, strong, readonly) NSNumber *broadcastTimeInSeconds;

/**
 * Number of measurements that should be used to count median value.
 */
@property (nonatomic, strong, readonly) NSNumber *medianLength;

/**
 *
 */
@property (nonatomic, strong, readonly) NSNumber *role;

/**
 *
 */
@property (nonatomic, strong, readonly) NSNumber *phyFrequency;

@end

NS_ASSUME_NONNULL_END
