//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingBase.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationProtocol has to be implemented by Cloud-only setting operations.
 */
@protocol ESTCloudOperationProtocol <NSObject>

/**
 *  Return ESTSettingBase subclass associated with the operation.
 *
 *  @return Setting class.
 */
- (Class)settingClass;

/**
 *  Replaces operation setting with another one containing value fetched from Cloud.
 *
 *  @param setting New setting object.
 */
- (void)updateSettingWithSetting:(ESTSettingBase *)setting;

@end

NS_ASSUME_NONNULL_END
