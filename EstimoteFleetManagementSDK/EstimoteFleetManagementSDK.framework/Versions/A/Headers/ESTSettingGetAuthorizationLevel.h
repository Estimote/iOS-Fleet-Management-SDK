//
// Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingProtocol.h"

typedef NS_ENUM(NSInteger, ESTAuthorizationLevel)
{
    ESTAuthorizationLevelNotAuthorized,
    ESTAuthorizationLevelAuthorized
};

typedef void(^ESTSettingGetAuthLevelCompletionBlock)(ESTAuthorizationLevel accessLevel, NSError *error);


@interface ESTSettingGetAuthorizationLevel : NSObject <ESTDeviceSettingProtocol>

- (instancetype)initWithCompletion:(ESTSettingGetAuthLevelCompletionBlock)completion;

@end
