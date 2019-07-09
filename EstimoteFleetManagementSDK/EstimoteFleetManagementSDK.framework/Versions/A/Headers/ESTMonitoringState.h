//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

/**
 Represents possible monitoring states for a user in relation to a proximity zone.

 - ESTMonitoringStateUnknown: It's unkown whether the user is inside or outside the zone.
 - ESTMonitoringStateInside: The user is inside the zone.
 - ESTMonitoringStateOutside: The user is outside the zone.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
typedef NS_ENUM (NSUInteger, ESTMonitoringState) {
    ESTMonitoringStateUnknown = 0,
    ESTMonitoringStateInsideZone,
    ESTMonitoringStateOutsideZone
};
