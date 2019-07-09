//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please use ESTRequestGetDeviceOwner instead.")
@interface ESTRequestGetBeaconOwner : ESTRequestGetJSON

@property (nonatomic, strong) NSString *beaconUID; // mac or proximityUUID:major:minor

@end
