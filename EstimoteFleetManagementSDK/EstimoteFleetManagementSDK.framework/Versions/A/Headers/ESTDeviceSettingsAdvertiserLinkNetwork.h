//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents settings structure for Link Network advertiser.
 */
@interface ESTDeviceSettingsAdvertiserLinkNetwork : ESTDeviceSettingsAdvertiser

/**
 *  Link Network domain setting.
 */
@property (nonatomic, strong, readonly) NSString *domain;

/**
 *  Link Network link identifier setting.
 */
@property (nonatomic, strong, readonly) NSNumber *linkID;

/**
 *  Link Network measurement period setting.
 */
@property (nonatomic, strong, readonly) NSNumber *measurementPeriod;



@end

NS_ASSUME_NONNULL_END
