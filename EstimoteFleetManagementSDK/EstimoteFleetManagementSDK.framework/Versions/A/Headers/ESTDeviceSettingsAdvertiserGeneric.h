//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents settings structure for generic advertiser.
 */
@interface ESTDeviceSettingsAdvertiserGeneric : ESTDeviceSettingsAdvertiser

/*
 *  Data broadcasted in the bluetooth packet.
 */
@property (nonatomic, strong, readonly) NSString *payload;

@end

NS_ASSUME_NONNULL_END
