//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceLocationBeacon.h"
#import "ESTDeviceNearable.h"
#import "ESTTelemetryNotificationProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class ESTDeviceManager;

@protocol ESTDeviceManagerDelegate <NSObject>

@optional

/**
 * Tells the delegate that one or more Estimote devices were discovered in the vicinity of the iOS device.
 * Actual class of objects depend on filter used to start the manager.
 *
 * @param manager The utility manager object reporting the event.
 * @param devices An array of ESTDevice subclass objects representing the discovered devices.
 *
 * @see ESTDeviceFilterIBeacon, ESTDeviceFilterTypeUtility.
 */
- (void)deviceManager:(ESTDeviceManager *)manager didDiscoverDevices:(NSArray<ESTDevice *> *)devices;

/**
 * Tells the delegate that a discovery error occurred.
 *
 * @param manager The utility manager object reporting the event.
 */
- (void)deviceManagerDidFailDiscovery:(ESTDeviceManager *) manager DEPRECATED_MSG_ATTRIBUTE("Since 4.27.0 please use deviceManager:didFailWithError:");

/**
 Tells the delegate the exact reason of discovery failure.

 @param manager The utility manager object reporting the event.
 @param error Failure error.
 */
- (void)deviceManager:(ESTDeviceManager *)manager didFailDiscoveryWithError:(NSError *)error;

@end

@protocol ESTDeviceFilter;

/**
 * The `ESTDeviceManager` class defines the interface for utility methods related to Estimote devices.
 * The main functionality allows to discover CoreBluetooth based representation of Estimote Beacon devices.
 *
 * One device manager instance can discover devices only with one filter at a time.
 */

@interface ESTDeviceManager : NSObject

/**
 *  Informs if a filtered or telemetry scan is in progress.
 */
@property (nonatomic, assign, readonly) BOOL isScanning;

/**
 *  Delegate to be informed about scan results every 1 sec.
 */
@property (nonatomic, weak) id<ESTDeviceManagerDelegate> delegate;

/**
 Designated initializer.

 @param queue A queue used for dispatching events of a `CBCentralManager` instance used for device discovery.
 @return Initialized object.
 */
- (instancetype)initWithCBCentralManagerQueue:(dispatch_queue_t)queue NS_DESIGNATED_INITIALIZER;

/**
 Convenience initializer.

 @return Initialized object.
 */
- (instancetype)init;

/**
 *  Start discovering Estimote devices determined by the filter, using CoreBluetooth.
 *  One filter can be active per a ESTDeviceManager instance.
 *  If called multiple times only the last provided filter is active.
 *
 *  Causes the delegate to be called with -[ESTDeviceManagerDelegate deviceManager:didDiscoverDevices:] every 1 sec.
 *
 *  @param filter Object conforming to ESTDeviceFilter protocol. Should be
 */
- (void)startDeviceDiscoveryWithFilter:(id<ESTDeviceFilter>)filter;

/**
 *  Stops Estimote device discovery.
 */
- (void)stopDeviceDiscovery;

/**
 *  Use this method to register objects that implement
 *  ESTTelemetryNotificationProtocol to receive updates
 *  about specific telemetry notifications.
 *
 *  @param infos Array of objects conforming to ESTTelemetryNotificationProtocol.
 */
- (void)registerForTelemetryNotifications:(NSArray <ESTTelemetryNotificationProtocol> *) infos DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.");

/**
 *  Use this method to register object that implements
 *  ESTTelemetryNotificationProtocol to receive updates
 *  about specific telemetry notifications.
 *
 *  @param info Single object conforming to ESTTelemetryNotificationProtocol.
 */
- (void)registerForTelemetryNotification:(id <ESTTelemetryNotificationProtocol>) info DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.");

/**
 *  Use this method to unregister object that implements
 *  ESTTelemetryNotificationProtocol from receiving updates
 *  about specific telemetry notifications.
 *
 *  @param info Single object conforming to ESTTelemetryNotificationProtocol.
 */
- (void)unregisterForTelemetryNotification:(id <ESTTelemetryNotificationProtocol>) info DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.");

@end

NS_ASSUME_NONNULL_END
