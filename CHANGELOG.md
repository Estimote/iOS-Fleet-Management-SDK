## 2.1.1 (Semptember 16, 2014)

Features:

 - Added support for the new CoreLocation authorization model introduced in iOS 8
 
   You can read more about it in our [Estimote SDK and iOS 8 Location Services](https://community.estimote.com/hc/en-us/articles/203393036-Estimote-SDK-and-iOS-8-Location-Services) guide.

Improvements:

 - Updated the [EstimoteSDK Reference](http://estimote.github.io/iOS-SDK/index.html) documentation
 - Added `connectWithAttempts:connectionTimeout:` method to `ESTBeacon` to allow overriding default connection parameters

## 2.1.0 (Semptember 4, 2014)

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
