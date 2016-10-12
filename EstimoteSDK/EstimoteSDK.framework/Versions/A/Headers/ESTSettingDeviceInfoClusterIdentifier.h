//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingDeviceInfoClusterIdentifierErrorDomain @"ESTSettingDeviceInfoClusterIdentifierErrorDomain"

@class ESTSettingDeviceInfoClusterIdentifier;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting ClusterIdentifier operation for DeviceInfo packet.
 *
 *  @param clusterIdentifierSetting ClusterIdentifier setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoClusterIdentifierCompletionBlock)(ESTSettingDeviceInfoClusterIdentifier * _Nullable clusterIdentifierSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoClusterIdentifier represents DeviceInfo ClusterIdentifier value.
 */
@interface ESTSettingDeviceInfoClusterIdentifier : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingDeviceInfoClusterIdentifier validationErrorForValue:]
 *
 *  @param clusterIdentifier DeviceInfo ClusterIdentifier value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(int)clusterIdentifier;

/**
 *  Returns current value of DeviceInfo ClusterIdentifier setting.
 *
 *  @return DeviceInfo ClusterIdentifier value.
 */
- (int)getValue;

/**
 *  Method allows to read value of initialized DeviceInfo ClusterIdentifier setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoClusterIdentifierCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized DeviceInfo ClusterIdentifier setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param clusterIdentifier ClusterIdentifier value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(int)clusterIdentifier completion:(ESTSettingDeviceInfoClusterIdentifierCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
