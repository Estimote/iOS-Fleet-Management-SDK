//
//  ProximityContentManager.swift
//  ProximityContent
//

protocol ProximityContentManagerDelegate: class {

    func proximityContentManager(proximityContentManager: ProximityContentManager, didUpdateContent content: AnyObject?)

}

class ProximityContentManager: NearestBeaconManagerDelegate {

    weak var delegate: ProximityContentManagerDelegate?

    private let beaconContentCache: BeaconContentCache
    private let nearestBeaconManager: NearestBeaconManager

    init(beaconRegions: [CLBeaconRegion], beaconContentFactory: BeaconContentFactory) {
        self.beaconContentCache = BeaconContentCache(beaconContentFactory: beaconContentFactory)
        self.nearestBeaconManager = NearestBeaconManager(beaconRegions: beaconRegions)
        self.nearestBeaconManager.delegate = self
    }

    convenience init(beaconIDs: [BeaconID], beaconContentFactory: BeaconContentFactory) {
        let beaconRegions = beaconIDs.map { $0.asBeaconRegion }
        self.init(beaconRegions: beaconRegions, beaconContentFactory: beaconContentFactory)
    }

    func startContentUpdates() {
        self.nearestBeaconManager.startNearestBeaconUpdates()
    }

    func stopContentUpdates() {
        self.nearestBeaconManager.stopNearestBeaconUpdates()
    }

    func nearestBeaconManager(nearestBeaconManager: NearestBeaconManager, didUpdateNearestBeaconID nearestBeaconID: BeaconID?) {
        if let nearestBeaconID = nearestBeaconID {
            self.beaconContentCache.contentForBeaconID(nearestBeaconID) { (proximityContent) in
                self.delegate?.proximityContentManager(self, didUpdateContent: proximityContent)
            }
        } else {
            self.delegate?.proximityContentManager(self, didUpdateContent: nil)
        }
    }

}
