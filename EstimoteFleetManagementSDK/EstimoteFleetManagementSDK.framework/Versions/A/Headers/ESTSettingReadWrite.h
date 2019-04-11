//  FleetManagementSDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadOnly.h"
#import "ESTBeaconOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingReadWrite serves as a base class for Read/Write settings defining
 *  set of methods required to create read and write operations.
 */
@interface ESTSettingReadWrite : ESTSettingReadOnly

/**
 *  Method allows to perform write operation for initialized setting object.
 *
 *  @param value Value that should be written to the device.
 *  @param completion Block invoked when write operation is complete.
 */
- (void)writeValue:(id)value
        completion:(ESTSettingCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
