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
 Designated initializer.

 @param credentials Cloud Credentials object. You can use `+[ESTCloudCredentials sharedInstance]` to get it.
 @param errorBlock Cloud Credentials object. You can use `+[ESTCloudCredentials sharedInstance]` to get it.
 */
- (instancetype)initWithCredentials:(ESTCloudCredentials *)credentials
                         errorBlock:(void (^)(NSError *error))errorBlock;

/**
 Start observing and calling callbacks on provided proximity zones:
 - request device details for all user's devices from Estimote Cloud,
 - start Estimote Monitoring at registered ranges,
 - call registered enter/exit/change blocks when proximity event occurs.

 @param zones Zones to be observed
 */
- (void)startObservingZones:(NSArray<ESTProximityZone *> *)zones;

@end

NS_ASSUME_NONNULL_END
