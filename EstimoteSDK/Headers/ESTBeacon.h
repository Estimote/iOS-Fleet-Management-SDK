//
//  ESTBeacon.h
//  EstimoteSDK
//
//  Version: 2.0.0
//  Created by Marcin Klimek on 06/03/14.
//  Copyright (c) 2014 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"


#define CONNECTION_ERROR_UID_MISSING    400
#define CONNECTION_ERROR_AUTHORIZATION  401
#define CONNECTION_ERROR_TIMEOUT        402

#define CHARACTERISTIC_ERROR            410
#define SAME_VALUE_ERROR                411

@class ESTBeacon;

/**
 
 The ESTBeaconDelegate protocol defines the delegate methods to respond for related events.
 */

@protocol ESTBeaconDelegate <NSObject>

@optional

/**
 * Delegate method that indicates error in beacon connection.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconConnectionDidFail:(ESTBeacon*)beacon withError:(NSError*)error;

/**
 * Delegate method that indicates success in beacon connection.
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconConnectionDidSucceeded:(ESTBeacon*)beacon;

/**
 * Delegate method that beacon did disconnect with device.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beacon:(ESTBeacon*)beacon didDisconnectWithError:(NSError*)error;

/**
 * Delegate method that beacon's accelerometer's state has changed.
 *
 * @param beacon reference to beacon object
 * @param state TRUE if beacon is in motion, NO if beacon has stopped being in motion.
 *
 * @return void
 */
- (void)beacon:(ESTBeacon*)beacon accelerometerStateChanged:(BOOL)state;

@end

/**
 
 The ESTBeacon class defines the interface for handling and configuring single estimote beacon. Instance of this class represents beacon with its current parametrs. In addition it allows to connect and modify settings like ProximityUUID, Major, Minor or Power. You should not build instance of this object by your own - it is generated using ESTBeaconManager class object.
 
 */

@interface ESTBeacon : NSObject

@property (readonly, nonatomic) ESTBeaconFirmwareState   firmwareState;
@property (nonatomic, weak)     id <ESTBeaconDelegate>   delegate;

/////////////////////////////////////////////////////
// bluetooth beacon available when used with
// startEstimoteBeaconsDiscoveryForRegion:


/// @name Publicly available properties

/**
 *  macAddress
 *
 *  Discussion:
 *    Hardware MAC address of the beacon.
 */
@property (readonly, nonatomic)   NSString*               macAddress;

/**
 *  proximityUUID
 *
 *    Proximity identifier associated with the beacon.
 *
 */
@property (readonly, nonatomic)   NSUUID*                 proximityUUID;

/**
 *  motionProximityUUID
 *
 *    Proximity identifier associated with the beacon.
 *
 */
@property (readonly, nonatomic)   NSUUID*                 motionProximityUUID;

/**
 *  major
 *
 *    Most significant value associated with the region. If a major value wasn't specified, this will be nil.
 *
 */
@property (readonly, nonatomic)   NSNumber*               major;

/**
 *  minor
 *
 *    Least significant value associated with the region. If a minor value wasn't specified, this will be nil.
 *
 */
@property (readonly, nonatomic)   NSNumber*               minor;



/**
 *  rssi
 *
 *    Received signal strength in decibels of the specified beacon.
 *    This value is an average of the RSSI samples collected since this beacon was last reported.
 *
 */
@property (readonly, nonatomic)   NSInteger               rssi;

/**
 *  distance
 *
 *    Distance between phone and beacon calculated based on rssi and measured power.
 *
 */
@property (readonly, nonatomic)   NSNumber*               distance;

/**
 *  proximity
 *
 *    The value in this property gives a general sense of the relative distance to the beacon. Use it to quickly identify beacons that are nearer to the user rather than farther away.
 */
@property (readonly, nonatomic)   CLProximity             proximity;

/**
 *  measuredPower
 *
 *    rssi value measured from 1m. This value is used for device calibration.
 */
@property (readonly, nonatomic)   NSNumber*               measuredPower;

/**
 *  hardwareVersion
 *
 *    Reference of the device peripheral object.
 */
@property (readonly, nonatomic)   CBPeripheral*           peripheral;

/////////////////////////////////////////////////////
// properties filled when read characteristic

/// @name Properties available after connection


/**
 *  connectionStatus
 *
 *    Property indicating connection status.
 */
@property (readonly, nonatomic)   ESTBeaconConnectionStatus connectionStatus;

/**
 *  power
 *
 *    Power of signal in dBm. Value available after connection with the beacon. It takes one of the values represented by ESTBeaconPower .
 */
@property (readonly, nonatomic)   NSNumber*               power;

/**
 *  advInterval
 *
 *    Advertising interval of the beacon. Value change from 50ms to 2000ms. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSNumber*               advInterval;

/**
 *  batteryLevel
 *
 *    Battery strength in %. Battery level change from 100% - 0%. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSNumber*               batteryLevel;

/**
 *  remainingLifetime
 *
 *    Remaining lifetime in seconds, based on current battery level, advertising interval and broadcasting power values
 */
@property (readonly, nonatomic)   NSTimeInterval          remainingLifetime;

/**
 *  batteryType
 *
 *    Beacon battery model
 */
@property (readonly, nonatomic)   ESTBeaconBatteryType    batteryType;

/**
 *  hardwareVersion
 *
 *    Version of device hardware. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSString*               hardwareVersion;

/**
 *  isMoving
 *
 *    Flag indicating accelerometer state
 */
@property (readonly, nonatomic)   BOOL                    isMoving;

/**
 *  firmwareVersion
 *
 *    Version of device firmware. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSString*               firmwareVersion;


/**
 *  firmwareUpdateInfo
 *
 *    Firmware update availability status. Value available after connection with the beacon and firmware version check.
 */
@property (readonly, nonatomic)  ESTBeaconFirmwareUpdate firmwareUpdateInfo;


/// @name Cloud related properties

/**
 *  name
 *
 *    Name of the beacon. Filled with value after successful cloud request.
 */
@property (readonly, nonatomic)   NSString*     name;

/**
 *  color
 *
 *    Color of the beacon. Filled with value after successful cloud request.
 */
@property (readonly, nonatomic)   ESTBeaconColor          color;

/// @name Sensor related properties

/**
 *  isAccelerometerAvailable
 *
 *    Indicates if accelerometer available.
 *
 * @since Estimote OS A2.0
 *
 */
@property (readonly, nonatomic)   BOOL  isAccelerometerAvailable;

/**
 *  isAccelerometerEditAvailable
 *
 *    Indicates if accelerometer state change is available.
 *
 *  @since Estimote OS A2.1
 *  @sa    -(void)enableAccelerometer:completion:
 */
@property (readonly, nonatomic)   BOOL  isAccelerometerEditAvailable;

/**
 *  accelerometerEnabled
 *
 *  Indicates is accelerometer enabled.
 *
 *  @since Estimote OS A2.1
 *  @sa    -(void)enableAccelerometer:completion:
 */
@property (readonly, nonatomic)    BOOL accelerometerEnabled;

#pragma mark - Connection handling methods

/// @name Connection handling methods

/**
 * Connect to particular beacon using bluetooth.
 * Connection is required to change values like
 * Major, Minor, Power and Advertising interval.
 *
 * @return void
 */
-(void)connect;

/**
 * Disconnect device with particular beacon
 *
 * @return void
 */
-(void)disconnect;

#pragma mark - Methods for sensors readings

/// @name Methods for sensors readings

/**
 * Reads temperature value in Celsius from the beacon.
 *
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)readTemperatureWithCompletion:(ESTNumberCompletionBlock)completion;

/**
 * Calibrates temperature on the beacon. To perform you should pass current temperature
 * that will be used as a reference.
 *
 * @param temperature reference temperature
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)calibrateTemperatureWithReferenceTemperature:(NSNumber*)temperature
                                          completion:(ESTNumberCompletionBlock)completion;

/**
 * Reads number of individual accelerometer interactions since last reset.
 *
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)readAccelerometerCountWithCompletion:(ESTNumberCompletionBlock)completion;

/**
 * Resets number of individual accelerometer interactions to 0.
 *
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)resetAccelerometerCountWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

#pragma mark - Methods for writing beacon configuration

/// @name Methods for writing beacon configuration

/**
 * Sets Name to the bluetooth connected beacon.
 *
 * @param name new name of the beacon
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeName:(NSString*)name completion:(ESTStringCompletionBlock)completion;

/**
 * Writes Proximity UUID param to bluetooth connected beacon.
 *
 * @param pUUID new Proximity UUID value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeProximityUUID:(NSString*)pUUID completion:(ESTStringCompletionBlock)completion;

/**
 * Writes Motion Proximity UUID param to bluetooth connected beacon.
 * It is broadcasted by the beacons when it is in motion.
 *
 * @param pUUID new Motion Proximity UUID value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeMotionProximityUUID:(NSString*)pUUID completion:(ESTStringCompletionBlock)completion;

/**
 * Writes major param to bluetooth connected beacon.
 *
 * @param major major beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeMajor:(unsigned short)major completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes minor param to bluetooth connected beacon.
 *
 * @param minor minor beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeMinor:(unsigned short)minor completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes advertising interval (in milisec) of connected beacon.
 *
 * @param advertising interval of beacon (50 - 2000 ms)
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeAdvInterval:(unsigned short)interval completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes power of bluetooth connected beacon.
 *
 * @param power advertising beacon power
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writePower:(ESTBeaconPower)power completion:(ESTPowerCompletionBlock)completion;

/**
 * Resets beacon to factory settings. It changes Major, Minor, UUID,
 * Power and Adv Inteval to original values.
 *
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)resetToFactorySettingsWithCompletion:(ESTCompletionBlock)completion;

/**
 * Turn on / off accelerometer in beacon.
 *
 * @param completion block handling operation completion
 *
 * @return void
 * @since Estimote OS A2.1
 * @sa isAccelerometerAvailable, isAccelerometerEditAvailable
*/
- (void)enableAccelerometer:(BOOL)enable
                 completion:(ESTBoolCompletionBlock)completion;

#pragma mark - Methods for firmware update

/// @name Methods for firmware update

/**
 * Verifies if new firmware version is available for download
 * without any additional action. Internet connection
 * is required to pass this process.
 *
 * @param completion Block handling operation completion
 *
 * @return void
 */
-(void)checkFirmwareUpdateWithCompletion:(ESTFirmwareInfoCompletionBlock)completion;

/**
 * Verifies if new firmware version is available for download
 * and updates firmware of connected beacon. Internet connection
 * is required to pass this process.
 *
 * @param progress Block handling operation progress
 * @param completion Block handling operation completion
 *
 * @return void
 */
-(void)updateFirmwareWithProgress:(ESTProgressBlock)progress
                       completion:(ESTCompletionBlock)completion;


#pragma mark - Utility methods

/// @name utility methods

/**
 * Allows comparison between two ESTBeacon objects
 *
 * @return YES or NO
 */
- (BOOL)isEqualToBeacon:(ESTBeacon *)beacon;


@end
