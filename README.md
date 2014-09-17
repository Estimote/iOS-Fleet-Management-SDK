EstimoteSDK for iOS
=======

Introduction
-------

Estimote SDK allows you to play with Apple's iBeacon technology using Estimote hardware beacons, as well as [Estimote Virtual Beacon iOS Application](https://itunes.apple.com/us/app/estimote-virtual-beacon/id686915066). To learn more, read the [API section on our website](http://estimote.com/api/index.html#). You can review [SDK documentation](http://estimote.github.io/iOS-SDK/) and check our [Community Portal](http://community.estimote.com) to get the answers for the most common questions related to our Hardware and Software.

Overview
-------


Estimote SDK is a wrapper around Apple's CoreLocation framework. The SDK requires iOS 7+, as it is based on the CoreLocation's support for iBeacon first introduced in iOS 7. The featureset of this Estimote SDK is wrapped mostly in 3 classes: ESTBeaconManager, ESTBeaconRegion and ESTBeacon. Each class corresponds to a similar CoreLocation class (CLLocationManager, CLBeaconRegion, CLBeacon), but also introduces functionalities specific for the Estimate Beacons Platform.

ESTBeaconManager is the starting point of the library. It allows you to get a list of all Estimote beacon devices (represented by ESTBeacon objects). It exposes monitoring and ranging methods in a similar fashion to CLLocationManager. In addition to location functionality, it allows you to get a list of beacons based on the CoreBluetooth framework. It is extremely important to have this possibility in case the device stops advertising in an iBeacon manner.

ESTBeaconRegion directly extends the CLBeaconRegion class of the CoreLocation framework.

ESTBeacon represents a single Estimote Beacon device. Objects of this class are created by the ESTBeaconManager. The most important difference, compared to CLBeacon class, is the two way communication with the beacon device. Keeping reference to the original CLBeacon object allows you to connect with the device and interact with it. All available Bluetooth characteristics, like signal power or major/minor value, can be read and changed to create a customized behavior. The firmware update option is available using this class as well.


Installation
-------

The easiest way to intall is to use CocoaPods. It takes care of all the required frameworks and third party dependencies:

```
pod 'EstimoteSDK'
```

Alternatively, you can install it manually. Follow the steps described below:

1. Copy the EstimoteSDK directory (containing libEstimoteSDK.a and Headers) into your project directory.

2. Open your project settings and go to the "Build Phases" tab. In the Link library with binaries section click "+". In the popup window click "add another" at the bottom and select the libEstimoteSDK.a library file.

  In addition, the EstimoteSDK requires the following native iOS frameworks:
  * CoreBluetooth.framework
  * CoreLocation.framework
  * SystemConfiguration.framework

  When you add them to your project settings, it should look like on the screenshot below.

  ![ScreenShot LinkWithBinaryLibraries](http://estimote.com/api/BuildPhasesScreenshot.png)

3. Go to the "Build Settings" section of project settings and search for "Header Search Paths". Add a line containing "$(SRCROOT)/../EstimoteSDK/Headers".

4. You are done, congratulations! Happy tinkering!

Changelog
-------

To see what has changed in recent versions of Estimote SDK, see the [CHANGELOG](https://github.com/Estimote/iOS-SDK/blob/master/CHANGELOG.md).
