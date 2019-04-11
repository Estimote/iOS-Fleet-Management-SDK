//  FleetManagementSDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

@class ESTSettingEddystoneUIDEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Enable operation for Eddystone UID packet.
 *
 *  @param enabledSetting Enable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneUIDEnableCompletionBlock)(ESTSettingEddystoneUIDEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneUIDEnable represents Eddystone UID Enable value.
 */
@interface ESTSettingEddystoneUIDEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param enabled Eddystone UID Enable value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of Eddystone UID Enable setting.
 *
 *  @return Eddystone UID Enable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Eddystone UID Enable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneUIDEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone UID Enable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled Enable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingEddystoneUIDEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
