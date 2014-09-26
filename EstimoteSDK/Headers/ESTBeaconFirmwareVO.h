//
//  ESTBeaconFirmwareVO.h
//  EstimoteSDK
//
//  Version: 2.1.5
//  Created by Marcin Klimek on 12/12/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconFirmwareInfoVO.h"

@interface ESTBeaconFirmwareVO : ESTBeaconFirmwareInfoVO

@property (nonatomic, strong) NSString* firmwareUrl;
@property (nonatomic, strong) NSString* firmwareCleanerUrl;

@end
