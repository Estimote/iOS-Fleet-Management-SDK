//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTNearableCloudSettingsVO.h"
#import "ESTBaseVO.h"

DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0. Please use ESTDeviceDetails instead.")
@interface ESTNearableCloudVO : ESTBaseVO

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *color;
@property (nonatomic, strong) NSNumber *type;
@property (nonatomic, strong) ESTNearableCloudSettingsVO *settings;

- (instancetype)initWithCloudData:(NSDictionary *)data;

@end
