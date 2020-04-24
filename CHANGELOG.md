## 4.32.2 (April 24, 2020)
### Fixed
- `ESTNearableScanner` could from time to time trigger saving `unknown` values for nearable's firmware and/or hardware. Not anymore.
- Nearable's firmware update.
- Minor bugfixes.

## 4.31.1 (October 21, 2019)
### Fixed
- Failing to detect nearables on iOS 13 devices
- Improved compatibility with iOS 13

## 4.31.0 (July 5, 2019)

Time for the final release of Estimote Fleet Management 4.x
Next version of Estimote Fleet Management SDK will support (as its name would suggest) only managing devices at scale (i.e. connect and sync/update).
Stay tuned for EFM 5.x! 🖖

### Fixed
- Failing `ESTDeviceManager` when it scanned Estimote Secure Monitoring enabled frames.

### Deprecated
- Ranging devices. If you need to scan for all sorts of Estimote packets please use [`Estimote Bluetooth Scanning`](https://github.com/Estimote/iOS-Bluetooth-Scanning).
- Monitoring for devices. Monitoring is what you need? Don't hesitate to use [`Proximity SDK`](https://github.com/Estimote/iOS-Proximity-SDK-Source). 
- `ESTBeaconConnection` alongside with `ESTBulkUpdater` (the one for _old_ beacons, up to D3.4). If you would need for any reason to connect and/or changes settings you need this SDK in 4.x version.
- Sending telemetry readings to Cloud - if needed please use [`Proximity SDK`](https://github.com/Estimote/iOS-Proximity-SDK-Source).
- Sending analytics to Cloud.

### Important
- Many requests were updated, and even more deprecated. Please read https://cloud.estimote.com/docs/ if you haven't so far for more information.
- This is as well last version of Estimote Fleet Management _not using_ [`Estimote Bluetooth Scanning`](https://github.com/Estimote/iOS-Bluetooth-Scanning).

## 4.30.0 (May 22, 2019)

### Features
- Connecting to a device will synchronize NFC and Estimote Secure Monitoring (ESM) related settings.
- `ESTDeviceManager` will detect and decrypt ESM enabled devices.

## 4.29.0 (Apirl 4, 2019)

### Renaming!
Starting with version 4.29.0 this SDK will be named `Estimote FleetManagement SDK`, but don't worry - no API changes!
We've updated the name of the SDK to better reflect its purpose.

## 4.28.0 (March 21, 2019)

Features:
- Added "TemperatureOffset" setting.

You can use this setting to calibrate the beacon's temperature sensor.

For example, if you measure that the sensor in the beacon is off by 1.2 degree C (shows 21.2 instead of 20.0), set the temperature offset to -1.2.

## 4.27.0 (December 18, 2017)

Features:
-  Some classes have new initializers with queue for dispatching events of a `CBCentralManager`, see: `ESTDeviceManager`, `ESTMeshManager`.
- `ESTDeviceManager` has a new delegate method returning error for device discovery failure (see: `- (void)deviceManager:(ESTDeviceManager *)manager didFailDiscoveryWithError:(NSError *)error;`. Previous callback is deprecated since 4.27.0).

## 4.26.3 (November 13, 2017)

Bugfixes:
- Fixed not connecting with Location Beacons.

## 4.26.2 (November 10, 2017)

Features:
- `ESTMeshGateway` implements `ESTMeshGatewayDelegate` protocol. It will make tracking assets easier, as you can retrieve all necessary data from delegate's method.

Improvements:
- Simplified `ESTMeshManager` documentation, so it should be easier to grasp Mesh related concepts.
- Better granulation of asking for permissions when using Estimote Monitoring.

Bugfixes:
- Simplified and cleared confirming Mesh Buffer during connecting with Location Beacon,
- Confirming commands when connecting with Location Beacon,
- Minor cleaning and code improvements.

## 4.26.1 (October 24, 2017)

Bugfixes:
- Fix for `ESTBeaconDevice` crash when using `ESTBulkUpdater` update functionality.
- Fix for broken save of name, tags and location in Estimote Cloud using operation based mechanism.

## 4.26.0 (October 23, 2017)

Features:
- Gateway can track changes in Mesh network and periodicaly gather scan results, which are sent to Estimote Cloud
- Mesh network's settings can be set through `ESTMeshManager`
- connecting with Location Beacon confirms applying commands to Mesh network

Bugfixes:
- geolocation setting synchronises properly with Cloud
- incorrect comparing firmware revisions during the OTA update process

## 4.25.4 (October 16, 2017)

Improvements:
- Fixes for CoreBluetooth crash on iOS 11 devices. Multiple serial queues for CBCentralManager replaced with single one.
- Mesh Advertiser power settings synchronised with Estimote Cloud.

## 4.25.3 (October 11, 2017)

Improvements:
- Update related to change of AppStore submission guidelines

## 4.25.2 (October 10, 2017)

Bugfixes:
- We added pagination to the request for fetching user's devices. Now you can filter by identifiers, device types and result page of devices you want to retrieve from Cloud.

## 4.25.1 (October 5, 2017)

Bugfixes:
- We’ve fixed crash on CBPeripheral delegate observer removal. Crash was showing up on  iOS 11 only mainly when using ESTBulkUpdater class.

## 4.25.0 (October 4, 2017)

Features:
- ESTMeshManager is now supporting triggering scanning for nearables within Mesh network and generating scan report.
- ESTDeviceLocationBeacon has a new member (`ESTMeshScanReportsManager`) responsible for reading nearables scan reports from Mesh network.
- Added request wrapper for delete pending settings.

## 4.24.0 (September 26, 2017)

Features:
- introduced ESTMeshGateway - newest tool for controlling Mesh networks. ESTMeshGateway serves two purposes:
- confirming received Mesh packets in Estimote Cloud, so Cloud can track changes instantly,
- periodical polling Cloud for pending changes within Mesh network and applying them right away.
- connecting to Location Beacon applies Mesh buffer and locks pending changes within Mesh network (until they are applied across whole network)

Bugfixes:
- not connecting to old beacons (D3.x),
- synchronizing commands with Location Beacon,
- sending empty settings to Cloud.

## 4.23.0 (September 13, 2017)

Features:
- ESTMeshManager now supports triggering automapping commands in Cloud. Connect with any meshed device to start automapping across UWB Mesh network.

## 4.22.1 (August 29, 2017)

Bugfixes:
- Corrected converting values of battery percentage

## 4.22.0 (August 28, 2017)

Improvements:
* Added a method to `ESTMonitoringV2Manager` for checking current monitoring state.
* `ESTMonitoringV2ManagerDelegate` now also delegates successful start of monitoring and when monitoring state for a zone is first determined.

## 4.21.0 (August 22, 2017)

Features:
- Location (hardware revision “F”) support calibrating magnetometers via Cloud.

Bugfixes:
- Fixed building dictionary for GPIO settings confirmation.
- Fix for Here & Now support on UWB beacons.

## 4.20.1 (August 16, 2017)

Bugfixes:

- Fixed a bug where ESTBeaconManager would not send messages to its delegate (i.e. `beaconManager:didRangeBeacons:inRegion:`).

## 4.20.0 (August 10, 2017)

Bugfixes:

- Fixed duplicated symbols issues when using Estimote iOS SDK and Estimote Indoor SDK in the same project.
- Fixed "Download ZIP" button not working (see: https://github.com/git-lfs/git-lfs/issues/903)

Improvements:

- Contrary to the previous version (4.19.0), this one doesn't require git-lfs to run.
- Dropped support for armv7s architecture.
- Reduced framework size.

## 4.19.0 (July 28, 2017)

Features:

- ESTMonitoringV2Manager - it contains Estimote Monitoring v2.0 algorithm with more accurate monitoring events, better exit reliability, software-defined monitoring range, and more efficient monitoring for multiple beacons.

Bugfixes:

- Fixed a bug where Firmware Update would report progress even after cancelling the update process.

Improvements:

- Mesh message buffer sync is faster now.

## 4.18.0 (July 25, 2017)

Features:

- Cloud support and synchronization of GPIO settings.
- GPIO Config Port 0 state can be reflected on LED

## 4.17.0 (July 6, 2017)

Features:

- Estimote Routed Mesh support added.
  
  
  ## 4.16.2 (June 23, 2017)
  
  Bugfixes:
  
  - further framework size optimization
  
  
  ## 4.16.1 (June 22, 2017)
  
  Improvements:
  
  - deprecated ESTRequestV2GetDeviceDetails, now ESTRequestGetDeviceDetails should be used for fetching device's details from Estimote Cloud
  
  Bugfixes:
  
  - corrected symlinks in EstimoteSDK.framework (previously they made framework file excessively large)
  - fixed not synchronizing properly Here & Now advertiser
  
  
  ## 4.16.0 (June 5, 2017)
  
  Features:
  
  - Location Beacons have now generic advertisers, allowing to broadcast custom packets (e.g. one Location Beacon can broadcast up to 4 iBeacon packets)
  - Added feature set for Background Mode enabling correct work of Indoor Location in background. Please note that for enabling Estimote Monitoring there is a complete feature set ESTFeaturesetEstimoteMonitoring!
  
  Improvements:
  
  - Added support for +20dBm broadcasting power (Location Beacons with I1.2, i.e. UWB Beacons)
  
  Bugfixes:
  
  - proper development flag handling in pending settings
  
  ## 4.15.0 (May 16, 2017)
  
  Improvements:
  
  - Estimote Monitoring background mode support. Enabling this mode allows to use Estimote monitoring when application is in the background.
  - Development mode support. When development mode is enabled anyone can connect and configure beacon’s settings. Configuration process stays secure using authorisation mechanism. Applied changes are reflected in the Estimote Cloud Dashboard.
  - Improvement of secure beacon manager monitoring. With these changes enter/exit events are delivered in more reliable way.
  
  Bugfixes:
  
  - Fixed monitoring of nearables when ESTNearableTypeAll type is used. Before no events were generated.
  
  ## 4.14.1 (April 11, 2017)
  
  Improvements:
  
  - added convenience methods to ESTLocationBulkUpdater for calculating failed and successful updates
  
  Bugfixes:
  
  - added advertiser’s settings for Mesh and UWB to ESTDeviceSettings
  
  ## 4.14.0 (March 7, 2017)
  
  Features:
  - Bulk Updater now updates firmware of Location Beacons with Automatic Firmware Update enabled.
  
  Improvements:
  - Improved stability of settings management.
  - Improved Bulk Updater performance for big Deployments.
  - Improved Bulk Updater reliability in background mode.
  
  Bugfixes:
  - Fixed issue when changes to a devices's name were not applied.
  
  ## 4.13.1 (February 1, 2017)
  
  Bugfixes:
  
  - Before, apps running on iOS 10 could become unresponsive when scanning for multiple packets in an environment with a big number of beacons nearby the device.
  
  ## 4.11.0 (October 11, 2016)
  
  Features:
  
  - Location Beacon has Estimote Storage, a non-volatile data storage.  Feature requires firmware 4.9.0 or newer.
  
  ## 4.10.0 (September 30, 2016)
  
  Features:
  
  - Configurable delay for Motion Only Broadcasting. Thanks to this setting beacon is broadcasting for the while even if beacon stopped moving. Feature requires firmware 4.8.0 or newer.
  
  ## 4.9.0 (September 26, 2016)
  
  Features:
  
  - Shake to Connect broadcasting mode makes identifying Location Beacon easier
  - Near to Connect broadcasting mode makes connecting to Location Beacon easier
  - improved firmware update for Location Beacons
  - added automatic firmware update to Location Beacons bulk updater
  
  ## 4.8.1 (September 8, 2016)
  
  Features:
  
  - Added new power levels for Location and new Proximity Beacons
  
  Bugfixes:
  
  - Fixed bug with faulty Telemetry synchronisation with Cloud
  - Fixed synchronising Location Beacon settings with Cloud
  
  ## 4.8.0 (August 25, 2016)
  
  Features:
  
  - Estimote Monitoring support. It allows apps to detect when somebody is entering and exiting the range of beacons. Compared to iOS Core Location Monitoring, it allows for more granular enters/exits without any region limit or exit timeout.
  
  Bugfixes:
  
  - Fixed incorrect packet detection when scanning Telemetry v1.1.
  
  ## 4.7.4 (August 11, 2017)
  
  Features:
  
  - Added support for Telemetry v1.1 packet
  
  Improvements:
  
  - Fixed synchronising iBeacon packet's data for Location Beacons
  
  ## 4.7.3 (August 5, 2016)
  
  Bug fixes:
  - Fixed remaining battery lifetime issue for Proximity Beacons
  - Fixed ranging for connectivity packet for Proximity Beacons
  - Enhanced error validation for Proximity UUID setting
  
  ## 4.7.2 (July 21, 2016)
  
  Improvements:
  
  - ESTBulkUpdater applies Motion Only and Flip to Sleep broadcasting modes
  - Fixed synchronisation of nearables settings with Estimote Cloud
  
  ## 4.7.1 (July 4, 2016)
  
  Features:
  
  - Estimote Analitycs are turned on for monitoring and ranging.
  
  ## 4.7.0 (July 1, 2016)
  
  Bug fixes:
  
  - Fixed Dark to Sleep
  - Remote edit of Flip to Sleep
  - Fixed Conditional broadcasting for Location Beacons
  
  ## 4.6.0 (June 23, 2016)
  
  Features:
  
  - Added Eddystone URL support for nearables. Three broadcasting schemes available: nearable, iBeacon and Eddystone URL.
  
  ## 4.5.1 (June 16, 2016)
  
  Bug fixes:
  
  - Fixed Basic and Smart Power Modes handling for Proximity beacons.
  
  ## 4.5.0 (June 9, 2016)
  
  Features:
  
  - Nearables motion only setting added
  - Nearable are fully synced upon connection with Estimote Cloud
  - Added fleet management for nearables
  
  ## 4.4.0 (May 27, 2016)
  
  Features:
  
  - Google Eddystone Configuration Service support for Location Beacons.
  - GPIO UART protocol support for Location Beacons.
  
  Improvements:
  
  - Performance improvements to Analytics mechanism.
  
  ## 4.3.0 (May 6, 2016)
  
  Features:
  
  - ESTLogger added to ease debugging. Can be set with different levels for printing and caching logs.
  - Added writing tags for Proximity Beacons.
  
  Improvements:
  
  - Fixed changing beacon's settings on firmware update completion.
  - Refactored logs with new ESTLogger.
  
  ## 4.2.0 (May 5, 2016)
  
  Improvements:
  
  - ESTSecureBeaconManager now returns ESTBeacon objects instead of CLBeacon.
  
  
  ## 4.1.0 (April 15, 2016)
  
  Features:
  
  - Support of Google Eddystone Ephemeral ID.
  
  Improvements:
  
  - Improved monitoring of firmware stability.
  - Missing ESTNearableProtocolDelegate warning fixed.
  
  ## 4.0.0 (March 3, 2016)
  
  Features:
  
  - Two brand new management APIs: Convenience API and Advanced API.
  - Multipacket support for next gen beacons - now devices can broadcast multiple packets, with separate powers and advertising intervals independently.
  - GPIO support for next gen beacons.
  - ESTDeviceManager class for connectivity packet discovery.
  
  Improvements:
  
  - Using Cloud API v2 under the hood for next gen beacons making beacon-Cloud desynchronization nearly impossible.
  
  ## 3.8.2 (January 19, 2016)
  
  Improvements:
  
  - GPS Location support in ESTBeaconConnection
  - Firmware and Hardware version added to ESTNearableVO object fetched from cloud
  - Improved efficiency of Secure UUID monitoring.
  
  Bugfixes:
  
  - Firmware changelog properly filled in Cloud request.
  - Parsing of power and interval value in Nearables packet fixed
  - Occasional nearable connection crash fixed.
  
  ## 3.8.1 (November 25, 2015)
  
  Improvements:
  
  - Bitcode support fixed (Issue with archiving apps)
  - Eddystone stability improvements
  
  ## 3.8.0 (November 6, 2015)
  
  Features:
  
  - Internal structure update to support Estimote Indoor SDK 2.0.0
  - Request for fetching public beacon information
  
  Improvements:
  
  - Nullability coverage improved
  
  ## 3.7.1 (October 29, 2015)
  
  Features:
  
  - Estimote Cloud request to fetch public information about beacons
  
  Improvements:
  
  - Improved performance of Analytics in Secure Beacon Manager
  
  Bugfixes:
  
  - Corrected Eddystone Cloud data parsing
  - Corrected Power Modes parsing in settings history
  
  ## 3.7.0 (October 5, 2015)
  
  Features:
  
  - Firmware update for nearables
  - Reading and writing advertising interval and broadcasting power for nearables
  
  Improvements:
  
  - iOS 9 support (nullability and bitcode)
  
  
  ## 3.6.0 (September 10, 2015)
  
  Features:
  
  - New Beacon details request with option to request multiple beacons and selective fields
  - New request for fetching history of beacon settings changes
  - New request canceling pending settings applied in cloud
  
  Improvements:
  
  - Optimized analytics requests. Now sent in batch and locally cached
  - Bulk Updated progress contains additional update information
  
  ## 3.5.0 (August 26, 2015)
  
  Improvements:
  
  - Strongly improved Estimote Cloud API handling mechanism. ESTCloudManager was deprecated. ESTConfig with direct requests should be used instead.
  - ESTSecureBeaconManager supports accuracy based sorting for ranging
  
  ## 3.4.1 (August 25, 2015)
  
  Improvements:
  
  - Improvements to memory and network load: SDK won't automatically fetch and cache list of your beacons after invoking `[ESTCloudManager setupAppID:andAppToken:];`
  - Method `fetchNearableDetails:completion` in `ESTCloudManager` class allowing you to fetch additional data about nearable.
  - `ESTNearableVO` class available
  
  ## 3.4.0 (August 19, 2015)
  
  Improvements:
  
  - Security improvements in the beacon authorization mechanism
  - Over The Air Update (OTA) stability improvements
  - AppID and AppToken accessible from ESTCloudManager
  - GPS location accessible from ESTBeaconConnection
  
  ## 3.3.3 (July 29, 2015)
  
  Improvements:
  
  - Reduced frequency with which beacon cache is being written to disk, which
  results in reduced recurring CPU utilization.
  - Secure UUID performance improvements continue: in this episode, we sped up
  ranging for secure beacons; noticeable especially when ranging for a large
  amount of regions.
  
  Bug fixes:
  
  - Eddystone-URL will now correctly handle printable characters appearing at the
  very end of the URL.
  
  ## 3.3.2 (July 24, 2015)
  
  Bug fixes:
  
  - Unified way of handling Namespace ID and Instance ID (uppercase)
  - Eddystone telemetry property changes (awakeTime -> uptimeMillis, battery -> batteryVoltage, pocketType -> packetType)
  - Incorrect error when changing broadcasting type between Eddystone options.
  - Detecting Eddystone devices with telemetry only fixed.
  
  ## 3.3.1 (July 15, 2015)
  
  Features:
  
  - Eddystone manager supports discovery of all devices in range
  - Type corrections
  
  ## 3.3.0 (July 14, 2015)
  
  Features:
  
  - Eddystone support
  - Broadcasting schemes introduced
  
  ## 3.2.12 (July 14, 2015)
  
  Bugfixes:
  
  - Lots of improvements to stability and performance of Secure UUID ranging and monitoring
  
  ## 3.2.11 (July 9, 2015)
  
  Bugfixes:
  
  - Incorrect monitoring related events from ESTSecureBeaconManager fixed
  
  ## 3.2.10 (July 8, 2015)
  
  Bugfixes:
  
  - Crash during ranging beacons related to caching fixed
  - Missing beaconConnection:didDisconnectWithError: event enabled in ESTBeaconConnection
  
  ## 3.2.9 (July 7, 2015)
  
  Bugfixes:
  
  - Incorrect values sent to Estimote Cloud for Basic and Smart Power Modes
  - Crash on beacon device disconnect event corrected (additional issues found)
  
  ## 3.2.8 (July 2, 2015)
  
  Bugfixes:
  
  - Crash on beacon device disconnect event corrected
  - nil region handling added to Beacon Manager and Secure Beacon Manager
  - beaconManager:didFailWithError: callback added to Beacon Manager and Secure Beacon Manager
  - handling of beaconManager:didStartMonitoringForRegion: added to Secure Beacon Manager
  - handling of beaconManager:rangingBeaconsDidFailForRegion: added to Secure Beacon Manager
  - handling of beaconManager:monitoringDidFailForRegion: added to Secure Beacon Manager
  
  ## 3.2.7 (June 11, 2015)
  
  Bugfixes:
  
  - fixed crash in nearables caching
  
  ## 3.2.6 (June 10, 2015)
  
  Bugfixes:
  
  - fixed incorrect handling of accented characters in beacon names
  
  ## 3.2.5 (May 22, 2015)
  
  Bugfixes:
  
  - saving cache to disk no longer happens on the main thread
  
  Improvements:
  
  - added RSSI property (updated in real-time) to the ESTBeaconConnection
  - added a method to fetch a beacon's MAC address from the cloud to the
  ESTCloudManager
  
  ## 3.2.4 (May 19, 2015)
  
  Bugfixes:
  
  - Fixed a crash that could sometimes occur when stopping monitoring of a secure
  UUID region
  
  ## 3.2.3 (May 15, 2015)
  
  Bugfixes:
  
  - Bulk updater issue with updating device power to 0 value
  - Fixed duplicated events in Secured Beacon Manager
  - Smart Power Mode reading corrected
  
  Improvements:
  
  - Supress the "Bluetooth disabled" warning
  - Persist secure monitored regions between app relaunches
  - Secured Beacon Manager invoke beaconManager:didDeterminState: on main thread
  - SystemConfiguration added to the umbrella header
  
  ## 3.2.2 (April 29, 2015)
  
  Features:
  
  - New `monitoredRegions` and `rangedRegions` properties
  for ESTBeaconManager and ESTSecureBeaconManager
  
  Bugfixes:
  
  - ESTSecureBeaconManager now reports the initial state of the
  monitored region to the didDetermineState delegate method, just
  like Core Location monitoring does
  - ESTSecureBeaconManager now responds correctly to the
  `requestStateForRegion` method
  - The `color` property is now properly filled in from the Estimote
  Cloud during the process of connecting to the beacon
  - The `name` is now properly updated after changing it via the
  `writeName` method
  
  ## 3.2.1 (April 24, 2015)
  
  Bugfixes:
  
  - Deleted unnecessary logs
  
  ## 3.2.0 (April 23, 2015)
  
  Features:
  
  - New Analytics covering CoreLocation regions implemented
  - GPS support for Analytics added
  - Virtual Beacon demo added
  
  Bugfixes:
  
  - Virtual beacon fixed
  - Missing disconnect event for beacons fixed
  - Nearables monitoring fixed
  
  ## 3.1.0 (April 10, 2015)
  
  Features:
  
  - Option to mark GPS location for beacon
  
  Bugfixes:
  
  - Memory leak in secured region monitoring
  - Disconnect after OTA procedure issue
  - Analytics not sending events in regular/secured beacon manager
  - Motion state incorrect value sent to delegate fixed
  - Caching beacons corrected
  - Secured beacons ranging delay fixed
  - returnAllRangedBeaconsAtOnce flag of ESTBeaconManager fixed
  
  ## 3.0.3 (March 27, 2015)
  
  Bugfixes:
  
  - Crash on Utility manager delegate invocation fixed
  - Multiple invocations of Bulk update fixed
  
  Improvements:
  
  - Cocoapods support updated for Framework architecture
  - Awesome ASCII art header added:)
  
  ## 3.0.2 (March 26, 2015)
  
  Bugfixes:
  - Utility Manager bluetooth status handling fixed
  - Multiple invocations of startEstimoteBeaconDiscovery on ESTUtilityManager corrected
  - Fixed crash when using ESTBeaconConnection with swift
  - ESTBeaconManager locationManager:didStartMonitoringForRegion: proxy fixed
  - ESTBeaconManager locationManager:monitoringDidFailForRegion: proxy fixed
  - ESTBeaconManager locationManager:rangingBeaconsDidFailForRegion: proxy fixed
  - ESTBeaconConnection name property filled during connection
  - ESTSecuredBeaconManager related crash fixed
  
  ## 3.0.1 (March 24, 2015)
  
  Features:
  - Remote Beacon Management based on Push Notifications
  
  Improvements:
  - Save beacon settings after connection corrected
  - Additional settings tracked by the cloud
  
  ## 3.0.0 (March 18, 2015)
  
  Features:
  - Conditional broadcasting (flip to stop, motion only)
  - Remote Beacon Management
  
  Improvements:
  - New architecture of Estimote SDK
  - Support for firmware 3.0.1 (Authorization change)
  
  ## 3.0.0-beta (February 27, 2015)
  
  IMPORTANT:
  This is work in progress version of Estimote SDK 3.0.0. Functionality is currently limited comparing to stable 2.4.0. Please not that both Estimote SDK and Estimote beacons firmware 3.0.0 are not backward compatible!
  
  Improvements:
  - New architecture of Estimote SDK
  - Support for firmware 3.0.0
  
  ## 2.4.0 (February 9, 2015)
  
  Improvements:
  - Ranged nearables list sorting (RSSI = 127 moved to the end of the list)
  - Color added to nearable objects
  - Option to fetch all nearables from the cloud for authorized users (ESTNearableManager)
  - Example of changing beacons settings added
  
  Bugfixes:
  - Firmware and Hardware version formatting of nearables corrected
  - Nearables monitoring fixed (constant monitoring issue)
  
  ## 2.3.2 (January 16, 2015)
  
  Improvements:
  - Motion UUID support (please note that secured beacons are not supported yet).
  - Corrected handling of unknown nearable type name
  
  Bugfixes:
  - Fixed bug that caused crash after starting monitoring for the same sticker type more than once.
  
  ## 2.3.1 (January 8, 2015)
  
  Improvements:
  - Swift Ranging example added
  - Custom Triggers example added
  - Accelerometer example added
  
  Bugfixes:
  - Trigger manager double monitoring crash solved
  - Compilation issue with undefined symbol solved
  
  ## 2.3.0 (December 24, 2014)
  
  Features:
  - Estimote Nearables support added
  - Trigger engine
  
  Improvements:
  - Beacon discovery allows to define time interval
  - Estimote Cloud Authorization and Analytics methods moved to ESTConfig class
  
  Bugfixes:
  - Beacons color requests number optimised
  
  ## 2.2.1 (November 20, 2014)
  
  Improvements:
  - Bulk updater refactored
  - Bulk updater demo added
  
  ## 2.2.0 (November 19, 2014)
  
  Features:
  - Secure UUID rotation added to prevent from hijacking beacons
  - Bulk update
  - Estimote Analytics
  - 8x faster firmware update
  
  ## 2.1.5 (September 26, 2014)
  
  Bugfixes:
  - Corrected Firmware download bug
  
  ## 2.1.4 (September 25, 2014)
  
  Bugfixes:
  - Missing armv7s architecture added to the library
  
  ## 2.1.3 (September 24, 2014)
  
  Improvements:
  - Corrected Cocoapods support
  
  ## 2.1.2 (September 24, 2014)
  
  Improvements:
  - Support for iOS 8 Authorization in Examples app
  - Fixed problem with first time connection crashing
  - Stability improvements
  
  ## 2.1.1 (September 16, 2014)
  
  Features:
  
  - Added support for the new CoreLocation authorization model introduced in iOS 8
  
  You can read more about it in our [Estimote SDK and iOS 8 Location Services](https://community.estimote.com/hc/en-us/articles/203393036-Estimote-SDK-and-iOS-8-Location-Services) guide.
  
  Improvements:
  
  ## 2.1.0 (September 4, 2014)
  
  Features:
  
  - Added support for battery power modes
  
  Improvements:
  
  - Connection stability
  - Accelerometer support
  - Caching the beacon color information
  - Performance with high number of beacons
  
  Bugfixes:
  
  - Fixed crashes when using CoreLocation's non-beacon monitoring (i.e. `CLCiruclarRegion`) and Estimote SDK in a single app
  
  ## 2.0.1 (July 15, 2014)
  
  Bugfixes:
  
  - Fixed 100% CPU usage when ranging beacons
  
  ## 2.0.0 (June 6, 2014)
  
  Features:
  
  - Added integration with the Estimote Cloud
  - Added support for temperature and accelerometer sensors
  - Added `motionProximityUUID` to `ESTBeacon`
  - Added support for firmware: Estimote OS 2.0 and up
  
  Improvements:
  
  - Better connection status handling
  - Improved Examples app
  
  New `ESTBeacon` API:
  
  - The following methods have new names:
  
  - `connectToBeacon` is now `connect`
  - `disconnectBeacon` is now `disconnect`
  - `writeBeaconName:withCompletion:` is now `writeName:completion:`
  - `writeBeaconProximityUUID:withCompletion:` is now `writeProximityUUID:completion:`
  - `writeBeaconMajor:withCompletion:` is now `writeMajor:completion:`
  - `writeBeaconMinor:withCompletion:` is now `writeMinor:completion`
  - `writeBeaconAdvInterval:withCompletion:` is now `writeAdvInterval:completion:`
  - `writeBeaconPower:withCompletion:` is now `writePower:completion:`
  - `updateBeaconFirmwareWithProgress:andCompletion:` is now `updateFirmwareWithProgress:completion:`
  
  ## 1.3.0 (January 25, 2014)
  
  Features:
  
  - `proximityUUID` can now be changed
  
  ## 1.2.0 (December 9, 2013)
  
  Improvements:
  
  - `ESTBeacon` class cleanup (flat structure with iBeacon property removed)
  - Updated the EstimoteSDK Reference documentation
  
  Bugfixes:
  
  - Corrected the name of the DistanceDemo project
  
  ## 1.1.0 (December 2, 2013)
  
  Features:
  
  - Renamed the `frequency` property to `advInterval`
  - Added support for checking for available firmware updates
  - Renamed the library from *libEstimoteSDK7.a* to *libEstimoteSDK.a*
  
  Bugfixes:
  
  - Changed the type of `major`, `minor`, `power` and `advInterval` properties to unsigned short
  - Fixed an issue with the `(NSArray *)beacons` parameter of `beaconManager:didDiscoverBeacons:inRegion`
  
  ## 1.0.0 (November 7, 2013)
  
  Features:
  
  - Ranging and monitoring of Estimote beacons
  - Added support for connecting to Estimote beacons, which enables access to following properties:
  - major, minor, power and frequency - read and write
  - battery, firmware version and hardware version - readonly
  - Added support for updating firmware
