//  FleetManagementSDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"
#import "ESTGenericAdvertiserID.h"

#define ESTSettingGenericAdvertiserEnableErrorDomain @"ESTSettingGenericAdvertiserEnableErrorDomain"

/**
 *  Describes GenericAdvertiser GenericAdvertiserPower validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingGenericAdvertiserEnableError)
{
    /**
     *  Provided Advertiser ID is invalid.
     */
    ESTSettingGenericAdvertiserEnableErrorInvalidAdvertiserID = 1
};


@class ESTSettingGenericAdvertiserEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting GenericAdvertiserEnabled operation for GenericAdvertiser packet.
 *
 *  @param genericAdvertiserEnabledSetting GenericAdvertiserEnabled setting carrying value.
 *  @param error Operation error.          No error means success.
 */
typedef void(^ESTSettingGenericAdvertiserEnableCompletionBlock)(ESTSettingGenericAdvertiserEnable * _Nullable genericAdvertiserEnabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingGenericAdvertiserEnable represents GenericAdvertiser GenericAdvertiserEnabled value.
 */
@interface ESTSettingGenericAdvertiserEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Generic advertiser slot identifier. Check `ESTGenericAdvertiserID` for available options.
 */
@property (nonatomic, strong, readonly) NSNumber *advertiserID;

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:genericAdvertiserID:.
 *
 *  @see +[ESTSettingGenericAdvertiserEnable validationErrorForValue:]
 *
 *  @param genericAdvertiserEnabled GenericAdvertiser GenericAdvertiserEnabled value.
 *  @param advertiserID GenericAdvertiser ID represented by ESTGenericAdvertiserID enum.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)genericAdvertiserEnabled
                 advertiserID:(ESTGenericAdvertiserID)advertiserID;



- (instancetype)initWithData:(NSData *)data
                advertiserID:(ESTGenericAdvertiserID)advertiserID;

/**
 *  Returns current value of GenericAdvertiser GenericAdvertiserEnabled setting.
 *
 *  @return GenericAdvertiser GenericAdvertiserEnabled value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized GenericAdvertiser GenericAdvertiserEnabled setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GenericAdvertiser GenericAdvertiserEnabled setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param genericAdvertiserEnabled GenericAdvertiserEnabled value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)genericAdvertiserEnabled completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param enabled      GenericAdvertiser Enabled value.
 *  @param advertiserID GenericAdvertiser ID.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)enabled advertiserID:(ESTGenericAdvertiserID)advertiserID;

@end

NS_ASSUME_NONNULL_END
