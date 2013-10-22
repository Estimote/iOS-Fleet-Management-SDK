//
//  ESTBeacon.h
//  EstimoteSDK7
//
//  Version : 1.0.0
//  Created by Marcin Klimek on 9/19/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"

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
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconConnectionDidFail:(NSError*)error;

/**
 * Delegate method that indicates success in beacon connection.
 *
 * @return void
 */
- (void)beaconConnectionDidSucceeded;

/**
 * Delegate method that beacon did disconnect with device.
 *
  * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconDidDisconnectWithError:(NSError*)error;

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
@property (nonatomic, strong)   NSNumber*               frequency;
@property (nonatomic, strong)   NSNumber*               baterryLevel;

@property (nonatomic, strong)   NSString*               hardwareVersion;
@property (nonatomic, strong)   NSString*               firmwareVersion;

/////////////////////////////////////////////////////
// core location properties

@property (nonatomic, strong)   CLBeacon*               ibeacon;


@property (nonatomic, readonly)   BOOL                  isConnected;


/**
 * Connect to particular beacon using bluetooth.
 * Connection is required to change values like
 * Major, Minor, Power and Frequency.
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
- (void)readBeaconMajorWithCompletion:(ESTUnsignedCompletionBlock)completion;

/**
 * Read minor of connected beacon (Previous connection
 * required)
 *
 * @param completion block with minor value as param
 *
 * @return void
 */
- (void)readBeaconMinorWithCompletion:(ESTUnsignedCompletionBlock)completion;

/**
 * Read frequency of connected beacon (Previous connection
 * required)
 *
 * @param completion block with frequency value as param
 *
 * @return void
 */
- (void)readBeaconFrequencyWithCompletion:(ESTUnsignedCompletionBlock)completion;


/**
 * Read power of connected beacon (Previous connection
 * required)
 *
 * @param completion block with power value as param
 *
 * @return float value of beacon power
 */
- (void)readBeaconPowerWithCompletion:(ESTUnsignedCompletionBlock)completion;

/**
 * Read battery level of connected beacon (Previous connection
 * required)
 *
 * @param completion block with battery level value as param
 *
 * @return void
 */
- (void)readBeaconBatteryWithCompletion:(ESTUnsignedCompletionBlock)completion;

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
- (void)writeBeaconMajor:(short)major withCompletion:(ESTUnsignedCompletionBlock)completion;

/**
 * Writes minor param to bluetooth connected beacon.
 *
 * @param minor minor beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMinor:(short)minor withCompletion:(ESTUnsignedCompletionBlock)completion;

/**
 * Writes frequency of bluetooth connected beacon.
 *
 * @param frequency advertising beacon frequency
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconFrequency:(short)frequency withCompletion:(ESTUnsignedCompletionBlock)completion;


/**
 * Writes power of bluetooth connected beacon.
 *
 * @param power advertising beacon power
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconPower:(ESTBeaconPower)power withCompletion:(ESTUnsignedCompletionBlock)completion;


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
