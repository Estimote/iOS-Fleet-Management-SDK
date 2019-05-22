//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ESTSettingProtocol <NSObject, NSCopying>

@required

/**
 *  Method invoked when read/write operation finished with success.
 *
 *  @param result result of read/write operation
 */
- (void)fireSuccessBlockWithData:(NSData *)result;

/**
 *  Method invoked when read/write operation failed.
 *
 *  @param error NSError containing failure information
 */
- (void)fireFailureBlockWithError:(NSError *)error;

/**
 *  Method returns value of setting.
 *
 *  @return Value of setting. Type of value depends on the setting.
 */
- (id)getValue;

@end

NS_ASSUME_NONNULL_END
