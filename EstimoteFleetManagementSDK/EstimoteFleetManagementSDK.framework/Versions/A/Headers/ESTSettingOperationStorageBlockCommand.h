//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingStorageBlockCommand.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingOperationStorageBlockCommand allows to create read/write operations for Storage StorageBlockCommand setting of a device.
 */
@interface ESTSettingOperationStorageBlockCommand : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create write operation for Storage StorageBlockCommand setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingStorageBlockCommand *)setting completion:(ESTSettingStorageBlockCommandCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
