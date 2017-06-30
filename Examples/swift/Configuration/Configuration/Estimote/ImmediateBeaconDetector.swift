//
// Please report any problems with this app template to contact@estimote.com
//

import Foundation
// FIXME: comparison operators with optionals were removed from the Swift Standard Libary.
// Consider refactoring the code to use the non-optional operators.
fileprivate func < <T : Comparable>(lhs: T?, rhs: T?) -> Bool {
  switch (lhs, rhs) {
  case let (l?, r?):
    return l < r
  case (nil, _?):
    return true
  default:
    return false
  }
}

// FIXME: comparison operators with optionals were removed from the Swift Standard Libary.
// Consider refactoring the code to use the non-optional operators.
fileprivate func >= <T : Comparable>(lhs: T?, rhs: T?) -> Bool {
  switch (lhs, rhs) {
  case let (l?, r?):
    return l >= r
  default:
    return !(lhs < rhs)
  }
}


enum ImmediateBeaconDetectorError: Error {
    case bluetoothDisabled, unknown
}

protocol ImmediateBeaconDetectorDelegate: class {

    func immediateBeaconDetector(_ immediateBeaconDetector: ImmediateBeaconDetector, didDiscoverBeacon beacon: ESTDeviceLocationBeacon)

    func immediateBeaconDetector(_ immediateBeaconDetector: ImmediateBeaconDetector, didFailDiscovery error: ImmediateBeaconDetectorError)

}

/**
 This class encapsulates all the logic related to detecting when a beacon has been placed immediately on the phone.
 */
class ImmediateBeaconDetector: NSObject, ESTDeviceManagerDelegate, CBCentralManagerDelegate {

    let deviceManager = ESTDeviceManager()
    var bluetoothManager: CBCentralManager!

    unowned var delegate: ImmediateBeaconDetectorDelegate

    init(delegate: ImmediateBeaconDetectorDelegate) {
        self.delegate = delegate

        super.init()

        deviceManager.delegate = self

        bluetoothManager = CBCentralManager(delegate: self, queue: nil)
    }

    func start() {
        deviceManager.startDeviceDiscovery(with: ESTDeviceFilterLocationBeacon())
    }

    func stop() {
        deviceManager.stopDeviceDiscovery()
    }

    // MARK: ESTDeviceManagerDelegate

    func deviceManager(_ manager: ESTDeviceManager, didDiscover devices: [ESTDevice]) {
        let nextGenBeacons = devices as! [ESTDeviceLocationBeacon]
        let nearestBeacon = nextGenBeacons
            .map { ($0, normalizedRSSIForBeaconWithIdentifier($0.identifier, RSSI: $0.rssi)) }
            .filter { $0.1 != nil && $0.1 >= 0 }
            .max { $0.1 < $1.1 }?.0
        if let nearestBeacon = nearestBeacon {
            delegate.immediateBeaconDetector(self, didDiscoverBeacon: nearestBeacon)
        }
    }

    func deviceManagerDidFailDiscovery(_ manager: ESTDeviceManager) {
        if bluetoothManager.state != .poweredOn {
            delegate.immediateBeaconDetector(self, didFailDiscovery: .bluetoothDisabled)
        } else {
            delegate.immediateBeaconDetector(self, didFailDiscovery: .unknown)
        }
    }

    // MARK: CBCentralManagerDelegate

    func centralManagerDidUpdateState(_ central: CBCentralManager) {
    }

}
