//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class BeaconDetails {

    let beaconName: String
    let backgroundColor: UIColor

    init(beaconName: String, backgroundColor: UIColor) {
        self.beaconName = beaconName
        self.backgroundColor = backgroundColor
    }

    convenience init(beaconName: String, beaconColor: ESTColor) {
        self.init(
            beaconName: beaconName,
            backgroundColor: BeaconDetails.backgroundColorForBeaconColor(beaconColor))
    }

    private static let backgroundColors: [ESTColor: UIColor] = [
        .IcyMarshmallow: UIColor(red: 109/255.0, green: 170/255.0, blue: 199/255.0, alpha: 1.0),
        .BlueberryPie:   UIColor(red:  36/255.0, green:  24/255.0, blue:  93/255.0, alpha: 1.0),
        .MintCocktail:   UIColor(red: 155/255.0, green: 186/255.0, blue: 160/255.0, alpha: 1.0)
    ]

    static let neutralColor = UIColor(red: 160/255.0, green: 169/255.0, blue: 172/255.0, alpha: 1.0)

    private static func backgroundColorForBeaconColor(beaconColor: ESTColor) -> UIColor {
        return backgroundColors[beaconColor] ?? neutralColor
    }

}
