//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

/**
 *  Monitoring proximity represents mental model of a beacon's range.
 */
typedef NS_ENUM (NSUInteger, ESTMonitoringProximity) {
    /**
     *  Unknown proximity. Placeholder for a nil value.
     */
    ESTMonitoringProximityUnknown,
    /**
     *  Phone hears a beacon in near distance (≤ 1.5m).
     */
    ESTMonitoringProximityNear,
    /**
     *  Phone hears a beacon in medium distance (≤ 7m).
     */
    ESTMonitoringProximityMedium,
    /**
     *  Phone hears a far beacon (≤ 15m).
     */
    ESTMonitoringProximityFar
};
