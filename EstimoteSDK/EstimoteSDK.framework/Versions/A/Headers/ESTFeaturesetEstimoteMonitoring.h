//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceLocationBeacon.h"


NS_ASSUME_NONNULL_BEGIN

/**
 *  ESTFeaturesetEstimoteMonitoring encapsulates operations required for Estimote Monitoring's functionality.
 *  The algorithm relies on Estimote Location being advertised, and this helper tool ensures that 
 *  the settings are set properly.
 */
@interface ESTFeaturesetEstimoteMonitoring : NSObject

/**
 *  Designated initializer.
 *
 *  @param device Next Gen device the settings are to be applied to.
 */
- (instancetype)initWithDevice:(ESTDeviceLocationBeacon *)device;

/**
 *  Perform read operations for settings related to Estimote Monitoring, decide whether they satisfy
 *  prerequisites for Estimote Monitoring and call <code>completion</code> when all are done.
 *
 *  @param completion Completion block invoked after all operations are done (either successfully or not).
 *
 *  @discussion
 *  If all underlying operations succeed, <code>completion</code>'s <code>featuresetEnabled</code> tells 
 *  whether Estimote Monitoring prerequisites are met, <code>errors</code> is nil.
 *
 *  If any of underlying operation fails, <code>completion</code>'s <code>featuresetEnabled</code> 
 *  is set to <code>NO</code>, and <code>errors</code> array contains errors resulting from failed operations.
 */
- (void)readSettingsWithCompletion:(void (^)(BOOL featuresetEnabled, NSArray<NSError *> * _Nullable errors))completion;

/**
 *  Write Estimote Monitoring values for settings related to EM algorithms.
 *  Call <code>completion</code> when all setting operations are done.
 *
 *  @param completion Completion block invoked after all operations are done (either successfully or not).
 *
 *  @discussion
 *  If all underlying operations succeed, <code>completion</code>'s <code>errors</code> is nil.
 *
 *  If any of underlying operation fails, <code>completion</code>'s <code>errors</code> array
 *  contains errors resulting from failed operations.
 */
- (void)writeEnableSettings:(BOOL)enabled withCompletion:(void (^)(NSArray<NSError *> * _Nullable errors))completion;

/**
 *  Settings that were written when executing this featureset, for Estimote SDK versions <= 4.22.1.
 *  Calls +classNamesToSettingsForDeviceIdentifier: with nil.
 *
 *  @return Dictionary with setting class names as keys, setting objects as values.
 */
+ (NSDictionary<NSString *, ESTSettingBase *> *)classNamesToSettings
DEPRECATED_MSG_ATTRIBUTE("Use +classNamesToSettingsForDeviceIdentifier: instead");

/**
 *  Settings written when executing this featureset. 
 *  This method requires passing device identifier, because Generic Advertiser data setting 
 *  (in particular: its MAC address) depends on the identifier.
 *  If a nil value is passed, MAC address in Generic Advertiser data setting is set to 6 bytes of 0xFF.
 *
 *  @param deviceIdentifier Identifier of the device that should have the settings applied.
 *
 *  @return Dictionary with setting class names as keys, setting objects as values.
 */
+ (NSDictionary<NSString *, ESTSettingBase *> *)classNamesToSettingsForDeviceIdentifier:(nullable NSString *)deviceIdentifier;

/**
 *  Write operations for this featureset, for Estimote SDK versions <= 4.22.1.
 *  Calls +getWriteOperationsForDeviceIdentifier: with nil.
 */
+ (NSArray <id<ESTBeaconOperationProtocol>> *)getWriteOperations
DEPRECATED_MSG_ATTRIBUTE("Use +getWriteOperationsForDeviceIdentifier: instead");

/**
 *  An array containing write operations from given featureset.
 *  This method requires passing device identifier, because Generic Advertiser data setting
 *  (in particular: its MAC address) depends on the identifier.
 *  If a nil value is passed, MAC address in Generic Advertiser data setting is set to 6 bytes of 0xFF.
 */
+ (NSArray <id<ESTBeaconOperationProtocol>> *)getWriteOperationsForDeviceIdentifier:(nullable NSString *)deviceIdentifier;

/**
 *  Determine whether the provided settings represent a proper configuration for Estimote Monitoring.
 *  Supports providing more settings than required specifically for the check.
 *
 *  This method requires passing device identifier, because Generic Advertiser data setting
 *  (in particular: its MAC address) depends on the identifier.
 *
 *  For backwards compatibility, this method ignores MAC address part of Generic Advertiser data setting.
 *
 *  @param settingsToTest Array with setting objects to check.
 *  @param deviceIdentifier Identifier of the device that should have the settings applied.
 *
 *  @return YES if the array contains all the settings required for Estimote Monitoring and the setting values
 *          are correct for Estimote Monitoring. NO if the array doesn't contain all the settings required
 *          for Estimote Monitoring or any of the setting values is incorrect Estimote Monitoring.
 */
+ (BOOL)featuresetEnabledForSettings:(NSArray<ESTSettingBase *> *)settingsToTest
                 forDeviceIdentifier:(nullable NSString *)deviceIdentifier;

@end

NS_ASSUME_NONNULL_END
