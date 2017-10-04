//
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
#import "ESTDefinitions.h"

@class ESTDeviceLocationBeacon;
@class ESTPeripheralTypeUtility;
@class ESTMeshNearablesScanReportVO;

/**
 Completion block.

 @param scanReportVO Value object of scan report.
 @param error Error, if reading scan report failed.
 */
typedef void(^ESTReportScanVOCompletionBlock)(ESTMeshNearablesScanReportVO * _Nullable scanReportVO, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

/**
 Handles reading Bluetooth scan reports from device.
 */
@interface ESTMeshScanReportsManager : NSObject

/**
 Not supported.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not supported.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Reads scan report from device.

 @param completion Completion block containing `ESTMeshNearablesScanReportVO` object, if reading was successful.
 */
- (void)readScanReportWithCompletion:(ESTReportScanVOCompletionBlock)completion;

@end

@interface ESTMeshScanReportsManager (Internal)

/**
 Designated initializer.
 
 @param peripheral Device's peripheral, which will handle reading scan report settings.
 @return Initialized object.
 */
- (instancetype)initWithPeripheral:(ESTPeripheralTypeUtility *)peripheral;

@end

NS_ASSUME_NONNULL_END
