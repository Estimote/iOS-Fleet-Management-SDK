
Estimote SDK 3.0.0 Beta for Apple iOS Platform
=======
IMPORTANT RELEASE NOTE!
-------
Estimote SDK has been with us for more than a year now. Thanks to feedback from our developer community, we’ve learned a lot about how it helps developers to reach their goals. However we also learned some of its shortcomings. As we want to deliver the best developer experience we decided to restructure our SDK and introduce some backward incompatible changes which will ultimately make it much easier to develop using our stack. We’ve released this project as an opt-in beta to make it easier for developers to get familiar with it and so that we can get your feedback on the changes as soon as possible.

This update comes with firmware update to version 3.0.1. This version changes the way authorization is handled during device connection. It also introduces a new feature we call “conditional broadcasting”, which allows you to restrict broadcasting based on a beacon’s orientation and movement. Now you can enable one of the two new modes of beacon operation:

* *“Flip to Sleep”* — in this mode, the beacon will not broadcast advertising packets when placed on its back (gecko pad facing up).
* *“Motion only”* — in this mode, the beacon will only broadcast advertising packets when it's moving

There are two main motivations behind this feature - firstly, it makes it much easier to test beacon enabled apps, as both of these modes provide a virtual “off” switch for your beacons. Secondly, we’re always looking for ways to save battery life, and both the new broadcasting modes, in particular “motion only” advertising offer innovative ways to save beacon power in some specific use cases.

**Please note that Estimote beacon firmware 3.0.1 is not backward compatible! This means you won't be able to perform connection using 2.4.0 Estimote SDK and 2.12 AppStore app to updated devices.**

We've also started [discusion about Estimote SDK 3.0.0](https://forums.estimote.com/t/sdk-3-0-beta-discussion/78) using our recently announced Estimote Forums. Feel free to participate and give us your feedback!

Introduction
-------
We want the Estimote iOS SDK to be first choice when building any Estimote Beacon or nearable related experience for the Apple iOS Platform. Our SDK provides a wide range of both utility and client facing features that will save time and make development easier than ever. It's built purely on Apple CoreLocation and CoreBluetooth technologies and is 100% iBeacon compatible.

In addition to the Estimote SDK we've included a lot of examples to show you how to use our SDK in real scenarios. You should also try to use our utility app that can be found in AppStore: [Estimote Virtual Beacon iOS Application](https://itunes.apple.com/us/app/estimote-virtual-beacon/id686915066). 

To learn more, read the [API section on our website](http://estimote.com/api/index.html#). You can review the [SDK documentation](http://estimote.github.io/iOS-SDK/) and check our [Community Portal](http://community.estimote.com) to get the answers for the most common questions related to iBeacon in general as well as to questions about Estimote specific Hardware and Software.

Installation
-------
With Estimote SDK 3.0 we converted the previously used **Static Library** approach to a **Static Framework** based approach. This means just a single file (*EstimoteSDK.framework*) needs to be included into your project to get started, allowing you to focus on development instead of Xcode project configuration. To include Estimote SDK into your project you should perform the following steps: 

1. Drag and drop EstimoteSDK.framework file into your Xcode project. It will automatically show up in your project navigator and will be added to *"Linked Frameworks and Libraries"* section in project settings. 

2. Estimote SDK depends on Apple's CoreLocation and CoreBlueooth frameworks as well as SystemConfiguration framework to handle Estimote Cloud API requests, so you should include them in your project too. When you add them to your project settings, it should look like on the screenshot below.
<img src="images/build_phases.png" alt="Build Phases" width="840">

3. That's it, congratulations and happy tinkering!

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
The SDK requires iOS 7+, as it depends on the CoreLocation's support for iBeacon first introduced in iOS 7. The feature set of this Estimote SDK is divided into two parts: *Client* and *Utility*. 

**Client** part is dedicated to be used inside your publicly distributed applications featuring Estimote Beacon or Nearable integration. It helps you work with Apple iBeacon objects, adding some useful functionality like filtering, ranged object limitation or combining beacons from few regions into one callback. 

There are also two interesting additions: a simulator class that allows you to speed up testing of your app using virtual beacon/nearable objects, and a helper class for Apple Watch integration. Description of most important components can be found below:

* **ESTBeaconManager** - Simple wrapper around CoreLocation CLLocationManager class. It exposes API to range and monitor iBeacon devices with some additional options like sorting or filtering. It works with pure CLBeacon objects.
* **ESTSecureBeaconManager** - CLLocationManager wrapper dedicated to work with devices that are using Estimote Secure UUID mechanism. Similarily to ESTBeaconManager it allows to range and monitor secured devices as well as verify their proximity.
* **ESTSimulatedBeaconManager** - Creates virtual beacons instances to use in Xcode iOS Simulator. It lets you dispatch fake beacon events related to iBeacon ranging and monitoring.
* **ESTNearableManager** - Entry point to work with Estimote nearable devices. It allows to range and monitor stickers with given type or identifier in the similar manner to how it's done with iBeacon.
* **ESTSimulatedNearableManager** - Analogously to "ESTSimulatedBeaconManager" it lets you generate fake ranging and monitoring events for Estimote nearable devices.
* **ESTNotificationTransporter** - Helper class allowing easy Apple Watch App Extension integration. You will find more details on [Estimote WatchKit SDK](https://github.com/Estimote/Estimote-WatchKit-SDK).

On top of basic ranging and monitoring functionality delivered by classes mentioned above you can also use a higher level **Estimote Trigger engine**. It provides abstraction that simplifies building complex rules describing circumstances that should trigger some action. Sample conditions can be described like this: *"Let me know when I'm next to my moving bike nearable, after 5pm when temperature is lower than 15C."*. 

Estimote Trigger engine provides basic rules (*ESTRule*) related to Estimote nearables and time events. It was created in a way that makes it easy to extend default rules so you can easily build custom rules that suit your needs. Most important classes you will want to use are:

* **ESTTriggerManager** - Entry point for trigger engine mechanism. Its main responsibility is to manage all defined rules and inform you when provided conditions are satisfied.
* **ESTRule** - Base implementation of a rule. All predefined classes like ESTTemperatureRule or ESTMotionRule are based on it and you should also use it to build your own custom rules.
* **ESTTrigger** - Class that allows you to describe context based on a set of rules.

In the typical workflow you will wrap your rules in ESTTrigger object and pass it to ESTTriggerManager.

**Utility** was created to support apps that manage Estimote beacons and nearables. It provides beacon connectivity and configuration methods, so you can easily change settings like Proximity UUID, Major, Minor, Power Modes and much more. It also allows you to easily perform Over The Air firmware update. It works mainly with CoreBluetooth framework. Main classes you are going to use are:

* **ESTUtilityManager** - Allows you to discover devices using both CoreLocation and CoreBluetooth. Discover device identifier then can be used to connect and configure device.
* **ESTBeaconConnection** - Manages connection and configuration of particular device. Allows to both read and write all the settings. 
* **ESTBeaconFirmwareUpdate** - Needed to perform Over The Air firmware update of Estimote beacon.

Another valuable component is **Bulk Updater** mechanism, which lets you update settings of multiple devices in batches. It's compatible with **Remote Management** feature based on Estimote Cloud, so you can define a set of new settings both locally or remotely. After new settings are defined and synced with Estimote Cloud, the updates will be performed using all iOS running devices that are connected to the particular Estimote Account.

Changelog
-------

To see what has changed in recent versions of Estimote SDK, see the [CHANGELOG](https://github.com/Estimote/iOS-SDK/blob/master/CHANGELOG.md).

