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

NS_ASSUME_NONNULL_BEGIN


/**
 Responsible for two way communication between Mesh network and Cloud. ESTMeshGateway serves two purposes:
 - listen for Mesh packets and send confirmations to Estimote Cloud,
 - periodically fetch pending Mesh buffers for user's Mesh networks and apply them.
 Note that ESTMeshGateway requires appID and appToken (), which you can obtain via www.cloud.estimote.com
 See: + (void)setupAppID:(NSString *)appID andAppToken:(NSString *)appToken
 
 */
@interface ESTMeshGateway : NSObject

/**
 Triggers applying newest Mesh buffers to nearest devices, and confirming ranged Mesh packets to Cloud.
 */
- (void)start;

/**
 Stops both confirming Mesh packets to the Cloud, and applying pending Mesh buffers.
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
