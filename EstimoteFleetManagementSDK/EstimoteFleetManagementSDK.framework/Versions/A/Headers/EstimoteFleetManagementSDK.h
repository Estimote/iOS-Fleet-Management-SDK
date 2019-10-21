//  Estimote Fleet Management SDK
//  Version: 4.31.1
//  Copyright (c) 2016 Estimote. All rights reserved.

/**
 *  Apple frameworks
 */
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <SystemConfiguration/SystemConfiguration.h>

/**
 *  Utility tools
 */
#import "ESTDeviceManager.h"
#import "ESTDeviceFilterLocationBeacon.h"
#import "ESTDeviceFilterNearable.h"
#import "ESTLogger.h"

/**
 *  Beacons
 */
#import "ESTBeaconDefinitions.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTDeviceNearable.h"

/**
 *  Settings Connectivity
 */
#import "ESTSettingsConnectivity.h"
#import "ESTSettingConnectivityInterval.h"
#import "ESTSettingConnectivityPower.h"
#import "ESTSettingShakeToConnectEnable.h"

#import "ESTBeaconOperationConnectivityInterval.h"
#import "ESTBeaconOperationConnectivityPower.h"
#import "ESTBeaconOperationShakeToConnectEnable.h"

/**
 *  Settings Power
 */
#import "ESTSettingsPower.h"

#import "ESTSettingPowerSmartPowerModeEnable.h"
#import "ESTSettingPowerFlipToSleepEnable.h"
#import "ESTSettingPowerDarkToSleepEnable.h"
#import "ESTSettingPowerBatteryLifetime.h"
#import "ESTSettingPowerMotionOnlyBroadcastingEnable.h"
#import "ESTSettingPowerMotionOnlyBroadcastingDelay.h"

#import "ESTBeaconOperationPowerSmartPowerModeEnable.h"
#import "ESTBeaconOperationPowerFlipToSleepEnable.h"
#import "ESTBeaconOperationPowerDarkToSleepEnable.h"
#import "ESTCloudOperationPowerBatteryLifetime.h"
#import "ESTBeaconOperationPowerMotionOnlyBroadcastingEnable.h"
#import "ESTBeaconOperationPowerMotionOnlyBroadcastingDelay.h"

/**
 *  Settings Power
 */
#import "ESTSettingPowerScheduledAdvertisingEnable.h"
#import "ESTSettingPowerScheduledAdvertisingPeriod.h"
#import "ESTSettingPowerBatteryPercentage.h"
#import "ESTSettingPowerBatteryVoltage.h"

#import "ESTBeaconOperationPowerScheduledAdvertisingEnable.h"
#import "ESTBeaconOperationPowerScheduledAdvertisingPeriod.h"
#import "ESTBeaconOperationPowerBatteryPercentage.h"
#import "ESTBeaconOperationPowerBatteryVoltage.h"

/**
 *  Settings Device Info
 */
#import "ESTSettingsDeviceInfo.h"
#import "ESTSettingDeviceInfoFirmwareVersion.h"
#import "ESTSettingDeviceInfoApplicationVersion.h"
#import "ESTSettingDeviceInfoBootloaderVersion.h"
#import "ESTSettingDeviceInfoHardwareVersion.h"
#import "ESTSettingDeviceInfoUTCTime.h"
#import "ESTSettingDeviceInfoTags.h"
#import "ESTSettingDeviceInfoGeoLocation.h"
#import "ESTSettingDeviceInfoName.h"
#import "ESTSettingDeviceInfoColor.h"
#import "ESTSettingDeviceInfoIndoorLocationIdentifier.h"
#import "ESTSettingDeviceInfoIndoorLocationName.h"
#import "ESTSettingDeviceInfoUptime.h"
#import "ESTSettingDeviceInfoDevelopmentMode.h"

#import "ESTCloudOperationDeviceInfoFirmwareVersion.h"
#import "ESTBeaconOperationDeviceInfoApplicationVersion.h"
#import "ESTBeaconOperationDeviceInfoBootloaderVersion.h"
#import "ESTBeaconOperationDeviceInfoHardwareVersion.h"
#import "ESTBeaconOperationDeviceInfoUTCTime.h"
#import "ESTCloudOperationDeviceInfoTags.h"
#import "ESTCloudOperationDeviceInfoGeoLocation.h"
#import "ESTCloudOperationDeviceInfoName.h"
#import "ESTCloudOperationDeviceInfoColor.h"
#import "ESTCloudOperationDeviceInfoIndoorLocationIdentifier.h"
#import "ESTBeaconOperationDeviceInfoUptime.h"
#import "ESTCloudOperationDeviceInfoDevelopmentMode.h"

/**
 *  Settings iBeacon Packet
 */
#import "ESTSettingsIBeacon.h"
#import "ESTSettingIBeaconEnable.h"
#import "ESTSettingIBeaconInterval.h"
#import "ESTSettingIBeaconMajor.h"
#import "ESTSettingIBeaconMinor.h"
#import "ESTSettingIBeaconPower.h"
#import "ESTSettingIBeaconProximityUUID.h"
#import "ESTSettingIBeaconSecureUUIDEnable.h"
#import "ESTSettingIBeaconSecureUUIDPeriodScaler.h"
#import "ESTSettingIBeaconNonStrictMode.h"
#import "ESTSettingIBeaconMotionUUID.h"
#import "ESTSettingIBeaconMotionUUIDEnable.h"

#import "ESTBeaconOperationIBeaconEnable.h"
#import "ESTBeaconOperationIBeaconInterval.h"
#import "ESTBeaconOperationIBeaconMajor.h"
#import "ESTBeaconOperationIBeaconMinor.h"
#import "ESTBeaconOperationIBeaconPower.h"
#import "ESTBeaconOperationIBeaconProximityUUID.h"
#import "ESTBeaconOperationIBeaconSecureUUIDEnable.h"
#import "ESTBeaconOperationIBeaconSecureUUIDPeriodScaler.h"
#import "ESTCloudOperationIBeaconNonStrictMode.h"
#import "ESTBeaconOperationIBeaconMotionUUID.h"
#import "ESTBeaconOperationIBeaconMotionUUIDEnable.h"

/**
 *  Settings Estimote Packet
 */
#import "ESTSettingsEstimoteLocation.h"
#import "ESTSettingEstimoteLocationEnable.h"
#import "ESTSettingEstimoteLocationInterval.h"
#import "ESTSettingEstimoteLocationPower.h"

#import "ESTBeaconOperationEstimoteLocationEnable.h"
#import "ESTBeaconOperationEstimoteLocationInterval.h"
#import "ESTBeaconOperationEstimoteLocationPower.h"

/**
 *  Settings Estimote Telemetry Packet
 */
#import "ESTSettingsEstimoteTLM.h"
#import "ESTSettingEstimoteTLMEnable.h"
#import "ESTSettingEstimoteTLMInterval.h"
#import "ESTSettingEstimoteTLMPower.h"

#import "ESTBeaconOperationEstimoteTLMEnable.h"
#import "ESTBeaconOperationEstimoteTLMInterval.h"
#import "ESTBeaconOperationEstimoteTLMPower.h"

/**
 Settings Eddystone UID Packet
 */
#import "ESTSettingsEddystoneUID.h"
#import "ESTSettingEddystoneUIDEnable.h"
#import "ESTSettingEddystoneUIDInstance.h"
#import "ESTSettingEddystoneUIDNamespace.h"
#import "ESTSettingEddystoneUIDInterval.h"
#import "ESTSettingEddystoneUIDPower.h"

#import "ESTBeaconOperationEddystoneUIDEnable.h"
#import "ESTBeaconOperationEddystoneUIDInstance.h"
#import "ESTBeaconOperationEddystoneUIDNamespace.h"
#import "ESTBeaconOperationEddystoneUIDInterval.h"
#import "ESTBeaconOperationEddystoneUIDPower.h"

/**
 Settings Eddystone URL Packet
 */
#import "ESTSettingsEddystoneURL.h"
#import "ESTSettingEddystoneURLEnable.h"
#import "ESTSettingEddystoneURLData.h"
#import "ESTSettingEddystoneURLInterval.h"
#import "ESTSettingEddystoneURLPower.h"

#import "ESTBeaconOperationEddystoneURLEnable.h"
#import "ESTBeaconOperationEddystoneURLData.h"
#import "ESTBeaconOperationEddystoneURLInterval.h"
#import "ESTBeaconOperationEddystoneURLPower.h"

/**
 Settings Eddystone TLM packet
 */
#import "ESTSettingsEddystoneTLM.h"
#import "ESTSettingEddystoneTLMEnable.h"
#import "ESTSettingEddystoneTLMInterval.h"
#import "ESTSettingEddystoneTLMPower.h"

#import "ESTBeaconOperationEddystoneTLMEnable.h"
#import "ESTBeaconOperationEddystoneTLMInterval.h"
#import "ESTBeaconOperationEddystoneTLMPower.h"

/**
 Settings Eddystone EID packet
 */
#import "ESTSettingsEddystoneEID.h"
#import "ESTSettingEddystoneEIDInterval.h"
#import "ESTSettingEddystoneEIDEnable.h"
#import "ESTSettingEddystoneEIDPower.h"

#import "ESTBeaconOperationEddystoneEIDInterval.h"
#import "ESTBeaconOperationEddystoneEIDEnable.h"
#import "ESTBeaconOperationEddystoneEIDPower.h"

/**
 *  Generic Advertisers
 */
#import "ESTSettingGenericAdvertiserEnable.h"
#import "ESTSettingGenericAdvertiserPower.h"
#import "ESTSettingGenericAdvertiserInterval.h"
#import "ESTSettingGenericAdvertiserData.h"

#import "ESTBeaconOperationGenericAdvertiserEnable.h"
#import "ESTBeaconOperationGenericAdvertiserPower.h"
#import "ESTBeaconOperationGenericAdvertiserInterval.h"
#import "ESTBeaconOperationGenericAdvertiserData.h"

/**
 *  GPIO Support
 */
#import "ESTSettingsGPIO.h"
#import "ESTSettingGPIONotificationEnable.h"
#import "ESTGPIOConfig.h"
#import "ESTGPIOPortsData.h"
#import "ESTSettingGPIOPortsData.h"
#import "ESTSettingGPIOConfigPort0.h"
#import "ESTSettingGPIOConfigPort1.h"
#import "ESTSettingGPIO0StateReflectingOnLEDEnable.h"

#import "ESTBeaconOperationGPIONotificationEnable.h"
#import "ESTBeaconOperationGPIOPortsData.h"
#import "ESTBeaconOperationGPIOConfigPort0.h"
#import "ESTBeaconOperationGPIOConfigPort1.h"
#import "ESTBeaconOperationGPIO0StateReflectingOnLEDEnable.h"

/**
 *  Sensors
 */
#import "ESTSettingsSensors.h"

#import "ESTSettingSensorsAmbientLight.h"
#import "ESTSettingSensorsMotionNotificationEnable.h"
#import "ESTSettingSensorsTemperature.h"
#import "ESTSettingSensorsTemperatureOffset.h"
#import "ESTSettingSensorsPressure.h"

#import "ESTBeaconOperationSensorsAmbientLight.h"
#import "ESTBeaconOperationSensorsMotionNotificationEnable.h"
#import "ESTBeaconOperationSensorsTemperature.h"
#import "ESTBeaconOperationSensorsTemperatureOffset.h"
#import "ESTBeaconOperationSensorsPressure.h"

#import "ESTNotificationMotion.h"
#import "ESTNotificationGPIOData.h"

/**
 *  Eddystone Configuration Service
 */
#import "ESTSettingsEddystoneConfigurationService.h"
#import "ESTSettingEddystoneConfigurationServiceEnable.h"

/**
 *  Nearables
 */
#import "ESTNearableDefinitions.h"
#import "ESTNearableSettingsManager.h"

#import "ESTSettingNearableInterval.h"
#import "ESTSettingNearablePower.h"

#import "ESTNearableOperationProtocol.h"
#import "ESTNearableOperationNearableInterval.h"
#import "ESTNearableOperationNearablePower.h"
#import "ESTNearableOperationName.h"
#import "ESTNearableOperationApplicationVersion.h"
#import "ESTNearableOperationHardware.h"
#import "ESTNearableOperationMotionOnly.h"
#import "ESTNearableOperationIBeaconProximityUUID.h"
#import "ESTNearableOperationIBeaconMajor.h"
#import "ESTNearableOperationIBeaconMinor.h"
#import "ESTNearableOperationEddystoneURL.h"
#import "ESTNearableOperationBroadcastingScheme.h"

/**
 *  Bulk updater
 */
#import "ESTLocationBeaconBulkUpdater.h"
#import "ESTLocationBeaconBulkUpdateConfiguration.h"

/**
 *  Cloud API handling
 */
#import "ESTConfig.h"
#import "ESTRequestV3GetFirmwares.h"
#import "ESTRequestV3GetDeviceOwner.h"
#import "ESTRequestGetDeviceDetails.h"
#import "ESTRequestGetDevices.h"
#import "ESTRequestDeletePendingSettings.h"

/**
 *  Cloud value objects
 */
#import "ESTBaseVO.h"
#import "ESTDeviceDetails.h"
#import "ESTDeviceShadow.h"
#import "ESTDeviceSettings.h"
#import "ESTDeviceSettingsGeneral.h"
#import "ESTDeviceSettingsAdvertiserConnectivity.h"
#import "ESTDeviceSettingsAdvertiser.h"
#import "ESTDeviceSettingsAdvertiserIBeacon.h"
#import "ESTDeviceSettingsAdvertiserEddystoneUID.h"
#import "ESTDeviceSettingsAdvertiserEddystoneURL.h"
#import "ESTDeviceSettingsAdvertiserEddystoneTLM.h"
#import "ESTDeviceSettingsAdvertiserEddystoneEID.h"
#import "ESTDeviceSettingsAdvertiserEstimoteLocation.h"
#import "ESTDeviceSettingsAdvertiserEstimoteTLM.h"
#import "ESTDeviceSettingsAdvertiserGeneric.h"
#import "ESTDeviceStatusReport.h"
#import "ESTDeviceGeoLocation.h"
#import "ESTDeviceIndoorLocation.h"
#import "ESTDeviceSchedule.h"
#import "ESTFirmwareInfoV4VO.h"
#import "ESTMesh.h"
#import "ESTNearableFirmwareVO.h"
#import "ESTNearableFirmwareUpdateVO.h"


/**
 *  Estimote Storage
 */
#import "ESTStorageManager.h"

/**
 *  Estimote Mesh
 */
#import "ESTMeshManager.h"
#import "ESTMeshGateway.h"
#import "ESTMeshNearablesScanReportVO.h"
#import "ESTMeshNearablesScanResultVO.h"
#import "ESTMeshScanReportsManager.h"


/* ----------------- DEPRECATED ----------------- */
#import "ESTUtilityManager.h"
#import "ESTBluetoothBeacon.h"
#import "ESTDeviceFilterBeaconV1.h"

#import "ESTBeacon.h"
#import "ESTBeaconManager.h"
#import "ESTSecureBeaconManager.h"
#import "ESTBeaconConnection.h"

#import "ESTNearable.h"
#import "ESTNearableManager.h"
#import "ESTSimulatedNearableManager.h"

#import "ESTBulkUpdater.h"

/**
 *  Trigger engine
 */
#import "ESTTriggerManager.h"

/**
 *  Apple Watch support
 */
#import "ESTNotificationTransporter.h"

/**
 *  Eddystone Support
 */
#import "ESTEddystoneManager.h"
#import "ESTEddystoneFilterUID.h"
#import "ESTEddystoneFilterEID.h"
#import "ESTEddystoneFilterURL.h"
#import "ESTEddystoneFilterURLDomain.h"

/**
 *  Cloud API handling
 */
#import "ESTCloudManager.h"
#import "ESTRequestGetBeacons.h"
#import "ESTRequestGetBeaconsDetails.h"
#import "ESTRequestGetBeaconsPublicDetails.h"
#import "ESTRequestBeaconColor.h"
#import "ESTRequestBeaconMac.h"
#import "ESTRequestAssignGPSLocation.h"

#import "ESTRequestRegisterDevice.h"
#import "ESTRequestGetPendingSettings.h"
#import "ESTRequestCancelPendingSettings.h"
#import "ESTRequestGetSettingsHistory.h"

#import "ESTBeaconVO.h"
#import "ESTNearableVO.h"

#import "ESTRequestV2DeletePendingSettings.h"
#import "ESTRequestV2GetDeviceDetails.h"
#import "ESTRequestV2GetDevices.h"
#import "ESTRequestV2DevicesUpdate.h"
#import "ESTRequestGetNearables.h"

/**
 *  Analytics handling
 */
#import "ESTAnalyticsManager.h"
#import "ESTRequestAnalyticsTrack.h"
#import "ESTAnalyticsEventVO.h"

/**
 * Monitoring
 */
#import "ESTMonitoringManager.h"
#import "ESTMonitoringV2Manager.h"

/**
 * Telemetry support
 */
#import "ESTTelemetryNotificationProtocol.h"
#import "ESTTelemetryNotificationMotion.h"
#import "ESTTelemetryNotificationAmbientLight.h"
#import "ESTTelemetryNotificationTemperature.h"
#import "ESTTelemetryNotificationSystemStatus.h"
#import "ESTTelemetryNotificationMagnetometer.h"
#import "ESTTelemetryNotificationGPIO.h"
#import "ESTTelemetryNotificationPressure.h"

/**
 *  Featuresets
 */
#import "ESTFeaturesetEstimoteMonitoring.h"
#import "ESTFeaturesetBackgroundMode.h"
