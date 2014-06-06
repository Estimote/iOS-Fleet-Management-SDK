//
//  ESTBeaconManager.h
//  EstimoteSDK
//
//  Version: 2.0.0
//  Created by Marcin Klimek on 9/18/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconRegion.h"
#import "ESTBeacon.h"
#import "ESTBeaconDefinitions.h"

@class ESTBeaconManager;

/**
 
 The ESTBeaconManagerDelegate protocol defines the delegate methods to respond for related events.
 */

@protocol ESTBeaconManagerDelegate <NSObject>

@optional

/**
 * Delegate method invoked when ranging started.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */

- (void)beaconManager:(ESTBeaconManager *)manager
didStartMonitoringForRegion:(CLRegion *)region;

/**
 * Delegate method invoked during ranging.
 * Allows to retrieve NSArray of all discoverd beacons
 * represented with ESTBeacon objects.
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as ESTBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region;

/**
 * Delegate method invoked wehen ranging fails
 * for particular region. Related NSError object passed.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
rangingBeaconsDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;


/**
 * Delegate method invoked wehen monitoring fails
 * for particular region. Related NSError object passed.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
monitoringDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;
/**
 * Method triggered when iOS device enters estimote 
 * beacon region during monitoring.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
      didEnterRegion:(ESTBeaconRegion *)region;


/**
 * Method triggered when iOS device leaves estimote
 * beacon region during monitoring.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
       didExitRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when estimote beacon region state
 * was determined using requestStateForRegion:
 *
 * @param manager estimote beacon manager
 * @param state estimote beacon region state
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
     didDetermineState:(CLRegionState)state
             forRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when device starts advertising
 * as iBeacon.
 *
 * @param manager estimote beacon manager
 * @param error info about any error
 *
 * @return void
 */
-(void)beaconManagerDidStartAdvertising:(ESTBeaconManager *)manager
                                  error:(NSError *)error;

/**
 * Delegate method invoked to handle discovered
 * ESTBeacon objects using CoreBluetooth framework
 * in particular region.
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as ESTBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
          didDiscoverBeacons:(NSArray *)beacons
                    inRegion:(ESTBeaconRegion *)region;

/**
 * Delegate method invoked when CoreBluetooth based
 * discovery process fails.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
    didFailDiscoveryInRegion:(ESTBeaconRegion *)region;




@end



/**
 
 The ESTBeaconManager class defines the interface for handling and configuring the estimote beacons and get related events to your application. You use an instance of this class to establish the parameters that describes each beacon behavior. You can also use a beacon manager object to retrieve all beacons in range.
 
 A beacon manager object provides support for the following location-related activities:
 
 * Monitoring distinct regions of interest and generating location events when the user enters or leaves those regions (works in background mode).
 * Reporting the range to nearby beacons and ther distance for the device.
 
 */

@interface ESTBeaconManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic, weak) id <ESTBeaconManagerDelegate> delegate;

/**
 Allows to avoid beacons with unknown state (proximity == 0), when ranging. Default value is NO.
 */
@property (nonatomic) BOOL avoidUnknownStateBeacons;

/**
 When ranging more then one region, beaconManager:didRangeBeacons:inRegion: always returns list of beacons for all ranged regions.
 */
@property (nonatomic) BOOL returnAllRangedBeaconsAtOnce;


/// @name CoreLocation based iBeacon monitoring and ranging methods
#pragma mark - CoreLocation based iBeacon monitoring and ranging methods

/**
 * Range Estimote beacon described with region object.
 * Delegate method beaconManager:didRangeBeacons:inRegion: 
 * is used to retrieve found beacons. Returned NSArray contains 
 * ESTBeacon objects.
 *
 * @param region estimote beacon region (nil starts ranging all estimote beacons)
 *
 * @return void
 */
-(void)startRangingBeaconsInRegion:(ESTBeaconRegion*)region;



/**
 * Start monitoring for particular region.
 * Functionality works in the background mode as well.
 * Every time you enter or leave region appropriet
 * delegate method inovked: beaconManager:didEnterRegtion:
 * and beaconManager:didExitRegion:
 *
 * @param region estimote beacon region (nil starts monitoring all estimote beacons)
 *
 * @return void
 */
-(void)startMonitoringForRegion:(ESTBeaconRegion*)region;

/**
 * Stops ranging Estimote beacons.
 *
 * @param region estimote beacon region (parameter can not be nil)
 *
 * @return void
 */
-(void)stopRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * Stops ranging Estimote beacons in all ranged regions.
 *
 *
 * @return void
 */
-(void)stopRangingBeaconsInAllRegions;

/**
 * Unsubscribe application from iOS monitoring of
 * Estimote beacon region.
 *
 * @param region estimote beacon region (parameter can not be nil)
 *
 * @return void
 */
-(void)stopMonitoringForRegion:(ESTBeaconRegion *)region;

/**
 * Allows to validate current state for particular region
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)requestStateForRegion:(ESTBeaconRegion *)region;

/// @name Turning device into iBeacon

/**
 * Allows to turn device into virtual estimote beacon.
 *
 * @param proximityUUID proximity UUID beacon value
 * @param major minor beacon value
 * @param minor major beacon value
 * @param identifier unique identifier for you region
 *
 * @return void
 */
-(void)startAdvertisingWithProximityUUID:(NSUUID *)proximityUUID
                                   major:(CLBeaconMajorValue)major
                                   minor:(CLBeaconMinorValue)minor
                              identifier:(NSString*)identifier;

/**
 * Stop beacon advertising
 *
 * @return void
 */
-(void)stopAdvertising;


/// @name CoreBluetooth based utility methods
#pragma mark - CoreBluetooth based utility methods

/**
 * Start single beacon discovery process based on CoreBluetooth
 * framework. Method is useful for older beacons discovery 
 * that are not advertising as iBeacons.
 *
 * @param region estimote beacon region (nil discovers all estimote beacons)
 *
 * @return void
 */
-(void)startEstimoteBeaconsDiscoveryForRegion:(ESTBeaconRegion*)region;

/**
 * Stops CoreBluetooth based beacon discovery process.
 *
 * @return void
 */
-(void)stopEstimoteBeaconDiscovery;

/**
 * Get the array of UUIDs that were saved to beacons
 *
 * @return NSArray of UUID strings
 */
+(NSArray *)recentlyUsedUUIDs;


/// @name Estimote Cloud based methods
#pragma mark - Estimote Cloud based methods

/**
 * Setup App ID and App token that allows to access beacons information stored in Estimote Cloud.
 *
 * @return void
 */
+(void)setupAppID:(NSString*)appID andAppToken:(NSString*)appToken;

/**
 * Fetch beacons that are assign to your account.
 * Method works only after successful authentication.
 *
 * @param completion block handling operation completion
 *
 * @return void
 */
-(void)fetchEstimoteBeaconsWithCompletion:(ESTArrayCompletionBlock)completion;

@end

