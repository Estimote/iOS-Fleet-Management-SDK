//  Estimote Fleet Management SDK
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshFirmwarePropagateCommandErrorDomain @"ESTSettingMeshFirmwarePropagateCommandErrorDomain"

/**
 *  Describes ESTMeshCommand possible values.
 */
typedef NS_ENUM(NSUInteger, ESTMeshCommand)
{
    /**
     *  Command for triggering firmware propagation across Mesh network.
     */
    ESTMeshCommandPropagateFirmware = 1
};

/**
 *  Describes ESTMeshCommand setting validation error.
 */
typedef NS_ENUM(NSUInteger, ESTMeshCommandError)
{
    /**
     *  Provided value is out of range.
     */
    ESTMeshCommandErrorOutOfRange = 1
};

@class ESTSettingMeshFirmwarePropagateCommand;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of write setting FirmwarePropagate operation for Mesh packet.
 *
 *  @param firmwarePropagateSetting FirmwarePropagate setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshFirmwarePropagateCompletionBlock)(ESTSettingMeshFirmwarePropagateCommand * _Nullable firmwarePropagateSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshFirmwarePropagate represents Mesh FirmwarePropagate value.
 */
@interface ESTSettingMeshFirmwarePropagateCommand : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshFirmwarePropagateCommand validationErrorForValue:]
 *
 *  @param meshCommand  Value of command to be used.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTMeshCommand)meshCommand;

/**
 *  Returns current value of Mesh  setting.
 *
 *  @return ESTMeshCommand value.
 */
- (ESTMeshCommand)getValue;

/**
 *  Method allows to create write operation from already initialized Mesh ESTMeshCommand setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param meshCommand  ESTMeshCommand value to be written to the device.
 *  @param completion   Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTMeshCommand)meshCommand completion:(ESTSettingMeshFirmwarePropagateCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param meshCommand ESTMeshCommand value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTMeshCommand)meshCommand;

@end

NS_ASSUME_NONNULL_END
