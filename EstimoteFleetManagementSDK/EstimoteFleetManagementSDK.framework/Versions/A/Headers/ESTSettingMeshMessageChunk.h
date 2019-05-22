//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshMessageChunkErrorDomain @"ESTSettingMeshMessageChunkErrorDomain"

/**
 *  Describes Mesh MessageChunk validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMeshMessageChunkError)
{
     /**
     *  Provided value has invalid length.
     */
    ESTSettingMeshMessageChunkErrorInvalidLength = 1
};

@class ESTSettingMeshMessageChunk;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of write only setting MessageChunk operation for Mesh packet.
 *
 *  @param meshMessageChunkSetting MessageChunk setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshMessageChunkCompletionBlock)(ESTSettingMeshMessageChunk * _Nullable meshMessageChunkSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshMessageChunk represents data chunks written to Mesh Message Buffer.
 */
@interface ESTSettingMeshMessageChunk : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshMessageChunk validationErrorForValue:]
 *
 *  @param meshMessageChunk Mesh MessageChunk value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSData *)meshMessageChunk;

/**
 *  Returns current value of Mesh MessageChunk setting.
 *
 *  @return Mesh MessageChunk value.
 */
- (NSData *)getValue;

/**
 *  Method allows to create write operation from already initialized Mesh MessageChunk setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param meshMessageChunk MessageChunk value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSData *)meshMessageChunk completion:(ESTSettingMeshMessageChunkCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param meshMessageChunk MessageChunk value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSData *)meshMessageChunk;

@end

NS_ASSUME_NONNULL_END
