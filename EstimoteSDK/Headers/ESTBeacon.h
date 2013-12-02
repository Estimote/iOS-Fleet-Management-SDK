//
//  ESTBeacon.h
//  EstimoteSDK
//
//  Version : 1.1.0
//  Created by Marcin Klimek on 9/19/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"

@class ESTBeacon;

////////////////////////////////////////////////////////////////////
// Estimote beacon delegate protocol


/**
 
 ESTBeaconDelegate defines beacon connection delegate mathods. Connection is asynchronous operation so you need to be prepared that eg. beaconDidDisconnectWith: method can be invoked without previous action.
 
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
- (void)beaconDidDisconnect:(ESTBeacon*)beacon withError:(NSError*)error;

@end


////////////////////////////////////////////////////////////////////
// Interface definition

/**
 
 The ESTBeacon class represents a beacon that was encountered during region monitoring. You do not create instances of this class directly. The ESTBeaconManager object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon was encountered.
 
 
ESTBeacon class contains basic Apple CLBeacon object reference as well as some additional functionality. It allows to  connect with Estimote beacon to read / write its characteristics.
 
 */

@interface ESTBeacon : NSObject

@property (nonatomic)           ESTBeaconFirmwareState  firmwareState;
@property (nonatomic)           id <ESTBeaconDelegate>  delegate;

/////////////////////////////////////////////////////
// bluetooth beacon available when used with
// startEstimoteBeaconsDiscoveryForRegion:

@property (nonatomic, strong)   CBPeripheral*           peripheral;
@property (nonatomic, strong)   NSString*               macAddress;
@property (nonatomic, strong)   NSNumber*               measuredPower;
@property (nonatomic, strong)   NSNumber*               major;
@property (nonatomic, strong)   NSNumber*               minor;
@property (nonatomic, strong)   NSNumber*               rssi;

/////////////////////////////////////////////////////
// properties filled when read characteristic

@property (nonatomic, strong)   NSNumber*               power;
@property (nonatomic, strong)   NSNumber*               advInterval;
@property (nonatomic, strong)   NSNumber*               batteryLevel;

@property (nonatomic, strong)   NSString*               hardwareVersion;
@property (nonatomic, strong)   NSString*               firmwareVersion;

/////////////////////////////////////////////////////
// core location properties

@property (nonatomic, strong)   CLBeacon*               ibeacon;


@property (nonatomic, readonly)   BOOL                  isConnected;


/**
 * Connect to particular beacon using bluetooth.
 * Connection is required to change values like
 * Major, Minor, Power and Advertising interval.
 *
 * @return void
 */
-(void)connectToBeacon;

/**
 * Disconnect device with particular beacon
 *
 * @return void
 */
-(void)disconnectBeacon;

/**
 * Read major of connected beacon (Previous connection
 * required)
 *
 * @param completion block with major value as param
 *
 * @return void
 */
- (void)readBeaconMajorWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Read minor of connected beacon (Previous connection
 * required)
 *
 * @param completion block with minor value as param
 *
 * @return void
 */
- (void)readBeaconMinorWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Read advertising interval of connected beacon (Previous connection
 * required)
 *
 * @param completion block with advertising interval value as param
 *
 * @return void
 */
- (void)readBeaconAdvIntervalWithCompletion:(ESTUnsignedShortCompletionBlock)completion;


/**
 * Read power of connected beacon (Previous connection
 * required)
 *
 * @param completion block with power value as param
 *
 * @return float value of beacon power
 */
- (void)readBeaconPowerWithCompletion:(ESTPowerCompletionBlock)completion;

/**
 * Read battery level of connected beacon (Previous connection
 * required)
 *
 * @param completion block with battery level value as param
 *
 * @return void
 */
- (void)readBeaconBatteryWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Read firmware version of connected beacon (Previous connection
 * required)
 *
 * @param completion block with firmware version value as param
 *
 * @return void
 */
- (void)readBeaconFirmwareVersionWithCompletion:(ESTStringCompletionBlock)completion;

/**
 * Read hardware version of connected beacon (Previous connection
 * required)
 *
 * @param completion block with hardware version value as param
 *
 * @return void
 */
- (void)readBeaconHardwareVersionWithCompletion:(ESTStringCompletionBlock)completion;


/**
 * Writes major param to bluetooth connected beacon.
 *
 * @param major major beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMajor:(unsigned short)major withCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes minor param to bluetooth connected beacon.
 *
 * @param minor minor beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMinor:(unsigned short)minor withCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes advertising interval (in milisec) of connected beacon.
 *
 * @param advertising interval of beacon (50 - 2000 ms)
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconAdvInterval:(unsigned short)interval withCompletion:(ESTUnsignedShortCompletionBlock)completion;


/**
 * Writes power of bluetooth connected beacon.
 *
 * @param power advertising beacon power
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconPower:(ESTBeaconPower)power withCompletion:(ESTPowerCompletionBlock)completion;


/**
 * Verifies if new firmware version is available for download
 * without any additional action. Internet connection
 * is required to pass this process.
 *
 * @param completion Block handling operation completion
 *
 * @return void
 */
-(void)checkFirmwareUpdateWithCompletion:(ESTFirmwareUpdateCompletionBlock)completion;

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
-(void)updateBeaconFirmwareWithProgress:(ESTStringCompletionBlock)progress
                          andCompletion:(ESTCompletionBlock)completion;

@end
