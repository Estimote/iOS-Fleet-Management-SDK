//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTRequestGetJSON.h"
#import "ESTDefinitions.h"
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ESTBeaconDetailsFields)
{
    ESTBeaconDetailsAllFields                        = 1 << 0,
    ESTBeaconDetailsFieldMac                         = 1 << 1,
    ESTBeaconDetailsFieldColor                       = 1 << 2,
    ESTBeaconDetailsFieldName                        = 1 << 3,
    ESTBeaconDetailsFieldGPSLocation                 = 1 << 4,
    ESTBeaconDetailsFieldIndoorLocation              = 1 << 5,
    ESTBeaconDetailsFieldPublicIdentifier            = 1 << 6,
    
    ESTBeaconDetailsAllSettings                      = 1 << 7,
    ESTBeaconDetailsFieldBattery                     = 1 << 8,
    ESTBeaconDetailsFieldPower                       = 1 << 9,
    ESTBeaconDetailsFieldInterval                    = 1 << 10,
    ESTBeaconDetailsFieldHardware                    = 1 << 11,
    ESTBeaconDetailsFieldFirmware                    = 1 << 12,
    ESTBeaconDetailsFieldBasicPowerMode              = 1 << 13,
    ESTBeaconDetailsFieldSmartPowerMode              = 1 << 14,
    ESTBeaconDetailsFieldTimeZone                    = 1 << 15,
    ESTBeaconDetailsFieldSecurity                    = 1 << 16,
    ESTBeaconDetailsFieldMotionDetection             = 1 << 17,
    ESTBeaconDetailsFieldConditionalBroadcasting     = 1 << 18,
    ESTBeaconDetailsFieldBroadcastingScheme          = 1 << 19,
    ESTBeaconDetailsFieldUUIDMajorMinor              = 1 << 20,
    ESTBeaconDetailsFieldEddystoneNamespaceID        = 1 << 21,
    ESTBeaconDetailsFieldEddystoneInstanceID         = 1 << 22
};

typedef void(^ESTRequestGetBeaconsDetailsBlock)(NSArray * _Nullable beaconVOArray, NSError * _Nullable error);


@interface ESTRequestGetBeaconsDetails : ESTRequestGetJSON

/** Array of identifiers of beacons which details should be fetched. 
 * Can be MAC addresses or Eddystone Identifiers or proximityUUID:major:minor strings
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *beaconIdentifiers;
@property (nonatomic, assign, readonly) ESTBeaconDetailsFields fields;

/**
 *  Initialise request with Beacons array.
 *
 *  @param beacons Array of CLBeacon objects
 *
 *  @param fields A mask of fields indicating which beacon parameters you want to fetch
 *
 *  @return instance of request
 */
- (instancetype)initWithBeacons:(NSArray<CLBeacon *> *)beacons andFields:(ESTBeaconDetailsFields)fields;

/**
 *  Initialise request with MAC addresses.
 *
 *  @param macAddresses Array of MAC addresses as NSStrings
 *
 *  @param fields A mask of fields indicating which beacon parameters you want to fetch
 *
 *  @return instance of request
 */
- (instancetype)initWithMacAddresses:(NSArray<NSString *> *)macAddresses andFields:(ESTBeaconDetailsFields)fields;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (Array of beaconVO objects).
 */
- (void)sendRequestWithCompletion:(ESTRequestGetBeaconsDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END
