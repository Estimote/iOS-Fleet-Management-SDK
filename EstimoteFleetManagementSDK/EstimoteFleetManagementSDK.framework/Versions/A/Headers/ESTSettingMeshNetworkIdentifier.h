//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshNetworkIdentifierErrorDomain @"ESTSettingMeshNetworkIdentifierErrorDomain"

@class ESTSettingMeshNetworkIdentifier;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting NetworkIdentifier operation for Mesh packet.
 *
 *  @param networkIdentifierSetting NetworkIdentifier setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshNetworkIdentifierCompletionBlock)(ESTSettingMeshNetworkIdentifier * _Nullable networkIdentifierSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshNetworkIdentifier represents Mesh NetworkIdentifier value.
 */
@interface ESTSettingMeshNetworkIdentifier : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshNetworkIdentifier validationErrorForValue:]
 *
 *  @param networkIdentifier Mesh NetworkIdentifier value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint32_t)networkIdentifier;

/**
 *  Returns current value of Mesh NetworkIdentifier setting.
 *
 *  @return Mesh NetworkIdentifier value.
 */
- (uint32_t)getValue;

/**
 *  Method allows to read value of initialized Mesh NetworkIdentifier setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshNetworkIdentifierCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Mesh NetworkIdentifier setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param networkIdentifier NetworkIdentifier value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint32_t)networkIdentifier completion:(ESTSettingMeshNetworkIdentifierCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
