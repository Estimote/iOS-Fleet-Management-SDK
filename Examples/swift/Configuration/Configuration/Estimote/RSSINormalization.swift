//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

var cachedTxPowers = [String: Int]()
var bannedIdentifiers = Set<String>()

let expectedRSSIs = [
    -30: -68,
    -20: -56,
    -16: -52,
    -12: -48,
     -8: -44,
     -4: -40,
      0: -36,
      4: -32,
]
let deviceRSSICorrection = UIDevice.currentDevice().model == "iPad" ? -14 : 0
let minConsiderableRSSI = expectedRSSIs.minElement({$0.1 < $1.1})!.1 + deviceRSSICorrection

// First, this method normalizes the RSSI between beacons with different Tx power.
//
// Second, this method normalizes the RSSI relative to the RSSI that's expected when the beacon lies on top of the device.
// - eq 0 if the RSSI is exactly as expected
// - gt 0 if the RSSI is greater than expected (meaning the beacon is very likely lying on top of the device)
// - lt 0 if the RSSI is less than expected (meaning the beacon is likely further away from the device)
// The absolute value indicates the magnitude of the difference: e.g, -8 is likely more further away than -4.

func normalizedRSSIForBeaconWithIdentifier(identifier: String, RSSI: Int) -> Int? {
    if RSSI == 127 || RSSI < minConsiderableRSSI { return nil }

    if let txPower = cachedTxPowers[identifier] {
        if let expectedRSSI = expectedRSSIs[txPower] {
            let normalizedRSSI = RSSI - (expectedRSSI + deviceRSSICorrection)
            NSLog("normalized RSSI \(identifier) => \(normalizedRSSI) @ \(txPower) Tx power")
            return normalizedRSSI
        }
    } else if !bannedIdentifiers.contains(identifier) {
        // ban this identifier for the duration of the request, so that we don't send out another request
        bannedIdentifiers.insert(identifier)

        let request = ESTRequestV2GetDeviceDetails(deviceIdentifier: identifier)
        NSLog("requesting Tx power info for \(identifier)")
        request.sendRequestWithCompletion { deviceDetails, error in
            if let deviceDetails = deviceDetails {
                bannedIdentifiers.remove(identifier)
                cachedTxPowers[identifier] = deviceDetails.settings.connectivity.first!.powerInDBm.integerValue
            }
            // we only "unban" the identifier if the request succeeded; we don't want to keep asking about a beacon that results in errors, i.e., doesn't exist or we don't have permission to ask about
        }
    }

    return nil
}
