//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceSettingProtocol.h"
#import "ESTCloudSettingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTSettingiBeaconMacErrorDomain @"ESTSettingiBeaconMacErrorDomain"

/**
 *  Block used to inform about read/write operation completion.
 *
 *  @param mac Mac address broadcast by beacon while broadcasting iBeacon packet.
 *  @param error Operation error. No error means success.
 */
typedef void (^ESTSettingiBeaconMacCompletionBlock)(NSString *mac, NSError *_Nullable error);


/**
 * ESTSettingiBeaconMac allows to set mac address to broadcast in iBeacon packet.
 */
@interface ESTSettingiBeaconMac : NSObject <ESTDeviceSettingProtocol, ESTCloudSettingProtocol>


/**
 *  Initialization method used for read operation.
 *
 *  @param completion Completion block fired when operation is done.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCompletion:(ESTSettingiBeaconMacCompletionBlock)completion;


/**
 *  Method allows to initialize setting object for write operation.
 *
 *  @param mac Mac address to save in beacon.
 *  @param completion Completion block fired when operation is done.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)mac
                   completion:(ESTSettingiBeaconMacCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
