//
//  ESTBeaconConnection.h
//  EstimoteSDK
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconDefinitions.h"

NSString *InventoryErrorDomain = @"com.estimote.sdk.connection";

enum
{
    ESTConnectionInternetConnectionError,
    ESTConnectionIdentifierMissingError,
    ESTConnectionNotAuthorizedError,
    ESTConnectionNotConnectedToReadWrite
};

@class ESTBeaconConnection;

@protocol ESTBeaconConnectionDelegate <NSObject>

@optional

/**
 * Tells the delegate that an attempt to connect to a nearable succeeded and the connection has been established.
 *
 * @param connection The nearable connection object reporting the event.
 */
- (void)beaconConnectionDidSucceeded:(ESTBeaconConnection *)connection;

/**
 * Tells the delegate that an attempt to connect to a nearable has failed.
 *
 * @param connection The nearable connection object reporting the event.
 * @param error An error object containing the error code that indicates why connection failed.
 */
- (void)beaconConnection:(ESTBeaconConnection *)connection didFailWithError:(NSError *)error;

/**
 * Tells the delegate that a previously connected nearable has disconnected.
 *
 * @param connection The nearable connection object reporting the event.
 * @param error An error object containing the error code that indicates why the beacon disconnected.
 */
- (void)beaconConnection:(ESTBeaconConnection *)connection didDisconnectWithError:(NSError *)error;


@end

@interface ESTBeaconConnection : NSObject

/**
 *  Delegate object receiving callbacks.
 */
@property (nonatomic, assign) id<ESTBeaconConnectionDelegate> delegate;

/**
 * Identifier of the device that you aim to connect. 
 * Based on the method you used to initialize it may contain:
 * - Device Mac address
 * - Device iBeacon properties formated as follows: ProximityUUUID:Major:Minor
 *
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 * The connection status between the user device and the beacon.
 *
 * @see ESTConnectionStatus
 */
@property (readonly, nonatomic) ESTConnectionStatus connectionStatus;


/**
 *  Static method initializing connection object with Estimote beacon
 *
 *  @param proximityUUID discovered beacons Proximity UUID
 *  @param major discovered beacons Major
 *  @param minor discovered beacons Minor
 *  @param delegate delegate reference
 *
 *  @return nearable connection object
 */
+ (instancetype)connectionWithProximityUUID:(NSUUID *)proximityUUID
                                      major:(CLBeaconMajorValue)major
                                      minor:(CLBeaconMinorValue)minor
                              delegate:(id<ESTBeaconConnectionDelegate>)delegate;

/**
 *  Static method initializing connection object with Estimote beacon
 *
 *  @param macAddress discovered beacon object MAC address
 *  @param delegate delegate reference
 *
 *  @return beacon connection object
 */
+ (instancetype)connectionWithMacAddress:(NSString *)macAddress
                                delegate:(id<ESTBeaconConnectionDelegate>)delegate;

/**
 *  Method initializing connection object with Estimote beacon with
 *  delegate object support
 *
 *  @param proximityUUID discovered beacons Proximity UUID
 *  @param major discovered beacons Major
 *  @param minor discovered beacons Minor
 *  @param delegate delegate to handle callbacks
 *  @param startImmediately indicates if created object should start connection immediately
 *
 *  @return beacon connection object
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor
                             delegate:(id<ESTBeaconConnectionDelegate>)delegate
                     startImmediately:(BOOL)startImmediately;

/**
 *  Method initializing connection object with Estimote beacon with
 *  delegate object support
 *
 *  @param beacon discovered beacon
 *  @param delegate delegate to handle callbacks
 *  @param startImmediately indicates if created object should start connection immediately
 *
 *  @return beacon connection object
 */
- (instancetype)initWithBeacon:(CLBeacon *)beacon
                      delegate:(id<ESTBeaconConnectionDelegate>)delegate
              startImmediately:(BOOL)startImmediately;

/**
 *  Method initializing connection object with beacon with
 *  delegate object support
 *
 *  @param macAddress discovered beacon object MAC address
 *  @param delegate delegate to handle callbacks
 *  @param startImmediately indicates if created object should start connection immediately
 *
 *  @return beacon connection object
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress
                          delegate:(id<ESTBeaconConnectionDelegate>)delegate
                  startImmediately:(BOOL)startImmediately;


#pragma mark Connection handling

/**
 *  Initiates connection procedure
 */
- (void)startConnection;

/**
 *  Cancels connection procedure
 */
- (void)cancelConnection;


#pragma mark - Device identification

/**
 * The MAC address of the beacon.
 */
@property (readonly, nonatomic) NSString *macAddress;

/**
 * The name of the beacon.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSString *name;

/**
 * The color of the beacon.
 *
 * This value is stored and retrieved from the Estimote Cloud, which means it might be unavailable under certain circumestances - e.g. no Internet connectivity.
 *
 * @see ESTColor
 */
@property (readonly, nonatomic) ESTColor color;

#pragma mark - iBeacon settings

/**
 * The proximity ID of the beacon.
 *
 * @see writeProximityUUID:completion:
 */
@property (readonly, nonatomic) NSUUID *proximityUUID;

/**
 * The proximity ID of the beacon when it's in motion.
 *
 * This default to the same value as the `<proximityUUID>`. Setting it to a different value enables you to detect whether a beacon is in motion or not without a need to connect to the beacon. This can be achieved in two ways:
 *
 * 1. When ranging beacons - if the beacon is in motion, the `proximityUUID` property will be equal to the `motionProximityUUID`. Note that the `motionProximityUUID` property is not available unless connected to the beacon, so you need to know its value in advance.
 *
 * 2. When monitoring regions - you can have two separate regions, one with the regular `proximityUUID` and one with the `motionProximityUUID`. Enter and exit notifications will then correspond to the beacon starting and stopping to move.
 *
 * @warning This feature is disabled by default. The option to enable it will be made available in an upcoming update to the SDK.
 *
 * @since Estimote OS 2.0
 *
 * @see writeMotionProximityUUID:completion:
 */
@property (readonly, nonatomic) NSUUID *motionProximityUUID;

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
 * The power of the beacon's radio signal in dBm.
 *
 * This is a `char` value, so the proper way to retrieve it is `[beacon.power charValue]`.
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

#pragma mark - Hardware and software information

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

#pragma mark - Power management

/**
 * The battery charge level for the beacon.
 *
 * Battery level ranges from 0 (fully discharged) to 100 (fully charged).
 */
@property (readonly, nonatomic) NSNumber *batteryLevel;

/**
 * The battery model.
 *
 * @see ESTBeaconBatteryType
 */
@property (readonly, nonatomic) ESTBeaconBatteryType batteryType;

/**
 *    Remaining lifetime in days, based on current battery level, advertising interval and broadcasting power values
 */
@property (readonly, nonatomic) NSNumber *remainingLifetime;

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



#pragma mark - Sensors handling

/**
 * The ambient temperature of the beacon (in Celsius).
 *
 */
@property (readonly, nonatomic) NSNumber *temperature;

/**
 * A flag indicating which type of broadcasting is enabled
 *
 * @since Estimote OS A3.0.0
 *
 * @see setConditionalBroadcastingType:completion:
 */
@property (readonly, nonatomic) ESTConditionalBroadcastingType conditionalBroadcasting;

/**
 * A flag indicating if accelerometer is enabled.
 *
 * @since Estimote OS A2.1
 *
 * @see enableAccelerometer:completion:
 */
@property (readonly, nonatomic) BOOL motionDetectionEnabled;

#pragma mark - Writing methods

/**
 * Sets the `<name>` of the beacon.
 *
 * @param name The new name of the beacon.
 * @param completion A block that is called when the new name has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `NSString *value` - The new name of the beacon.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeName:(NSString *)name completion:(ESTStringCompletionBlock)completion;

/**
 * Sets the `<proximityUUID>`.
 *
 * @param pUUID The new `proximityUUID`.
 * @param completion A block that is called when the new `proximityUUID` has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `NSString *value` - The new `proximityUUID`.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @warning If you change the `proximityUUID`, you might want to consider changing the `<motionProximityUUID>` as well. If you don't, the beacon will broadcast two different `proximityUUIDs` depending on whether its in motion or not!@
 */
- (void)writeProximityUUID:(NSString *)pUUID completion:(ESTStringCompletionBlock)completion;

/**
 * Sets the `<major>` value.
 *
 * @param major The new `major` value.
 * @param completion A block that is called when the new `major` value has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `unsigned short value` - The new `major` value.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeMajor:(unsigned short)major completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the `<minor>` value.
 *
 * @param minor The new `minor` value.
 * @param completion A block that is called when the new `minor` value has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `unsigned short value` - The new `minor` value.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeMinor:(unsigned short)minor completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the advertising interval, i.e. `<advInterval>`.
 *
 * @param interval The new `advInterval` in miliseconds. The value must be in range from 100 to 2000.
 * @param completion A block that is called when the new `advInterval` has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `unsigned short value` - The new `advInterval`.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeAdvInterval:(unsigned short)interval completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the broadcasting `<power>`.
 *
 * @param power The new broadcasting `power`. Must be one of the <ESTBeaconPower> values.
 * @param completion A block that is called when the new broadcasting power has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `ESTBeaconPower value` - The new broadcasting `power`.
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writePower:(ESTBeaconPower)power completion:(ESTPowerCompletionBlock)completion;

#pragma mark - Reset to factory

/**
 * Resets the beacon's `<major>`, `<minor>`, `<proximityUUID>`, broadcasting `<power>` and `<advInterval>` to factory settings.
 *
 * @param completion A block that is called when the settings have been reset.
 *
 * The completion block receives the following parameters:
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @warning This method does not reset the `<motionProximityUUID>`. You can reset it yourself to the default value of `ESTIMOTE_PROXIMITY_UUID` using the `<writeMotionProximityUUID:completion:>` method.
 */
- (void)resetToFactorySettingsWithCompletion:(ESTCompletionBlock)completion;

@end
