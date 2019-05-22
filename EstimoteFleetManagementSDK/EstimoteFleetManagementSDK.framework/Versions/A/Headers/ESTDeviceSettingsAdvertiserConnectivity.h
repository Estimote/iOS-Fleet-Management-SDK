//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTDeviceSettingsAdvertiserConnectivity
 */
@interface ESTDeviceSettingsAdvertiserConnectivity : ESTDeviceSettingsAdvertiser

/**
 *  Indicates if Shake To Configure mode is enabled;
 */
@property (nonatomic, readonly) NSNumber *shakeToConnectEnabled;

@end

NS_ASSUME_NONNULL_END
