
### Setting operations list

Group | Short name | Value type | Operation class | Stored in device | Stored in Cloud
---|---
EstimoteProximity | Enable | BOOL | ESTBeaconOperationEstimoteProximityEnable | ✅ | ✅
EstimoteProximity | Interval | unsigned short | ESTBeaconOperationEstimoteProximityInterval | ✅ | ✅
EstimoteProximity | Power | ESTEstimoteProximityPower | ESTBeaconOperationEstimoteProximityPower | ✅ | ✅
EstimoteTLM | Enable | BOOL | ESTBeaconOperationEstimoteTLMEnable | ✅ | ✅
EstimoteTLM | Interval | unsigned short | ESTBeaconOperationEstimoteTLMInterval | ✅ | ✅
EstimoteTLM | Power | ESTEstimoteTLMPower | ESTBeaconOperationEstimoteTLMPower | ✅ | ✅
iBeacon | Enable | BOOL | ESTBeaconOperationIBeaconEnable | ✅ | ✅
iBeacon | Proximity UUID | NSUUID * | ESTBeaconOperationIBeaconProximityUUID | ✅ | ✅
iBeacon | Major | unsigned short | ESTBeaconOperationIBeaconMajor | ✅ | ✅
iBeacon | Minor | unsigned short | ESTBeaconOperationIBeaconMinor | ✅ | ✅
iBeacon | Secure UUID Enable | BOOL | ESTBeaconOperationSecureUUIDEnable | ✅ | ✅
iBeacon | Secure UUID Period Scaler | uint8_t | ESTBeaconOperationSecureUUIDPeriodScaler | ✅ | ✅
iBeacon | Non-strict mode | BOOL | ESTBeaconOperationIBeaconNonStrictMode | ✅ | ✅
EddystoneUID | Enable | BOOL | ESTBeaconOperationEddystoneUIDEnable | ✅ | ✅
EddystoneUID | Namespace | NSString | ESTBeaconOperationEddystoneUIDNamespace | ✅ | ✅
EddystoneUID | Instance | NSString  | ESTBeaconOperationEddysyoneUIDInstance | ✅ | ✅
EddystoneUID | Interval | unsigned short | ESTBeaconOperationEddysyoneUIDInterval | ✅ | ✅
EddystoneUID | Power | ESTEddystoneUIDPower | ESTBeaconOperationEddystoneUIDPower | ✅ | ✅
EddystoneURL | Enable | BOOL | ESTBeaconOperationEddystoneURLEnable | ✅ | ✅
EddystoneURL | URL Data | NSString * | ESTBeaconOperationEddystoneURLData | ✅ | ✅
EddystoneURL | Interval | unsigned short | ESTBeaconOperationEddystoneURLData | ✅ | ✅
EddystoneURL | Power | ESTEddystoneURLPower | ESTBeaconOperationEddystoneURLPower | ✅ | ✅
EddystoneTLM | Enable | BOOL | ESTBeaconOperationEddystoneTLMEnable | ✅ | ✅
EddystoneTLM | Interval | unsigned short | ESTBeaconOperationEddystoneTLMInterval | ✅ | ✅
EddystoneTLM | Power | ESTEddystoneTLMPower | ESTBeaconOperationEddystoneTLMPower | ✅ | ✅
Connectivity | Interval | unsigned short | ESTBeaconOperationConnectivityInterval | ✅ | ✅
Connectivity | Power | ESTConnectivityPower | ESTBeaconOperationConnectivityPower | ✅ | ✅
DeviceInfo | Color | ESTColor | ESTCloudOperationDeviceInfoColor | ❌ | ✅
DeviceInfo | UTCTime | NSTimeInterval | ESTBeaconOperationUTCTime | ✅ | ❌  
DeviceInfo | Name | NSString * | ESTCloudOperationDeviceInfoName | ✅ | ❌
DeviceInfo | Tags | NSSet<NSString * > * | ESTCloudOperationDeviceInfoTags | ✅ | ❌
