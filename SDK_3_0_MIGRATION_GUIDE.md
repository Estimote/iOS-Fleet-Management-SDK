#Estimote SDK migration guide from 2.4 to 3.0


Following document covers all backward incompatible changes introduced in Estimote SDK 3.0 in comparison to 2.4.

## Table of Contents

<!-- START doctoc -->

- [Static Library vs. Framework](#static-library-vs-framework)
- [Ranging and monitoring beacons](#ranging-and-monitoring-beacons)
  - [ESTBeaconManager](#estbeaconmanager)
  - [ESTSecureBeaconManager](#estsecurebeaconmanager)
  - [ESTUtilityManager](#estutilitymanager)
- [Estimote Cloud integration](#estimote-cloud-integration)
  - [Authorisation and Statistics](#authorisation-and-statistics)
  - [Fetching beacons from the Estimote Cloud](#fetching-beacons-from-the-estimote-cloud)
  - [Fetching nearables from the Estimote Cloud](#fetching-nearables-from-the-estimote-cloud)
  - [Fetching details of single beacon](#fetching-details-of-single-beacon)
- [Changing beacons settings](#changing-beacons-settings)
- [Updating beacons firmware](#updating-beacons-firmware)
- [Bulk update of beacons settings](#bulk-update-of-beacons-settings)


## Static Library vs. Framework
	
With introduction of Estimote SDK 3.0 we decided to move from Static Library to Static Framework architecture. With static library, you had to distribute public class headers and compiled library (*libEstimoteSDK.a*) separately. With Static framework it’s not the case anymore. You are using one single file EstimoteSDK.framework that contains both compiled library and public header files. Installing Estimote SDK is as simple as dropping it over Xcode project now. We decided not to move to Dynamic Framework architecture (introduced together with iOS 8) just yet, as we would have to drop iOS 7 support.

## Ranging and monitoring beacons 

Ranging and monitoring of beacons has been simplified. In SDK 2.4 ESTBeaconManager was responsible for many different things including:

* Ranging for regular iBeacon devices
* Ranging for secured Estimote iBeacon devices 
* Bluetooth scanning for Estimote beacons
* Fetching beacons assigned to your account from Estimote Cloud

This was a lot for a single class, that’s why we decided to split it. With SDK 3.0 this functionality was split.


### ESTBeaconManager

`ESTBeaconManager` class remains, but with narrowed functionality. In the current form it is responsible for ranging and monitoring iBeacon devices as well as advertising as iBeacon. It mainly covers CoreLocation functionality but with useful helpers including `preventUnknownUpdateCount`, `avoidUnknownStateBeacons` and `returnAllRangedBeaconsAtOnce` (Already available in previous versions of Estimote SDK). 

Delegate methods works with `CLBeacon` objects (instead of `ESTBeacon`) and `CLBeaconRegion` (instead of `ESTBeaconRegion`). Let's use ranging delegate as example:

**SDK 2.4 syntax:**

```
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region
{
    if (beacons.count > 0)
    {
        ESTBeacon *firstBeacon = [beacons objectAtIndex:0];
    }
}
```

**SDK 3.0 syntax:**

```
- (void)beaconManager:(id)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(CLBeaconRegion *)region
{
    if (beacons.count > 0)
    {
        CLBeacon *firstBeacon = [beacons objectAtIndex:0];
    }
}
```

### ESTSecureBeaconManager

New class responsible purely for ranging beacons using Estimote Secure UUID feature. It has exactly the same set of methods and it's sharing the same protocol as `ESTBeaconManager` defined in *ESTBeaconManagerDelegate.h* (it can be easily replaced in the code when you decide to switch to secure beacons). For example you you want to range for beacon with default Proximity UUID, major = 23554 and minor = 98130: 

**SDK 2.4 syntax:**

```
ESTBeaconRegion *region = [[ESTBeaconRegion alloc] initWithProximityUUID:ESTIMOTE_PROXIMITY_UUID
                                			                       major:23554
                          				                      identifier:@"EstimoteSampleRegion"
                              				                     secured:YES];
                              
 self.beaconManager = [[ESTBeaconManager alloc] init];
 self.beaconManager.delegate = self;
 self.beaconManager startRangingBeaconsInRegion:self.region];
```

**SDK 3.0 syntax:**

```
CLBeaconRegion *region = [[CLBeaconRegion alloc] initWithProximityUUID:ESTIMOTE_PROXIMITY_UUID
											                     major:23554
                                                            identifier:@"EstimoteSampleRegion"];
self.beaconManager = [[ESTSecuredBeaconManager alloc] init];
self.beaconManager.delegate = self;
self.beaconManager startRangingBeaconsInRegion:self.region];
```

`beaconManager:didRangeBeacons:inRegion:` is handling result of ranging beacons with Secured Proximity UUID feature enabled: 

**SDK 2.4 syntax:**

```
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region
{
    if (beacons.count > 0)
    {
        ESTBeacon *firstSecuredBeacon = [beacons objectAtIndex:0];
    }
}
```

**SDK 3.0 syntax:**

```
- (void)beaconManager:(id)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(CLBeaconRegion *)region
{
    if (beacons.count > 0)
    {
        CLBeacon *firstSecuredBeacon = [beacons objectAtIndex:0];
    }
}
```


It's important to note that `ESTSecureBeaconManager` is working exclusively with secured beacon, devices with Secure UUID feature turned off won't be returned.

### ESTUtilityManager

It allows to scan for Estimote beacons using CoreBluetooth instead of CoreLocation framework. As those two frameworks delivers different sets of information we decided to introduce `ESTBluetoothBeacon`. This is value object class that contains all the information delivered from manufacturer specific data in bluetooth packet. 

**SDK 2.4 syntax:**

```
ESTBeaconRegion *region = [[ESTBeaconRegion alloc] initWithProximityUUID:ESTIMOTE_PROXIMITY_UUID
                          				                      identifier:@"EstimoteSampleRegion"];
                              
 self.beaconManager = [[ESTBeaconManager alloc] init];
 self.beaconManager.delegate = self;
 
 self.beaconManager startEstimoteBeaconDiscoveryForRegion:region updateInterval:1.];
```

**SDK 3.0 syntax:**

```
self.utilityManager = [[ESTUtilityManager alloc] init];
self.utilityManager.delegate = self;

[self.utilityManager startEstimoteBeaconDiscovery];
```

or you can specify update interval for callback method

```
self.utilityManager = [[ESTUtilityManager alloc] init];
self.utilityManager.delegate = self;

[self.utilityManager startEstimoteBeaconDiscoveryWithUpdateInterval:2.5];
```

As a result of scanning array of `ESTBluetoothBeacon` objects in delivered to `utilityManager:didDiscoverBeacons:` delegate method.

**SDK 2.4 syntax:**

```
- (void)beaconManager:(ESTBeaconManager *)manager
   didDiscoverBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region
{
    if (beacons.count > 0)
    {
        ESTBeacon *beacon = [beacons objectAtIndex:0];
    }
}
```

**SDK 3.0 syntax:**

```
- (void)utilityManager:(ESTUtilityManager *)manager 
 	didDiscoverBeacons:(NSArray *)beacons
{
    if (beacons.count > 0)
    {
        ESTBluetoothBeacon *beacon = [beacons objectAtIndex:0];
    }
}
```

## Estimote Cloud integration

Communication with Estimote cloud was completely moved to ESTCloudManager.

### Authorisation and Statistics

Version 2.4 was using `ESTConfig` static methods to provide App ID and App Token required to authenticate Estimote Cloud. It also allowed to configure optional beacon related statistics. With SDK 3.0 we decided to create completely new `ESTCloudManager` class that is responsible for integration with Estimote Cloud. Both methods were moved there.

**SDK 2.4 syntax:**

```
[ESTConfig setupAppID:@"test_app" andAppToken:@"6e053af01483782dba582c4"];
[ESTConfig enableAnalytics:YES];
```

**SDK 3.0 syntax:**

```
[ESTCloudManager setupAppID:@"test_app" andAppToken:@"6e053af01483782dba582c4"];
[ESTCloudManager enableAnalytics:YES];
```
### Fetching beacons from the Estimote Cloud

Fetching beacons assigned to authorised account from the Estimote Cloud was moved from `ESTBeaconManager` to `ESTCloudManager`:

**SDK 2.4 syntax:**

```
ESTBeaconManager *beaconManager = [ESTBeaconManager new];

[beaconManager fetchEstimoteBeaconsWithCompletion:^(NSArray *value, NSError *error) {}];
```

**SDK 3.0 syntax:**

```
ESTCloudManager *cloudAPI = [ESTCloudManager new];

[cloudAPI fetchEstimoteBeaconsWithCompletion:^(NSArray *value, NSError *error) {}];
```

### Fetching nearables from the Estimote Cloud

Fetching beacons assigned to authorised account from the Estimote Cloud was moved from `ESTNearableManager` to `ESTCloudManager`:

**SDK 2.4 syntax:**

```
ESTNearableManager *nearableManager = [ESTNearableManager new];

[nearableManager fetchEstimoteNearablesWithCompletion:^(NSArray *value, NSError *error) {}];
```

**SDK 3.0 syntax:**

```
ESTCloudManager *cloudAPI = [ESTCloudManager new];

[cloudAPI fetchEstimoteNearablesWithCompletion:^(NSArray *value, NSError *error) {}];
```

### Fetching details of single beacon

With Estimote SDK 3.0 new cloud API methods were introduced. They allow to fetch details of single beacon (authorisation required). Let's fetch details of beacon with default Estimote Proximity UUID, major = 23554 and minor = 98130:

**SDK 3.0 syntax:**

```
ESTCloudManager *cloudAPI = [ESTCloudManager new];

[cloudAPI fetchBeaconDetails:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D:23554:98130" 
				  completion:^(NSObject *value, NSError *error) {}];
```
You can also get colour of the particular beacon. You don't need to be authorised to access this information. Let's fetch colour information for the same beacon as before:

**SDK 3.0 syntax:**

```
ESTCloudManager *cloudAPI = [ESTCloudManager new];

[cloudAPI fetchColorForBeaconWithProximityUUID:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D" 
                                     	 major:23554
                                     	 minor:98130
				  					completion:^(NSObject *value, NSError *error) {}];
```

## Changing beacons settings

`ESTBeacon` class was used in SDK 2.4 to handle connectivity and settings change. Estimote SDK 3.0 is using new `ESTBeaconConnection` object to connect and modify beacon settings. Way of establishing connection changed:

**SDK 2.4 syntax:**

```
ESTBeacon *beacon = self.beacons[0];
beacon.delegate = self;
[beacon connect];
```

**SDK 3.0 syntax:**

```
ESTBeaconConnection *beaconConnection = self.doorBeaconConnection;
beaconConnection.delegate = self;
[beaconConnection startConnection];
```


All properties provided by this class are accessible after connection. Before connection is establish they are equals to `nil` or filled with Unknown state described in associated ENUM definition. 

To change settings you should use "write" prefixed methods on `ESTBeaconConnection` class object. Methods names remained the same. To change beacons `major` value:

**SDK 2.4 syntax:**

```
ESTBeacon *beacon = self.beacons[0];
[beacon writeMajor:newMajor 
		completion:^(unsigned short major, NSError *error) {}];
```
**SDK 3.0 syntax:**

```
ESTBeaconConnection *beaconConnection = self.doorBeaconConnection;
[beaconConnection writeMajor:newMajor 
				  completion:^(unsigned short major, NSError *error) {}];
```

## Updating beacons firmware

As entire connection related functionality was moved to `ESTBeaconConnection` so was Over The Air update. Method names remained the same though. To perform firmware update you should perform following code:


**SDK 2.4 syntax:**

```
ESTBeacon *beacon = self.beacons[0];
[beacon updateFirmwareWithProgress:^(NSInteger value, NSString *description, NSError *error) {} 
						completion:^(NSError *error) {}];
```

**SDK 3.0 syntax:**

```
ESTBeaconConnection *beaconConnection = self.doorBeaconConnection;
[beaconConnection updateFirmwareWithProgress:^(NSInteger value, NSString *description, NSError *error) {} 
								  completion:^(NSError *error) {}];
```

You can also verify firmware availability with `checkFirmwareUpdateWithCompletion:` method:

**SDK 2.4 syntax:**

```
ESTBeacon *beacon = self.beacons[0];
[beacon checkFirmwareUpdateWithCompletion:^(ESTFirmwareInfoVO *firmwareInfo, NSError *error) {} 
						completion:^(NSError *error) {}];
```

**SDK 3.0 syntax:**

```
ESTBeaconConnection *beaconConnection = self.doorBeaconConnection;
[beaconConnection checkFirmwareUpdateWithCompletion:^(ESTFirmwareInfoVO *firmwareInfo, NSError *error) {} 
						completion:^(NSError *error) {}];
```

Estimote SDK 3.0 delivers update to 3.0.1 version of beacon firmware. Important to note is that Firmware 3.0.0 introduce **new version of authorisation mechanism that works only with SDK 3.0.** This indicates that you won’t be able to connection to beacons with 3.0.1 firmware installed using older version of  iOS Estimote SDK. Android SDK won’t let you connect to the beacon as well. Estimote SDK 3.0 keeps backward compatibility - you are able to connect to devices running all previous versions of firmware.

## Bulk update of beacons settings

Bulk updater remained in the same form. Main difference is that `ESTBeaconUpdateInfo` in Estimote SDK 3.0 is working with devices identified using Mac Address instead of iBeacons ProximityUUID, major and minor. 	

**SDK 2.4 syntax:**

```
ESTBeaconUpdateConfig *sampleConfig = [ESTBeaconUpdateConfig new];
sampleConfig.power = [NSNumber numberWithChar:ESTBeaconPowerLevel7];
sampleConfig.advInterval = [NSNumber numberWithInt:700];
        
ESTBeaconUpdateInfo *info = [[ESTBeaconUpdateInfo alloc] initWithBeacon:self.beacon 
												                  config:sampleConfig];
												                  
[[ESTBulkUpdater sharedInstance] startWithBeaconInfos:@[info] timeout:3600.];
```
        
**SDK 3.0 syntax:**

```
ESTBeaconUpdateConfig *sampleConfig = [ESTBeaconUpdateConfig new];
sampleConfig.power = [NSNumber numberWithChar:ESTBeaconPowerLevel7];
sampleConfig.advInterval = [NSNumber numberWithInt:700];

ESTBeaconUpdateInfo *info = [[ESTBeaconUpdateInfo alloc] initWithMacAddress:self.beacon.macAddress 
										                             config:sampleConfig];
										                             
[[ESTBulkUpdater sharedInstance] startWithBeaconInfos:@[info] timeout:3600.];
```

Additionally you have access to Estimote API method to fetch all pending settings applied to the beacons using Estimote Cloud:


**SDK 3.0 syntax:**

```
ESTCloudManager *cloudAPI = [ESTCloudManager new];

[self.cloudAPI fetchPendingBeaconsSettingsWithCompletion:^(NSArray *value, NSError *error) {

	[[ESTBulkUpdater sharedInstance] startWithBeaconInfos:value timeout:3600.];
}];
```