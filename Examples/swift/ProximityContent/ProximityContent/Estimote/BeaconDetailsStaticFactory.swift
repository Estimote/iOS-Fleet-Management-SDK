//
// Please report any problems with this app template to contact@estimote.com
//

class BeaconDetailsStaticFactory: BeaconContentFactory {
    
    let staticContent: [BeaconID: BeaconDetails]
    
    init(staticContent: [BeaconID: BeaconDetails]) {
        self.staticContent = staticContent
    }
    
    func requestContent(for beacon: CLBeacon, completion: @escaping (_ content: AnyObject) -> ()) {
        if let beaconDetails = self.staticContent[beacon.beaconID] {
            completion(beaconDetails)
        } else {
            NSLog("No static content found for beacon \(beacon.beaconID), will use default values instead. Make sure there's some content defined for this beacon.")
            completion(BeaconDetails(
                beaconName: "beacon",
                beaconColor: .unknown))
        }
    }
    
}
