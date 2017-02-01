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

#import "ESTBaseVO.h"
#import "ESTDeviceLocationBeacon.h"

@class ESTDeviceSettings;

typedef NS_ENUM(NSInteger, ESTMeshNetworkType)
{
    /**
     *  Standard Mesh network.
     */
    ESTMeshNetworkTypeStandard,
    /**
     *  Cluster type of Mesh network with time schedules for broadcasting advertisers predefined in Cloud.
     */
    ESTMeshNetworkTypeCluster
};

#define ESTMeshErrorDomain @"ESTMeshErrorDomain"

typedef NS_ENUM(NSInteger, ESTMeshError)
{
    /**
     *  Provided arguments are invalid.
     */
    ESTMeshErrorInvalidArguments,
    /**
     *  Failed to add device to the Mesh network in the Cloud.
     */
    ESTMeshErrorAddingDeviceFailed,
    /**
     *  Failed to remove device from the Mesh network in the Cloud.
     */
    ESTMeshErrorRemovingDeviceFailed
};

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTMesh represents object of Mesh network's details stored in Estimote Cloud.
 */
@interface ESTMesh : ESTBaseVO <NSCopying, NSCoding>

/**
 *  Mesh network's identifier.
 */
@property (nonatomic, strong, readonly) NSNumber *networkIdentifier;

/**
 *  Mesh network's name.
 */
@property (nonatomic, strong, readonly) NSString *networkName;

/**
 *  Mesh network's type.
 */
@property (nonatomic, assign, readonly) ESTMeshNetworkType networkType;

/**
 *  List of devices that Mesh consists of. Each device has already applied Mesh network's settings.
 */
@property (nonatomic, strong, readwrite) NSArray <ESTDeviceLocationBeacon *> *devices;

/**
 *  Mesh network's settings shared among all devices included in the Mesh.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettings *settings;

/**
 *  Method allows to initialize Mesh network object.
 *
 *  @param  cloudData   Data fetched from Estimote Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudData:(NSDictionary *)cloudData;

/**
 *  Method for adding ESTDeviceLocationBeacon to Mesh network. Keep in mind that established bluetooth connection
 *  is required to perform this method.
 *
 *  @param  device  ESTDeviceLocationBeacon object to be added to Mesh network.
 *  @param  completion  Completion block with operation result. Nil error means success.
 */
- (void)addDevice:(ESTDeviceLocationBeacon *)device completion:(ESTCompletionBlock)completion;


/**
 *  Removes device from Mesh network.
 *
 *  @param device     Presently connected device you want to remove from Mesh.
 *  @param completion Completion block with result. Error of nil value means that the request was successful.
 */
- (void)removeDevice:(ESTDeviceLocationBeacon *)device completion:(ESTCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
