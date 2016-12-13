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

@class ESTDeviceSettings;

typedef NS_ENUM(NSInteger, ESTMeshNetworkType)
{
    ESTMeshNetworkTypeStandard,
    ESTMeshNetworkTypeCluster
};

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTMeshNetworkDetailsVO represents vaule object of Mesh network's details stored in Estimote Cloud.
 */
@interface ESTMeshNetworkDetailsVO : ESTBaseVO

/**
 *  Mesh network's identifier.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  Mesh network's name.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 *  Mesh network's key.
 */
@property (nonatomic, strong, readonly) NSString *networkKey;

/**
 *  Mesh network's type.
 */
@property (nonatomic, readonly) ESTMeshNetworkType networkType;

/**
 *  List of devices that Mesh consists of. Each device has already applied Mesh network's settings.
 */
@property (nonatomic, strong, readonly) NSArray *devices;

/**
 *  List of devices included in Mesh network, that don't have yet Mesh network's settings applied.
 */
@property (nonatomic, strong, readonly) NSArray *pendingDevices;

/**
 *  Mesh network's settings shared among all devices included in the Mesh.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettings *settings;

/**
 *  Method allows to initialize value object with data coming from Estimote Cloud request `ESTRequestGetMesh`.
 *
 *  @param meshDetails Dictionary containing parsed JSON data coming from Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudData:(NSDictionary *)meshDetails;

@end

NS_ASSUME_NONNULL_END
