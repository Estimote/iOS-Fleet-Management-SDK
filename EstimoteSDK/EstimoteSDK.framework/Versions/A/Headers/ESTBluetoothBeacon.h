//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.2.4
//  Copyright (c) 2015 Estimote. All rights reserved.

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
