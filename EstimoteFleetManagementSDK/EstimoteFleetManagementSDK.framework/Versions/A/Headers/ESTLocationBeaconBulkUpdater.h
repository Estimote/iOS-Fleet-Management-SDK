//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTLocationBeaconBulkUpdateConfiguration.h"

#define ESTLocationBeaconBulkUpdaterErrorDomain @"ESTLocationBeaconBulkUpdaterErrorDomain"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Defines types of errors that can occur inside the bulk updater mechanis.
 */
typedef NS_ENUM (NSInteger, ESTLocationBeaconBulkUpdaterError) {
    /**
     *  Device passed as a part of bulk update was not in range.
     */
    ESTLocationBeaconBulkUpdaterErrorDeviceDiscoveryFailed,
    /**
     *  No pending changes related to settings and firmawre updated.
     */
    ESTLocationBeaconBulkUpdaterErrorNoPendingChanges,
    /**
     *  Bulk updater timeout.
     */
    ESTLocationBeaconBulkUpdaterErrorTimeout
};

/**
 *  Defines the possible statuses of the whole bulk updater mechanism.
 */
typedef NS_ENUM (NSInteger, ESTBulkUpdaterStatus) {
    /**
     * Bulk updater is ready to `startWithUpdateConfigurations:`.
     */
    ESTBulkUpdaterStatusIdle = 0,

    /**
     *  Bulk updater is performing bulk update actions. Cancel bulk before using `startWithUpdateConfigurations:` again.
     */
    ESTBulkUpdaterStatusRunning
};

/**
 *  Possible update statuses of a device contained in `ESTLocationBeaconBulkUpdateConfiguration`.
 */
typedef NS_ENUM (NSInteger, ESTBulkUpdaterDeviceUpdateStatus) {
    /**
     *  Not able to determine current update status.
     */
    ESTBulkUpdaterDeviceUpdateStatusUnknown,

    /**
     *  Device not detected yet. Scanning in progress.
     */
    ESTBulkUpdaterDeviceUpdateStatusScanning,

    /**
     *  Device detected. Waiting to connect and update settings.
     */
    ESTBulkUpdaterDeviceUpdateStatusPendingUpdate,

    /**
     *  Device is beeing connected to and updated.
     */
    ESTBulkUpdaterDeviceUpdateStatusUpdating,

    /**
     *  Device update succeeded.
     */
    ESTBulkUpdaterDeviceUpdateStatusSucceeded,

    /**
     *  Device update failed.
     */
    ESTBulkUpdaterDeviceUpdateStatusFailed,

    /**
     *  Device out of scanning range.
     */
    ESTBulkUpdaterDeviceUpdateStatusOutOfRange
};

@class ESTLocationBeaconBulkUpdater;

/**
 * `ESTLocationBeaconBulkUpdaterDelegate` protocol defines a list of delegate methods that bulk update will use to inform about its progress.
 */
@protocol ESTLocationBeaconBulkUpdaterDelegate <NSObject>

@optional

/**
 *  Informs bulkdUpdater delegate that list of devices to update was fetched. List of devices can be accessed through `updateConfigurations`.
 */
- (void)bulkUpdaterDidFetchDevices:(ESTLocationBeaconBulkUpdater *)bulkUpdater;

/**
 *  Informs bulkUpdater delegate about a change of status for certain device.
 *
 *  @param bulkUpdater Bulk updater that passes the status change information.
 *
 *  @param updateStatus New update status of a device.
 *
 *  @param deviceIdentifier Identifier of a device for which the update status was changed.
 */
- (void)bulkUpdater:(ESTLocationBeaconBulkUpdater *)bulkUpdater didUpdateStatus:(ESTBulkUpdaterDeviceUpdateStatus)updateStatus forDeviceWithIdentifier:(NSString *)deviceIdentifier;

/**
 *  Informs bulkUpdater delegate about successful end of bulk update procedure.
 *
 *  @param bulkUpdater Bulk updater that processed all `updateConfigurations`.
 */
- (void)bulkUpdaterDidFinish:(ESTLocationBeaconBulkUpdater *)bulkUpdater;

/**
 *  Informs bulkUpdater delegate about bulk update failure.
 *
 *  @param bulkUpdater Bulk updater that failed to process all `updateConfigurations`.
 *
 *  @param error Error containing helpful information about the failure.
 */
- (void)bulkUpdater:(ESTLocationBeaconBulkUpdater *)bulkUpdater didFailWithError:(NSError *)error;

/**
 *  Informs bulkUpdater delegate that caller decided to cancel update.
 */
- (void)bulkUpdaterDidCancel:(ESTLocationBeaconBulkUpdater *)bulkUpdater;

@end

/**
 * Class that can be used to perform bulk updates on new generation Estimote beacons.
 * To start bulk update you need to prepare an array of `ESTLocationBeaconBulkUpdateConfiguration` objects
 * containing a device identifier and an array of `ESTSettingOperation` objects that will be initialized with
 * `ESTSettingReadWrite' subclass objects designed for specific settings.
 */

@interface ESTLocationBeaconBulkUpdater : NSObject

/**
 *  Delegate object that conforms to `ESTLocationBeaconBulkUpdaterDelegate` protocol.
 */
@property (nonatomic, weak) id<ESTLocationBeaconBulkUpdaterDelegate> delegate;

/**
 *  Timeout for bulk update procedure in seconds. Default values is 600s (10 minutes). 0 means no timeout.
 */
@property (nonatomic, assign, readonly) NSTimeInterval timeout;

/**
 *  Interval for device informations fetching from Estimote Cloud.
 */
@property (nonatomic, assign, readonly) NSTimeInterval fetchInterval;

/**
 *  Informs about the current status of bulk updater.
 */
@property (nonatomic, assign, readonly) ESTBulkUpdaterStatus status;

/**
 *  Represents a list of current update configurations.
 */
@property (nonatomic, assign, readonly) NSArray<ESTLocationBeaconBulkUpdateConfiguration *> *updateConfigurations;

/**
 *  Flag controlling whether a firmware update step should be skipped during the Bulk Update process.
 *  If YES, then the step is skipped.
 *  If NO, then the step is performed as usual.
 *  The default value is NO.
 */
@property (nonatomic, readwrite) BOOL skipsFirmwareUpdateStep;

/**
 * Designated initializer.
 *
 * @param queue A queue used for dispatching events of a `CBCentralManager` instance used for device discovery.
 * @return Initialized object.
 */
- (instancetype)initWithCBCentralManagerQueue:(dispatch_queue_t)queue NS_DESIGNATED_INITIALIZER;

/**
 * Convenience initializer.
 *
 * @return Initialized object.
 */
- (instancetype)init;

/**
 *  Starts `ESTLocationBeaconBulkUpdater` with current pending settings from Estimote Cloud.
 */
- (void)start;

/**
 *  Starts `ESTLocationBeaconBulkUpdater` with current pending settings from Estimote Cloud.
 *
 * @param timeout Bulk Updater timeout. 0 means no timeout.
 *
 */
- (void)startWithTimeout:(NSTimeInterval)timeout;

/**
 *  Starts `ESTLocationBeaconBulkUpdater` with current pending settings from Estimote Cloud.
 *
 * @param timeout Bulk Updater timeout. 0 means no timeout.
 * @param fetchInterval Bulk Updater fetch interval. 0 represents default 5 min.
 *
 */
- (void)startWithTimeout:(NSTimeInterval)timeout
           fetchInterval:(NSTimeInterval)fetchInterval;

/**
 * Starts the bulk update procedure.
 * This method will not cause anything if bulk updater is currently performing updates.
 *
 * @see status
 *
 * @param updateConfigurations Array of `ESTLocationBeaconBulkUpdateConfiguration` objects.
 */
- (void)startWithUpdateConfigurations:(NSArray <ESTLocationBeaconBulkUpdateConfiguration *> *)updateConfigurations;

/**
 * Starts the bulk update procedure.
 * This method will not cause anything if bulk updater is currently performing updates.
 *
 * @see status
 *
 * @param updateConfigurations Array of `ESTLocationBeaconBulkUpdateConfiguration` objects.
 * @param timeout Bulk Updater timeout. 0 means no timeout.
 *
 */
- (void)startWithUpdateConfigurations:(NSArray <ESTLocationBeaconBulkUpdateConfiguration *> *)updateConfigurations
                              timeout:(NSTimeInterval)timeout;

/**
 * Cancels the bulk update procedure.
 * Note that, if update for a certain device has already started it might not be canceled.
 */
- (void)cancel;

/**
 * Informs about the update status for a given device identifier.
 *
 * @param deviceIdentifier Identifier of a device.
 *
 * @return `ESTBulkUpdaterUpdateStatus` value, informing about the current update status.
 */
- (ESTBulkUpdaterDeviceUpdateStatus)statusForDeviceWithIdentifier:(NSString *)deviceIdentifier;

/**
 *  Count of already updated devices.
 */
- (NSInteger)numberOfSuccessfulUpdates;

/**
 *  Count of already failed devices' updates.
 */
- (NSInteger)numberOfFailedUpdates;

@end

NS_ASSUME_NONNULL_END
