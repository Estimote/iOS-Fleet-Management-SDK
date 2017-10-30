# Estimote SDK example apps

## General Info

**Hint:**
You can generate yourself a ready-made project from most of these templates on https://cloud.estimote.com/#/apps/add. It will be automatically renamed for you, and have your App Token and beacon UUIDs already put in.

**Pods update**

Some of the following apps uses a few external dependencies managed through [CocoaPods](https://cocoapods.org).

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

## Examples

- **Blank**

A blank Xcode project with Estimote SDK already integrated.

- **Notification**

> Uses: beacon monitoring, local notifications

Show a notification if the app is not running, and the user enters or exits range of a monitored beacon.

- **ProximityContent**

> Uses: ranging beacons, Estimote Cloud API to fetch the beacon's name & color

Change the background color and text on the screen depending on which of the ranged beacons is the closest.

- **Showroom**

> Uses: [sticker beacons](http://estimote.com/#products), Nearable packet, trigger engine

Change the text on screen when user picks up a nearable (motion detection). Imagine, e.g., an iPad mounted in a showroom, and products with Estimote Stickers attached to them. Whenever a visitor picks an item up, the iPad shows information about the product.

- **Configuration** (Swift only, requires Estimote Beacons with the 4th-gen firmware, 4.x+)

> Uses: SDK 4.0's configuration API, Estimote Cloud: tags & geolocation

Configure and tag your beacons for deployment. _(See the README.md file in this project's directory for more info.)_

- **GPIO** (Swift only, requires Estimote Beacons with the 4th-gen firmware, 4.x+)

> Uses: SDK 4.0's configuration API … and, well, GPIO (:

Wirelessly access external devices connected to the beacons' GPIO ports. _(See the README.md file in this project's directory for more info.)_

- **Loyalty** (Swift only, requires Estimote Beacons with the 4th-gen firmware, 4.x+)

> Uses: Estimote Proximity Beacons, Estimote monitoring

Cashier-customer app that allows cashiers to see customers at checkout in their iPad app and grant them bonus points for their shopping. Completely new experience of earning points without carrying loyalty cards or scanning barcodes.

- **NFCStamps** (Swift only, requires Estimote Beacons with the 4th-gen firmware, 4.x+)

> Uses: Estimote Beacons NFC chips, CoreNFC

Build NFC-powered use cases with CoreNFC framework from Apple and NFC chips inside our beacons.
