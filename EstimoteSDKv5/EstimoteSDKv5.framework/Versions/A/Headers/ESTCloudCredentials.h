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
 Estimote Cloud credentials encapsulated in a value object. To acquire App ID & App Token go to
 https://cloud.estimote.com/#/apps.
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

@end

NS_ASSUME_NONNULL_END
