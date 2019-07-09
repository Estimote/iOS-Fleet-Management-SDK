//
//  EstimoteSDK
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "ESTRequestGetJSON.h"


/**
 Downloads firmware's details for beacons and nearables.
 */
@interface ESTRequestFirmwareV4 : ESTRequestGetJSON

- (id)init __attribute__((unavailable("Must use initWithPublicID: instead.")));

+ (id)new __attribute__((unavailable("Must use initWithPublicID: instead.")));

- (instancetype)initWithPublicID:(NSString *)publicID;

@end
