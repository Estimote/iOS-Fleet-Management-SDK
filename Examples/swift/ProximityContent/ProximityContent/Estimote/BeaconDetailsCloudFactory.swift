//
// Please report any problems with this app template to contact@estimote.com
//

class BeaconDetailsCloudFactory: BeaconContentFactory {
    
    func requestContent(for beacon: CLBeacon, completion: @escaping (_ content: AnyObject) -> ()) {
        let beaconDetailsRequest = ESTRequestGetBeaconsDetails(beacons: [beacon], andFields: ESTBeaconDetailsFields.allFields)
        
        beaconDetailsRequest.sendRequest { (beaconsVO, error) in
            if let beaconDetails = beaconsVO?.first as? ESTBeaconVO {
                completion(BeaconDetails(
                    beaconName: beaconDetails.name ?? "\(beacon.major):\(beacon.minor)",
                    beaconColor: beaconDetails.color))
            } else {
                NSLog("Couldn't fetch data from Estimote Cloud for beacon \(beacon.beaconID), will use default values instead. Double-check if the app ID and app token provided in the AppDelegate are correct, and if the beacon with such ID is assigned to your Estimote Account. The error was: \(String(describing: error))")
                completion(BeaconDetails(
                    beaconName: "beacon",
                    beaconColor: .unknown))
            }
        }
    }
    
}
