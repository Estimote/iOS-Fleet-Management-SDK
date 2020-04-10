
# Estimote Fleet Management SDK for Apple iOS

>If this name seems unfamiliar, please rest assured that everything is ok. With release of 4.29.0 we only changed the naming (https://github.com/Estimote/iOS-Fleet-Management-SDK/releases/tag/4.29.0)

## Table of Contents

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [Introduction](#introduction)
- [Installation](#installation)
  - [CocoaPods](#cocoapods)
  - [Manual](#manual)
- [Requirements](#requirements)
- [Fleet Management](#fleet-management)
  - [Bulk Updater](#bulk-updater)
  - [Usage example](#usage-example)
- [Configuring individual beacons](#configuring-individual-beacons)
  - [Connecting to devices](#connecting-to-devices)
  - [Settings](#settings)
  - [Convenience API](#convenience-api)
  - [Usage example](#usage-example-1)
  - [Advanced API](#advanced-api)
  - [Usage example](#usage-example-2)
- [Changelog](#changelog)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->


## Introduction

This iOS SDK can be used to update the settings of multiple Estimote beacons at once. You no longer need to connect to each beacon individually. Instead, you use Estimote Cloud to queue ‘pending settings’ on your beacons. Then, your iOS app equipped with this SDK ( see [Bulk Updater](#bulk-updater) section) can propagate those settings the moment it encounters the beacons. This also means that, once you deploy the beacons, users of your app can propagate the settings by simply being around the beacons.

### Before diving in...
If you simply need to change the settings (or apply ‘pending settings’) of the nearby Estimote beacons, get [Estimote iOS app](https://itunes.apple.com/us/app/estimote/id686915066?mt=8). For a single beacon or a few of them, this will be the fastest method.

If you have more Estimote devices, [Estimote Deployment app](https://itunes.apple.com/us/app/estimote-deployment/id1109375679?mt=8) will be a better choice. It uses Bulk Updater to propagate settings to multiple beacons at once.

All the proximity monitoring features of this SDK have been deprecated and are no longer supported. Instead, **we strongly recommend [Estimote Proximity SDK for iOS](https://github.com/Estimote/iOS-Proximity-SDK) powered by Estimote Monitoring.** This Estimote Fleet Management SDK, on the other hand, should be used for beacon fleet management (as new naming suggests right? :wink: ).
> :bulb: Keep in mind that tags & attachments from Estimote Proximity SDK are updated instantly, without the need to propagate settings to beacons.

To learn more about Fleet Management SDK, review the [SDK documentation]([http://estimote.github.io/iOS-Fleet-Management-SDK/](http://estimote.github.io/iOS-Fleet-Management-SDK/)) and check the Developer Portal tutorial. Visit also [Estimote Cloud API docs](https://cloud.estimote.com/docs/).

## Installation

### CocoaPods 
[CocoaPods](https://cocoapods.org/) is an easy way to add external libraries. To use it to fetch Estimote Fleet Management SDK:
1. Add `pod 'EstimoteFleetManagementSDK'` to your Podfile
2. Run `pod install --repo-update`
3. For Swift project: you will need a *bridging header*, so just add a new file with Objective-C, confirm you want to a create a bridging header and just remove the not needed Objective-C file. In the bridging header, add: `#import <EstimoteFleetManagementSDK/EstimoteFleetManagementSDK.h>`
For Objective-c project: add to your code `#import <EstimoteFleetManagementSDK/EstimoteFleetManagementSDK.h>`
4. You're ready to rock!

### Manual
Alternatively, include a single *EstimoteFleetManagementSDK.framework* file in your project to get started:

1. Drag and drop *EstimoteFleetManagementSDK.framework* file into your Xcode project. It will automatically show up in your project navigator and will be added to *Linked Frameworks and Libraries* section in project settings.
2. That's it, congratulations and happy hacking!


## Requirements

- One or more Estimote Beacons.
- An iOS device with Bluetooth Low Energy running iOS 10 or later. Using BLE with iOS Simulator isn't supported.
- An [Estimote Cloud](https://cloud.estimote.com/) account.

## Fleet Management

### Bulk Updater

With this feature you can:

1. Enable or disable packets (e.g. iBeacon, Eddystone-UID)
1. Modify the settings of individual beacons (e.g. increase the broadcasting power, decrease the advertising interval, modify Eddystone-URL’s link)
1. Update Estimote beacon firmware

To perform bulk update operations on devices represented by *ESTDeviceLocationBeacon* class (e.g. Location Beacons) you should use the *ESTLocationBeaconBulkUpdater* class. 

> Contrary to the ESTBulkUpdater it is not designed to be used as a singleton.

*ESTLocationBeaconBulkUpdater* requires an array of *ESTLocationBeaconBulkUpdaterConfiguration* objects to start. *ESTLocationBeaconBulkUpdaterConfiguration* consists of an identifier of the device which settings you want to modify and an array of *ESTSettingOperation* described in the [Advanced API](#advanced-api) section. All bulk updater events will be delivered to the object assigned as it's delegate which should conform to *ESTLocationBeaconBulkUpdaterDelegate* protocol.

### Usage example

I have an array of identifiers for my Location Beacons that should have their iBeacon packet on and major value set to 200.

```objective-c
NSMutableArray *bulkUpdateConfigurations = [NSMutableArray new];

NSArray *identifiers = @[@"identifier1", @"identifier2", @"identifier3"];
for (NSString *identifier in identifiers) {

    ESTSettingIBeaconEnable *enableSetting = [[ESTSettingIBeaconEnable alloc] initWithValue:YES];
    ESTBeaconOperationIBeaconEnable *enableOperation = [ESTBeaconOperationIBeaconEnable writeOperationWithSetting:enableSetting completion:^(ESTSettingIBeaconEnable *iBeaconEnableSetting, NSError *error) {
    }];

    unsigned short major = 200;
    ESTSettingIBeaconMajor *majorSetting = [[ESTSettingIBeaconMajor alloc] initWithValue:major];
    ESTBeaconOperationIBeaconMajor *majorOperation = [ESTBeaconOperationIBeaconMajor writeOperationWithSetting:majorSetting completion:^(ESTSettingIBeaconMajor *major, NSError *error) {
    }];

    ESTLocationBeaconBulkUpdateConfiguration *configuration = [[ESTLocationBeaconBulkUpdateConfiguration alloc] initWithDeviceIdentifier:identifier settingsOperations:@[enableOperation, majorOperation]];
    [bulkUpdateConfigurations addObject:configuration];
}

[self.bulkUpdater startWithUpdateConfigurations:[NSArray arrayWithArray:bulkUpdateConfigurations]];
```

## Configuring individual beacons

### Connecting to devices

Connecting to an Estimote beacon lets you change its settings (enable/disable packets, modify broadcasting power or advertising interval etc). If a beacon is set to Deployed & Protected [access mode](https://community.estimote.com/hc/en-us/articles/115000221671-What-is-Access-Mode-How-to-enable-it-), you have to be the beacon's owner in Estimote Cloud to modify any settings. 

> Every attempt to connect with a device not logged in to your Estimote account will fail. Enable Development access mode to allow your coworkers to also edit beacon's settings.

Connectivity packets are represented by *ESTDeviceConnectable* subclasses, the main one being *ESTDeviceLocationBeacon*. It represents:

- Estimote Location Beacons (hardware revision “F”)
- Estimote Proximity Beacons (hardware revisions “G” and “J”)

If you have Estimote Nearables (Stickers), use *ESTDeviceNearable* instead. In order to connect to the first-generation Estimote Proximity Beacon (hardware revision "D"), use the [SDK 3 API](https://github.com/Estimote/iOS-Fleet-Management-SDK/blob/master/SDK_3_x_README.md#utility).


**In this SDK, following steps are required to connect to a device:**

1. Create *ESTDeviceManager*, make sure your class conforms to *ESTDeviceManagerDelegate* protocol.
1. Start discovery by calling *startDiscoveryWithFilter*: with filter object. This can be either *ESTDeviceFilterLocationBeacon* or *ESTDeviceFilterNearable*.
1. Method *deviceManager:didDiscoverDevices*: provides discovered devices matching filter. 
1. Make sure your class conforms to *ESTDeviceConnectableDelegate* protocol and call connect on discovered *ESTDeviceConnectable* object. Now, the SDK verifies if the device is linked to account specified by AppID + AppToken pair, authorizes user, connects on the Bluetooth level and synchronizes settings by fetching their values from Cloud and writing to the device.

### Settings

In this SDK, each device setting is represented by an *ESTSettingBase* subclass. There are two ways of reading/writing settings - [Convenience API](#convenience-api) and [Advanced API](#advanced-api).

These classes are wrappers around basic types (both primitives and objects) such as *unsigned integer* or *NSString*,

- *ESTSetting** classes are wrappers around values providing validation.
- *ESTBeaconOperation** classes specify details used to read or write setting to the device.

### Convenience API

To simply change a device setting you can use the Convenience API tree. Each device has one, here's an example of *ESTDeviceLocationBeacon* settings tree:

``` 
device
  |- settings
    |- iBeacon
      |- proximityUUID
      |- major
      |- minor
      ...
    |- estimote
      |- enable
      |- power
      ...
    |- deviceInfo
      |- color
      |- name
      ...
    ...
```

To read/write a device setting value call *readValueWithCompletion*: or *writeValue:completion:* method on one of the tree's leaf.

### Usage example

I have an Estimote Location Beacon and I want to turn iBeacon packet on, change its Major value to 500, and read its Proximity UUID.

```objective-c
[device.settings.iBeacon.enable writeValue:YES completion:^(ESTSettingIBeaconEnable *enableSetting, NSError *error) {
  NSLog(@"iBeacon packet enabled");
}];

[device.settings.iBeacon.major writeValue:500 completion:^(ESTSettingIBeaconMajor *majorSetting, NSError *error) {
  NSLog(@"Major set to 500");
}];

[device.settings.iBeacon.proximityUUID readValueWithCompletion:^(ESTSettingIBeaconProximityUUID *uuidSetting, NSError *error) {
  NSLog(@"Proximity UUID is %@", [uuidSetting getValue]);  
}];
```

### Advanced API

To speed up interacting with multiple settings at once you can use the Advanced API. Each setting has its own setting and operation classes pair.

- Setting classes are subclasses of E*STSettingBase* and have their names constructed by concatenating *ESTSetting* + *SettingGroupName* + *SettingShortName* (i.e. *ESTSettingIBeaconMajor*). They are wrappers around setting values (both primitive types and object types), they also provide value validation.
- Operation classes are subclasses of *ESTSettingOperation* and have their name constructed by concatenating *ESTBeaconOperation* (if it's a setting stored in the device memory, such as iBeacon Major) or *ESTCloudOperation* (if it's a setting stored only in Cloud, such as *DeviceInfo* Name) + *SettingGroupName* + *SettingShortName* (i.e. *ESTBeaconOperationIBeaconMajor* or *ESTCloudOperationDeviceInfoName*).

### Usage example

I have an Estimote Location Beacon and I want to turn iBeacon packet on, change its Major value to 200, read its Proximity UUID, perform many other operations and want to do this as fast as possible.

```objective-c
ESTSettingIBeaconEnable *enableSetting = [[ESTSettingIBeaconEnable alloc] initWithValue:YES];
ESTBeaconOperationIBeaconEnable *enableOperation = [ESTBeaconOperationIBeaconEnable writeOperationWithSetting:enableSetting completion:^(ESTSettingIBeaconEnable *setting, NSError *error)
  NSLog(@"iBeacon packet enabled");
}];

unsigned short major = 200;
ESTSettingIBeaconMajor *majorSetting = [[ESTSettingIBeaconMajor alloc] initWithValue:major];
ESTBeaconOperationIBeaconMajor *majorOperation = [ESTBeaconOperationIBeaconMajor writeOperationWithSetting:majorSetting completion:^(ESTSettingIBeaconMajor *setting, NSError *error) {
  NSLog(@"Major set to 200");
}];

ESTBeaconOperationIBeaconProximityUUID *uuidOperation = [ESTBeaconOperationIBeaconProximityUUID readValueWithCompletion:^(ESTSettingIBeaconProximityUUID *setting, NSError *error) {
  NSLog(@"Proximity UUID is %@", [uuidSetting getValue]);
}];

...

[device.settings performOperations:enableOperation, majorOperation, uuidOperation, ..., nil];
```

## Changelog

To see what has changed in recent versions of Estimote SDK, see the [CHANGELOG](CHANGELOG.md).
