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

- (id)initWithDeviceIdentifier:(NSString *)deviceIdentifier settingsOperations:(NSArray <ESTSettingOperation *> *)settingsOperations;

@end

NS_ASSUME_NONNULL_END
