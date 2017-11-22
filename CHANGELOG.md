## 5.0.0-alpha.5 (November 22, 2017)

Improvements:

- Estimote Cloud's Analytics events are cached and sent in batches.
- `ESTProximityObserver`'s error block is invoked with error object having domain & error codes defined in `ESTProximityObserver.h`.
- Renamed `ESTProximityZone`'s `onEnterBlock`, `onExitBlock`, `onChangeBlock` to `onEnterAction`, `onExitAction`, `onChangeAction` for better compatibility with Android Proximity SDK.

Bugfixes:

- Fixed a bug where Estimote Monitoring would ignore use motion detection.

## 5.0.0-alpha.4 (October 20, 2017)

Improvements:

- Estimote Monitoring algorithm that powers Proximity Observer now uses device motion to improve experience.
- Optimized CPU and RAM usage when observing multiple zones.

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