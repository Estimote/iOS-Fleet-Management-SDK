//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.3.1
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBluetoothBeacon.h"

typedef NS_ENUM(NSInteger, ESTUtilitManagerState)
{
    ESTUtilitManagerStateIdle,
    ESTUtilitManagerStateScanning
};

@class ESTUtilityManager;

@protocol ESTUtilityManagerDelegate <NSObject>

@optional

/**
 * Tells the delegate that one or more beacons were discovered in the vicinity of the device.
 *
 * @param manager The utility manager object reporting the event.
 * @param beacons An array of `<ESTBluetoothBeacon>` objects representing the beacons discovered.
 */
- (void)utilityManager:(ESTUtilityManager *)manager
    didDiscoverBeacons:(NSArray *)beacons;

/**
 * Tells the delegate that beacons discovery error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 */
- (void)utilityManagerDidFailDiscovery:(ESTUtilityManager *)manager;

@end

/**
 * The `ESTUtilityManager` class defines the interface for utility methods related to Estimote Beacons. The main functionality 
 * allows to discover CoreBluetooth based representation of Estimote Beacon devices.
 */

@interface ESTUtilityManager : NSObject

 /**
 *  Current state of Utility manager
 */
@property (nonatomic, assign, readonly) ESTUtilitManagerState state;

/**
 *  Delegate object.
 */
@property (nonatomic, weak) id<ESTUtilityManagerDelegate> delegate;

/**
 * Starts a CoreBluetooth scan in search for all Estimote Beacons in range.
 * Related `utilityManager:didDiscoverBeacons:` is fired every 0.2 sec until
 * stopEstimoteBeaconDiscovery method invocation.
 *
 */
- (void)startEstimoteBeaconDiscovery;

/**
 * Starts a CoreBluetooth scan in search for all Estimote Beacons in range.
 * Related `utilityManager:didDiscoverBeacons:` is fired until
 * stopEstimoteBeaconDiscovery method invocation. Delegate method interval
 * is provided as a method param.
 *
 *  @param interval Interval, in seconds, for updates from delegate method.
 */
- (void)startEstimoteBeaconDiscoveryWithUpdateInterval:(NSTimeInterval)interval;

/**
 * Stops the CoreBluetooth based beacon discovery.
 */
- (void)stopEstimoteBeaconDiscovery;

@end
