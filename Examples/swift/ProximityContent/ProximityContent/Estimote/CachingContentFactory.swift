//
// Please report any problems with this app template to contact@estimote.com
//

class CachingContentFactory: BeaconContentFactory {
    
    private let beaconContentFactory: BeaconContentFactory
    
    private var cachedContent = Dictionary<BeaconID, AnyObject>()
    
    init(beaconContentFactory: BeaconContentFactory) {
        self.beaconContentFactory = beaconContentFactory
    }
    
    func requestContent(for beacon: CLBeacon, completion: @escaping (_ content: AnyObject) -> ()) {
        if let cachedContent: AnyObject = self.cachedContent[beacon.beaconID] {
            completion(cachedContent)
        } else {
            self.beaconContentFactory.requestContent(for: beacon) { (content) in
                self.cachedContent[beacon.beaconID] = content
                completion(content)
            }
        }
    }
    
}
