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

@interface ESTFirmwareInfoVO : NSObject

@property (nonatomic, strong) NSString *hardwareVersion;
@property (nonatomic, strong) NSString *firmwareVersion;
@property (nonatomic, strong) NSString *changelog;
@property (nonatomic, assign) BOOL isUpdateAvailable;

@end
