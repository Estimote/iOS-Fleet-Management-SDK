//
//  ESTBluetoothBeacon.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 24/02/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface ESTBluetoothBeacon : NSObject

@property (nonatomic, strong) NSString *macAddress;
@property (nonatomic, strong) NSNumber *major;
@property (nonatomic, strong) NSNumber *minor;
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSNumber *measuredPower;
@property (nonatomic, strong) NSDate *discoveryDate;
@property (nonatomic, strong) NSData *advertisementData;
@property (nonatomic, assign) NSInteger rssi;

@property (nonatomic, assign) NSInteger firmwareState;

@end
