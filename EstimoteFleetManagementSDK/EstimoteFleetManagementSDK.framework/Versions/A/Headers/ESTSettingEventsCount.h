//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingEventsCount;

#define ESTEventsCountDomain @"ESTEventsCountDomain"

typedef NS_ENUM(NSUInteger, ESTEventsCountError)
{
    /**
     *  Provided value is out of allowed range.
     */
    ESTEventsCountErrorValueNotAllowed = 1
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting Count operation for Events packet.
 *
 *  @param countSetting Count setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEventsCountCompletionBlock)(ESTSettingEventsCount * _Nullable countSetting, NSError * _Nullable error);


/**
 *  ESTSettingEventsCount represents Events Count value.
 */
@interface ESTSettingEventsCount : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param count Events Count value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(uint8_t)count;

/**
 *  Returns current value of Events Count setting.
 *
 *  @return Events Count value.
 */
- (uint8_t)getValue;

/**
 *  Method allows to read value of initialized Events Count setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEventsCountCompletionBlock)completion;

/**
 *  Method allows to write value of Events Count setting object.
 *
 *  @param value Value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint8_t)value
        completion:(ESTSettingCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param count Events count value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint8_t)count;

@end

NS_ASSUME_NONNULL_END
