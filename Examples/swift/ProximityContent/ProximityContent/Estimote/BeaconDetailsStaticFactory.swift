//
// Please report any problems with this app template to contact@estimote.com
//

class BeaconDetailsStaticFactory: BeaconContentFactory {

    let staticContent: [BeaconID: BeaconDetails]

    init(staticContent: [BeaconID: BeaconDetails]) {
        self.staticContent = staticContent
    }

    func contentForBeaconID(beaconID: BeaconID, completion: (content: AnyObject) -> ()) {
        if let beaconDetails = self.staticContent[beaconID] {
            completion(content: beaconDetails)
        } else {
            NSLog("No static content found for beacon \(beaconID), will use default values instead. Make sure there's some content defined for this beacon.")
            completion(content: BeaconDetails(
                beaconName: "beacon",
                beaconColor: .Unknown))
        }
    }

}
