//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTMonitoringState.h"

NS_ASSUME_NONNULL_BEGIN

@class ESTMonitoringV2Manager;

#define ESTMonitoringV2ManagerErrorDomain @"ESTMonitoringV2ManagerErrorDomain"

/**
 Possible errors generated while using Monitoring Manager related to configuration, permissions or Bluetooth problems.

 - ESTMonitoringManagerErrorBluetoothNotSupported: Platform doesn't support BLE.
 - ESTMonitoringManagerErrorUnauthorizedToUseBluetooth: App isn't authorize to use BLE.
 - ESTMonitoringManagerErrorBluetoothOff: Bluetooth is currently powered off.
 - ESTMonitoringManagerErrorDistanceTooLow: Desired mean trigger distance is too low.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
typedef NS_ENUM (NSInteger, ESTMonitoringV2ManagerError) {
    ESTMonitoringV2ManagerErrorBluetoothNotSupported        = 1,
    ESTMonitoringV2ManagerErrorUnauthorizedToUseBluetooth   = 2,
    ESTMonitoringV2ManagerErrorBluetoothOff                 = 3,
    ESTMonitoringV2ManagerErrorDesiredDistanceTooLow        = 4,
    ESTMonitoringV2ManagerErrorUnauthorizedToMonitorBeacons = 5
};

/**
 Describes messages sent from Monitoring Manager to its delegate object.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@protocol ESTMonitoringV2ManagerDelegate <NSObject>

@required

/**
 Called when monitoring has failed because of invalid configuration, permissions or Bluetooth problems.
 The error object's <code>code</code> is a case of <code>ESTMonitoringV2ManagerError</code> enum.
 The error object's <code>domain</code> is <code>ESTMonitoringV2ManagerErrorDomain</code>.

 @param manager Monitoring manager reporting the error.
 @param error   Error object.
 */
- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didFailWithError:(NSError *)error;

@optional

/**
 Called when monitoring has started successfully.

 @param manager Monitoring manager.
 */
- (void)monitoringManagerDidStart:(ESTMonitoringV2Manager *)manager;

/**
 Called when a monitoring state for a proximity zone defined by a beacon was first determined.

 @param manager Monitoring manager reporting the event.
 @param state Monitoring state for the zone.
 @param identifier Identifier of the beacon defining the zone.
 */
- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didDetermineInitialState:(ESTMonitoringState)state forBeaconWithIdentifier:(NSString *)identifier;

/**
 Called when user entered proximity defined by <code>meanTriggerDistance</code> of the monitored device.

 @param manager    Monitoring manager reporting the event.
 @param identifier Device identifier broadcasted in the Estimote Location packet that triggered the enter event.
 */
- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didEnterDesiredRangeOfBeaconWithIdentifier:(NSString *)identifier;

/**
 Called when user exited proximity defined by <code>meanTriggerDistance</code> of the monitored device.

 @param manager    Monitoring manager reporting the event.
 @param identifier Device identifier broadcasted in the Estimote Location packet that triggered the enter event.
 */
- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didExitDesiredRangeOfBeaconWithIdentifier:(NSString *)identifier;

/**
 Called when the authorization status for the application related to beacon monitoring has changed.

 @param manager Monitoring manager reporting the event.
 @param authorizationStatus New authorization status for the application.
 */
- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)authorizationStatus;

@end

/**
 Handles beacon enter/exit events using Estimote Monitoring v2.0 algorithm.

 Estimote Monitoring uses Core Bluetooth and Core Location frameworks underneath.
 To make it work when the app is in background, make sure following entries
 are present in <code>Info.plist</code> file:

 - <code>bluetooth-central</code>, AKA "Background Modes" -> "Uses Bluetooth LE accessories". Allows Core Bluetooth
 operation in background.

 - <code>NSBluetoothPeripheralUsageDescription</code>, description for Bluetooth alert.

 - <code>NSLocationAlwaysUsageDescription</code>, description for Location alert.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTMonitoringV2Manager : NSObject

/**
 Distance boundary between inside and outside states passed in initializer.
 */
@property (nonatomic, assign, readonly) double desiredMeanTriggerDistance;

/**
 Delegate object that monitoring methods will be sent to.
 */
@property (nonatomic, weak, readwrite) id<ESTMonitoringV2ManagerDelegate> delegate;

/**
 Core Location region currently used by Estimote Monitoring to improve beacon monitoring reliability
 when the app is in Background.

 Nil before <code>-startMonitoringForIdentifiers:</code> is called or <code>-stopMonitoring</code> wasn't called yet.

 Note:
 This region uses one of 20 Core Location monitoring slots available per app. For more info on global limit
 of Core Location regions visit:
 https://developer.apple.com/library/content/documentation/UserExperience/Conceptual/LocationAwarenessPG/RegionMonitoring/RegionMonitoring.html#//apple_ref/doc/uid/TP40009497-CH9-SW5
 */
@property (nonatomic, strong, readonly, nullable) CLBeaconRegion *backgroundSupportRegion;

/**
 Beacon identifiers that monitoring was set up for using <code>-startMonitoringForIdentifiers:</code>.
 */
@property (nonatomic, strong, readonly) NSSet<NSString *> *monitoredIdentifiers;

/**
 App’s authorization status for beacon monitoring.

 @return Authorization status.
 */
@property (nonatomic, assign, readonly) CLAuthorizationStatus authorizationStatus;

- (instancetype)init NS_UNAVAILABLE;

/**
 Designated initializer.

 Note:
 Due to BLE signal unstability the actual place where notifications occur will differ.
 The value passed as <code>meanTriggerDistance</code> defines the desired mean distance
 from the beacon where events should happen.

 @param meanTriggerDistance Distance boundary between inside and outside states.
 Enter/exit events are reported when crossing these states.
 @param delegate            Delegate object to invoke callbacks on.

 @return Initialized object.
 */
- (instancetype)initWithDesiredMeanTriggerDistance:(double)meanTriggerDistance
                                          delegate:(id<ESTMonitoringV2ManagerDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 Start monitoring beacons with given identifiers and start reporting monitoring events
 for these beacons to <code>delegate</code>.

 Overwrite the previously monitored identifiers when called multiple times.

 Note:
 In order to work, beacon monitoring requires an "Always" or "WhenInUse" authorization to use Core Location services.
 See <code>requestWhenInUseAuthorization</code> and <code>requestAlwaysAuthorization</code> methods.
 In case of insufficient authorization status <code>monitoringManager:didFailWithError:</code> method is called on a delegate.

 @param identifiers Identifiers of beacons to be monitored. Device identifer can be read
 by visiting https://cloud.estimote.com/#/
 */
- (void)startMonitoringForIdentifiers:(NSArray<NSString *> *)identifiers;

/**
 Stop monitoring beacons with identifiers passed to <code>-startMonitoringForIdentififers:</code>.

 Additionally, stop Core Location beacon monitoring for <code>-backgroundSupportRegion</code>.
 */
- (void)stopMonitoring;

/**
 Informs about the current monitoring state of a proximity zone defined by a beacon.

 @param identifier Identifier of the beacon.
 @return Current monitoring state for the zone.
 */
- (ESTMonitoringState)stateForBeaconWithIdentifier:(NSString *)identifier;

/**
 Requests permission for monitoring beacons while the app is in the foreground.
 */
- (void)requestWhenInUseAuthorization;

/**
 Requests permission for monitoring beacons whenever the app is running.
 */
- (void)requestAlwaysAuthorization;

@end

NS_ASSUME_NONNULL_END
