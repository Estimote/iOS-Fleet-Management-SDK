//
// Please report any problems with this app template to contact@estimote.com
//

import Foundation
import UIKit

/// Provides an API for fetching content related to beacons, in this simple case it's colors.
class CloudManager {
    
    enum RequestResult<T> {
        case success(T)
        case error
    }
    
    func fetchColors(beaconIdentifiers: [String], completion: @escaping ((RequestResult<[String: UIColor]>) -> ())) {
        
        let request = ESTRequestGetBeaconsDetails(macAddresses: beaconIdentifiers, andFields: ESTBeaconDetailsFields.fieldColor)
        
        request.sendRequest(completion: { (beaconInfos, error) in
            guard error == nil, let beaconInfos = beaconInfos as? [ESTBeaconVO] else {
                completion(.error)
                return
            }
            
            var colorByIdentifier = [String: UIColor]()
            for beaconInfo in beaconInfos {
                let color = UIColor.colorForEstimoteColor(beaconInfo.color)
                colorByIdentifier[beaconInfo.macAddress] = color
            }
            completion(.success(colorByIdentifier))
        })
    }
}
