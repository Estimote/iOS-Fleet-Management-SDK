//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshNetworkKeyErrorDomain @"ESTSettingMeshNetworkKeyErrorDomain"

/**
 *  Describes Mesh NetworkKey validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMeshNetworkKeyError)
{
     /**
     *  Provided value is too short.
     */
    ESTSettingMeshNetworkKeyErrorTooShort = 1,
    
    /**
     *  Provided value is too long.
     */
    ESTSettingMeshNetworkKeyErrorTooLong = 2
};

@class ESTSettingMeshNetworkKey;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting NetworkKey operation for Mesh packet.
 *
 *  @param networkKeySetting NetworkKey setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshNetworkKeyCompletionBlock)(ESTSettingMeshNetworkKey * _Nullable networkKeySetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshNetworkKey represents Mesh NetworkKey value.
 */
@interface ESTSettingMeshNetworkKey : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshNetworkKey validationErrorForValue:]
 *
 *  @param networkKey Mesh NetworkKey value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSString *)networkKey;

/**
 *  Returns current value of Mesh NetworkKey setting.
 *
 *  @return Mesh NetworkKey value.
 */
- (NSString *)getValue;

/**
 *  Method allows to create write operation from already initialized Mesh NetworkKey setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param networkKey NetworkKey value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSString *)networkKey completion:(ESTSettingMeshNetworkKeyCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param networkKey NetworkKey value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)networkKey;

@end

NS_ASSUME_NONNULL_END
