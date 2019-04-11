//  FleetManagementSDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"

@class ESTSettingStorageMaximumSize;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting MaximumSize operation for Storage packet.
 *
 *  @param maximumSizeSetting MaximumSize setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingStorageMaximumSizeCompletionBlock)(ESTSettingStorageMaximumSize * _Nullable maximumSizeSetting, NSError * _Nullable error);


/**
 *  ESTSettingStorageMaximumSize represents Storage MaximumSize value.
 */
@interface ESTSettingStorageMaximumSize : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param maximumSize Storage MaximumSize value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(uint32_t)maximumSize;

/**
 *  Returns current value of Storage MaximumSize setting.
 *
 *  @return Storage MaximumSize value.
 */
- (uint32_t)getValue;

/**
 *  Method allows to read value of initialized Storage MaximumSize setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingStorageMaximumSizeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
