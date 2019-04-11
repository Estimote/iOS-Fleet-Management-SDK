//
// Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingProtocol.h"

typedef void(^ESTSettingSetAuthLevelCompletionBlock)(NSError *error);


@interface ESTSettingSetAuthorizationLevel : NSObject <ESTDeviceSettingProtocol>

- (instancetype)initWithCompletion:(ESTSettingSetAuthLevelCompletionBlock)completion;

@end
