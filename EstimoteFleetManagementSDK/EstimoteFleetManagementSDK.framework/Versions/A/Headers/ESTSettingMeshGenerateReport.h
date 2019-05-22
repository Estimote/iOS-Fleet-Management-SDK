//  Estimote Fleet Management SDK
//  Copyright (c) 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshGenerateReportErrorDomain @"ESTSettingMeshGenerateReportErrorDomain"

@class ESTSettingMeshGenerateReport;

/**
 *  Describes Mesh Report validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMeshGenerateReportError)
{
    /**
     *  Provided register ID is not supported.
     */
    ESTSettingMeshGenerateReportErrorUnsupportedRegister = 1
};


/**
 *  Describes Mesh Report supported registers.
 */
typedef NS_ENUM(uint16_t, ESTMeshReportRegister)
{
    /**
     *  Register generating Estimote stickers bluetooth scan report.
     */
    ESTMeshReportRegisterStickersScan = 0x00A1
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of write only setting GenerateReport operation for Mesh packet.
 *
 *  @param generateReportSetting Generate report setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshGenerateReportCompletionBlock)(ESTSettingMeshGenerateReport * _Nullable generateReportSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshGenerateReport represents Mesh GenerateReport value.
 */
@interface ESTSettingMeshGenerateReport : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshGenerateReport validationErrorForValue:]
 *
 *  @param registerID ID of register that should be used for report generation.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTMeshReportRegister)registerID;

/**
 *  Returns current value of Mesh GenerateReport setting.
 *
 *  @return Mesh GenerateReport value.
 */
- (ESTMeshReportRegister)getValue;

/**
 *  Method allows to create write only operation from already initialized Mesh GenerateReport setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param registerID Regisetr ID value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTMeshReportRegister)registerID completion:(ESTSettingMeshGenerateReportCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param registerID Register ID value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTMeshReportRegister)registerID;

@end

NS_ASSUME_NONNULL_END
