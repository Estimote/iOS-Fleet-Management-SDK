//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2017 Estimote. All rights reserved.

#import "ESTRequestGetJSON.h"

#define ESTRequestV3GetFirmwaresDomain @"ESTRequestV3GetFirmwares"

/**
 *  Describes errors related to `ESTRequestV3GetFirmwares`.
 */
typedef NS_ENUM(NSInteger, EStrequestV3GetFirmwresError) {
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
