//
//  ESTBeaconRegion.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 * An ESTBeaconRegion object defines a single beacon or a group of beacons that can be used with ESTBeaconManager to range, monitor and discover beacons.
 *
 * There are three ways to define a region based on Apple implementation:
 *
 * 1. By providing proximityUUID, major and minor - i.e. initWithProximityUUID:major:minor:identifier: - this defines a region consisting of a single beacon that matches all three of these properties.
 *
 * 2. By providing proximityUUID and major - i.e. initWithProximityUUID:major:identifier: - this defines a region that can consist of multiple beacons, as long as their proximityUUID and major match those of the region.
 *
 * 3. By providing proximityUUID only - i.e. initWithProximityUUID:identifier: - this defines a region that can consist of multiple beacons, as long as their proximityUUID matches this of the region.
 *
 * For more details, consult Apple's CLBeaconRegion documentation:
 *
 * https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLBeaconRegion_class/Reference/Reference.html
 *
 * ### Estimote secure UUID rotation
 *
 * In addition to basic CLBeaconRegion functionality support for Estimote Secure UUID rotation feature was added. Estimote Secure UUID rotation allows to secure beacon from hijacking by randomizing its proximity UUID, major and minor values over time. Feature can be turned on starting from beacon firmware in version A2.2.0 by invoking enableEstimoteSecureUUID:completion: method of ESTBeacon object (Connection to the beacon is required). Security is transparent from developer perspective. You should still range/monitor for original proximity UUID, major and minor values of the beacons. the only difference is secured region property that should be set to YES using following methods:
 *
 * 1. initWithProximityUUID:major:minor:identifier:secured:
 *
 * 2. initWithProximityUUID:major:identifier:secured:
 *
 * 3. initWithProximityUUID:identifier:secured:
 *
 */

@interface ESTBeaconRegion : CLBeaconRegion

/**
 *  Indicates if region is related to the beacon with Estimote Secure UUID rotation
 *  feature enabled.
 */
@property (nonatomic, assign) BOOL isSecured;

/**
 *  Indicates if region should be related to the Estimote beacon in motion or not.
 *  Motion UUID should be enabled on the Estimote beacon on to work with this flag.
 */
@property (nonatomic, assign) BOOL inMotion;

/**
 * A flag indicating availability and status of the Basic Power Mode.
 *
 * @since Estimote OS A2.1
 *
 * @see ESTBeaconPowerSavingMode
 * @see enableBasicPowerMode:completion
 */

/**
 *  Initialize a beacon region identified by an proximityUUID. 
 *  Apple CLBeaconRegion based method with Estimote Secure UUID rotation support added.
 *
 *  @since Estimote OS A2.2
 *
 *  @param proximityUUID Beacon region proximity UUID
 *  @param identifier    Beacon region identifier
 *  @param secured       Estimote Secure UUID rotation flag as BOOL value
 *
 *  @return Created region object
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                           identifier:(NSString *)identifier
                              secured:(BOOL)secured;

/**
 *  Initialize a beacon region identified by an proximityUUID and major values.
 *  Apple CLBeaconRegion based method with Estimote Secure UUID rotation support added.
 *
 *  @since Estimote OS A2.2
 *
 *  @param proximityUUID Beacon region proximity UUID
 *  @param major         Beacon region major
 *  @param identifier    Beacon identifier
 *  @param secured       Estimote Secure UUID rotation flag as BOOL value
 *
 *  @return Created region object
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                           identifier:(NSString *)identifier
                              secured:(BOOL)secured;

/**
 *  Initialize a beacon region identified by an proximityUUID, major and minor values.
 *  Apple CLBeaconRegion based method with Estimote Secure UUID rotation support added.
 *
 *  @since Estimote OS A2.2
 *
 *  @param proximityUUID Beacon region proximity UUID
 *  @param major         Beacon region major
 *  @param minor         Beacon region minor
 *  @param identifier    Beacon identifier
 *  @param secured       Estimote Secure UUID rotation flag as BOOL value
 *
 *  @return Created region object
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor
                           identifier:(NSString *)identifier
                              secured:(BOOL)secured;

@end
