Estimote SDK 3.0.0 Beta for Apple iOS Platform
=======
IMPORTANT RELEASE NOTE!
-------
Estimote SDK has been with us for more than a year now. Thanks to feedback from our developer community, we’ve learned a lot about how it helps developers to reach their goals. And we also learned some of its shortcomings. As we want to deliver the best developer experience we decided to restructure our SDK and introduce some backward incompatible changes which will ultimately make it much easier to develop using our SDK. We’ve released this project as an opt-in beta to make it easier for developers to get familiar with it and so that we can get your feedback on the changes as fast as possible.

This update comes with firmware update to version 3.0.1. This version changes the way authorization is handled during device connection. It also introduces a new feature we call “conditional broadcasting”, which allows you to restrict broadcasting based on a beacon’s physical position. Conditional broadcasting enables two new modes of beacon operation:

* *“Flip to sleep”* - in this mode, the beacon will not broadcast advertising packets when placed on its back (gecko pad facing up).
* *“Motion only”* broadcasting - in this mode, the beacon will only broadcast advertising packets when moving

There are two main motivations behind this feature - firstly, it makes it much easier to test beacon enabled apps, both of these modes provide a virtual “off” switch for your beacons. Secondly, we’re always looking for ways to save battery life, and both the new broadcasting modes, in particular “motion only” advertising offer innovative ways to save beacon power. 

** Please note that Estimote beacon firmware 3.0.1 is not backward compatible! This means you won't be able to perform connection using 2.4.0 Estimote SDK and 2.12 AppStore app to updated devices.**

We've also started [discusion about Estimote SDK 3.0.0](https://forums.estimote.com/t/sdk-3-0-beta-discussion/78) using our recently announced Estimote Forums. Feel free to participate and give us your feedback about it!

Introduction
-------
We want the Estimote iOS SDK to be first choice when building any Estimote Beacon or nearable related experience for the Apple iOS Platform. Our SDK provides a wide range of both utility and client facing features that will save time and make development / beacon management easier than ever. It's built purely on Apple CoreLocation and CoreBluetooth technologies and is 100% iBeacon compatible.

In addition to the Estimote SDK we've included a lot of examples to show how SDK can be used. You should also try to use main utility application that can be found in AppStore: [Estimote Virtual Beacon iOS Application](https://itunes.apple.com/us/app/estimote-virtual-beacon/id686915066). 

To learn more, read the [API section on our website](http://estimote.com/api/index.html#). You can review [SDK documentation](http://estimote.github.io/iOS-SDK/) and check our [Community Portal](http://community.estimote.com) to get the answers for the most common questions related to iBeacon in general as well as Estimote specific Hardware and Software.

Installation
-------
With Estimote SDK 3.0 we converted previously used Static Library approach to **Static Framework** based approach. This means just a single file (*EstimoteSDK.framework*) needs to be included into your project to get started, allowing you to focus on development instead of Xcode project configuration. To include Estimote SDK into your project you should perform following steps: 

1. Drag and drop EstimoteSDK.framework file into your Xcode project. It will automatically show up in your project navigator and will be added to *"Linked Frameworks and Libraries"* section in project settings. 

2. As Estimote SDK depends on Apple CoreLocation and CoreBlueooth frameworks as well as SystemConfiguration framework to handle Estimote Cloud API requests you should include them in your project too.When you add them to your project settings, it should look like on the screenshot below.
<img src="images/build_phases.png" alt="Build Phases" width="840">

3. You are done, congratulations! Happy tinkering!

Examples
-------
Estimote SDK contains a lot of examples and inspiration to help you get familiar with the way it can be used in your app. Alternatively, you can use the provided example apps as a basis for more sophisticated beacon management tools. Examples are completely open source and cover most important areas of beacons and nearables configuration and management.

<img src="images/home_screen.png" alt="Home Screen" width="280">
<img src="images/ibeacon_list.png" alt="Beacon List" width="280">
<img src="images/distance_demo.png" alt="Distance Demo" width="280">
<img src="images/beacon_details.png" alt="Beacon Details" width="280">
<img src="images/temperature.png" alt="Temerature" width="280">
<img src="images/notify_demo.png" alt="Notify Demo" width="280">

Technical overview
-------
The SDK requires iOS 7+, as it is based on the CoreLocation's support for iBeacon first introduced in iOS 7 as well as CoreBluetooth framework. The featureset of this Estimote SDK is divided into two parts *Client* and *Utility*. 

**Client** part is dedicated to be used inside your publicly distributed applications featuring Estimote Beacon and Nearable integration. It helps you work with Apple iBeacon objects, adding some useful functionality like filtering, ranged object limitation or combining beacons from few regions into one callback. It also contains Simulator class that allows to play with beacons in the Apple Xcode Simulator. Another additions is helper class for Apple Watch integration. Description of most important components can be found below:

* **ESTBeaconManager** - Simple wrapper around CoreLocation CLLocationManager class. It expose api to range and monitor iBeacon devices with some additional options like sorting or filtering. It works with pure CLBeacon objects.
* **ESTSecureBeaconManager** - CLLocationMangare wrapper dedicated to work with devices using Estimote Secure UUID mechanism. Similar to ESTBeaconManager it allows to range and monitor secured devices as well as verify their proximity.
* **ESTSimulatedBeaconManager** - Allows to work with beacons in Xcode iOS Simulator. It let you dispatch "fake" beacon events related to iBeacon ranging and monitoring.
* **ESTNearableManager** - Entry point to work with Estimote nearable devices. It allows to range and monitor (in similar to iBeacon manner) stickers with given type or identifier. 
* **ESTSimulatedNearableManager** - Similarly to "ESTSimulatedBeaconManager" it allows to generate fake ranging and monitoring events for Estimote nearable devices.
* **ESTNotificationTransporter** - Helper class allowing easy Apple Watch App Extension integration. You can find out more details on [Estimote WatchKit SDK](https://github.com/Estimote/Estimote-WatchKit-SDK).

On top of basic ranging and monitoring functionality delivered by classes mentioned above we've build **Estimote Trigger engine**. It allows to define complex rules describing desired circumstances in very easy way. Sample circumstance can be described like this: *"Let me know when I'm next to my moving bike nearable, after 5pm when temperature is lower than 15C."*. 

Implementation of Estimote Trigger engine delivers basic rules (*ESTRule*) related to Estimote nearables and time events. It was created in the way that can be easily extended so you can easily build custom rules that suits your needs. Main classes that you gonna need are:

* **ESTTriggerManager** - Entry point for trigger engine mechanism. Its main responsibility is to get rules you've prepared and inform you when desired circumstances are meet.
* **ESTRule** - Basic implementation of rule. All predefined rules like ESTTemperatureRule or ESTMotionRule are based on it. You can also use this class to build your own custom rules.
* **ESTTrigger** - Trigger allows to create real life circumstances definition based on particular set of rules. You wrap your rules in ESTTrigger object to pass it to ESTTriggerManager.

**Utility** was created to support Estimote beacons and nearables management applications. It delivers beacon connectivity and configuration. You can easily change basic settings like Proximity UUID, Major, Minor, Power Modes and much more. You can also easily perform Over The Air firmware update. It works mainly with CoreBluetooth framework. Main classes you are going to use are:

* **ESTUtilityManager** - Allows you to discover devices using both CoreLocation and CoreBluetooth. Discover device identifier then can be used to connect and configure device.
* **ESTBeaconConnection** - Manages connection and configuration of particular device. Allows to both read and write all the settings. 
* **ESTBeaconFirmwareUpdate** - Helps to perform Over The Air firmware update of Estimote beacon.

Apart from using classes mentioned above you can also benefit from using **Bulk Updater** mechanism. It can be used both locally or remotely. Remote management is based on Estimote Cloud. It allows to define set of new settings for group of devices and perform them using all iOS running devices that are connected to particular Estimote Cloud account.

Changelog
-------

To see what has changed in recent versions of Estimote SDK, see the [CHANGELOG](https://github.com/Estimote/iOS-SDK/blob/master/CHANGELOG.md).



