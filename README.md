EstimoteSDK for iOS 7
=======

Introduction
-------

Estimote SDK allows to play with Apple iBeacon technology, using Estimote hardware beacons as well as [Estimote Virtual Beacon iOS Application](https://itunes.apple.com/us/app/estimote-virtual-beacon/id686915066). To find out more about it read [API section on our website](http://estimote.com/api/index.html#), please. You can review [SDK documentation](http://estimote.github.io/iOS-SDK/) and check our [Community Portal](http://community.estimote.com) to get answers for most common questions related to our Hardware and Software.

Overview
-------


Estimote SDK is a wrapper around Apple's CoreLocation framework. It is dedicated for iOS 7 as it's based on newly introduced CoreLocation framework functionality called iBeacon. It consists of 3 classes: ESTBeaconManager, ESTBeaconRegion and ESTBeacon. Each of them is an equivalent of CoreLocation classes (CLLocationManager, CLBeaconRegion, CLBeacon) created in particular for Estimate Beacons Platform.

ESTBeaconManager is a starting point of the library. It allows to get list of all estimate beacon devices (represented by ESTBeacon objects). It expose monitoring and ranging methods in the similar fashion then CLLocationManager. In addition to location functionality it allows to get list of beacons based CoreBluetooth framework. It is extremely important to have this option in case that device stop advertising in an iBeacon manner.

ESTBeaconRegion is a directly extending CLBeaconRegion class of CoreLocation framework. As Estimote Beacon Platform is using single ProximityUUID, this class helps create region object faster. You don't need to remember and play with ProximityUUID parameter.

ESTBeacon represents single beacon device. Objects of this class are generated using ESTBeaconManager (There is no sense to create them manually). The most important difference (comparing to CLBeacon class) is two way communication with the beacon device. Keeping reference to original CLBeacon object it allows to connect with the device and interact with it. All available bluetooth characteristics (like signal power or major/minor value) can be read and changed to create customised behaviour. Firmware update option is available using this class as well. 


Installation
-------

Follow steps described below to install EstimoteSDK library:

1. Copy EstimoteSDK directory (containing libEstimoteSDK.a and Headers) into your project directory.

2. Open your project settings and go to Build Phase tab. In the Link library with binaries section click +. In the popup window click add another at the bottom and select libEstimoteSDK.a library file. 

  In addition EstimoteSDK requires following native iOS frameworks:
  * CoreBluetooth.framework
  * CoreLocation.framework
  * SystemConfiguration.framework

  When you add them your project settings should look like on the screenshot below.

  ![ScreenShot LinkWithBinaryLibraries](http://estimote.com/api/BuildPhasesScreenshot.png)

3. Go to Build Settings section of project settings and search for Header Search Paths. Add line containing "$(SRCROOT)/../EstimoteSDK/Headers".

4. Congratulations! You are done.
 
Changelog
-------

To see what has changed in recent versions of Estimote SDK, see the [CHANGELOG](https://github.com/Estimote/iOS-SDK/blob/master/CHANGELOG.md).
