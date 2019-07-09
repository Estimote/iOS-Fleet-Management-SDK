//
//  ESTRequestDeletePendingSettings.h
//  EstimoteFleetManagementSDK
//
//  Created by Filip Chwastowski on 29/05/2019.
//  Copyright © 2019 Estimote. All rights reserved.
//

#import "ESTRequestPostJSON.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestDeletePendingSettingsErrorDomain @"ESTRequestDeletePendingSettingsErrorDomain"

/**
 Error that can occur for ESTRequestDeletePendingSettings operation.

 - ESTRequestDeletePendingSettingsFailed: When deletion of pending settings fails for some devices.
 */
typedef NS_ENUM (NSUInteger, ESTRequestDeletePendingSettingsError) {
    ESTRequestDeletePendingSettingsFailed
};

/**
 Completion block fired when request is complete.

 @param devices   Array of user's devices identifiers, for which Cloud has pending changes.
 @param error    Error of request. No error means success.
 */
typedef void (^ESTRequestDeletePendingSettingsBlock)(NSArray< NSString *> *_Nullable devices, NSError *_Nullable error);

/**
 ESTRequestDeletePendingSettings allows to delete all pending settings for provided list of devices.
 */
@interface ESTRequestDeletePendingSettings : ESTRequestPostJSON

/**
 Identifiers of a devices for whom pending settings should be removed.
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *deviceIdentifiers;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;
/**
 Initialize request with device's identifiers.

 @param deviceIdentifiers Device's identifier for which pending settings will be deleted.
 @return Initialized request.
 */
- (instancetype)initWithDeviceIdentifiers:(NSArray<NSString *> *)deviceIdentifiers;

/**
 Methods allows to send request with completion block invoked as a result.

 @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestDeletePendingSettingsBlock)completion;

@end

NS_ASSUME_NONNULL_END
