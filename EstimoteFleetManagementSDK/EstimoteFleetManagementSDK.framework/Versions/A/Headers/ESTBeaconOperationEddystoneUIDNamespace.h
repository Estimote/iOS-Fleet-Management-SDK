//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingEddystoneUIDNamespace.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationEddystoneUIDNamespace allows to create read/write operations for Eddystone UID Namespace setting of a device.
 */
@interface ESTBeaconOperationEddystoneUIDNamespace : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Eddystone UID Namespace setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingEddystoneUIDNamespaceCompletionBlock)completion;

/**
 *  Method allows to create write operation for Eddystone UID Namespace setting.
 *
 *  @param setting      Value to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingEddystoneUIDNamespace *)setting completion:(ESTSettingEddystoneUIDNamespaceCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
