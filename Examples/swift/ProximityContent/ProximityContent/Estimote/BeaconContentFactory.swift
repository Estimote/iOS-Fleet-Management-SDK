//
// Please report any problems with this app template to contact@estimote.com
//

protocol BeaconContentFactory {

    func requestContent(for beacon: CLBeacon, completion: @escaping (_ content: AnyObject) -> ())

}
