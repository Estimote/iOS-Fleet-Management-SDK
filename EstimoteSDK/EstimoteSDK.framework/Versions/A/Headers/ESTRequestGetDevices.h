//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"

@class ESTDeviceDetails;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param  devicesDetails  Details of the devices wrapped in an array of ESTDeviceDetails class objects.
 *  @param  totalCount  Total count of devices assigned in Cloud.
 *  @param  nextPage    Index of the next available page of devices details. Nil value means there are no more details to fetch.
 *  @param  error   Error of request. No error means success.
 */
typedef void (^ESTRequestGetDevicesBlock)(NSArray<ESTDeviceDetails *> *_Nullable devicesDetails,
                                          NSNumber * _Nullable totalCount,
                                          NSNumber * _Nullable nextPage,
                                          NSError * _Nullable error);

/**
 *  Device's types that can be requested.
 */
typedef NS_OPTIONS(NSUInteger, ESTRequestGetDevicesTypeMask) {
    ESTRequestGetDevicesTypeMaskBeacon = 1 << 0,
    ESTRequestGetDevicesTypeMaskMirror = 1 << 1,
    ESTRequestGetDevicesTypeMaskSticker = 1 << 2,
    ESTRequestGetDevicesTypeMaskAll = 0b111
};

/**
 *  Allows to get user's devices details from the Estimote Cloud API.
 */
@interface ESTRequestGetDevices : ESTRequestGetJSON

- (instancetype)init DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.25.2. Please use initWithIdentifiers:type:page:");

/**
 *  Designated initializer.
 *
 *  @param identifiers List of device identifiers to fetch. Identifiers should be separated by comma. If nil, then all devices within defined range will be fetched.
 *  @param deviceType Device types, which will be returned.
 *  @param page From which page data should be returned.
 *
 *  @return Initialized request.
 */
- (instancetype)initWithIdentifiers:(nullable NSArray<NSString *> *)identifiers
                               type:(ESTRequestGetDevicesTypeMask)deviceType
                               page:(NSNumber *)page NS_DESIGNATED_INITIALIZER;

/**
 *  Convenience initializer returning devices with given identifiers and devices' types.
 *  Note it has no `page` parameter, so this method will initialize a request fetching up to 100 devices.
 *
 *  @param identifiers List of device identifiers to fetch. Identifiers should be separated by comma. If nil, then all devices within
 * defined range will be fetched.
 *  @param deviceType List of device type which will be returned.
 *
 *  @return Initialized request.
 */
- (instancetype)initWithIdentifiers:(nullable NSArray<NSString *> *)identifiers type:(ESTRequestGetDevicesTypeMask)deviceType;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestGetDevicesBlock)completion;

@end

NS_ASSUME_NONNULL_END
