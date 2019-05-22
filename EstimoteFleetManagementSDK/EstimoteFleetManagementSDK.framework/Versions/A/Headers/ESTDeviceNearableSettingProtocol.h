//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTDeviceSettingProtocol.h"


@protocol ESTDeviceNearableSettingProtocol <ESTDeviceSettingProtocol>

@required

/**
 *  Size of data sent in nearable setting packet
 *
 *  @return size of data in packet
 */
- (NSInteger)size;

@end
