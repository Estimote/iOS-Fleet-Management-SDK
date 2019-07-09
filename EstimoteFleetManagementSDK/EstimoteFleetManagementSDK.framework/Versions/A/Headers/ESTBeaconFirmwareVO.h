//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTFirmwareInfoVO.h"

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTBeaconFirmwareVO : ESTFirmwareInfoVO

@property (nonatomic, strong) NSString *firmwareUrl;
@property (nonatomic, strong) NSString *firmwareCleanerUrl;

@end
