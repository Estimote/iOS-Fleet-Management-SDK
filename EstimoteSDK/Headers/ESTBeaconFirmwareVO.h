//
//  ESTBeaconFirmwareVO.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 12/12/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ESTBeaconFirmwareVO : NSObject

@property (nonatomic, strong) NSString* hardwareVersion;
@property (nonatomic, strong) NSString* firmwareVersion;
@property (nonatomic, strong) NSString* firmwareUrl;
@property (nonatomic, strong) NSString* firmwareCleanerUrl;

@end
