//
// Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingProtocol.h"

typedef void(^ESTSettingGetRemoteChallengeCompletionBlock)(NSString *remoteChallengeResponse, NSError *error);


@interface ESTSettingGetRemoteChallengeResponse : NSObject <ESTDeviceSettingProtocol>

- (instancetype)initWithCompletion:(ESTSettingGetRemoteChallengeCompletionBlock)completion;

@end
