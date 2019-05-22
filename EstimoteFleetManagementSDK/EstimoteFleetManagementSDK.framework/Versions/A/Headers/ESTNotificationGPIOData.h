//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceNotificationProtocol.h"
#import "ESTGPIOPortsData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Notification Block used to inform about GPIO ports state change during connection.
 *
 *  @param portsData current state of all GPIO ports.
 */
typedef void(^ESTNotificationGPIODataBlock)(ESTGPIOPortsData *portsData);


/**
 *  ESTNotificationSettingGPIOData allows to listen for GPIO ports state change during connection.
 */
@interface ESTNotificationGPIOData : NSObject <ESTDeviceNotificationProtocol, NSCopying>

/**
 *  Allows to initialize object with notification block.
 *
 *  @param handler Notification handler block called on GPIO ports data update.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithHandlerBlock:(ESTNotificationGPIODataBlock)handler;

@end

NS_ASSUME_NONNULL_END
