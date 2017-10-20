//
// Please report any problems with this app template to contact@estimote.com
//

import Foundation
import UIKit

// Adds UI-related methods to ViewController class.
extension ViewController {
    func updateBeaconZoneViews(beaconIdentifiersInRange identifiersInRange: Set<String>) {
        UIView.animate(withDuration: 0.2) {
            
            let thereIsBeaconInRange: Bool = !identifiersInRange.isEmpty
            self.hideViewIfNeeded(view: self.noBeaconsView, shouldBeHidden: thereIsBeaconInRange)
            
            self.beaconIdentifiers.forEach({ (identifier) in
                guard let zoneView = self.zoneViewByBeaconIdentifier[identifier] else { return }
                
                let identifierIsNotInRange: Bool = !identifiersInRange.contains(identifier)
                self.hideViewIfNeeded(view: zoneView, shouldBeHidden: identifierIsNotInRange)
            })
        }
    }
    
    func hideViewIfNeeded(view: UIView, shouldBeHidden hidden: Bool) {
        if view.isHidden != hidden {
            view.isHidden = hidden
        }
    }
    
    func addBeaconZoneViews(colorByBeaconIdentifier: [String: UIColor]) {
        for identifier in colorByBeaconIdentifier.keys {
            
            let zoneView = UIView()
            zoneView.translatesAutoresizingMaskIntoConstraints = false
            zoneView.backgroundColor = colorByBeaconIdentifier[identifier]
            
            let beaconImageView = UIImageView(image: UIImage(named: "Beacon"))
            beaconImageView.contentMode = .scaleAspectFit
            beaconImageView.translatesAutoresizingMaskIntoConstraints = false
            zoneView.addSubview(beaconImageView)
            
            let identifierLabel = UILabel()
            identifierLabel.translatesAutoresizingMaskIntoConstraints = false
            identifierLabel.textAlignment = .center
            identifierLabel.font = UIFont.boldSystemFont(ofSize: 18.0)
            identifierLabel.numberOfLines = 0
            identifierLabel.textColor = UIColor.white
            identifierLabel.text = identifier
            zoneView.addSubview(identifierLabel)
            
            // Setup constraints
            let verticalAlignmentConstraint = NSLayoutConstraint.constraints(
                withVisualFormat: "V:|-24-[beacon]-8@999-[identifier]-|",
                options: [.alignAllCenterX],
                metrics: nil,
                views: ["beacon": beaconImageView, "identifier": identifierLabel])
            NSLayoutConstraint.activate(verticalAlignmentConstraint)
            beaconImageView.centerXAnchor.constraint(equalTo: zoneView.centerXAnchor).isActive = true
            identifierLabel.setContentHuggingPriority(UILayoutPriority.required, for: .vertical)
            identifierLabel.setContentCompressionResistancePriority(UILayoutPriority.required, for: .vertical)
            
            self.zoneViewByBeaconIdentifier[identifier] = zoneView
            self.stackView.addArrangedSubview(zoneView)
            zoneView.isHidden = true
        }
    }
    
    func presentFetchingColorsFailedAlert() {
        let alert = UIAlertController(title: "Fetching colors failed", message: "Check your internet connection, App ID and App Token.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }
    
    func presentMonitoringFailedAlert() {
        let alert = UIAlertController(title: "Monitoring failed", message: "Make sure bluetooth is on and the app has permission to use it.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }
}

