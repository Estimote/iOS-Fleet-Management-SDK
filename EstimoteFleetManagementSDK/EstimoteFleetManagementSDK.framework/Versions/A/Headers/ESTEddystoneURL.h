//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTEddystone.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ESTEddystoneURL represents Eddystone URL packet coming from `ESTEddystoneManager` class.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTEddystoneURL : ESTEddystone

/**
 *  URL address advertised by the beacon device
 *  packet type is set to ESTBeaconPacketTypeEddystoneURL
 */
@property (nonatomic, strong, readonly) NSString *_Nullable url;

/**
 *  Initialized ESTEddystoneURL object with url.
 *
 *  @param url URL broadcasted by the device.
 */
- (instancetype)initWithURL:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
