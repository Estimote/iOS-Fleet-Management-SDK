//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingDeviceInfoApplicationHash;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting ApplicationHash operation for Device Info packet.
 *
 *  @param applicationHashSetting ApplicationHash setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoApplicationHashCompletionBlock)(ESTSettingDeviceInfoApplicationHash * _Nullable applicationHashSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoApplicationHash represents Device Info ApplicationHash value.
 */
@interface ESTSettingDeviceInfoApplicationHash : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param applicationHash Device Info ApplicationHash value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)applicationHash;

/**
 *  Returns current value of Device Info ApplicationHash setting.
 *
 *  @return Device Info ApplicationHash value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Device Info ApplicationHash setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoApplicationHashCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
