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

#import "ESTCloudCredentials.h"
#import "ESTProximityZone.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const ESTProximityObserverErrorDomain;

/**
 Possible errors invoked with Proximity Observer's error block.
 */
typedef NS_ENUM(NSUInteger, ESTProximityObserverError) {
    /* Unknown error probably due to a bug. If you're getting errors with this code please report it on
     * https://forums.estimote.com, using contact@estimote.com or filing an issue on Github. */
    ESTProximityObserverErrorUnknown = 0,

    /* Fetching attachments from Cloud failed. */
    ESTProximityObserverErrorFetchingAttachmentsFailed,

    /* Observed zone doesn't match any attachments fetched from Cloud. */
    ESTProximityObserverErrorNoAttachmentsMatchingZone,

    /* Bluetooth is unsupported on this iOS device. */
    ESTProximityObserverErrorBluetoothUnsupported,

    /* Bluetooth is turned off. */
    ESTProximityObserverErrorBluetoothOff,

    /* Couldn't use motion detection. */
    ESTProximityObserverErrorMotionDetectionFailed,
};

/**
 Observes and reports proximity of Estimote devices. 
 Uses Estimote Monitoring under the hood. Encapsulates it under tag-based beacon identification and callback blocks.
 */
@interface ESTProximityObserver : NSObject

/**
 Init is disabled for this class.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 New is disabled for this class.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Default initializer.
 @param credentials Cloud Credentials object used to authorize requests sent to Estimote Cloud.
 @param errorBlock Block invoked whenever error occurs. The parameter is an NSError object, with
                   domain equal to ESTProximityObserverErrorDomain and code from ESTProximityObserverError enum.
 */
- (instancetype)initWithCredentials:(ESTCloudCredentials *)credentials
                         errorBlock:(void (^)(NSError *error))errorBlock;

/**
 Start observing and calling callbacks on provided proximity zones:
 - request device details for all user's devices from Estimote Cloud,
 - start Estimote Monitoring at registered ranges,
 - call registered enter/exit/change blocks when proximity event occurs.

 Subsequent calls of this method cause overwriting previously observed zones.

 @param zones Zones to be observed
 */
- (void)startObservingZones:(NSArray<ESTProximityZone *> *)zones;

/**
 Stop observing and calling callbacks for all zones that were provided with -startObservingZones:,
 release memory resources allocated for monitoring the zones.

 Subsequent calls of this method (without re-starting observing zones) have the same effect as calling it just once.
 */
- (void)stopObservingZones;

@end

NS_ASSUME_NONNULL_END
