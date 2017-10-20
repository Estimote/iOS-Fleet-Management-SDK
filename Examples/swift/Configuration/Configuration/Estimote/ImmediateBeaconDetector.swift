//
// Please report any problems with this app template to contact@estimote.com
//

import Foundation

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

    @objc let deviceManager = ESTDeviceManager()
    @objc var bluetoothManager: CBCentralManager!

    unowned var delegate: ImmediateBeaconDetectorDelegate

    init(delegate: ImmediateBeaconDetectorDelegate) {
        self.delegate = delegate

        super.init()

        deviceManager.delegate = self

        bluetoothManager = CBCentralManager(delegate: self, queue: nil)
    }

    @objc func start() {
        deviceManager.startDeviceDiscovery(with: ESTDeviceFilterLocationBeacon())
    }

    @objc func stop() {
        deviceManager.stopDeviceDiscovery()
    }

    // MARK: ESTDeviceManagerDelegate

    func deviceManager(_ manager: ESTDeviceManager, didDiscover devices: [ESTDevice]) {
        let nextGenBeacons = devices as! [ESTDeviceLocationBeacon]
        let beaconsWithNormalizedRSSI = nextGenBeacons.map { ($0, normalizedRSSIForBeaconWithIdentifier($0.identifier, RSSI: $0.rssi)) }.filter { $0.1 != nil && $0.1! >= 0 }
        let nearestBeacon = beaconsWithNormalizedRSSI.max { $0.1! < $1.1! }?.0
        
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
