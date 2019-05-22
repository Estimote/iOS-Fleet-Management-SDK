//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingUWBPhyFrequencyErrorDomain @"ESTSettingUWBPhyFrequencyErrorDomain"

@class ESTSettingUWBPhyFrequency;

/**
 *  Available power levels for UWB packet.
 */
typedef NS_ENUM(uint8_t, ESTUWBPhyFrequency)
{
    ESTUWBPhyFrequencyChanging = 0,
    ESTUWBPhyFrequency3_5GHz = 1,
    ESTUWBPhyFrequency6_5GHz = 2
};


NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting PhyFrequency operation for UWB packet.
 *
 *  @param phyFrequencySetting PhyFrequency setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingUWBPhyFrequencyCompletionBlock)(ESTSettingUWBPhyFrequency * _Nullable phyFrequencySetting, NSError * _Nullable error);


/**
 *  ESTSettingUWBPhyFrequency represents UWB PhyFrequency value.
 *  PhyFrequency describes the UWB channel frequency.
 *  @see ESTUWBPhyFrequency
 */
@interface ESTSettingUWBPhyFrequency : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingUWBPhyFrequency validationErrorForValue:]
 *
 *  @param phyFrequency UWB PhyFrequency value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTUWBPhyFrequency)phyFrequency;

/**
 *  Returns current value of UWB PhyFrequency setting.
 *
 *  @return UWB PhyFrequency value.
 */
- (ESTUWBPhyFrequency)getValue;

/**
 *  Method allows to read value of initialized UWB PhyFrequency setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingUWBPhyFrequencyCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized UWB PhyFrequency setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param phyFrequency PhyFrequency value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTUWBPhyFrequency)phyFrequency completion:(ESTSettingUWBPhyFrequencyCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param phyFrequency PhyFrequency value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTUWBPhyFrequency)phyFrequency;

@end

NS_ASSUME_NONNULL_END
