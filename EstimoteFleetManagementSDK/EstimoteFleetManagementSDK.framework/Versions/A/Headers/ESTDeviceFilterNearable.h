//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceFilter.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Class defines scanning & filtering attributes required by ESTDeviceManager to discover devices that can be connected to.
 *  Results in -[ESTDeviceManagerDelegate deviceManager:didDiscoverDevices:] being called with a collection of
 *  ESTDeviceNearable objects.
 *
 *  @see -[ESTDeviceManager startDeviceDiscoveryWithFilter:].
 */
@interface ESTDeviceFilterNearable : NSObject <ESTDeviceFilter>

/**
 *  Initializes ESTDeviceFilterNearable object without a predicate.
 *  Use this init to discover devices that can be connected to without additional filtering.
 *
 *  @return Initialized filter object.
 */
- (instancetype)init;

/**
 *  Initializes ESTDeviceFilterNearable object with a predicate for filtering by identifier.
 *  Use this method to find a particular device that can be connected to, since the identifier is unique for Estimote devices.
 *
 *  @param identifier Identifier of the searched device.
 *
 *  @return Initialized filter object.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
