//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshReportErrorDomain @"ESTSettingStorageDataChunkErrorDomain"

/**
 *  Describes Mesh Report Page validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMeshReportPageError)
{
     /**
     *  Provided value has invalid length.
     */
    ESTSettingMeshReportPageErrorInvalidLength = 1
};

@class ESTSettingMeshReportPage;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting report page operation for Mesh network.
 *
 *  @param reportPage Report Page setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshReportPageCompletionBlock)(ESTSettingMeshReportPage * _Nullable reportPage, NSError * _Nullable error);


/**
 *  ESTSettingMeshReport represents Mesh Report value.
 */
@interface ESTSettingMeshReportPage : ESTSettingReadWrite <NSCopying>

/**
 *  Returns current value of Mesh report setting.
 *
 *  @return Mesh ReportPage value.
 */
- (NSData *)getValue;

/**
 *  Method allows to read value of initialized Mesh Report Page setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshReportPageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
