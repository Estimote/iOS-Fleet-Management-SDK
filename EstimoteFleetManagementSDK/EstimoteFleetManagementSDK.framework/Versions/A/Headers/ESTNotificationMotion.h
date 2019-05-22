//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceNotificationProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ESTNotificationMotionBlock)(BOOL inMotion);


/**
 *  ESTNotificationMotion
 */
@interface ESTNotificationMotion : NSObject <ESTDeviceNotificationProtocol, NSCopying>

- (instancetype)initWithHandlerBlock:(ESTNotificationMotionBlock)handler;

@end

NS_ASSUME_NONNULL_END
