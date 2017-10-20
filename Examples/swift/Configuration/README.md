### Configuration app

**IMPORTANT:** The Configuration app works only with [Location Beacons](http://blog.estimote.com/post/139902664710/launching-the-most-robust-location-beacons-on-the) and [Proximity Beacons with NFC](http://blog.estimote.com/post/147038205465/announcing-next-gen-proximity-beacons-with) at this time.

This app uses a few external dependencies managed through [CocoaPods](https://cocoapods.org).

You can check if you have CocoaPods installed by running:
```
$ pod --version
```

If you don't have CocoaPods installed you must install them before building this app. You can follow [CocoaPods getting started instructions](https://guides.cocoapods.org/using/getting-started.html).

In the project folder run:
```
$ pod update
```
to add pods to your project.

Make sure you open the project using .xcworkspace file instead of .xcodeproj file.

#### Extras

The Configuration app comes with an extra Scanner app, which you can use to evaluate your beacon setup. This is most helpful for deployment flows that go like this:

1. Take a bag of beacons with you into the venue you want to deploy beacons in.
2. One by one, pull beacons out of the bag, and configure them using the Configuration app you prepared yourself earlier. In the example Configuration app code, the beacon are tagged with their department ("electronics", "toys", etc.) and aisle number ("aisle 13", etc.)
3. Use the Scanner app from Extras to evaluate the range, signal bleed, and enter events of the beacons you've just deployed. The Scanner app fetches your tags from Estimote Cloud and cross-references them with detected beacons, for easier evaluation.
