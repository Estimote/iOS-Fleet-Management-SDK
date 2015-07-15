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
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconUpdateConfig.h"
#import "ESTBeaconConnection.h"

typedef NS_ENUM(NSInteger, ESBeaconUpdateInfoStatus)
{
    ESBeaconUpdateInfoStatusIdle,
    ESBeaconUpdateInfoStatusReadyToUpdate,
    ESBeaconUpdateInfoStatusUpdating,
    ESBeaconUpdateInfoStatusUpdateSuccess,
    ESBeaconUpdateInfoStatusUpdateFailed
};

/**
 * The `ESBeaconUpdateInfoDelegate` protocol defines the delegate method used to confirm when `ESBeaconUpdateInfo` is ready to be performed in the operation queue (related bluetooth peripheral was found).
 */

@protocol ESBeaconUpdateInfoDelegate <NSObject>

- (void)beaconUpdateInfoInitialized:(id)beaconUpdateInfo;

@end

/**
 * The `ESBeaconUpdateInfo` class represents all required data for single Estimote beacon bulk update operation. It should be intialized by device Mac Address that should be updated and `<ESBeaconUpdateConfig>` config object that describes how update is going to be performed.
 */

@interface ESTBeaconUpdateInfo : NSObject <NSCoding>

/**
 *  Delegate object described with `ESBeaconUpdateInfoDelegate` protocol.
 */
@property (nonatomic, weak) id<ESBeaconUpdateInfoDelegate> delegate;

/**
 *  Beacon about which this info is for.
 */
@property (nonatomic, strong) ESTBeaconConnection *beaconConnection;

/**
 *  Device mac address about which this info is for.
 */
@property (nonatomic, strong) NSString *macAddress;

/**
 *  Configuration based on which update should be performed.
 */
@property (nonatomic, strong) ESTBeaconUpdateConfig *config;

/**
 *  Current status of beacon update.
 */
@property (nonatomic, assign) ESBeaconUpdateInfoStatus status;

/**
 *  Error object if beacon failed to update.
 */
@property (nonatomic, strong) NSError *error;


/**
 *  Initialize object with beacon that is going to be updated and proper
 *  config file containing description how update should be performed.
 *
 *  @param macAddress   Mac Address of beacon.
 *  @param config       Config description for update.
 *
 *  @return initialized instance of this class
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress
                            config:(ESTBeaconUpdateConfig *)config;

/**
 *  Initialize object with beacon that is going to be updated and proper
 *  config file containing description how update should be performed
 *  with delegate object.
 *
 *  @param macAddress   Mac Address of beacon.
 *  @param config       Config description for update.
 *  @param delegate     Delegate to receive events.
 *
 *  @return initialized instance of this class
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress
                            config:(ESTBeaconUpdateConfig *)config
                          delegate:(id<ESBeaconUpdateInfoDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 *  Scans for peripheral related with the beacon.
 */
- (void)findPeripheralWithTimeout:(NSTimeInterval)timeout;

/**
 *  Allows to update config for the related beacon. Overrides previous settings.
 *
 *  @param config new config object
 */
- (void)updateWithConfig:(ESTBeaconUpdateConfig *)config;

/**
 *  Custom description method of Beacon update information.
 *
 *  @return description string
 */
- (NSString *)description;

@end
