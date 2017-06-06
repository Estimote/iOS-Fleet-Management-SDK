//
// Please report any problems with this app template to contact@estimote.com
//

import Foundation

enum ImmediateBeaconDetectorError: ErrorType {
    case BluetoothDisabled, Unknown
}

protocol ImmediateBeaconDetectorDelegate: class {

    func immediateBeaconDetector(immediateBeaconDetector: ImmediateBeaconDetector, didDiscoverBeacon beacon: ESTDeviceLocationBeacon)

    func immediateBeaconDetector(immediateBeaconDetector: ImmediateBeaconDetector, didFailDiscovery error: ImmediateBeaconDetectorError)

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
        deviceManager.startDeviceDiscoveryWithFilter(ESTDeviceFilterLocationBeacon())
    }

    func stop() {
        deviceManager.stopDeviceDiscovery()
    }

    // MARK: ESTDeviceManagerDelegate

    func deviceManager(manager: ESTDeviceManager, didDiscoverDevices devices: [ESTDevice]) {
        let nextGenBeacons = devices as! [ESTDeviceLocationBeacon]
        let nearestBeacon = nextGenBeacons
            .map { ($0, normalizedRSSIForBeaconWithIdentifier($0.identifier, RSSI: $0.rssi)) }
            .filter { $0.1 != nil && $0.1 >= 0 }
            .maxElement { $0.1 < $1.1 }?.0
        if let nearestBeacon = nearestBeacon {
            delegate.immediateBeaconDetector(self, didDiscoverBeacon: nearestBeacon)
        }
    }

    func deviceManagerDidFailDiscovery(manager: ESTDeviceManager) {
        if bluetoothManager.state != .PoweredOn {
            delegate.immediateBeaconDetector(self, didFailDiscovery: .BluetoothDisabled)
        } else {
            delegate.immediateBeaconDetector(self, didFailDiscovery: .Unknown)
        }
    }

    // MARK: CBCentralManagerDelegate

    func centralManagerDidUpdateState(central: CBCentralManager) {
    }

}
