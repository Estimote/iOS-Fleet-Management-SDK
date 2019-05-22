//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingAuthChallenge;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting AuthChallenge operation for authorization packet.
 *
 *  @param authChallengeSetting AuthChallenge setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingAuthChallengeCompletionBlock)(ESTSettingAuthChallenge * _Nullable authChallengeSetting, NSError * _Nullable error);


/**
 *  ESTSettingAuthChallenge represents authorization AuthChallenge value.
 */
@interface ESTSettingAuthChallenge : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param authChallenge authorization AuthChallenge value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)authChallenge;

/**
 *  Returns current value of authorization AuthChallenge setting.
 *
 *  @return authorization AuthChallenge value.
 */
- (NSString *)getValue;

@end

NS_ASSUME_NONNULL_END
