//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <CoreLocation/CoreLocation.h>

/**
 *  Use this class to simulate beacons.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTSimulatedBeaconManager : CLLocationManager <CLLocationManagerDelegate>

/**
*  Array with simulated CLBeacon objects.
*/
@property (nonatomic, readonly) NSArray *simulatedBeacons;

/**
*  Use this initializer if you don't want to specify beacons in JSON.
*  You will receive empty array in locationManager:didRangeBeacons:inRegion delegate method.
*
*  @param delegate Set delegate for CLLocationManagerDelegate updates.
*
*  @return Instance of this object.
*/
- (instancetype)initWithDelegate:(id <CLLocationManagerDelegate>)delegate;

/**
 *  Use this initializer if you want to specify beacons in JSON.
 *  Providing only filename is sufficient, but remember that your file
 *  should be *.json type and accessible from MainBundle.
 *  By default, order of beacons in the list will be reflected in simulatedBeacons array,
 *  which means, this class do not provide simulation of fluctuating RSSI or proximity.
 *  However, you can set those values in JSON file, they will be parsed into CLBeacon object.
 *
 *  @param path            Path for json file with description of beacons you want to simulate.
 *  @param delegate        Set delegate for CLLocationManagerDelegate updates.
 *
 *  @return Instance of this object.
 */
- (instancetype)initWithDelegate:(id <CLLocationManagerDelegate>)delegate
                     pathForJSON:(NSString *)path NS_DESIGNATED_INITIALIZER;

@end
