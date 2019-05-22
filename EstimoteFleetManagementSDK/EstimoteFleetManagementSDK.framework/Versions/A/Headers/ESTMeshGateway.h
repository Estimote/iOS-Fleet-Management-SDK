//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ESTMeshGateway, ESTMeshNearablesScanReportVO;

@protocol ESTMeshGatewayDelegate <NSObject>
@optional
/**
 Called when Mesh Gateway read scan report.

 @param gateway Gateway instance that gathered report.
 @param scanReport Value object of scan report.
 @param settingsVersion Settings version of Mesh network.
 @param networkIdentifier Mesh network identifier.
 */
- (void)gateway:(ESTMeshGateway *)gateway didReadScanReport:(ESTMeshNearablesScanReportVO *)scanReport withSettingsVersion:(NSNumber *)settingsVersion forNetwork:(NSNumber *)networkIdentifier;
@end

/**
 Responsible for two way communication between Mesh network and Cloud. ESTMeshGateway serves two purposes:
 - listen for Mesh packets and send confirmations to Estimote Cloud,
 - periodically fetch pending Mesh buffers for user's Mesh networks and apply them.
 Note that ESTMeshGateway requires appID and appToken (), which you can obtain via www.cloud.estimote.com
 See: + (void)setupAppID:(NSString *)appID andAppToken:(NSString *)appToken
 */
@interface ESTMeshGateway : NSObject

/**
 Delegate's object.
 */
@property (nonatomic, weak) id<ESTMeshGatewayDelegate> delegate;

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
