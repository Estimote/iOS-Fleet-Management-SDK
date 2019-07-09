//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTRequestGetJSON.h"
#import "ESTBeaconVO.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestBeaconDetailsErrorDomain @"ESTRequestBeaconDetailsErrorDomain"

/**
 *  Errors occurring for request.
 */
typedef NS_ENUM (NSInteger, ESTRequestBeaconDetailsError) {
    /**
     *  Error returned when Estimote Cloud failed to find details for beacon with provided ID.
     */
    ESTRequestBeaconDetailsErrorDetailsNotAvailable
};

typedef void (^ESTRequestBeaconDetailsBlock)(ESTBeaconVO *_Nullable beaconVO, NSError *_Nullable error);

/**
 *  ESTRequestBeaconDetails is used to fetch details of single beacon device.
 */

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 3.6.0 Please use ESTRequestGetDeviceDetails instead.")
@interface ESTRequestBeaconDetails : ESTRequestGetJSON

@property (nonatomic, strong, readonly) NSString *beaconUID;

/**
 *  Initialise request with MAC address.
 *
 *  @param macAddress MAC address of device provided as NSString
 *
 *  @return instance of request
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress;

/**
 *  Initialise request with MAC address.
 *
 *  @param beacon Proximity UUID, Major and Minor provided as CLBeacon
 *
 *  @return instance of request
 */
- (instancetype)initWithBeacon:(CLBeacon *)beacon;

/**
 *  Initialise request with Beacon parameters.
 *
 *  @param proximityUUID Beacon's proximity UUID
 *  @param major         Beacon's major
 *  @param minor         Beacon's minor
 *
 *  @return instance of request
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (CLLocation object).
 */
- (void)sendRequestWithCompletion:(ESTRequestBeaconDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END
