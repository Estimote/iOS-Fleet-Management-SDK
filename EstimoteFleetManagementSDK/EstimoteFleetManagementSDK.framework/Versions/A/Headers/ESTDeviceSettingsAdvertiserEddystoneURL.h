//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents settings structure for Eddystone URL advertiser.
 */
@interface ESTDeviceSettingsAdvertiserEddystoneURL : ESTDeviceSettingsAdvertiser

/**
 *  URL address broadcasted in Eddystone URL packet.
 */
@property (nonatomic, strong, readonly) NSString *url;

@end

NS_ASSUME_NONNULL_END
