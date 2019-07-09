//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceLocationBeacon.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ESTFeaturesetBackgroundMode encapsulates operations required for Background Mode's functionality.
 *  The algorithm relies on Generic Adevrtiser, and this helper tool ensures that
 *  the settings are set properly.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTFeaturesetBackgroundMode : NSObject

/**
 *  Designated initializer.
 *
 *  @param device Next Gen device the settings are to be applied to.
 */
- (instancetype)initWithDevice:(ESTDeviceLocationBeacon *)device;

/**
 *  Perform read operations for settings related to Background Mode, decide whether they satisfy
 *  prerequisites for Background Mode and call <code>completion</code> when all are done.
 *
 *  @param completion Completion block invoked after all operations are done (either successfully or not).
 *
 *  @discussion
 *  If all underlying operations succeed, <code>completion</code>'s <code>featuresetEnabled</code> tells
 *  whether Background Mode prerequisites are met, <code>errors</code> is nil.
 *
 *  If any of underlying operation fails, <code>completion</code>'s <code>featuresetEnabled</code>
 *  is set to <code>NO</code>, and <code>errors</code> array contains errors resulting from failed operations.
 */
- (void)readSettingsWithCompletion:(void (^)(BOOL featuresetEnabled, NSArray<NSError *> *_Nullable errors))completion;

/**
 *  Write Background Mode values for settings related to EM algorithms.
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
- (void)writeEnableSettings:(BOOL)enabled withCompletion:(void (^)(NSArray<NSError *> *_Nullable errors))completion;

/**
 *  Settings that were written when executing this featureset, for Estimote SDK versions <= 4.22.1.
 *  Calls +classNamesToSettingsForDeviceIdentifier: with nil.
 *
 *  @return Dictionary with setting class names as keys, setting objects as values.
 */
+ (NSDictionary<NSString *, ESTSettingBase *> *) classNamesToSettings
    DEPRECATED_MSG_ATTRIBUTE("Use +classNamesToSettingsForDeviceIdentifier: instead");

/**
 *  Settings written when executing this featureset. This method requires passing device identifier,
 *  because Generic Advertiser data setting value depends on it.
 *
 *  @param deviceIdentifier Identifier of the device that should have the settings applied.
 *
 *  @return Dictionary with setting class names as keys, setting objects as values.
 */
+ (NSDictionary<NSString *, ESTSettingBase *> *)classNamesToSettingsForDeviceIdentifier:(nullable NSString *)deviceIdentifier;

/**
 *  Write operations for this featureset, for Estimote SDK versions <= 4.22.1.
 *  Calls +classNamesToSettingsForDeviceIdentifier: with nil.

 */
+ (NSArray <id<ESTBeaconOperationProtocol> > *) getWriteOperations
    DEPRECATED_MSG_ATTRIBUTE("Use +getWriteOperationsForDeviceIdentifier: instead");

/**
 *  An array containing write operations from given featureset.
 *  This method requires passing device identifier, because Generic Advertiser data setting value depends on it.
 */
+ (NSArray <id<ESTBeaconOperationProtocol> > *)getWriteOperationsForDeviceIdentifier:(nullable NSString *)deviceIdentifier;

/**
 *  Determine whether the provided settings represent a proper configuration for Estimote Monitoring.
 *  Supports providing more settings than required specifically for the check.
 *  This method requires passing device identifier, because Generic Advertiser data setting value depends on it.
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
