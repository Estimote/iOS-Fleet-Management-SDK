//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class ViewController: UIViewController, ProximityContentManagerDelegate {

    @IBOutlet weak var label: UILabel!
    @IBOutlet weak var image: UIImageView!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!

    var proximityContentManager: ProximityContentManager!

    override func viewDidLoad() {
        super.viewDidLoad()

        self.activityIndicator.startAnimating()

        self.proximityContentManager = ProximityContentManager(
            beaconIDs: [
                // TODO: replace with UUIDs, majors and minors of your own beacons
                BeaconID(UUIDString: "B9407F30-F5F8-466E-AFF9-25556B57FE6D", major: 1, minor: 1),
                BeaconID(UUIDString: "B9407F30-F5F8-466E-AFF9-25556B57FE6D", major: 2, minor: 2),
                BeaconID(UUIDString: "B9407F30-F5F8-466E-AFF9-25556B57FE6D", major: 3, minor: 3)
            ],
            beaconContentFactory: CachingContentFactory(beaconContentFactory: BeaconDetailsCloudFactory()))
        self.proximityContentManager.delegate = self
        self.proximityContentManager.startContentUpdates()
    }

    func proximityContentManager(proximityContentManager: ProximityContentManager, didUpdateContent content: AnyObject?) {
        self.activityIndicator?.stopAnimating()
        self.activityIndicator?.removeFromSuperview()

        if let beaconDetails = content as? BeaconDetails {
            self.view.backgroundColor = beaconDetails.backgroundColor
            self.label.text = "You're in \(beaconDetails.beaconName)'s range!"
            self.image.hidden = false
        } else {
            self.view.backgroundColor = BeaconDetails.neutralColor
            self.label.text = "No beacons in range."
            self.image.hidden = true
        }
    }

    override func preferredStatusBarStyle() -> UIStatusBarStyle {
        return .LightContent
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}
