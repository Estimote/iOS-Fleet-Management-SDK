//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESTFirmwareInfoVO : NSObject

@property (nonatomic, strong) NSString * _Nullable hardwareVersion;
@property (nonatomic, strong) NSString * _Nullable firmwareVersion;
@property (nonatomic, strong) NSString * _Nullable changelog;
@property (nonatomic, assign) BOOL isUpdateAvailable;

@end

NS_ASSUME_NONNULL_END
