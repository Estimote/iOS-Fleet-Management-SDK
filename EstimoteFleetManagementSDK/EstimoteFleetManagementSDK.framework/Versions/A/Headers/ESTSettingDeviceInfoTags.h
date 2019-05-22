//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingDeviceInfoTags;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Tags operation for Cloud packet.
 *
 *  @param tagsSetting Tags setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoTagsCompletionBlock)(ESTSettingDeviceInfoTags * _Nullable tagsSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoTags represents Cloud Tags value.
 */
@interface ESTSettingDeviceInfoTags : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingDeviceInfoTags validationErrorForValue:]
 *
 *  @param tags Cloud Tags value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSSet<NSString *> *)tags;

/**
 *  Returns current value of Cloud Tags setting.
 *
 *  @return Cloud Tags value.
 */
- (NSSet<NSString *> *)getValue;

/**
 *  Method allows to read value of initialized Cloud Tags setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoTagsCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Cloud Tags setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param tags Set containing tags to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSSet<NSString *> *)tags completion:(ESTSettingDeviceInfoTagsCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param tags Tags value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSSet<NSString *> *)tags;

@end

NS_ASSUME_NONNULL_END
