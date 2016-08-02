//
// Please report any problems with this app template to contact@estimote.com
//

protocol BeaconContentFactory {

    func contentForBeaconID(beaconID: BeaconID, completion: (content: AnyObject) -> ())

}
