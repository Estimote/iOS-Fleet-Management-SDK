//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTFirmwareInfoVO.h"


@interface ESTBeaconFirmwareVO : ESTFirmwareInfoVO

@property (nonatomic, strong) NSString *firmwareUrl;
@property (nonatomic, strong) NSString *firmwareCleanerUrl;

@end
