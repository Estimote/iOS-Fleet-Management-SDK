//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import "ESTBaseVO.h"


/**
 *  This Value Object represents update of pending settings and firmware information for single device.
 *  Object is used by ESTRequestV2DevicesUpdate.
 */
@interface ESTDeviceUpdateInfo : ESTBaseVO

/**
 *  Identifier of the devices.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  Flag indicating availability of pending settings.
 */
@property (nonatomic, assign, readonly) BOOL pendingSettingsAvailable;

/**
 *  Flag indicating availability of firmware update.
 */
@property (nonatomic, assign, readonly) BOOL firmwareUpdateAvailable;

/**
 *  Method allows to initialise object.
 *
 *  @param identifier               Identifier of the device.
 *  @param pendingSettingsAvailable Flag indicating pending settings availability.
 *  @param firmwareUpdateAvailable  Flag indicating firmware update availability.
 *
 *  @return Initialised object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)identifier
                pendingSettingsAvailable:(BOOL)pendingSettingsAvailable
                 firmwareUpdateAvailable:(BOOL)firmwareUpdateAvailable;

- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

@end
