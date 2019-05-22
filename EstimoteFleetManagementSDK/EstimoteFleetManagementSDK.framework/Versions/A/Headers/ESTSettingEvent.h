//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingEvent;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting Event operation for Events packet.
 *
 *  @param eventSetting Event setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEventCompletionBlock)(ESTSettingEvent * _Nullable eventSetting, NSError * _Nullable error);


/**
 *  ESTSettingEvent represents Events Event value.
 */
@interface ESTSettingEvent : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param event Events Event value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSData *)event;

/**
 *  Returns current value of Events Event setting.
 *
 *  @return Events Event value.
 */
- (NSData *)getValue;

/**
 *  Method allows to read value of initialized Events Event setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEventCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
