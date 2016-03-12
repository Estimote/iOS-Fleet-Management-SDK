## Estimote SDK example apps

**Hint:**  
You can generate yourself a ready-made project from one of these templates on https://cloud.estimote.com/#/apps/add. It will be automatically renamed for you, and have your App Token and beacon UUIDs already put in.

- **Blank**

  A blank Xcode project with Estimote SDK already integrated.

- **HeroIcon**

  > Uses: beacon monitoring, suggested apps

  Monitor for a beacon to have iOS show the app's icon on the lock screen ("suggested apps" feature introduced in iOS&nbsp;8) when in range of the beacon.

- **Notification**

  > Uses: beacon monitoring, local notifications

  Show a notification if the app is not running, and the user enters or exits range of a monitored beacon.

- **ProximityContent**

  > Uses: ranging beacons, Estimote Cloud API to fetch the beacon's name & color

  Change the background color and text on the screen depending on which of the ranged beacons is the closest.

- **Showroom**

  > Uses: [sticker beacons](http://developer.estimote.com/nearables/stickers-vs-beacons/), Nearable packet, trigger engine

  Change the text on screen when user picks up a nearable (motion detection). Imagine, e.g., an iPad mounted in a showroom, and products with Estimote Stickers attached to them. Whenever a visitor picks an item up, the iPad shows information about the product.

- **Configuration** (available in Swift only; works only with Location Beacons)

  > Uses: SDK 4.0's configuration API, Estimote Cloud: tags & geolocation

  Configure and tag your beacons for deployment. _(See the README.md file in this project's directory for more info.)_
