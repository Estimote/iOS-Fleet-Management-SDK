//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

func estimoteCloudReachable() -> Bool {
    var address = sockaddr_in()
    address.sin_len = UInt8(sizeofValue(address))
    address.sin_family = sa_family_t(AF_INET)
    address.sin_port = in_port_t(443)
    address.sin_addr.s_addr = inet_addr("cloud.estimote.com")

    guard let reachability = withUnsafePointer(&address, {
        SCNetworkReachabilityCreateWithAddress(nil, UnsafePointer($0))
    }) else {
        return false
    }

    var flags : SCNetworkReachabilityFlags = []
    if !SCNetworkReachabilityGetFlags(reachability, &flags) {
        return false
    }

    let isReachable = flags.contains(.Reachable)
    let needsConnection = flags.contains(.ConnectionRequired)

    return isReachable && !needsConnection
}

func updateFirmwareIfUpdateAvailable(
    beacon: ESTDeviceLocationBeacon,
    progress: (progressPercentage: Int) -> Void,
    completion: (error: NSError?) -> Void) {

        beacon.updateFirmwareWithProgress(
            { progressPercentage in
                dispatch_async(dispatch_get_main_queue(), {
                    progress(progressPercentage: progressPercentage)
                })
            }, completion: { error in
                if error == nil || error!.code == ESTDeviceLocationBeaconError.FirmwareUpdateNoUpdate.rawValue {
                    dispatch_async(dispatch_get_main_queue(), {
                        completion(error: nil)
                    })
                } else {
                    dispatch_async(dispatch_get_main_queue(), {
                        completion(error: error)
                    })
                }
            }
        )
}

func writeSettingsToBeacon(
    beacon: ESTDeviceLocationBeacon,
    settings: [ESTSettingReadWrite],
    progress: (finishedOperationsCount: Int) -> Void,
    completion: (failedOperations: [(operationIdentifier: String, error: NSError)]) -> Void) {

        var finishedOperationsCount = 0
        var failedOperations = [(operationIdentifier: String, error: NSError)]()

        let completionGenerator = { (operationIdentifier: String) ->
            ((newValue: AnyObject?, error: NSError?) -> Void) in return { _, maybeError in
                finishedOperationsCount += 1
                if let error = maybeError {
                    failedOperations.append((operationIdentifier, error))
                }

                progress(finishedOperationsCount: finishedOperationsCount)
                if finishedOperationsCount == settings.count {
                    completion(failedOperations: failedOperations)
                }
            }
        }

        let operations = settings.map {
            operationForSetting($0, completionGenerator: completionGenerator)!
        }
        beacon.settings!.performOperationsFromArray(operations)
}

func operationForSetting(
    setting: ESTSettingReadWrite,
    completionGenerator: (operationIdentifier: String) -> ((AnyObject?, NSError?) -> Void))
    -> ESTBeaconOperationProtocol! {

        switch setting {

        case let setting as ESTSettingDeviceInfoTags:
            return ESTCloudOperationDeviceInfoTags.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "tags"))

        case let setting as ESTSettingDeviceInfoGeoLocation:
            return ESTCloudOperationDeviceInfoGeoLocation.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "geolocation"))

        case let setting as ESTSettingPowerSmartPowerModeEnable:
            return ESTBeaconOperationPowerSmartPowerModeEnable.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "smart power mode"))

        case let setting as ESTSettingIBeaconEnable:
            return ESTBeaconOperationIBeaconEnable.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon enabled"))

        case let setting as ESTSettingIBeaconInterval:
            return ESTBeaconOperationIBeaconInterval.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon advertising interval"))

        case let setting as ESTSettingIBeaconMajor:
            return ESTBeaconOperationIBeaconMajor.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon major"))

        case let setting as ESTSettingIBeaconMinor:
            return ESTBeaconOperationIBeaconMinor.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon minor"))

        case let setting as ESTSettingIBeaconNonStrictMode:
            return ESTCloudOperationIBeaconNonStrictMode.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon non-strict mode"))

        case let setting as ESTSettingIBeaconPower:
            return ESTBeaconOperationIBeaconPower.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon transmit power"))

        case let setting as ESTSettingIBeaconProximityUUID:
            return ESTBeaconOperationIBeaconProximityUUID.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon UUID"))

        case let setting as ESTSettingIBeaconSecureUUIDEnable:
            return ESTBeaconOperationIBeaconSecureUUIDEnable.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "iBeacon Secure UUID enabled"))

        case let setting as ESTSettingEstimoteTLMEnable:
            return ESTBeaconOperationEstimoteTLMEnable.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "TLM enabled"))

        case let setting as ESTSettingEstimoteTLMInterval:
            return ESTBeaconOperationEstimoteTLMInterval.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "TLM advertising interval"))

        case let setting as ESTSettingEstimoteTLMPower:
            return ESTBeaconOperationEstimoteTLMPower.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "TLM transmit power"))

        case let setting as ESTSettingConnectivityInterval:
            return ESTBeaconOperationConnectivityInterval.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "connectivity advertising interval"))

        case let setting as ESTSettingConnectivityPower:
            return ESTBeaconOperationConnectivityPower.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "connectivity transmit power"))

        case let setting as ESTSettingEstimoteLocationEnable:
            return ESTBeaconOperationEstimoteLocationEnable.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "Estimote packet enabled"))

        case let setting as ESTSettingEstimoteLocationInterval:
            return ESTBeaconOperationEstimoteLocationInterval.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "Estimote packet advertising interval"))

        case let setting as ESTSettingEstimoteLocationPower:
            return ESTBeaconOperationEstimoteLocationPower.writeOperationWithSetting(setting,
                completion: completionGenerator(operationIdentifier: "Estimote packet transmit power"))

        default:
            assertionFailure("Couldn't find an operation to handle writing the \(setting.dynamicType) setting. Make sure there's an appropriate case statement in the `operationForSetting:` function.")
            return nil
        }
}
