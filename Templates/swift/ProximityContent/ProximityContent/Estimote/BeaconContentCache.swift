//
//  BeaconContentCache.swift
//  ProximityContent
//

class BeaconContentCache {

    private let beaconContentFactory: BeaconContentFactory

    private var cachedContent = Dictionary<BeaconID, AnyObject>()

    init(beaconContentFactory: BeaconContentFactory) {
        self.beaconContentFactory = beaconContentFactory
    }

    func contentForBeaconID(beaconID: BeaconID, completion: (AnyObject) -> ()) {
        if let content: AnyObject = self.cachedContent[beaconID] {
            completion(content)
        } else {
            self.beaconContentFactory.contentForBeaconID(beaconID) { (content) in
                self.cachedContent[beaconID] = content
                completion(content)
            }
        }
    }

}
