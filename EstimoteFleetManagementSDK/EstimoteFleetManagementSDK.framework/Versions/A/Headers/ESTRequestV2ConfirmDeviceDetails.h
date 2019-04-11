//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestPostJSON.h"
#import "ESTDeviceSettingsCollection.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param error Error of request. No error means success.
 */
typedef void(^ESTRequestV2ConfirmDeviceDetailsBlock)(NSError * _Nullable error);


/**
 *  ESTRequestV2ConfirmDeviceDetails allows to confirm in Estimote Cloud 
 *  that settings were applied.
 */
@interface ESTRequestV2ConfirmDeviceDetails : ESTRequestPostJSON

/**
 *  Identifier of the device.
 */
@property (nonatomic, strong, readonly) NSString *deviceIdentifier;

/**
 *  Current settings of the device. All settings should be provided.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettingsCollection *settingsCollection;

/**
 *  Initialize request with device details.
 *
 *  @param deviceIdentifier Device's identifier which details should be sent to cloud.
 *  @param settingsCollection Collection of settings that will be confirmed with Estimote Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier
                                settings:(ESTDeviceSettingsCollection *)settingsCollection;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV2ConfirmDeviceDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END