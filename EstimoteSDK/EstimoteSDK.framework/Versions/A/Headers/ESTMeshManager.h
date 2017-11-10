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

@class ESTMeshManager;

typedef void(^ESTMeshCompletionBlock)(ESTMesh * _Nullable networkDetails, NSError * _Nullable error);
typedef void(^ESTMeshArrayCompletionBlock)(NSArray <ESTMesh *> * _Nullable meshList, NSError * _Nullable error);

typedef NS_ENUM(NSInteger, ESTMeshManagerError) {
    
    ///  One or more arguments are invalid.
    ESTMeshManagerErrorInvalidValue,
    
    /// The platform does not support Bluetooth low energy.
    ESTMeshManagerBluetoothNotSupported,
    
    /// The app is not authorized to use Bluetooth low energy.
    ESTMeshManagerUnauthorizedToUseBluetooth,
    
    /// Bluetooth is currently powered off.
    ESTMeshManagerBluetoothOff,
    
    /// Failed to trigger automapping command in Cloud.
    ESTMeshManagerErrorAutomappingFailed,
    
    /// Failed to trigger asset tracking command in Cloud.
    ESTMeshManagerErrorAssetTrackingFailed,
    
    /// Failed to trigger reading scan reports command in Cloud.
    ESTMeshManagerErrorPrepareNearablesScanReportFailed,
    
    /// Failed to perform configuration of devices in mesh.
    ESTMeshManagerErrorConfigurationFailed
};

/**
 *  Defines delegate methods for ESTMeshManager objects.
 */
@protocol ESTMeshManagerDelegate <NSObject>

/**
 *  Called when mesh manager successfully confirms mesh settings for given devices.
 *
 *  @param manager    Mesh manager reporting the event.
 *  @param deviceIdentifiers    Identifiers of given devices.
 */
@optional
- (void)meshManager:(ESTMeshManager *)manager didConfirmMeshSettingsForDeviceIdentifiers:(NSArray<NSString *> *)deviceIdentifiers;

/**
 *  Called when mesh manager fails to confirm mesh settings.
 *
 *  @param manager    Mesh manager reporting the event.
 *  @param error    Error object with information on the reason of failure.
 */
@optional
- (void)meshManager:(ESTMeshManager *)manager didFailMeshSettingsConfirmationWithError:(NSError *)error;

@end

/**
 *  ESTMeshManager is responsible for Mesh networks management and synchronising with Estimote Cloud.
 */
@interface ESTMeshManager : NSObject

/**
 *  Delegate object.
 */
@property (nonatomic, weak) id<ESTMeshManagerDelegate> delegate;

/**
 *  Informs whether the process of confirming mesh settings is active.
 */
@property (nonatomic, readonly) BOOL isConfirmingMeshSettings;

/**
 * Initializer.
 *
 * @return Initialized object or nil if it couldn't be created.
 */
- (instancetype)init;

/**
 * Initializer with the ability to set a delegate object.
 *
 * @param delegate Delegate object.
 *
 * @return Initialized object or nil if it couldn't be created.
 */
- (instancetype)initWithDelegate:(id<ESTMeshManagerDelegate> _Nullable)delegate;

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

/**
 *  Starts sending mesh settings confirmation requests to Estimote Cloud for every meshed device in range.
 */
- (void)startConfirmingMeshSettings;

/**
 *  Stops sending mesh settings confirmation requests to Estimote Cloud.
 */
- (void)stopConfirmingMeshSettings;

/**
 Queues UWB ranging command in the Cloud.
 @warning The comand is synchronized upon device connection.
 @warning The comamnd is executed upon device disconnection.

 @param networkIdentifier Identifier of Mesh network, that automapping will be triggered for.
 @param completion Completion block with operation's error. Nil value means success.
 */
- (void)queueAutomappingCommandInCloudForNetworkIdentifier:(uint32_t)networkIdentifier completion:(ESTCompletionBlock)completion;

/**
 Method allows to prepare pending settings for all beacons in the mesh network.

 @param networkIdentifier Identifier of mesh network.
 @param deviceSettings Group of settings that should be applied.
 @param completion Completion block with operation's error. Nil value means success.
 */
- (void)configureNetwork:(uint32_t)networkIdentifier
                settings:(ESTDeviceSettingsCollection *)deviceSettings
              completion:(ESTCompletionBlock)completion;

/**
 Sets a pending setting in the Cloud; this setting causes beacons in this mesh network to start scanning for nearables.
 @warning The beacon synchronizes pending settings upon connection and executes them upon disconnection.

 @param networkIdentifier Identifier of Mesh network, that tracking nearables will be enabled for.
 @param completion Completion block with operation's error. Nil value means success.
 */
- (void)enableAssetTrackingForNetworkIdentifier:(uint32_t)networkIdentifier completion:(ESTCompletionBlock)completion;

/**
 Creates a pending command to prepare (merge) scan reports with nearables' signal readings across the mesh network and queues this command in the Cloud.
 
 @warning The comand is synchronized upon device connection.
 @warning The comamnd is executed upon device disconnection.
 @warning Only works if `enableAssetTrackingForNetworkIdentifier:completion:` was executed in advance.

 @param networkIdentifier Identifier of Mesh network, that reading scan reports will be triggered for.
 @param completion Completion block with operation's error. Nil value means success.
 */
- (void)prepareNearablesScanReportCommandForNetworkIdentifier:(uint32_t)networkIdentifier completion:(ESTCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
