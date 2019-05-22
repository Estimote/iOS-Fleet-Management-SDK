//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingMeshMessageBufferMaxSize;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting MessageBufferMaxSize operation for Mesh packet.
 *
 *  @param messageBufferMaxSizeSetting MessageBufferMaxSize setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshMessageBufferMaxSizeCompletionBlock)(ESTSettingMeshMessageBufferMaxSize * _Nullable messageBufferMaxSizeSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshMessageBufferMaxSize represents Mesh MessageBufferMaxSize value.
 */
@interface ESTSettingMeshMessageBufferMaxSize : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param messageBufferMaxSize Mesh MessageBufferMaxSize value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(uint16_t)messageBufferMaxSize;

/**
 *  Returns current value of Mesh MessageBufferMaxSize setting.
 *
 *  @return Mesh MessageBufferMaxSize value.
 */
- (uint16_t)getValue;

/**
 *  Method allows to read value of initialized Mesh MessageBufferMaxSize setting object.
 */
- (void)readValueWithCompletion:(ESTSettingMeshMessageBufferMaxSizeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
