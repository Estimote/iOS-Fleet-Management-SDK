//
// Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingProtocol.h"

typedef void(^ESTSettingGetChallengeCompletionBlock)(NSString *localChallenge, NSError *error);


@interface ESTSettingGetLocalChallenge : NSObject <ESTDeviceSettingProtocol>

- (instancetype)initWithCompletion:(ESTSettingGetChallengeCompletionBlock)completion;

@end
