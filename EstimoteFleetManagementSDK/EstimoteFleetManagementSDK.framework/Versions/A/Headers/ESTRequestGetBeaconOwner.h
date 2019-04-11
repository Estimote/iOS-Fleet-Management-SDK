//  FleetManagementSDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"


@interface ESTRequestGetBeaconOwner : ESTRequestGetJSON

@property (nonatomic, strong) NSString *beaconUID; // mac or proximityUUID:major:minor

@end
