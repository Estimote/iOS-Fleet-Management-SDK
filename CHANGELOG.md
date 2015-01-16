## 2.3.2 (January 16, 2015)

Improvements:
- Motion UUID support (please note that secured beacons are not supported yet).
- Corrected handling of unknown nearable type name

Bugfixes:
- Fixed bug that caused crash after starting monitoring for the same sticker type more than once.

## 2.3.1 (January 8, 2015)

Improvements:
- Swift Ranging example added
- Custom Triggers example added
- Accelerometer example added

Bugfixes:
- Trigger manager double monitoring crash solved
- Compilation issue with undefined symbol solved 

## 2.3.0 (December 24, 2014)

Features:
- Estimote Nearables support added
- Trigger engine

Improvements:
- Beacon discovery allows to define time interval
- Estimote Cloud Authorization and Analytics methods moved to ESTConfig class

Bugfixes:
- Beacons color requests number optimised

## 2.2.1 (November 20, 2014)

Improvements:
- Bulk updater refactored
- Bulk updater demo added

## 2.2.0 (November 19, 2014)

Features:
- Secure UUID rotation added to prevent from hijacking beacons
- Bulk update
- Estimote Analytics
- 8x faster firmware update

## 2.1.5 (September 26, 2014)

Bugfixes:
- Corrected Firmware download bug

## 2.1.4 (September 25, 2014)

Bugfixes:
- Missing armv7s architecture added to the library

## 2.1.3 (September 24, 2014)

Improvements:
- Corrected Cocoapods support

## 2.1.2 (September 24, 2014)

Improvements:
- Support for iOS 8 Authorization in Examples app
- Fixed problem with first time connection crashing
- Stability improvements

## 2.1.1 (September 16, 2014)

Features:

 - Added support for the new CoreLocation authorization model introduced in iOS 8
 
   You can read more about it in our [Estimote SDK and iOS 8 Location Services](https://community.estimote.com/hc/en-us/articles/203393036-Estimote-SDK-and-iOS-8-Location-Services) guide.

Improvements:

## 2.1.0 (September 4, 2014)

Features:

 - Added support for battery power modes

Improvements:

 - Connection stability
 - Accelerometer support
 - Caching the beacon color information
 - Performance with high number of beacons

Bugfixes:

 - Fixed crashes when using CoreLocation's non-beacon monitoring (i.e. `CLCiruclarRegion`) and Estimote SDK in a single app

## 2.0.1 (July 15, 2014)

Bugfixes:

 - Fixed 100% CPU usage when ranging beacons

## 2.0.0 (June 6, 2014)

Features:

 - Added integration with the Estimote Cloud
 - Added support for temperature and accelerometer sensors
 - Added `motionProximityUUID` to `ESTBeacon`
 - Added support for firmware: Estimote OS 2.0 and up
 
Improvements:

 - Better connection status handling
 - Improved Examples app
	
New `ESTBeacon` API:

 - The following methods have new names:

   - `connectToBeacon` is now `connect`
   - `disconnectBeacon` is now `disconnect`
   - `writeBeaconName:withCompletion:` is now `writeName:completion:`
   - `writeBeaconProximityUUID:withCompletion:` is now `writeProximityUUID:completion:`
   - `writeBeaconMajor:withCompletion:` is now `writeMajor:completion:`
   - `writeBeaconMinor:withCompletion:` is now `writeMinor:completion`
   - `writeBeaconAdvInterval:withCompletion:` is now `writeAdvInterval:completion:`
   - `writeBeaconPower:withCompletion:` is now `writePower:completion:`
   - `updateBeaconFirmwareWithProgress:andCompletion:` is now `updateFirmwareWithProgress:completion:`

## 1.3.0 (January 25, 2014)

Features:

  - `proximityUUID` can now be changed

## 1.2.0 (December 9, 2013)

Improvements:

  - `ESTBeacon` class cleanup (flat structure with iBeacon property removed)
  - Updated the EstimoteSDK Reference documentation

Bugfixes:

  - Corrected the name of the DistanceDemo project
  
## 1.1.0 (December 2, 2013)

Features:

  - Renamed the `frequency` property to `advInterval`
  - Added support for checking for available firmware updates
  - Renamed the library from *libEstimoteSDK7.a* to *libEstimoteSDK.a*

Bugfixes:

  - Changed the type of `major`, `minor`, `power` and `advInterval` properties to unsigned short
  - Fixed an issue with the `(NSArray *)beacons` parameter of `beaconManager:didDiscoverBeacons:inRegion`

## 1.0.0 (November 7, 2013)

Features:

  - Ranging and monitoring of Estimote beacons
  - Added support for connecting to Estimote beacons, which enables access to following properties:
    - major, minor, power and frequency - read and write
    - battery, firmware version and hardware version - readonly
  - Added support for updating firmware
