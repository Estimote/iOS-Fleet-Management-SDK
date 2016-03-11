//
//  EstimoteSDK
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESTFirmwareInfoV4VO : NSObject

@property (nonatomic, assign) BOOL updateAvailable;
@property (nonatomic, strong) NSString *  version;

@property (nonatomic, strong) NSString *  hardwareVersion;

@property (nonatomic, strong) NSString *  applicationVersion;
@property (nonatomic, strong) NSString *  bootloaderVersion;
@property (nonatomic, strong) NSString *  softdeviceVersion;

@property (nonatomic, strong) NSString *  changelog;

@property (nonatomic, strong) NSString *  tarURL;

+ (BOOL)firmwareVersion:(NSString *)firmwareVersion isBiggerThan:(nonnull NSString *)referenceFirmwareVersion;

@end

NS_ASSUME_NONNULL_END
