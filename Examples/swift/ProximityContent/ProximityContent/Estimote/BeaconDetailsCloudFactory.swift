//
// Please report any problems with this app template to contact@estimote.com
//

class BeaconDetailsCloudFactory: BeaconContentFactory {

    func contentForBeaconID(beaconID: BeaconID, completion: (content: AnyObject) -> ()) {
        let beaconDetailsRequest = ESTRequestBeaconDetails(
            proximityUUID: beaconID.proximityUUID, major: beaconID.major, minor: beaconID.minor)

        beaconDetailsRequest.sendRequestWithCompletion { (beaconDetails, error) in
            if let beaconDetails = beaconDetails {
                completion(content: BeaconDetails(
                    beaconName: beaconDetails.name ?? "\(beaconID.major):\(beaconID.minor)",
                    beaconColor: beaconDetails.color))
            } else {
                NSLog("Couldn't fetch data from Estimote Cloud for beacon \(beaconID), will use default values instead. Double-check if the app ID and app token provided in the AppDelegate are correct, and if the beacon with such ID is assigned to your Estimote Account. The error was: \(error)")
                completion(content: BeaconDetails(
                    beaconName: "beacon",
                    beaconColor: .Unknown))
            }
        }
    }

}
