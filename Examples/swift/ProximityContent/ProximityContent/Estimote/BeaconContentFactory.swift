//
// Please report any problems with this app template to contact@estimote.com
//

protocol BeaconContentFactory {

    func requestContent(for beaconID: BeaconID, completion: @escaping (_ content: AnyObject) -> ())

}
