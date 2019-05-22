//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingEddystoneEIDIdentityKeyErrorDomain @"ESTSettingEddystoneEIDIdentityKeyErrorDomain"

/**
 *  Describes EddystoneEID IdentityKey validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneEIDIdentityKeyError)
{
     /**
     *  Provided value is too long.
     */
    ESTSettingEddystoneEIDIdentityKeyErrorValueTooLong = 1,
    
    /**
     *  Provided value is too short.
     */
    ESTSettingEddystoneEIDIdentityKeyErrorValueTooShort = 2,
    
    /**
     *  Provided value is not a hex string.
     */
    ESTSettingEddystoneEIDIdentityKeyErrorInvalidFormat = 3
};

@class ESTSettingEddystoneEIDIdentityKey;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of write setting IdentityKey operation for EddystoneEID packet.
 *
 *  @param identityKeySetting IdentityKey setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneEIDIdentityKeyCompletionBlock)(ESTSettingEddystoneEIDIdentityKey * _Nullable identityKeySetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneEIDIdentityKey represents EddystoneEID IdentityKey value.
 */
@interface ESTSettingEddystoneEIDIdentityKey : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEddystoneEIDIdentityKey validationErrorForValue:]
 *
 *  @param identityKey EddystoneEID IdentityKey value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSString *)identityKey;

/**
 *  Returns current value of EddystoneEID IdentityKey setting.
 *
 *  @return EddystoneEID IdentityKey value.
 */
- (NSString *)getValue;

/**
 *  Method allows to create write operation from already initialized EddystoneEID IdentityKey setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param identityKey IdentityKey value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSString *)identityKey completion:(ESTSettingEddystoneEIDIdentityKeyCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param identityKey IdentityKey value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)identityKey;

@end

NS_ASSUME_NONNULL_END
