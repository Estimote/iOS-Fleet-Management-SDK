//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshSynchronisationListErrorDomain @"ESTSettingMeshSynchronisationListErrorDomain"

/**
 *  Describes Mesh SynchronisationList validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMeshSynchronisationListError)
{
     /**
     *  Provided value does not have even length.
     */
    ESTSettingMeshSynchronisationListErrorOddLength = 1,
    /**
     *  Provided value is too long.
     */
    ESTSettingMeshSynchronisationListErrorTooLong = 2,
    /**
     *  Provided value is missing
     */
    ESTSettingMeshSynchronisationListErrorNoValue = 3
};

@class ESTSettingMeshSynchronisationList;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting SynchronisationList operation for Mesh packet.
 *
 *  @param synchronisationListSetting SynchronisationList setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshSynchronisationListCompletionBlock)(ESTSettingMeshSynchronisationList * _Nullable synchronisationListSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshSynchronisationList represents Mesh SynchronisationList value.
 */
@interface ESTSettingMeshSynchronisationList : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshSynchronisationList validationErrorForValue:]
 *
 *  @param synchronisationList Mesh SynchronisationList value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSArray *)synchronisationList;

/**
 *  Returns current value of Mesh SynchronisationList setting.
 *
 *  @return Mesh SynchronisationList value.
 */
- (NSArray *)getValue;

/**
 *  Method allows to read value of initialized Mesh SynchronisationList setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshSynchronisationListCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Mesh SynchronisationList setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param synchronisationList SynchronisationList value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSArray *)synchronisationList completion:(ESTSettingMeshSynchronisationListCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param synchronisationList SynchronisationList value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSArray *)synchronisationList;

@end

NS_ASSUME_NONNULL_END
