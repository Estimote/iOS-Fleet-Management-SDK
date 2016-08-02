//
// Please report any problems with this app template to contact@estimote.com
//

class CachingContentFactory: BeaconContentFactory {

    private let beaconContentFactory: BeaconContentFactory

    private var cachedContent = Dictionary<BeaconID, AnyObject>()

    init(beaconContentFactory: BeaconContentFactory) {
        self.beaconContentFactory = beaconContentFactory
    }

    func contentForBeaconID(beaconID: BeaconID, completion: (content: AnyObject) -> ()) {
        if let cachedContent: AnyObject = self.cachedContent[beaconID] {
            completion(content: cachedContent)
        } else {
            self.beaconContentFactory.contentForBeaconID(beaconID) { (content) in
                self.cachedContent[beaconID] = content
                completion(content: content)
            }
        }
    }

}
