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
#import "ESTRequestGetJSON.h"

@class ESTMeshNetworkDetailsVO;

#define ESTRequestGetMeshNetworksErrorDomain @"ESTRequestGetMeshNetworksErrorDomain"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param result   Cloud response description as array of `ESTMeshNetworkDetailsVO` objects. Nil value means request failed.
 *  @param error    Request's error. Nil value means request was successful.
 */
typedef void(^ESTRequestGetMeshNetworksBlock)(NSArray <ESTMeshNetworkDetailsVO *> * _Nullable result, NSError * _Nullable error);


/**
 *  ESTRequestGetMeshNetworks represents request for fetching all Mesh networks' details assigned to currently authorized user.
 */
@interface ESTRequestGetMeshNetworks : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestGetMeshNetworksBlock)completion;

@end

NS_ASSUME_NONNULL_END
