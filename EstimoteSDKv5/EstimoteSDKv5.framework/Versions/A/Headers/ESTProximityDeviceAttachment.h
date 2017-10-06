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
 Represents JSON attached to a device in Estimote Cloud.
 For the alpha & beta releases, attachment is encoded as a device tag with JSON string contents.
 See https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info.
 */
@interface ESTProximityDeviceAttachment : NSObject

/**
 Device identifier that has the attachment.
 */
@property (nonatomic, strong, readonly) NSString *deviceIdentifier;

/**
 JSON attached to the device (tag parsed to JSON).
 */
@property (nonatomic, strong, readonly) NSDictionary<NSString *, id> *json;

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

 @param deviceIdentifier Device identifier that has the attachment.
 @param json JSON attached to the device (tag parsed to JSON).
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier
                                    json:(NSDictionary<NSString *, id> *)json NS_DESIGNATED_INITIALIZER;

#pragma mark Equality

/**
 Compare attachment objects. For both obhects, this method invokes `-[NSString isEqualToString:]` on `deviceIdentifier`
 and `-[NSDictionary isEqualToDictionary:]` on `attachmentJSON`.
 */
- (BOOL)isEqualToAttachment:(ESTProximityDeviceAttachment *)other;

/**
 Compare pointer values, classes and invoke `-isEqualToAttachment`.
 */
- (BOOL)isEqual:(nullable id)other;

/**
 `deviceIdentifier` hash XORed with `attachmentJSON` hash.
 */
- (NSUInteger)hash;

@end

NS_ASSUME_NONNULL_END
