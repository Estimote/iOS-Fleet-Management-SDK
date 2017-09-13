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

/**
 Represents possible monitoring states for a user in relation to a proximity zone.
 
 - ESTMonitoringStateUnknown: It's unkown whether the user is inside or outside the zone.
 - ESTMonitoringStateInside: The user is inside the zone.
 - ESTMonitoringStateOutside: The user is outside the zone.
 */
typedef NS_ENUM(NSUInteger, ESTMonitoringState) {
    ESTMonitoringStateUnknown = 0,
    ESTMonitoringStateInsideZone,
    ESTMonitoringStateOutsideZone
};
