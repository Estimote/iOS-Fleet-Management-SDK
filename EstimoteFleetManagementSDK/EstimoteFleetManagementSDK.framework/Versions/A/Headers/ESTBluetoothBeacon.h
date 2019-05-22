//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTBluetoothBeacon : ESTDevice

@property (nonatomic, strong) NSNumber *major;
@property (nonatomic, strong) NSNumber *minor;
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSNumber *measuredPower;

@property (nonatomic, assign) NSInteger firmwareState;

@end

NS_ASSUME_NONNULL_END
