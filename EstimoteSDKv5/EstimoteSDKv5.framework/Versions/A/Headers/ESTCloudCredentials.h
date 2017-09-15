//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 Estimote Cloud credentials available as a singleton.
 Go to https://cloud.estimote.com/#/apps to acquire them.
 
 You should call `+setUpSharedInstanceWithAppID:appToken:` and `+sharedInstance` to get an instance of this class.
 However, if you really need a non-singleton instance, use `-initWithAppID:appToken`.
 */
@interface ESTCloudCredentials : NSObject

/**
 App ID generated in Estimote Cloud.
 */
@property (nonatomic, strong, readonly) NSString *appID;

/**
 App Token generated in Estimote Cloud.
 */
@property (nonatomic, strong, readonly) NSString *appToken;

/**
 Cloud credentials singleton.
 
 Note: this property is set by `+setUpSharedInstanceWithAppID:appToken:`. If the method wasn't called yet, or
 after `+removeSharedInstance` was called, this property is nil.
 */
@property (nonatomic, strong, readonly, class, nullable) ESTCloudCredentials *sharedInstance NS_SWIFT_NAME(shared);

/**
 Init is disabled for this class.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 New is disabled for this class.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initializer.

 @param appID App ID generated in Estimote Cloud.
 @param appToken App Token generated in Estimote Cloud.
 */
- (instancetype)initWithAppID:(NSString *)appID appToken:(NSString *)appToken NS_DESIGNATED_INITIALIZER;

/**
 Create a shared instance and store it globally. Calling this method causes +sharedInstance 
 to return an object instead of nil.

 @param appID App ID generated in Estimote Cloud.
 @param appToken App Token generated in Estimote Cloud.
 */
+ (void)setUpSharedInstanceWithAppID:(NSString *)appID
                            appToken:(NSString *)appToken NS_SWIFT_NAME(setUpSharedInstance(appID:appToken:));

/**
 Remove shared instance. Calling this method causes `+sharedInstance` to return nil.
 */
+ (void)removeSharedInstance;

@end

NS_ASSUME_NONNULL_END
