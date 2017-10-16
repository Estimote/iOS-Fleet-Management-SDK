## 5.0.0-alpha.3 (October 13, 2017)

Bugfixes: 

- Fixed issue with CoreBluetooth scanning that caused occasional crashes on iOS 11.

## 5.0.0-alpha.2 (October 6, 2017)

Features: 

- `ESTProximityZone` that allows filtering JSON attachments by key, value pairs. Instances of this class also enable registering callbacks for monitoring events.
- Sending Estimote Monitoring analytics events that will be presented in Estimote Cloud's dashboard in upcoming release.

Improvements: 

- Optimized resources allocation when starting observation of multiple zones (calling `-[ESTProximityObserver startObservingZones:]`).

## 5.0.0-alpha.1 (September 15, 2017)

Features: 

- `ESTProximityObserver` with `onEnter`, `onExit`, `onBeaconsInRangeChange` methods, based on Estimote Monitoring.
- Attachment-based beacon identification.