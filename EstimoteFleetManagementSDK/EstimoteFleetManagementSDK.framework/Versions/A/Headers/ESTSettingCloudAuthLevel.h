//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

typedef NS_ENUM(uint8_t, ESTBeaconCloudAuthLevel)
{
    ESTBeaconCloudAuthLevelNotAuthorized = 0x00,
    ESTBeaconCloudAuthLevelAuthorizedAdmin = 0xFF
};

@class ESTSettingCloudAuthLevel;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting GetAuthLevel operation for authorization packet.
 *
 *  @param getAuthLevelSetting GetAuthLevel setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingCloudAuthLevelCompletionBlock)(ESTSettingCloudAuthLevel * _Nullable getAuthLevelSetting, NSError * _Nullable error);


/**
 *  ESTBeaconGen1SettingGetAuthLevel represents authorization GetAuthLevel value.
 */
@interface ESTSettingCloudAuthLevel : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param getAuthLevel authorization GetAuthLevel value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(ESTBeaconCloudAuthLevel)getAuthLevel;

/**
 *  Returns current value of authorization GetAuthLevel setting.
 *
 *  @return authorization GetAuthLevel value.
 */
- (ESTBeaconCloudAuthLevel)getValue;

@end

NS_ASSUME_NONNULL_END
