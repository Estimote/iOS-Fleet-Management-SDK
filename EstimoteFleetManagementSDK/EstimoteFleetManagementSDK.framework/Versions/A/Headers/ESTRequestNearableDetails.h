//
//  ESTRequestNearableDetails.h
//  EstimoteSDK
//
//  Created by Estimote Polska on 8/20/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please use ESTRequestGetDeviceDetails instead.")
@interface ESTRequestNearableDetails : ESTRequestGetJSON

@property (nonatomic, strong, readonly) NSString *nearableUID; // mac or proximityUUID:major:minor

- (instancetype)initWithNearableUID:(NSString *)nearableUID;

@end
