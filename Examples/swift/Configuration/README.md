### Configuration app

**IMPORTANT:** The Configuration app works only with [Location Beacons](http://blog.estimote.com/post/139902664710/launching-the-most-robust-location-beacons-on-the) (hardware revision "F") and [next-gen Proximity Beacons](http://blog.estimote.com/post/147038205465/announcing-next-gen-proximity-beacons-with) (hardware revision "G") at this time.

This app uses a few external dependencies managed through [CocoaPods](https://github.com/CocoaPods/CocoaPods).

You must install and run CocoaPods before building this app:

1.  Follow [CocoaPods installation instructions](http://guides.cocoapods.org/using/getting-started.html#installation).

2.  Open Terminal and navigate to this directory.

    ```
    $ cd ~/path/to/Configuration
    ```

3.  Run Carthage.

   ```
   $ pod install
   ```

 4.  Open Configuration.xcworkspace.


#### Extras

The Configuration app comes with an extra Scanner app, which you can use to evaluate your beacon setup. This is most helpful for deployment flows that go like this:

1. Take a bag of beacons with you into the venue you want to deploy beacons in.
2. One by one, pull beacons out of the bag, and configure them using the Configuration app you prepared yourself earlier. In the example Configuration app code, the beacon are tagged with their department ("electronics", "toys", etc.) and aisle number ("aisle 13", etc.)
3. Use the Scanner app from Extras to evaluate the range, signal bleed, and enter events of the beacons you've just deployed. The Scanner app fetches your tags from Estimote Cloud and cross-references them with detected beacons, for easier evaluation.
