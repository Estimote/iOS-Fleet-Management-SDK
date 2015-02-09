//
//  ESTBeacon.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2014 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"
#import "ESTBeaconVO.h"

#define CONNECTION_ERROR_UID_MISSING    400
#define CONNECTION_ERROR_AUTHORIZATION  401
#define CONNECTION_ERROR_TIMEOUT        402

#define CHARACTERISTIC_ERROR            410
#define SAME_VALUE_ERROR                411

@class ESTBeacon;

/**
 * The ESTBeaconDelegate protocol defines the delegate methods used to receive updates about ESTBeacon connection status, as well as sensor related updates once a connection to the beacon has been established.
 */

@protocol ESTBeaconDelegate <NSObject>

@optional

/**
 * Tells the delegate that an attempt to connect to a beacon succeeded and the connection has been established.
 *
 * @param beacon The beacon object reporting the event.
 */
- (void)beaconConnectionDidSucceeded:(ESTBeacon *)beacon;

/**
 * Tells the delegate that an attempt to connect to a beacon has failed.
 *
 * @param beacon The beacon object reporting the event.
 * @param error An error object containing the error code that indicates why connection failed.
 */
- (void)beaconConnectionDidFail:(ESTBeacon *)beacon withError:(NSError *)error;

/**
 * Tells the delegate that a previously connected beacon has disconnected.
 *
 * @param beacon The beacon object reporting the event.
 * @param error An error object containing the error code that indicates why the beacon disconnected.
 */
- (void)beacon:(ESTBeacon *)beacon didDisconnectWithError:(NSError *)error;

/**
 * Tells the delegate that a beacon's [ESTBeacon isMoving] value has changed.
 *
 * @param beacon The beacon object reporting the event.
 * @param state The new isMoving value.
 */
- (void)beacon:(ESTBeacon *)beacon accelerometerStateChanged:(BOOL)state;

@end

/**
 * The ESTBeacon class defines the interface for interacting with a single Estimote beacon. It enables you to retrieve properties of the beacon as well as alter its configuration settings. You do not create instances of this class directly. The ESTBeaconManager object reports encountered beacons to its associated delegate object.
 *
 * The identity of a beacon is defined by its proximityUUID, major, and minor properties. The combination of the three is required to be globally unique among all the Estimote beacons - a constraint that is being validated by the Estimote Cloud at the time of modifying any of these properties.
 *
 * The ESTBeacon instance is being populated with a different set of properties depending on which ESTBeaconManager's method was used to scan for and discover the beacon. There are two such methods currently:
 *
 * - startRangingBeaconsInRegion: - which is a CoreLocation based scan.
 *
 * - startEstimoteBeaconsDiscoveryForRegion: - which is a CoreBluetooth based scan.
 *
 * Additional properties become available once connected to the beacon. See connect for more details about connecting to the beacon. You will also need to assign a delegate to be notified about connection and disconnection events. The delegate needs to conform to the ESTBeaconDelegate protocol.
 */

@interface ESTBeacon : NSObject <NSCopying, NSCoding>

#pragma mark Accessing the Delegate
///--------------------------------------------------------------------
/// @name Accessing the Delegate
///--------------------------------------------------------------------

/**
 * The delegate object to receive beacon related events.
 *
 * @see ESTBeaconDelegate
 */
@property (nonatomic, weak) id <ESTBeaconDelegate> delegate;

#pragma mark Properties Always Available
///--------------------------------------------------------------------
/// @name Properties Always Available
///--------------------------------------------------------------------

/**
 * The most significant value in the beacon.
 *
 * @see writeMajor:completion:
 */
@property (readonly, nonatomic) NSNumber *major;

/**
 * The least significant value in the beacon.
 *
 * @see writeMinor:completion:
 */
@property (readonly, nonatomic) NSNumber *minor;

/**
 * The color of the beacon.
 *
 * This value is stored and retrieved from the Estimote Cloud, which means it might be unavailable under certain circumestances - e.g. no Internet connectivity.
 *
 * @see ESTBeaconColor
 */
@property (readonly, nonatomic) ESTBeaconColor color;

/**
 * The received signal strength of the beacon, measured in decibels.
 *
 * This value is the average RSSI value of the samples received since the range of the beacon was last reported to your app.
 */
@property (readonly, nonatomic) NSInteger rssi;

/**
 * The connection status between the user device and the beacon.
 *
 * @see ESTBeaconConnectionStatus
 */
@property (readonly, nonatomic) ESTConnectionStatus connectionStatus;

#pragma mark Public Properties Available After CoreLocation Based Scan
///--------------------------------------------------------------------
/// @name Properties Available After CoreLocation Based Scan
///--------------------------------------------------------------------

/**
 * The proximity ID of the beacon.
 *
 * @see writeProximityUUID:completion:
 */
@property (readonly, nonatomic) NSUUID *proximityUUID;

/**
 * An estimated distance from the beacon in meters.
 *
 * This value is only as accurate as the rssi readings, i.e. it is subject to the same external factors such as multipath propagation, diffraction, absorption and interference. In general, the greater the distance, the lesser the accuracy.
 */
@property (readonly, nonatomic) NSNumber *distance;

/**
 * The relative proximity to the beacon.
 *
 * The value in this property gives a general sense of the relative proximity to the beacon. Use it to quickly identify beacons that are nearer to the user rather than farther away.
 */
@property (readonly, nonatomic) CLProximity proximity;

#pragma mark Public Properties Available After CoreBluetooth Based Scan
///--------------------------------------------------------------------
/// @name Properties Available After CoreBluetooth Based Scan
///--------------------------------------------------------------------

/**
 * The MAC address of the beacon.
 */
@property (readonly, nonatomic) NSString *macAddress;

/**
 * Factory calibrated constant indicating the expected RSSI value at the distance of 1 meter from the beacon.
 *
 * The value of this constant depends on the broadcasting power and is used to calculate the estimated distance from the beacon.
 */
@property (readonly, nonatomic) NSNumber *measuredPower;

/**
 * Flag indicating the state the beacon's firmware is in.
 *
 * This can be either:
 *
 * - ESTBeaconFirmwareStateApp - A fully functional state. This is the usual state the firmware is in.
 *
 * - ESTBeaconFirmwareStateBoot - A limited function state. This is a temporary state the firmware can find itself in during a firmware update. If the update didn't finish successfully, the firmware might remain in that state. Retry updating the firmware in order to regain full functionality. When in this state, the beacon can only be discovered using CoreBluetooth based scanning and cannot be discovered using CoreLocation based scanning.
 *
 * @see ESTBeaconFirmwareState
 */
@property (readonly, nonatomic) ESTBeaconFirmwareState firmwareState;

/**
 *  The underlying Bluetooth peripheral device.
 */
@property (readonly, nonatomic) CBPeripheral *peripheral;

#pragma mark Properties Available After Connecting
///--------------------------------------------------------------------
/// @name Properties Available After Connecting
///--------------------------------------------------------------------

/**
 * The name of the beacon.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSString *name;

/**
 * The proximity ID of the beacon when it's in motion.
 *
 * This default to the same value as the proximityUUID. Setting it to a different value enables you to detect whether a beacon is in motion or not without a need to connect to the beacon. This can be achieved in two ways:
 *
 * 1. When ranging beacons - if the beacon is in motion, the proximityUUID property will be equal to the motionProximityUUID. Note that the motionProximityUUID property is not available unless connected to the beacon, so you need to know its value in advance.
 *
 * 2. When monitoring regions - you can have two separate regions, one with the regular proximityUUID and one with the motionProximityUUID. Enter and exit notifications will then correspond to the beacon starting and stopping to move.
 *
 * @warning This feature is disabled by default. The option to enable it will be made available in an upcoming update to the SDK.
 *
 * @since Estimote OS 2.0
 *
 * @see writeMotionProximityUUID:completion:
 */
@property (readonly, nonatomic) NSUUID *motionProximityUUID;

/**
 * The power of the beacon's radio signal in dBm.
 *
 * This is a char value, so the proper way to retrieve it is [beacon.power charValue].
 *
 * @see writePower:completion:
 */
@property (readonly, nonatomic) NSNumber *power;

/**
 * The advertising interval of the beacon in ms.
 *
 * @see writeAdvInterval:completion:
 */
@property (readonly, nonatomic) NSNumber *advInterval;

/**
 * The battery charge level for the beacon.
 *
 * Battery level ranges from 0 (fully discharged) to 100 (fully charged).
 */
@property (readonly, nonatomic) NSNumber *batteryLevel;

/**
 *    Remaining lifetime in days, based on current battery level, advertising interval and broadcasting power values
 */
@property (readonly, nonatomic) NSNumber *remainingLifetime;

/**
 * The battery model.
 * 
 * @see ESTBeaconBatteryType
 */
@property (readonly, nonatomic) ESTBeaconBatteryType batteryType;

/**
 * The hardware version of the beacon.
 */
@property (readonly, nonatomic) NSString *hardwareVersion;

/**
 * The firmware version of the beacon.
 *
 * @see checkFirmwareUpdateWithCompletion:
 * @see updateFirmwareWithProgress:completion:
 */
@property (readonly, nonatomic) NSString *firmwareVersion;

/**
 * A flag indicating if a firmware update is available.
 *
 * @bug This property has a ESTBeaconFirmwareUpdateNone value at all times. Use the checkFirmwareUpdateWithCompletion: method instead.
 *
 * @see ESTBeaconFirmwareUpdate
 */
@property (readonly, nonatomic) ESTFirmwareUpdate firmwareUpdateInfo;

/**
 * A flag indicating if the beacon is in motion or not.
 *
 * This value changes:
 *
 * - from NO to YES immediately after a still beacon starts moving,
 *
 * - from YES to NO after a beacon stops moving and remains still for 2 seconds.
 *
 * @see [ESTBeaconDelegate beacon:accelerometerStateChanged:]
 */
@property (readonly, nonatomic) BOOL isMoving;

/**
 * A flag indicating if the beacon has UUID rotation turned on.
 *
 * @since Estimote OS A2.2
 */
@property (readonly, nonatomic) BOOL isSecured;

/**
 * A flag indicating if the accelerometer is available.
 *
 * @since Estimote OS A2.0
 */
@property (readonly, nonatomic) BOOL isAccelerometerAvailable;

/**
 * A flag indicating if accelerometer can be enabled and disabled.
 *
 * @since Estimote OS A2.1
 *
 * @see enableAccelerometer:completion:
 */
@property (readonly, nonatomic) BOOL isAccelerometerEditAvailable;

/**
 * A flag indicating if accelerometer is enabled.
 *
 * @since Estimote OS A2.1
 *
 * @see enableAccelerometer:completion:
 */
@property (readonly, nonatomic) BOOL accelerometerEnabled;

/**
 * A flag indicating if motion UUID is enabled.
 *
 * @since Estimote OS A2.1
 *
 * @see enableMotionUUID:completion:
 */
@property (readonly, nonatomic) BOOL motionUUIDEnabled;

/**
 * A flag indicating availability and status of the Basic Power Mode.
 *
 * @since Estimote OS A2.1
 *
 * @see ESTBeaconPowerSavingMode
 * @see enableBasicPowerMode:completion
 */
@property (readonly, nonatomic) ESTBeaconPowerSavingMode basicPowerMode;

/**
 * A flag indicating availability and status of the Smart Power Mode.
 *
 * @since Estimote OS A2.1
 *
 * @see ESTBeaconPowerSavingMode
 * @see enableSmartPowerMode:completion
 */
@property (readonly, nonatomic) ESTBeaconPowerSavingMode smartPowerMode;

/**
 *  A flag indicating status of Estimote Secure UUID.
 *
 *  @since Estimote OS 2.2
 *  @see ESTBeaconEstimoteSecureUUID
 *  @see enableEstimoteSecureUUID:completion
 */

@property (readonly, nonatomic) ESTBeaconEstimoteSecureUUID estimoteSecureUUID;

#pragma mark Connecting and Disconnecting
///--------------------------------------------------------------------
/// @name Connecting and Disconnecting
///--------------------------------------------------------------------

/**
 * Connects to the beacon using default connection timeout (15 seconds) and number of attempts (4 times).
 *
 * Being connected to the beacon allows you to (re)configure the beacon. Because of that, connecting to the beacon is only possible if you're its verified owner. This implies that before you're able to connect to the beacon, you need to:
 *
 * - have the beacon assigned to your Estimote Cloud account,
 *
 * - set up your Estimote Cloud credentials using the [ESTConfig setupAppID:andAppToken:] class method.
 *
 * Upon successful connection, delegate's [ESTBeaconDelegate beaconConnectionDidSucceeded:] method is called. If connection fails, delegate's [ESTBeaconDelegate beaconConnectionDidFail:withError:] method will be called instead.
 *
 * @warning Once connected, the beacon stops broadcasting and thus will no longer be picked up by ranging, monitoring and discovery until disconnected.
 *
 * @see connectWithAttempts:connectionTimeout:
 */
- (void)connect;

/**
 * Connects to the beacon.
 *
 * This method allows you to overwrite the connection timeout and the number of attempts. Otherwise, it behaves exactly like connect.
 *
 * @param attempts Number of connection attempts before giving up.
 * @param timeout  Connection timeout in seconds.
 */
- (void)connectWithAttempts:(NSInteger)attempts
         connectionTimeout:(NSInteger)timeout;

/**
 * Disconnects from the beacon.
 *
 * Always remember to disconnect from the beacon when the connection is no longer required, as the beacon in the connected state stops broadcasting and thus is not being picked up by ranging, monitoring and discovery.
 */
- (void)disconnect;

#pragma mark Interacting with Sensors
///--------------------------------------------------------------------
/// @name Interacting with Sensors (must be connected)
///--------------------------------------------------------------------

/**
 * Retrieves the temperature of surrounding environment reported by the beacon.
 *
 * @param completion A block that is called when the temperature has been retrieved from the beacon.
 *
 * The completion block receives the following parameters:
 *
 * - NSNumber *value - The temperature in Celsius degrees.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 *
 * @see calibrateTemperatureWithReferenceTemperature:completion:
 */
- (void)readTemperatureWithCompletion:(ESTNumberCompletionBlock)completion;

/**
 * Calibrates the beacon's thermometer sensor.
 *
 * Beacons are basically calibrated out of the box, but additional manual calibration is recommended in order to minimize measurement error. When the sensor is not calibrated, measurement error is ±4 ℃. After calibration it's ±2 ℃.
 *
 * To perform calibration you need to keep the beacon at room temperature for a couple of minutes. Use a separate thermometer to read the actual value (in Celsius degrees) and pass it to this method.
 *
 * @param temperature The reference temperature in Celsius degrees.
 * @param completion A block that is called when the calibration has been completed.
 *
 * The completion block receives the following parameters:
 *
 * - NSNumber *value - The current temperature in Celsius degrees, after the calibration.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)calibrateTemperatureWithReferenceTemperature:(NSNumber *)temperature
                                          completion:(ESTNumberCompletionBlock)completion;

/**
 * Retrieves the number of times the beacon has been in motion since the last resetAccelerometerCountWithCompletion:.
 *
 * @param completion A block that is called when the counter has been retrieved.
 *
 * The completion block receives the following parameters:
 *
 * - NSNumber *value - The value of the counter.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)readAccelerometerCountWithCompletion:(ESTNumberCompletionBlock)completion;

/**
 * Resets the counter - number of times the beacon has been in motion since the last reset.
 *
 * @param completion A block that is called when the counter has been reset.
 *
 * The completion block receives the following parameters:
 *
 * - NSNumber *value - The new value of the counter.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)resetAccelerometerCountWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

#pragma mark Modifying Configuration Settings
///--------------------------------------------------------------------
/// @name Modifying Configuration Settings (must be connected)
///--------------------------------------------------------------------

/**
 * Sets the name of the beacon.
 *
 * @param name The new name of the beacon.
 * @param completion A block that is called when the new name has been set.
 *
 * The completion block receives the following parameters:
 *
 * - NSString *value - The new name of the beacon.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)writeName:(NSString *)name completion:(ESTStringCompletionBlock)completion;

/**
 * Sets the proximityUUID.
 *
 * @param pUUID The new proximityUUID.
 * @param completion A block that is called when the new proximityUUID has been set.
 *
 * The completion block receives the following parameters:
 *
 * - NSString *value - The new proximityUUID.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 *
 * @warning If you change the proximityUUID, you might want to consider changing the motionProximityUUID as well. If you don't, the beacon will broadcast two different proximityUUIDs depending on whether its in motion or not!@
 */
- (void)writeProximityUUID:(NSString *)pUUID completion:(ESTStringCompletionBlock)completion;

/**
 * Sets the major value.
 *
 * @param major The new major value.
 * @param completion A block that is called when the new major value has been set.
 *
 * The completion block receives the following parameters:
 *
 * - unsigned short value - The new major value.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)writeMajor:(unsigned short)major completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the minor value.
 *
 * @param minor The new minor value.
 * @param completion A block that is called when the new minor value has been set.
 *
 * The completion block receives the following parameters:
 *
 * - unsigned short value - The new minor value.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)writeMinor:(unsigned short)minor completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the advertising interval, i.e. advInterval.
 *
 * @param interval The new advInterval in miliseconds. The value must be in range from 100 to 2000.
 * @param completion A block that is called when the new advInterval has been set.
 *
 * The completion block receives the following parameters:
 *
 * - unsigned short value - The new advInterval.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)writeAdvInterval:(unsigned short)interval completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the broadcasting power.
 *
 * @param power The new broadcasting power. Must be one of the ESTBeaconPower values.
 * @param completion A block that is called when the new broadcasting power has been set.
 *
 * The completion block receives the following parameters:
 *
 * - ESTBeaconPower value - The new broadcasting power.
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)writePower:(ESTBeaconPower)power completion:(ESTPowerCompletionBlock)completion;

/**
 * Resets the beacon's major, minor, proximityUUID, broadcasting power and advInterval to factory settings.
 *
 * @param completion A block that is called when the settings have been reset.
 *
 * The completion block receives the following parameters:
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 *
 * @warning This method does not reset the motionProximityUUID. You can reset it yourself to the default value of ESTIMOTE_PROXIMITY_UUID using the writeMotionProximityUUID:completion: method.
 */
- (void)resetToFactorySettingsWithCompletion:(ESTCompletionBlock)completion;

/**
 * Enables or disables the accelerometer.
 *
 * @param enable YES to enable, NO to disable the accelerometer.
 * @param completion A block that is called when the accelerometer has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - BOOL value - YES if the accelerometer has been enabled, NO if the accelerometer has been disabled.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 *
 * @since Estimote OS A2.1
 *
 * @see isAccelerometerAvailable
 * @see isAccelerometerEditAvailable
 */
- (void)enableAccelerometer:(BOOL)enable
                 completion:(ESTBoolCompletionBlock)completion;


/**
 * Enables or disables the motion UUID.
 *
 * @param enable YES to enable, NO to disable the motion UUID.
 * @param completion A block that is called when the motion UUID has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - BOOL value - YES if the motion UUID has been enabled, NO if the motion UUID has been disabled.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 *
 * @since Estimote OS A2.1
 *
 * @see isAccelerometerAvailable
 * @see isAccelerometerEditAvailable
 */

- (void)enableMotionUUID:(BOOL)enable
              completion:(ESTBoolCompletionBlock)completion;

/**
 * Enables or disables the basicPowerMode.
 *
 * @param enable YES to enable, NO to disable the Basic Power Mode.
 * @param completion A block that is called when the Basic Power Mode has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - BOOL value - YES if the Basic Power Mode has been enabled, NO if the Basic Power Mode has been disabled.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)enableBasicPowerMode:(BOOL)enable
                  completion:(ESTBoolCompletionBlock)completion;

/**
 * Enables or disables the smartPowerMode.
 *
 * @param enable YES to enable, NO to disable the Smart Power Mode.
 * @param completion A block that is called when the Smart Power Mode has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - BOOL value - YES if the Smart Power Mode has been enabled, NO if the Smart Power Mode has been disabled.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)enableSmartPowerMode:(BOOL)enable
                  completion:(ESTBoolCompletionBlock)completion;

/**
 *  Enables Estimote Secure UUID.
 *
 *  @param enable     Yes to enable, No to disable Estimote Secure UUID.
 *  @param completion Block with operation result.
 */

- (void)enableEstimoteSecureUUID:(BOOL)enable
                      completion:(ESTBoolCompletionBlock)completion;

#pragma mark Updating Firmware
///--------------------------------------------------------------------
/// @name Updating Firmware (must be connected)
///--------------------------------------------------------------------

/**
 * Checks if an updated firmware is available.
 *
 * The result of the check is available as a ESTBeaconFirmwareInfoVO structure in the completion block and has the following properties:
 *
 * - BOOL isUpdateAvailable - YES if an update is available, NO if there's no update available. In the latter case, all the other properties of this structure will be nil.
 *
 * - NSString *hardwareVersion - The version of hardware this firmware update is dedicated for.
 *
 * - NSString *firmwareVersion - The version of the firmware available for update.
 *
 * - NSString *changelog - Changes introduced in the new version.
 *
 * @param completion A block that is called when the check has been completed.
 *
 * The completion block receives the following parameters:
 *
 * - ESTBeaconFirmwareInfoVO value - Indicates whether an update is available. If so, it also holds additional information about the update.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)checkFirmwareUpdateWithCompletion:(ESTFirmwareInfoCompletionBlock)completion;

/**
 * Updates the beacon's firmware.
 *
 * @param progress A block that is called throughout the update process to report on the progress.
 *
 * The progress block receives the following parameters:
 *
 * - NSInteger value - A percentage value (0-100) indicating the update progress.
 *
 * - NSString *description - A description of the current stage of the update.
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 *
 * @param completion A block that is called when the update has been completed.
 *
 * The completion block receives the following parameters:
 *
 * - NSError *error - If an error occurred, this error object describes the error. If the operation completed successfully, the value is nil.
 */
- (void)updateFirmwareWithProgress:(ESTProgressBlock)progress
                       completion:(ESTCompletionBlock)completion;

#pragma mark Comparing Beacons for Equality
///--------------------------------------------------------------------
/// @name Comparing Beacons for Equality
///--------------------------------------------------------------------

/**
 * Returns a Boolean value that indicates whether a given beacon is equal to the receiver.
 *
 * The comparison is based on macAddress if available. If not, the comparison is based on proximityUUID, major and minor.
 *
 * @warning You can only compare two ESTBeacon instances if both were discovered using a CoreLocation or a CoreBluetooth based scan. Trying to compare two ESTBeacon instances when one was discovered by a CoreLocation scan and the other one by a CoreBluetooth based scan will yield an undefined result.
 *
 *  This is because an ESTBeacon discovered using a CoreLocation based scan has its proximityUUID, major and minor populated, but not the macAddress. A beacon discovered by a CoreBluetooth based scan will in turn have its macAddress populated, but not the proximityUUID.
 */
- (BOOL)isEqualToBeacon:(ESTBeacon *)beacon;

#pragma mark Utility

/**
 * Returns ESTBeaconVO object from ESTBeacon, so it would be easier to compare beacons with already fetched from the cloud.
 */
- (ESTBeaconVO *)valueObject;

@end
