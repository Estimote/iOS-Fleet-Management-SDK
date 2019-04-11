//
// Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingProtocol.h"

typedef void(^ESTSettingSaveLocalChallengeResponseCompletionBlock)(NSError *error);


@interface ESTSettingSetLocalChallengeResponse : NSObject <ESTDeviceSettingProtocol> 

- (instancetype)initWithLocalChallengeResponse:(NSData *)data
                                    completion:(ESTSettingSaveLocalChallengeResponseCompletionBlock)completion;

@end
