//
//  ESTBeaconManager.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconRegion.h"
#import "ESTBeacon.h"
#import "ESTBeaconDefinitions.h"

@class ESTBeaconManager;

/**
 * The ESTBeaconManagerDelegate protocol defines the delegate methods used to receive beacon ranging, monitoring and discovery events from an ESTBeaconManager object.
 */

@protocol ESTBeaconManagerDelegate <NSObject>

@optional

#pragma mark Monitoring Events
///--------------------------------------------------------------------
/// @name Monitoring Events
///--------------------------------------------------------------------

/**
 * Tells the delegate that a new region is being monitored.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that is being monitored.
 */

- (void)beaconManager:(ESTBeaconManager *)manager
didStartMonitoringForRegion:(ESTBeaconRegion *)region;

/**
 * Tells the delegate that a region monitoring error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region for which the error occurred.
 * @param error An error object describing why monitoring failed.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
monitoringDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;

/**
 * Tells the delegate that the user entered the specified region.
 *
 * Because regions are a shared application resource, every active beacon and location manager object delivers this message to its associated delegate. It does not matter which beacon or location manager actually registered the specified region. And if multiple beacon and location managers share a delegate object, that delegate receives the message multiple times.
 *
 *The region object provided may not be the same one that was registered. As a result, you should never perform pointer-level comparisons to determine equality. Instead, use the region's identifier string to determine if your delegate should respond.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that was entered.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
      didEnterRegion:(ESTBeaconRegion *)region;

/**
 * Tells the delegate that the user left the specified region.
 *
 * Because regions are a shared application resource, every active beacon and location manager object delivers this message to its associated delegate. It does not matter which beacon or location manager actually registered the specified region. And if multiple beacon and location managers share a delegate object, that delegate receives the message multiple times.
 *
 *The region object provided may not be the same one that was registered. As a result, you should never perform pointer-level comparisons to determine equality. Instead, use the region's identifier string to determine if your delegate should respond.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that was exited.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
       didExitRegion:(ESTBeaconRegion *)region;

/**
 * Tells the delegate about the state of the specified region.
 *
 * The beacon manager calls this method whenever there is a boundary transition for a region. It calls this method in addition to calling the beaconManager:didEnterRegion: and beaconManager:didExitRegion: methods. The beacon manager also calls this method in response to a call to its [ESTBeaconManager requestStateForRegion:] method, which runs asynchronously.
 *
 * @param manager The beacon manager object reporting the event.
 * @param state The state of the specified region: CLRegionStateUnknown, CLRegionStateInside or CLRegionStateOutside.
 * @param region The region which state was determined.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
   didDetermineState:(CLRegionState)state
           forRegion:(ESTBeaconRegion *)region;

#pragma mark Ranging Events
///--------------------------------------------------------------------
/// @name Ranging Events
///--------------------------------------------------------------------

/**
 * Tells the delegate that one or more beacons are in range.
 *
 * @param manager The beacon manager object reporting the event.
 * @param beacons An array of ESTBeacon objects representing the beacons currently in range. You can use the information in these objects to determine the range of each beacon and its identifying information.
 * @param region The region that was used to range the beacons.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region;


/**
 * Tells the delegate that a region ranging error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region for which the error occurred.
 * @param error An error object describing why ranging failed.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
rangingBeaconsDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;

#pragma mark CoreBluetooth Discovery Events
///--------------------------------------------------------------------
/// @name CoreBluetooth Discovery Events
///--------------------------------------------------------------------

/**
 * Tells the delegate that one or more beacons were discovered in the vicinity of the device.
 *
 * @param manager The beacon manager object reporting the event.
 * @param beacons An array of ESTBeacon objects representing the beacons discovered.
 * @param region The region that was used to discover the beacons.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
  didDiscoverBeacons:(NSArray *)beacons
            inRegion:(ESTBeaconRegion *)region;

/**
 * Tells the delegate that beacons discovery error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region An error object describing why discovery failed.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
didFailDiscoveryInRegion:(ESTBeaconRegion *)region;

#pragma mark Advertising Events
///--------------------------------------------------------------------
/// @name Advertising Events
///--------------------------------------------------------------------

/**
 * Tells the delegate the the device started advertising as an iBeacon.
 *
 * @param manager The beacon manager object reporting the event.
 * @param error If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)beaconManagerDidStartAdvertising:(ESTBeaconManager *)manager
                                  error:(NSError *)error;

#pragma mark Authorization Change Events (new in iOS 8)
///--------------------------------------------------------------------
/// @name Authorization Change Events (new in iOS 8)
///--------------------------------------------------------------------

/**
 * Tells the delegate that the authorization status for the application changed.
 *
 * This method is called whenever the application's ability to use location services changes. Changes can occur because the user allowed or denied the use of location services for your application or for the system as a whole.
 *
 * If the authorization status is already known when you call the requestWhenInUseAuthorization or requestAlwaysAuthorization method, the beacon manager does not report the current authorization status to this method. The beacon manager only reports changes to the authorization status. For example, it calls this method when the status changes from kCLAuthorizationStatusNotDetermined to kCLAuthorizationStatusAuthorizedWhenInUse.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

@end

/**
 * The ESTBeaconManager class defines the interface for discovering, ranging and monitoring beacons and beacon regions, as well as configuring the iOS device to act as an iBeacon.
 */
@interface ESTBeaconManager : NSObject <CLLocationManagerDelegate>

#pragma mark Beacon Manager Configuration
///--------------------------------------------------------------------
/// @name Beacon Manager Configuration
///--------------------------------------------------------------------

/**
 * The delegate object to receive update events.
 *
 * @see ESTBeaconDelegate
 */
@property (nonatomic, weak) id <ESTBeaconManagerDelegate> delegate;


/**
 * When set to YES, ranging will skip all the beacons with proximity equal to CLProximityUnknown.
 */
@property (nonatomic) BOOL avoidUnknownStateBeacons;

/**
 * When proximity of a ranged beacon is CLProximityUnknown, iOS reports certain properties such as rssi or distance as unknown too. This property enables you to retain last known attributes of the beacon for a certain amount of time after its proximity changes to CLProximityUnknown.
 *
 * The value of this property reflects the number of ranging events which reported the beacon in the CLProximityUnknown state required to reset its attributes. By default this is 1, which means a single ranging event is enough to reset the beacon's attributes - resulting in immediate refreshes of all the CLProximityUnknown beacons. If you set it to e.g. 3, then 3 consecutive ranging events reporting the beacon as CLProximityUnknown are required to drop its last known attributes.
 *
 * You can use this property to improve ranging stability when your beacons are often reported as CLProximityUnknown, e.g. due to high advertising intervals.
 */
@property (nonatomic) NSInteger preventUnknownUpdateCount;

/**
 * When ranging multiple regions, setting this to YES will result in a single [ESTBeaconManagerDelegate beaconManager:didRangeBeacons:inRegion:] invocation reporting all the beacons ranged in all the regions for which ranging was started. In such case, the inRegion parameter will be nil, as ranging result does not represent a single region, but all the ranged regions instead.
 */
@property (nonatomic) BOOL returnAllRangedBeaconsAtOnce;

/**
 *  Initializes ESTBeaconManager with specified delegate
 *
 *  @param delegate ESTBeaconManager delegate to receive events.
 *
 *  @return Returns ESTBeaconManager
 */
- (instancetype)initWithDelegate:(id<ESTBeaconManagerDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 * Sets the limit (500 by default) of beacons to be delivered to the [ESTBeaconManagerDelegate beaconManager:didRangeBeacons:inRegion:] delegate method.
 */
- (void)updateRangeLimit:(NSInteger)limit;

#pragma mark CoreLocation Authorization (new in iOS 8)
///--------------------------------------------------------------------
/// @name CoreLocation Authorization (new in iOS 8)
///--------------------------------------------------------------------

/**
 * Returns the app's authorization status for using location services.
 *
 * For more details about the new location services authorization model please refer to the CoreLocation documentation.
 *
 * @see +[CLLocationManager authorizationStatus]
 *
 * @return A value indicating whether the app is authorized to use location services.
 */
+ (CLAuthorizationStatus)authorizationStatus;

/**
 * Requests permission to use location services while the app is in the foreground.
 *
 * "When in use" authorization is sufficient to use beacon ranging (startRangingBeaconsInRegion:) and monitoring (startMonitoringForRegion:) in the foreground, but is not enough to use monitoring in the background and will not relaunch a terminated app upon a monitoring event.
 *
 * For more details about the new location services authorization model please refer to the CoreLocation documentation.
 *
 * @see -[CLLocationManager requestWhenInUseAuthorization]
 */
- (void)requestWhenInUseAuthorization;

/**
 * Requests permission to use location services whenever the app is running.
 *
 * "Always" authorization is required to use beacon monitoring (startMonitoringForRegion:) in the background and to relaunch a terminated app upon a monitoring event.
 *
 * For more details about the new location services authorization model please refer to the CoreLocation documentation.
 *
 * @see -[CLLocationManager requestWhenInUseAuthorization]
 */
- (void)requestAlwaysAuthorization;

#pragma mark CoreLocation Based Scanning
///--------------------------------------------------------------------
/// @name CoreLocation Based Scanning
///--------------------------------------------------------------------

/**
 * Starts monitoring the specified region.
 *
 * If an existing region with the same identifier is already being monitored by the application, the old region is replaced by the new one. The regions you add using this method are shared by all beacon and location manager objects in your application.
 *
 * Region events are delivered to the [ESTBeaconManagerDelegate beaconManager:didEnterRegion:] and [ESTBeaconManagerDelegate beaconManager:didExitRegion:] methods of your delegate. If there is an error, the beacon manager calls the [ESTBeaconManagerDelegate beaconManager:monitoringDidFailForRegion:withError:] method of your delegate instead.
 *
 * @param region The region object that defines the boundary to monitor. This parameter must not be nil.
 *
 * @see ESTBeaconRegion
 * @see stopMonitoringForRegion:
 */
- (void)startMonitoringForRegion:(ESTBeaconRegion*)region;

/**
 * Stops monitoring the specified region.
 *
 * If the specified region object is not currently being monitored, this method has no effect.
 *
 * @param region The region object currently being monitored. This parameter must not be nil. The object you specify need not be the exact same object that you registered but its beacon region attributes should be the same.
 *
 * @see ESTBeaconRegion
 * @see startMonitoringForRegion:
 */
- (void)stopMonitoringForRegion:(ESTBeaconRegion *)region;

/**
 * Starts the delivery of notifications for beacons in the specified region.
 *
 * Once registered, the beacon manager reports any encountered beacons to its delegate by calling the [ESTBeaconManagerDelegate beaconManager:didRangeBeacons:inRegion:] method. If there is an error registering the specified beacon region, the beacon manager calls its delegate's [ESTBeaconManagerDelegate beaconManager:rangingBeaconsDidFailForRegion:withError:] method and provides the appropriate error information.
 *
 * @param region The region object that defines the identifying information for the targeted beacons. The number of beacons represented by this region object depends on which identifier values you use to initialize it. Beacons must match all of the identifiers you specify. This method copies the region information it needs from the object you provide. If nil, defaults to targeting all beacons with proximityUUID equal to ESTIMOTE_PROXIMITY_UUID.
 *
 * @see ESTBeaconRegion
 * @see stopRangingBeaconsInRegion:
 */
- (void)startRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * Stops the delivery of notifications for the specified beacon region.
 *
 * @param region The region that identifies the beacons. The object you specify need not be the exact same object that you registered but its beacon region attributes should be the same. If nil, defaults to targeting all beacons with proximityUUID equal to ESTIMOTE_PROXIMITY_UUID.
 *
 * @see ESTBeaconRegion
 * @see startRangingBeaconsInRegion:
 */
- (void)stopRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * Retrieves the state of a region.
 *
 * This method performs the request asynchronously and delivers the results to the beacon manager's delegate. You must implement the [ESTBeaconManagerDelegate beaconManager:didDetermineState:forRegion:] method in the delegate to receive the results.
 *
 * @param region The region whose state you want to know.
 */
- (void)requestStateForRegion:(ESTBeaconRegion *)region;

#pragma mark CoreBluetooth Based Scanning
///--------------------------------------------------------------------
/// @name CoreBluetooth Based Scanning
///--------------------------------------------------------------------

/**
 * Starts a CoreBluetooth scan in search for Estimote Beacons matching the beacon region provided.
 *
 * Only a single CoreBluetooth based beacon discovery can be active at the same time.
 *
 * @warning The CoreBluetooth based discovery ignores the provided region's proximityUUID property, returning beacons matching the major and minor values regardless of their proximityUUID.
 *
 * @param region The region object that defines the identifying information for the targeted beacons.
 */
- (void)startEstimoteBeaconsDiscoveryForRegion:(ESTBeaconRegion*)region;

/**
 * Starts a CoreBluetooth scan in search for Estimote Beacons matching the beacon region provided, with callback interval set in second parameter.
 *
 * Only a single CoreBluetooth based beacon discovery can be active at the same time.
 *
 * @warning The CoreBluetooth based discovery ignores the provided region's proximityUUID property, returning beacons matching the major and minor values regardless of their proximityUUID.
 *
 *  @param region The region object that defines the identifying information for the targeted beacons.
 *  @param interval Interval, in seconds, for updates from delegate method. If startEstimoteBeaconsDiscoveryForRegion method is used, default interval (0.2) is set.
 */
- (void)startEstimoteBeaconDiscoveryForRegion:(ESTBeaconRegion *)region updateInterval:(float)interval;

/**
 * Stops the CoreBluetooth based beacon discovery.
 */
- (void)stopEstimoteBeaconDiscovery;

#pragma mark Advertising as iBeacon
///--------------------------------------------------------------------
/// @name Advertising as iBeacon
///--------------------------------------------------------------------

/**
 * Start advertising the iOS device as a Bluetooth beacon.
 *
 * @param proximityUUID The proximityUUID to advertise.
 * @param major The major to advertise.
 * @param minor The minor to advertise.
 * @param identifier The identifier of the region used to advertise.
 */
- (void)startAdvertisingWithProximityUUID:(NSUUID *)proximityUUID
                                   major:(CLBeaconMajorValue)major
                                   minor:(CLBeaconMinorValue)minor
                              identifier:(NSString*)identifier;

/**
 * Stop advertising the iOS device as a Bluetooh beacon.
 */
- (void)stopAdvertising;

#pragma mark Utility
///--------------------------------------------------------------------
/// @name Utility
///--------------------------------------------------------------------

/**
 * Fetches a list of all the user's beacons from the Estimote Cloud.
 *
 * @param completion A block that is called when the list has been feteched from the Cloud.
 *
 * The completion block receives the following parameters:
 *
 * - NSArray *listOfBeacons - An array of ESTBeaconVO objects.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 *
 * The ESTBeaconVO object is a value object with the following properties:
 *
 * - NSString *UUID
 *
 * - NSNumber *major
 *
 * - NSNumber *minor
 *
 * - NSString *macAddress
 *
 * - NSNumber *batteryLifeExpectancy
 *
 * - NSString *hardware
 *
 * - NSString *firmware
 *
 * - ESTBeaconPower power
 *
 * - NSInteger advInterval
 *
 * - NSString *name
 *
 * - ESTBeaconColor color
 */
- (void)fetchEstimoteBeaconsWithCompletion:(ESTArrayCompletionBlock)completion;

/**
 * A list of UUIDs that have been written to and read from beacons.
 *
 * @return NSArray An array of NSString objects with UUID strings.
 */
+ (NSArray *)recentlyUsedUUIDs;

/**
 * A list of recently fetched ESTBeaconVO objects.
 *
 * This array is first populated when ESTConfig setupAppID:andAppToken: is called with correct credentials, and then refreshed each time fetchEstimoteBeaconsWithCompletion: is called.
 *
 * @return NSArray An array of ESTBeaconVO objects.
 */
+ (NSArray *)recentlyCachedBeacons;

/**
 * Method for checking if security for ranging and monitoring should be enabled.
 */
+ (BOOL)shouldUseRotation;

@end

