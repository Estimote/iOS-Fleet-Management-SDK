//  FleetManagementSDK
//  Copyright © 2016 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTSettingOperation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class used by bulk updater to store a device identifier 
 * together with an array of settings operations 
 * that should be performed on that device after discovery and connection.
 */
@interface ESTLocationBeaconBulkUpdateConfiguration : NSObject

/**
 * Identifier of a device that should be discovered and updated.
 */
@property (nonatomic, strong, readonly) NSString *deviceIdentifier;

/**
 *  Array of `ESTSettingOperation` objects that should be performed on that device.
 */
@property (nonatomic, strong, readonly) NSArray <ESTSettingOperation *>*settingsOperations;

/**
 *  Flag indicating firmware updated is available.
 */
@property (nonatomic, assign, readonly) BOOL firmwareUpdateAvailable;

/**
 *  Date when update configuration object was initialized.
 */
@property (nonatomic, strong) NSDate *createdAt;

/**
 *  Date when the device was last detected.
 */
@property (nonatomic, strong) NSDate *lastDetectedAt;

/**
 *  Method allows to initialize ESTLocationBeaconBulkUpdateConfiguration object.
 *
 *  @param deviceIdentifier        Identifier of the device.
 *  @param settingsOperations      Array of operations to perform.
 *  @param firmwareUpdateAvailable Flag indicating firmware update is available.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier
                      settingsOperations:(NSArray <ESTSettingOperation *> *)settingsOperations
                 firmwareUpdateAvailable:(BOOL)firmwareUpdateAvailable;

@end

NS_ASSUME_NONNULL_END
