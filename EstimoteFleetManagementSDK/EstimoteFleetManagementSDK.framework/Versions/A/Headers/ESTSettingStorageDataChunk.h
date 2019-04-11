//  FleetManagementSDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingStorageDataChunkErrorDomain @"ESTSettingStorageDataChunkErrorDomain"

/**
 *  Describes Storage DataChunk validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingStorageDataChunkError)
{
     /**
     *  Provided value has invalid length.
     */
    ESTSettingStorageDataChunkErrorInvalidLength = 1
};

@class ESTSettingStorageDataChunk;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting DataChunk operation for Storage packet.
 *
 *  @param dataChunkSetting DataChunk setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingStorageDataChunkCompletionBlock)(ESTSettingStorageDataChunk * _Nullable dataChunkSetting, NSError * _Nullable error);


/**
 *  ESTSettingStorageDataChunk represents Storage DataChunk value.
 */
@interface ESTSettingStorageDataChunk : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingStorageDataChunk validationErrorForValue:]
 *
 *  @param dataChunk Storage DataChunk value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSData *)dataChunk;

/**
 *  Returns current value of Storage DataChunk setting.
 *
 *  @return Storage DataChunk value.
 */
- (NSData *)getValue;

/**
 *  Method allows to read value of initialized Storage DataChunk setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingStorageDataChunkCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Storage DataChunk setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param dataChunk DataChunk value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSData *)dataChunk completion:(ESTSettingStorageDataChunkCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param dataChunk DataChunk value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSData *)dataChunk;

@end

NS_ASSUME_NONNULL_END
