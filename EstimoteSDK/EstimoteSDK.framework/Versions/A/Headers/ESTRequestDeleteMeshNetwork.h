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
#import "ESTRequestDelete.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param result   Cloud response description.
 *  @param error    Request's error. Nil value means request was successful.
 */
typedef void(^ESTRequestDeleteMeshNetworkBlock)(id _Nullable result, NSError * _Nullable error);


/**
 *  ESTRequestDeleteMeshNetwork represents request for deleting Mesh network from Cloud.
 */
@interface ESTRequestDeleteMeshNetwork : ESTRequestDelete

/**
 *  Designated iniatlizer.
 *
 *  @param networkIdentifier Identifier of Mesh network to be deleted.
 *
 *  @return Initilized request object.
 */
- (instancetype)initWithNetworkIdentifier:(NSNumber *)networkIdentifier;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestDeleteMeshNetworkBlock)completion;

@end

NS_ASSUME_NONNULL_END
