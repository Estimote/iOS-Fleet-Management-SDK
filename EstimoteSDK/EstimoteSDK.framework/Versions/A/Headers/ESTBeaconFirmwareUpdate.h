//
//  ESTBeaconFirmwareUpdate.h
//  EstimoteSDK
//
//  Version: 3.0.0
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconDefinitions.h"

@interface ESTBeaconFirmwareUpdate : NSObject

/**
 *  Initialize firmware update obejct with iBeacon object representing Estimote Device.
 *
 *  @param beacon iBeacon object (Proximity UUID, Major, Minor are required)
 *
 *  @return initialized ESTBeaconFirmwareUpdate object
 */
- (id)initWithBeacon:(CLBeacon *)beacon;

/**
 *  Initialize firmware update obejct with Estimote Beacon Mac Address.
 *  Mac address can be found using ESTUtilityManager object.
 *
 *  @param macAddress mac address of the device
 *
 *  @return initialized ESTBeaconFirmwareUpdate object
 */
- (id)initWithMacAddress:(NSString *)macAddress;


#pragma mark Updating Firmware
///--------------------------------------------------------------------
/// @name Updating Firmware (must be connected)
///--------------------------------------------------------------------

/**
 * Updates the beacon's firmware.
 *
 * @param progress A block that is called throughout the update process to report on the progress.
 *
 * The progress block receives the following parameters:
 *
 * - `NSInteger value` - A percentage value (0-100) indicating the update progress.
 *
 * - `NSString *description` - A description of the current stage of the update.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @param completion A block that is called when the update has been completed.
 *
 * The completion block receives the following parameters:
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)updateFirmwareWithProgress:(ESTProgressBlock)progress
                        completion:(ESTCompletionBlock)completion;

@end
