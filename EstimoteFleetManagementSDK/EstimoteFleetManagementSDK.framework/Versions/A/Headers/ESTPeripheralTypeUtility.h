//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTPeripheral.h"
#import "ESTDefinitions.h"
#import "ESTDeviceNotificationProtocol.h"

#define ESTPeripheralTypeUtilityErrorDomain @"ESTPeripheralTypeUtilityErrorDomain"

/**
 Possible operations errors while handling sending to and recieving data from peripheral.
 */
typedef NS_ENUM(NSInteger, ESTPeripheralTypeUtilityError) {
    /**
     Operation failed.
     */
    ESTPeripheralTypeUtilityErrorReadWriteOperationFailed,
    /**
     Generating packets failed.
     */
    ESTPeripheralTypeUtilityErrorPacketGenerationFailed
};

/**
 Errors when handling peripheral packets.
 */
typedef NS_ENUM(NSInteger, ESTPeripheralTypeUtilityErrorCode) {
    /**
     Unknown error.
     */
    ESTPeripheralTypeUtilityErrorCodeUnknown,
    /**
     Packet has invalid CRC checksum.
     */
    ESTPeripheralTypeUtilityErrorCodeInvalidCRC,
    /**
     Register identifier changed.
     */
    ESTPeripheralTypeUtilityErrorCodeRegisterIDChanged,
    /**
     Index of the chunk is invalid.
     */
    ESTPeripheralTypeUtilityErrorCodeInvalidChunkIndex,
    /**
     Packet has invalid length.
     */
    ESTPeripheralTypeUtilityErrorCodeInvalidLength,
    /**
     Packet has invalid size.
     */
    ESTPeripheralTypeUtilityErrorCodeInvalidValueSize,
    /**
     Packet has invalid value.
     */
    ESTPeripheralTypeUtilityErrorCodeInvalidValue,
    /**
     Register identifier is invalid.
     */
    ESTPeripheralTypeUtilityErrorCodeInvalidRegisterID,
    /**
     Operation is not allowed.
     */
    ESTPeripheralTypeUtilityErrorCodeInvalidOperation,
    /**
     Authorization level is insufficient.
     */
    ESTPeripheralTypeUtilityErrorCodeTooLowAuthLevel,
    /**
     Operation is blocked.
     */
    ESTPeripheralTypeUtilityErrorCodeOperationBlocked,
    /**
     Request was correct, but there is no more data to be read.
     */
    ESTPeripheralTypeUtilityErrorCodeNoDataReturned,
    /**
     Waiting for more data.
     */
    ESTPeripheralTypeUtilityErrorCodeWaitingForMore
};

/**
 *  State of device firmware.
 */
typedef NS_ENUM(NSInteger, ESTPeripheralFirmwareState) {
    /**
     *  Unknown state.
     */
    ESTPeripheralFirmwareStateUnknown,
    /**
     *  Bootloader state. Ready to be updated Over The Air.
     */
    ESTPeripheralFirmwareStateBoot,
    /**
     *  Application state. Ready to interact with settings.
     */
    ESTPeripheralFirmwareStateApp
};


/**
 *  ESTPeripheralTypeUtility delegate protocol.
 */
@protocol ESTPeripheralTypeUtilityDelegate <NSObject>

/**
 *  Method invoked after single operation was performed with the device successfully.
 *
 *  @param peripheral Peripheral object that performed operation.
 *  @param operation  Operation that was performed.
 *  @param data       Data received from the device to be deserialized.
 */
- (void)peripheral:(id<ESTPeripheral>)peripheral didPerformOperation:(id<ESTBeaconOperationProtocol>)operation andReceivedData:(NSData *)data;

/**
 *  Method invoked after single operation failed while communicating with the device.
 *
 *  @param peripheral Peripheral object that tried to perform operation.
 *  @param operation  Operation that was to be performed.
 *  @param error      Error explaining the failure reason.
 */
- (void)peripheral:(id<ESTPeripheral>)peripheral didFailOperation:(id<ESTBeaconOperationProtocol>)operation withError:(NSError *)error;

@end


/**
 *  ESTPeripheralTypeUtility is a wrapper around CBPeripheral object of beacon device.
 *  It allows to perform bluetooth only read/write operation on the device and reboot device;.
 */
@interface ESTPeripheralTypeUtility : NSObject <ESTPeripheral>

/**
 *  Flag indicates what is current firmware state (Unknown, App, Boot).
 */
@property (nonatomic, readonly) ESTPeripheralFirmwareState firmwareState;

/**
 *  Delegate object for `ESTPeripheralTypeUtility` class object.
 */
@property (nonatomic, strong) id<ESTPeripheralTypeUtilityDelegate> delegate;

/**
 *  Delegate object to be informed about device notification event.
 */
@property (nonatomic, weak) id<ESTPeripheralNotificationDelegate> notificationDelegate;

/**
 *  Restart device and put it into boot mode, what allows to perform
 *  Over The Air update.
 *
 *  @param completion Blocked invoked when reset is complete.
 */
- (void)resetPeripheralToBootWithCompletion:(ESTCompletionBlock)completion;

/**
 *  Perform read/write operation for setting.
 *
 *  @param operation Operation that should be performed.
 */
- (void)performSettingOperation:(id<ESTBeaconOperationProtocol>)operation;

/**
 *  Register for notifications from device provided during connection.
 *
 *  @param notification Notification we should register for.
 */
- (void)registerNotification:(id<ESTDeviceNotificationProtocol>)notification;

/**
 Unregister all notificaitons from device.
 */
- (void)unregisterAllNotifications;

@end
