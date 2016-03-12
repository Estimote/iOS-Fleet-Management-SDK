//
//  BeaconContentFactory.swift
//  ProximityContent
//

protocol BeaconContentFactory {

    func contentForBeaconID(beaconID: BeaconID, completion: (content: AnyObject) -> ())

}
