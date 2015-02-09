//
//  ESTBeaconFirmwareVO.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Created by Marcin Klimek on 12/12/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTFirmwareInfoVO.h"

@interface ESTBeaconFirmwareVO : ESTFirmwareInfoVO

@property (nonatomic, strong) NSString* firmwareUrl;
@property (nonatomic, strong) NSString* firmwareCleanerUrl;

@end
