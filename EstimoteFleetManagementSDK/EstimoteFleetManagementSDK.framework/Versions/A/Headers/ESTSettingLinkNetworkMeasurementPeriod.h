//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingLinkNetworkMeasurementPeriodErrorDomain @"ESTSettingLinkNetworkMeasurementPeriodErrorDomain"

@class ESTSettingLinkNetworkMeasurementPeriod;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting MeasurementPeriod operation for Link Network packet.
 *
 *  @param measurementPeriodSetting MeasurementPeriod setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingLinkNetworkMeasurementPeriodCompletionBlock)(ESTSettingLinkNetworkMeasurementPeriod * _Nullable measurementPeriodSetting, NSError * _Nullable error);


/**
 *  ESTSettingLinkNetworkMeasurementPeriod represents Link Network MeasurementPeriod value.
 */
@interface ESTSettingLinkNetworkMeasurementPeriod : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingLinkNetworkMeasurementPeriod validationErrorForValue:]
 *
 *  @param measurementPeriod Link Network MeasurementPeriod value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint8_t)measurementPeriod;

/**
 *  Returns current value of Link Network MeasurementPeriod setting.
 *
 *  @return Link Network MeasurementPeriod value.
 */
- (uint8_t)getValue;

/**
 *  Method allows to read value of initialized Link Network MeasurementPeriod setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingLinkNetworkMeasurementPeriodCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Link Network MeasurementPeriod setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param measurementPeriod MeasurementPeriod value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint8_t)measurementPeriod completion:(ESTSettingLinkNetworkMeasurementPeriodCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
