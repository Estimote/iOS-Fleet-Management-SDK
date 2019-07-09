//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import "ESTRequestGetJSON.h"

#define ESTRequestV3GetFirmwaresDomain @"ESTRequestV3GetFirmwares"

/**
 *  Describes errors related to `ESTRequestV3GetFirmwares`.
 */
typedef NS_ENUM (NSInteger, EStrequestV3GetFirmwresError) {
    /**
     *  Error for invalid response from Cloud, taht cannot be properly parsed.
     */
    EStrequestV3GetFirmwresErrorIvalidValue = 1
};

/**
 *  Request responsible for fetching dictionary of newest firmwares for each hardware revision.
 */
@interface ESTRequestV3GetFirmwares : ESTRequestGetJSON

@end
