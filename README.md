# Estimote iOS SDK

## Introduction

Estimote SDK aims to provide a simple way for apps to react to physical context by reading signals from [Estimote Beacons](https://estimote.com/products/). It uses Core Bluetooth and Core Location frameworks to provide the best beacon-based experience possible.

### Why should you use it

1. Reliability. It's built upon [Estimote Monitoring](http://blog.estimote.com/post/163745555265/estimote-monitoring-20-with-even-better-accuracy), Estimote's algorithm for reliable enter/exit reporting.
2. No need to operate on abstract identifiers, or Proximity UUID, Major, Minor triplets. Estimote SDK 5 lets you define zones by setting predicates for human-readable JSONs.
3. You can define multiple zones for a single beacon, i.e. at different ranges.
4. Cloud-backed grouping. When you change your mind and want to replace one beacon with another, all you need to do is reassign JSON attachments in Estimote Cloud. You don't even need to connect to the beacon!

Note: this is a **pre-release** version of Estimote SDK 5. For the lastest stable release, see [master branch](https://github.com/Estimote/iOS-SDK/tree/master).

## Installation

### CocoaPods 

[CocoaPods](https://cocoapods.org/) is a simple way to add external libraries. To use it to fetch Estimote SDK:

1. Add `pod 'EstimoteSDK', '~> 5.0.0-alpha'` to your Podfile
1. Run `pod install --repo-update`
1. Add `#import "EstimoteSDKv5/EstimoteSDKv5.h"` to your Objective-C code or Objective-C Bridging Header if you're using Swift.

### Manual

1. Download the repo
    - Click the "Download ZIP" button, or
    - Run `git clone git@github.com:Estimote/iOS-SDK.git --depth=1`

1. Drag & drop [EstimoteSDK.framework](EstimoteSDK/EstimoteSDK.framework) to your project (enable the checkbox in _Options_ > _Copy files if needed_)

## Requirements

- One or more [Estimote Proximity or Location Beacons](https://estimote.com/products/)
- An iOS device with Bluetooth Low Energy running iOS 8 or later. Using BLE with iOS Simulator isn't supported.

## Usage

The library is compatible with both Objective-C and Swift - it's written in Objective-C, its API is optimized for Swift. It's distributed as a static framework (static library bundled with headers in a special folder structure).

## Attachment-based identification

Details of each of your Estimote devices are available in [Estimote Cloud](https://cloud.estimote.com/#/). Each device has a unique identifier, but remembering it and using it for every one of your devices can be challenging. This is why Estimote SDK 5 uses attachment-based identification.

Each device has an associated JSON. When the SDK detects a proximity change of a device, it checks the device's attachment JSON to see which registered rule should be applied.

During the pre-release stage of Estimote SDK 5, attachment JSONs are encoded in [tags](https://community.estimote.com/hc/en-us/articles/204909347-How-to-tag-and-search-for-beacons-in-Estimote-Cloud-). The convention for a tag-encoded attachment is 
```
{
    "attachment" : {
        // Attachment JSON goes here.
        // You can put here any JSON you wish to use in your apps.
    }
}
```

### Example

To get a working prototype, check out the [Desk Observer](Examples/swift/DeskObserver) example app. It's a single screen app with three labels that change background color:
- when you are in close proximity to the first desk, 
- in close proximity to the second desk, 
- when you are in the venue in general.

The demo requires at least two Proximity or Location beacons configured for Estimote Monitoring. It's enabled by default in dev kits shipped after mid-September 2017; to enable it on your own check out the [instructions](https://community.estimote.com/hc/en-us/articles/226144728-How-to-enable-Estimote-Monitoring-).

The demo expects beacons having specific tags assigned:
- `{"attachment":{"desk":"blueberry","venue":"office"}}` for the first one,
- `{"attachment":{"desk":"mint","venue":"office"}}` for the second one.

These attachments can be used to define the zones presented below:

![](readme_images/demo_attachments.png)

<p align="center">
    <i>Attachment-based zones</i>
</p>

To conifgure the attachments:
1. Go to https://cloud.estimote.com/#/
1. Click on the beacon you want to configure
1. Click _Edit settings_ button
1. Click _Tags_ field
1. Click _Create New Tag_ button
1. Paste in the JSON with attachment that's going to represent your beacon
1. Click _Save changes_

Tags are Cloud-only settings — no additional connecting to the beacons with the Estimote app is required.

![](readme_images/adding_attachment_json_tag.png)

<p align="center">
    <i>Assigning attachment JSON as tag</i>
</p>

### Inside your app

To use the SDK within your app, go to the [apps section](https://cloud.estimote.com/#/apps) in Estimote Cloud. Register a new app or use one of the available templates to obtain App ID & App Token credentials pair.

In your app, set up the credentials using `ESTCloudCredentials`:

```swift
let credentials = ESTCloudCredentials(appID: "your-app-id", appToken: "your-app-token")
```

Then, configure proximity discovery with `ESTProximityObserver`. For more info on attachments, see [this section](#attachment-based-identification).

```swift
// Create observer instance
self.proximityObserver = ESTProximityObserver(credentials: credentials, errorBlock: { error in
    print("Ooops! \(error)")
})


// Define zones
let blueberryZone = ESTProximityZone(range: ESTProximityRange.custom(meanTriggerDistance: 0.5)!,
                                     attachmentKey: "desk",
                                     attachmentValue: "blueberry")
blueberryZone.onEnterAction = { attachment in
    print("Entered near range of 'desk':'blueberry'. Full beacon attachment: (attachment.attachmentJSON)")
}
blueberryZone.onExitAction = { (attachment) in
    print("Exited near range of 'desk':'blueberry'. Full beacon attachment: (attachment.attachmentJSON)")
}

// ... etc. You can define as many zones as you need.

// Start proximity observation
self.observer.startObserving([blueberryZone])
```

### Background support

To allow your app to react to physical context when it's in the background:
- Set _Uses Bluetooth LE accessories_ in your Xcode project settings -> _Capabilities_ -> _Background Modes_. It's required for Core Bluetooth to work in the background.
- Add a value for _Privacy - Location Always Usage Description_ key in your app's Info.plist file. It will be the message of an alert that will be shown to the user when the app calls `-[ESTProximityObserver start]`. It's required for Core Location to work.
