//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTMeshNearablesScanResultVO.h"

/**
 ESTMeshNearablesScanReportVO represents full report of mesh scan report
 consisting of single scan results delivered from beacons scanning
 for stickers. Single record is represented by `ESTMeshScanResultVO`.
 */
@interface ESTMeshNearablesScanReportVO : NSObject

/**
 Date of collecting the scan report.
 */
@property(nonatomic) NSDate *collectedAt;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initialiser convering provided data (taken from device)
 into value objects.

 @param data Scan report data taken from the device.
 @return Initialised report object.
 */
- (instancetype)initWithData:(NSArray<NSData *> *)data collectedAt:(NSDate *)collectedAt NS_DESIGNATED_INITIALIZER;

/**
 Returns array of scan results for given device identifier.
 Note these identifiers are eight characters long!

 @param deviceIdentifier Identifier of the device.
 @return Array of ESTMeshScanResultVO objects.
 */
- (NSArray<ESTMeshNearablesScanResultVO *> *)scanResultsForShortDeviceIdentifier:(NSString *)deviceIdentifier;

/**
 Cloud dictionary of scan report. See `ESTRequestSetScanReport` for usage.

 @return An array of NSString objects.
 */
- (NSDictionary *)cloudDictionary;

@end
