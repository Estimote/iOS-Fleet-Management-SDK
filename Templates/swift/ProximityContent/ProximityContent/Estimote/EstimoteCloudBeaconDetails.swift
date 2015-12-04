//
//  EstimoteCloudBeaconDetails.swift
//  ProximityContent
//

import UIKit

class EstimoteCloudBeaconDetails {

    let beaconName: String
    let backgroundColor: UIColor

    init(beaconName: String, backgroundColor: UIColor) {
        self.beaconName = beaconName
        self.backgroundColor = backgroundColor
    }

    static let neutralColor = UIColor(red: 160/255.0, green: 169/255.0, blue: 172/255.0, alpha: 1.0)

}

class EstimoteCloudBeaconDetailsFactory: BeaconContentFactory {

    private static let backgroundColors: [ESTColor: UIColor] = [
        .IcyMarshmallow: UIColor(red: 109/255.0, green: 170/255.0, blue: 199/255.0, alpha: 1.0),
        .BlueberryPie:   UIColor(red:  36/255.0, green:  24/255.0, blue:  93/255.0, alpha: 1.0),
        .MintCocktail:   UIColor(red: 155/255.0, green: 186/255.0, blue: 160/255.0, alpha: 1.0)
    ]

    func contentForBeaconID(beaconID: BeaconID, completion: (content: AnyObject) -> ()) {
        let beaconDetailsRequest = ESTRequestBeaconDetails(
            proximityUUID: beaconID.proximityUUID, major: beaconID.major, minor: beaconID.minor)

        beaconDetailsRequest.sendRequestWithCompletion { (beaconDetails, error) in
            if let beaconDetails = beaconDetails {
                completion(content: EstimoteCloudBeaconDetails(
                    beaconName: beaconDetails.name ?? "\(beaconID.major):\(beaconID.minor)",
                    backgroundColor: self.backgroundColorForBeaconColor(beaconDetails.color)))
            } else {
                NSLog("Couldn't fetch data from Estimote Cloud for beacon \(beaconID), will use default values instead. Double-check if the app ID and app token provided in the AppDelegate are correct, and if the beacon with such ID is assigned to your Estimote Account. The error was: \(error)")
                completion(content: EstimoteCloudBeaconDetails(
                    beaconName: "beacon",
                    backgroundColor: self.backgroundColorForBeaconColor(.Unknown)))
            }
        }
    }

    private func backgroundColorForBeaconColor(beaconColor: ESTColor) -> UIColor {
        return EstimoteCloudBeaconDetailsFactory.backgroundColors[beaconColor]
            ?? EstimoteCloudBeaconDetails.neutralColor
    }

}
