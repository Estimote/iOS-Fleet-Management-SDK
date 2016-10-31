//
// Please report any problems with this app template to contact@estimote.com
//

class CachingContentFactory: BeaconContentFactory {

    private let beaconContentFactory: BeaconContentFactory

    private var cachedContent = Dictionary<BeaconID, AnyObject>()

    init(beaconContentFactory: BeaconContentFactory) {
        self.beaconContentFactory = beaconContentFactory
    }

    func requestContent(for beaconID: BeaconID, completion: @escaping (_ content: AnyObject) -> ()) {
        if let cachedContent: AnyObject = self.cachedContent[beaconID] {
            completion(cachedContent)
        } else {
            self.beaconContentFactory.requestContent(for: beaconID) { (content) in
                self.cachedContent[beaconID] = content
                completion(content)
            }
        }
    }

}
