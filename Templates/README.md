## Estimote SDK example apps

Available examples:

- **Blank**

  A blank Xcode project with Estimote SDK already integrated. Use it to learn how to add Estimote SDK to your project.

- **HeroIcon**

  > Uses: beacon monitoring, suggested apps

  Monitor for a beacon to have iOS show the app's icon on the lock screen ("suggested apps" feature introduced in iOS&nbsp;8) when in range of the beacon.

- **Notification**

  > Uses: beacon monitoring, local notifications

  Show a notification if the app is not running, and the user enters or exits range of a monitored beacon.

- **Proximity Content**

  > Uses: ranging beacons, Estimote Cloud API to fetch the beacon's name & color

  Change the background color and text on the screen depending on which of the ranged beacons is the closest.

- **Showroom**

  > Uses: [sticker beacons](http://developer.estimote.com/nearables/stickers-vs-beacons/), Nearable packet, trigger engine

  Change the text on screen when user picks up a nearable (motion detection). Imagine, e.g., an iPad mounted in a showroom, and products with Estimote Stickers attached to them. Whenever a visitor picks an item up, the iPad shows information about the product.
