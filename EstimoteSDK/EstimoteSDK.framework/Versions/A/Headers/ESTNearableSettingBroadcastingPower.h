//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDeviceNearableSettingProtocol.h"
#import "ESTCloudSettingProtocol.h"
#import "ESTBeaconDefinitions.h"


@interface ESTNearableSettingBroadcastingPower : NSObject <ESTDeviceNearableSettingProtocol, ESTCloudSettingProtocol, NSCopying>

- (instancetype)initWithCompletion:(ESTSettingBroadcastingPowerCompletionBlock)completion;

- (instancetype)initWithValue:(ESTBeaconPower)power
                   completion:(ESTSettingBroadcastingPowerCompletionBlock)completion;

@end
