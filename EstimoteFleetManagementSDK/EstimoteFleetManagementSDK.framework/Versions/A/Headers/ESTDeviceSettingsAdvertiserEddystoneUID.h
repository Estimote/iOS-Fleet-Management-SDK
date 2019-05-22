//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents settings structure for Eddystone UID advertiser.
 */
@interface ESTDeviceSettingsAdvertiserEddystoneUID : ESTDeviceSettingsAdvertiser

/**
 *  Namespace ID broadcasted in Eddystone UID packet.
 */
@property (nonatomic, strong, readonly) NSString *namespaceID;

/**
 *  Instance ID broadcasted in Eddystone UID packet.
 */
@property (nonatomic, strong, readonly) NSString *instanceID;

@end

NS_ASSUME_NONNULL_END
