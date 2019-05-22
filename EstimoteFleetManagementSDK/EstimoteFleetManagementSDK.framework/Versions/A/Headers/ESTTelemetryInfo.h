//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

/**
 * Class for objects carying data from telemetry packet.
 */
@interface ESTTelemetryInfo : NSObject

/**
 *  Half (8 bytes) of the full device identifier (16 bytes)
 *  represented in hex string.
 */
@property (nonatomic, strong, readonly) NSString *shortIdentifier;

- (instancetype)initWithShortIdentifier:(NSString *)shortIdentifier;

@end
