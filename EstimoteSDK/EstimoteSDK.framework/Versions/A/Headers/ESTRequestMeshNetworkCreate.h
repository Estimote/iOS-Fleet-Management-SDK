//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestPostJSON.h"
#import "ESTMeshNetworkDetailsVO.h"

@class ESTDeviceSettingsCollection;

#define ESTRequestMeshNetworkCreateErrorDomain @"ESTRequestMeshNetworkCreateErrorDomain"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param result   Cloud response description as `ESTMeshNetworkDetailsVO` object. Nil value means request failed.
 *  @param error    Request's error. Nil value means request was successful.
 */
typedef void(^ESTRequestMeshNetworkCreateBlock)(ESTMeshNetworkDetailsVO * _Nullable result, NSError * _Nullable error);


/**
 *  ESTRequestMeshNetworkCreate represents request for creating Mesh network in Cloud.
 */
@interface ESTRequestMeshNetworkCreate : ESTRequestPostJSON

/**
 *  Designated iniatlizer.
 *
 *  @param  identifiers Identifiers of devices to be contained in the same Mesh network.
 *  @param  meshName    Name of Mesh network.
 *  @param  meshType    Type of Mesh Network. See `ESTMeshType` for available Mesh network types.
 *  @param  settingsCollection  Collection of settings to be applied throughout the Mesh network.
 *
 *  @return Initialized request object.
 */
- (instancetype)initWithIdentifiers:(NSArray<NSString *> *)identifiers
                           meshName:(NSString *)meshName
                           meshType:(ESTMeshNetworkType)meshType
                           settings:(ESTDeviceSettingsCollection *)settingsCollection;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestMeshNetworkCreateBlock)completion;

@end

NS_ASSUME_NONNULL_END
