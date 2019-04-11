//
// Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingProtocol.h"

typedef void(^ESTSettingSaveRemoteChallengeCompletionBlock)(NSError *error);


@interface ESTSettingSetRemoteChallenge : NSObject <ESTDeviceSettingProtocol>

- (instancetype)initWithRemoteChallenge:(NSData *)remoteChallenge
                             completion:(ESTSettingSaveRemoteChallengeCompletionBlock)completion;

@end
