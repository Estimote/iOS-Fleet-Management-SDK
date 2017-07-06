//
// Please report any problems with this app template to contact@estimote.com
//

protocol ProximityContentManagerDelegate: class {

    func proximityContentManager(_ proximityContentManager: ProximityContentManager, didUpdateContent content: AnyObject?)

}

class ProximityContentManager: NearestBeaconManagerDelegate {

    weak var delegate: ProximityContentManagerDelegate?

    private let beaconContentFactory: BeaconContentFactory

    private let nearestBeaconManager: NearestBeaconManager

    init(beaconRegions: [CLBeaconRegion], beaconContentFactory: BeaconContentFactory) {
        self.beaconContentFactory = beaconContentFactory
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

    func nearestBeaconManager(_ nearestBeaconManager: NearestBeaconManager, didUpdateNearestBeaconID nearestBeaconID: BeaconID?) {
        if let nearestBeaconID = nearestBeaconID {
            self.beaconContentFactory.requestContent(for: nearestBeaconID) { (proximityContent) in
                self.delegate?.proximityContentManager(self, didUpdateContent: proximityContent)
            }
        } else {
            self.delegate?.proximityContentManager(self, didUpdateContent: nil)
        }
    }

}
