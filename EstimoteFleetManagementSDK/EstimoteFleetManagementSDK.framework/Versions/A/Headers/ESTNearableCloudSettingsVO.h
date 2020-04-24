//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBaseVO.h"

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please refer to ESTDeviceDetails instead.")
@interface ESTNearableCloudSettingsVO : ESTBaseVO

@property (nonatomic, strong) NSString *applicationVersion;
@property (nonatomic, strong) NSString *bootloaderVersion;
@property (nonatomic, strong) NSString *hardwareVersion;

@property (nonatomic, strong) NSNumber *power;
@property (nonatomic, strong) NSNumber *advertisingInterval;

@property (nonatomic, strong) NSNumber *motionOnlyEnabled;

@property (nonatomic, strong) NSNumber *broadcastingScheme;
@property (nonatomic, strong) NSString *eddystoneURL;

- (instancetype)initWithCloudData:(NSDictionary *)data;

@end
