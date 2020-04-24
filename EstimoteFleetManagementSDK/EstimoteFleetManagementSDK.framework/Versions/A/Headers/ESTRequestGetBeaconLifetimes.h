//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTRequestGetJSON.h"

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please use ESTRequestGetDeviceDetails instead.")
@interface ESTRequestGetBeaconLifetimes : ESTRequestGetJSON

@property (nonatomic) NSString *beaconUID;

@end
