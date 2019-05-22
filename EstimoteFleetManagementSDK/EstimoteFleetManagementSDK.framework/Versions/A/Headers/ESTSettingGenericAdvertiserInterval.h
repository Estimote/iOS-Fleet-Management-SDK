//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"
#import "ESTGenericAdvertiserID.h"

#define ESTSettingGenericAdvertiserIntervalErrorDomain @"ESTSettingGenericAdvertiserIntervalErrorDomain"

/**
 *  Describes GenericAdvertiser GenericAdvertiserInterval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingGenericAdvertiserIntervalError)
{
    /**
     *  Provided value is too small.
     */
    ESTSettingGenericAdvertiserIntervalErrorValueTooSmall = 1,
    /**
     *  Provided value is too big.
     */
    ESTSettingGenericAdvertiserIntervalErrorValueTooBig,
    /**
     *  Provided Advertiser ID is invalid.
     */
    ESTSettingGenericAdvertiserIntervalErrorInvalidAdvertiserID
};

@class ESTSettingGenericAdvertiserInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting GenericAdvertiserInterval operation for GenericAdvertiser packet.
 *
 *  @param genericAdvertiserIntervalSetting GenericAdvertiserInterval setting carrying value.
 *  @param error Operation error.           No error means success.
 */
typedef void(^ESTSettingGenericAdvertiserIntervalCompletionBlock)(ESTSettingGenericAdvertiserInterval * _Nullable genericAdvertiserIntervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingGenericAdvertiserInterval represents GenericAdvertiser GenericAdvertiserInterval value.
 */
@interface ESTSettingGenericAdvertiserInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Generic advertiser slot identifier. Check `ESTGenericAdvertiserID` for available options.
 */
@property (nonatomic, strong, readonly) NSNumber *advertiserID;

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGenericAdvertiserInterval validationErrorForValue:]
 *
 *  @param genericAdvertiserInterval GenericAdvertiser GenericAdvertiserInterval value.
 *  @param advertiserID GenericAdvertiser ID.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(unsigned short)genericAdvertiserInterval
                 advertiserID:(ESTGenericAdvertiserID)advertiserID;

- (instancetype)initWithData:(NSData *)data
                advertiserID:(ESTGenericAdvertiserID)advertiserID;

/**
 *  Returns current value of GenericAdvertiser GenericAdvertiserInterval setting.
 *
 *  @return GenericAdvertiser GenericAdvertiserInterval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized GenericAdvertiser GenericAdvertiserInterval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 */
- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GenericAdvertiser GenericAdvertiserInterval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param genericAdvertiserInterval GenericAdvertiserInterval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 */
- (void)writeValue:(unsigned short)genericAdvertiserInterval completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param interval     GenericAdvertiser Interval value.
 *  @param advertiserID GenericAdvertiser ID.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)interval advertiserID:(ESTGenericAdvertiserID)advertiserID;

@end

NS_ASSUME_NONNULL_END
