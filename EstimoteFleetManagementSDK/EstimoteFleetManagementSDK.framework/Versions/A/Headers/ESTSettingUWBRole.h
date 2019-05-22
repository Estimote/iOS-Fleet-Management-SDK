//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBRoleErrorDomain @"ESTSettingUWBRoleErrorDomain"

@class ESTSettingUWBRole;

/**
 *  Available power levels for UWB packet.
 */
typedef NS_ENUM(uint8_t, ESTUWBRole)
{
    ESTUWBRoleInitiator = 0,
    ESTUWBRoleResponder = 1,
    ESTUWBRoleMixed = 2
};


NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Role operation for UWB packet.
 *
 *  @param roleSetting Role setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBRoleCompletionBlock)(ESTSettingUWBRole * _Nullable roleSetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBRole represents UWB Role value.
 *  @see ESTUWBRole
 */
@interface ESTSettingUWBRole : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBRole validationErrorForValue:]
 *
 *  @param role UWB Role value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTUWBRole)role;

/**
 *  Returns current value of UWB Role setting.
 *
 *  @return UWB Role value.
 */
- (ESTUWBRole)getValue;

/**
 *  Method allows to read value of initialized UWB  Role setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBRoleCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB Role setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param role Role value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTUWBRole)role completion:(ESTSettingUWBRoleCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param role Role value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTUWBRole)role;

@end

NS_ASSUME_NONNULL_END
