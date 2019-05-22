//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestPostJSON.h"
#import "ESTDeviceSettingsCollection.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param error Error of request. No error means success.
 */
typedef void(^ESTRequestV2SetDeviceDetailsBlock)(NSError * _Nullable error);


/**
 *  ESTRequestV2SetDeviceDetails allows to set settings to the device by sending
 *  pending settings in the Estimote Cloud.
 */
DEPRECATED_MSG_ATTRIBUTE("Please use `ESTRequestSetDeviceDetails` class for setting device's details in the Estimote Cloud.")
@interface ESTRequestV2SetDeviceDetails : ESTRequestPostJSON

/**
 *  Identifier of the device.
 */
@property (nonatomic, strong, readonly) NSString *deviceIdentifier;

/**
 *  Collection of the settings should be applied to the device.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettingsCollection *settingsCollection;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV2SetDeviceDetailsBlock)completion;

/**
 *  Method allows to initialize request.
 *
 *  @param deviceIdentifier   Identifier of the device.
 *  @param settingsCollection Collection of the settings that should be applied to the device.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier
                                settings:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
