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
#import "ESTMesh.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTMeshManagerErrorDomain @"ESTMeshManagerErrorDomain"


typedef void(^ESTMeshCompletionBlock)(ESTMesh *networkDetails, NSError * _Nullable error);
typedef void(^ESTMeshArrayCompletionBlock)(NSArray <ESTMesh *> * _Nullable meshList, NSError * _Nullable error);

typedef NS_ENUM(NSInteger, ESTMeshManagerError) {
    /**
     *  One or more arguments are invalid.
     */
    ESTMeshManagerErrorInvalidValue
};

/**
 *  ESTMeshManager is responsible for Mesh networks management and synchronising with Estimote Cloud.
 */
@interface ESTMeshManager : NSObject

/**
 *  Method allowing to create Mesh network in Cloud with provided details. Connection with Location Beacon is required to apply Mesh network's settings to the device.
 *  @see ESTDeviceLocationBeacon connect
 *
 *  @param  devices Array of Location Beacon's identifiers to be included in Mesh network.
 *  @param  name    Mesh network's name.
 *  @param  type    Type of Mesh network. @see ESTMeshNetworkType
 *  @param  settings    Reference settings to be used across Mesh network's devices.
 *  @param  completion  Completion block returning Mesh network object or error, if operation failed to succeed.
 */
- (void)createMeshFromDevices:(NSArray <NSString *> *)devices
                  networkName:(NSString *)name
                  networkType:(ESTMeshNetworkType)type
            referenceSettings:(ESTDeviceSettings *)settings
                   completion:(ESTMeshCompletionBlock)completion;

/**
 *  Method for fetching list of Mesh network's details.
 *
 *  @param  completion  Completion block returning list of Mesh network objects or error, if operation failed to succeed.
 */
- (void)fetchMeshListWithCompletion:(ESTMeshArrayCompletionBlock)completion;

/**
 *  Method for fetching single Mesh network's details.
 *
 *  @param  identifier  Identifier of Mesh network.
 *  @param  completion  Completion block returning list of Mesh network objects or error, if operation failed to succeed.
 */
- (void)fetchMeshDetailsWithIdentifier:(NSNumber *)identifier completion:(ESTMeshCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
