//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

/**
 This view controller allows the user to tweak the configuration of the beacon, before the deployment app continues to applying the configuration.

 Applying the configuration usually means two things:

   1. Upload the beacon configuration to Estimote Cloud and/or your own backend. Since beacons only broadcast their identifiers, you usually need to keep extra metadata about them in a remote database. For example, the `BeaconSetupViewController` might allow the user to input the message associated with the beacon. Or just tag the beacon's location (entrance, lobby area, etc.)

   2. Writing settings to the beacon hardware. You usually want all your beacons to be set to your custom UUID, tweak power and their advertising interval, etc. Some settings could be derived from the configuration choices made on this screen--e.g., entrance beacons could be set to higher transmit power, etc.

 The model behind this view controller is `BeaconConfig`, and you will usually want to keep the two in sync. See also: `prepareForSegue` below.

 **WHAT TO CUSTOMIZE HERE?** Pretty much everything. This is where you will usually want to start. Remember to tweak the `BeaconConfig` struct as well.
 */
class BeaconSetupViewController: UIViewController, GeoLocatorDelegate {

    @objc var beacon: ESTDeviceLocationBeacon!

    @objc var selectedTag: String? {
        didSet {
            validate()
        }
    }

    @objc var geoLocator: GeoLocator!
    @objc var geoLocation: CLLocation?
    @objc var appBecomeActiveObserver: AnyObject!

    // MARK: User Interface

    @IBOutlet weak var saveButton: UIBarButtonItem!

    @IBOutlet weak var beaconIDLabel: UILabel!
    @IBOutlet weak var tagsLabel: UILabel!

    @IBOutlet weak var pickTagButton: UIButton!
    @IBOutlet weak var aisleNumberTextField: UITextField!
    @IBOutlet weak var placementSegmentedControl: UISegmentedControl!

    @IBOutlet weak var geoLocationLabel: UILabel!
    @IBOutlet weak var geoLocationSpinner: UIActivityIndicatorView!

    @IBAction func handleTapGesture(_ sender: UITapGestureRecognizer) {
        view.endEditing(true)
    }

    @IBAction func handleAisleNumberChanged(_ sender: UITextField) {
        validate()
    }

    @IBAction func handlePlacementChanged(_ sender: UISegmentedControl) {
        validate()
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        geoLocator = GeoLocator(delegate: self)
        geoLocator.requestLocation()

        appBecomeActiveObserver = NotificationCenter.default.addObserver(forName: NSNotification.Name.UIApplicationDidBecomeActive, object: nil, queue: nil) { notification in
            // when we're coming back from the Settings app (because we asked the user to allow Location Services access), let's retry obtaining geolocation
            if self.geoLocation == nil && !self.geoLocator.requestInProgress {
                self.geoLocator.requestLocation()
            }
        }
    }

    deinit {
        NotificationCenter.default.removeObserver(appBecomeActiveObserver)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        beaconIDLabel.text = beacon.identifier
        tagsLabel.text = selectedTag ?? "(no tag)"
    }

    // MARK: Config validation & creation

    @objc func validate() {
        saveButton.isEnabled = selectedTag != nil && geoLocation != nil && placementSegmentedControl.selectedSegmentIndex != UISegmentedControlNoSegment
    }

    func createConfig() -> BeaconConfig {
        return BeaconConfig(
            tag: selectedTag!,
            aisleNumber: aisleNumberTextField.text!.isEmpty ? nil : Int(aisleNumberTextField.text!),
            placement: Placement(rawValue: placementSegmentedControl.selectedSegmentIndex)!,
            geoLocation: geoLocation!.coordinate
        )
    }

    // MARK: Navigation

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "PerformSetup" {
            let setupVC = segue.destination as! PerformSetupViewController
            setupVC.beacon = beacon
            setupVC.beaconConfig = createConfig()
        } else if segue.identifier == "ShowTagsPicker" {
            let tagsVC = (segue.destination as! UINavigationController).topViewController as! TagsViewController
            tagsVC.selectedTag = selectedTag
        } else if segue.identifier == "CancelSetup" {
            beacon.disconnect()
        }
    }

    @IBAction func backToBeaconSetup(_ segue: UIStoryboardSegue) {
        if segue.identifier == "SaveTags" {
            let tagsVC = segue.source as! TagsViewController
            selectedTag = tagsVC.selectedTag
        }
    }

    // MARK: GeoLocator delegate

    @objc func geoLocator(_ geoLocator: GeoLocator, didDetermineLocation location: CLLocation) {
        geoLocation = location

        geoLocationLabel.text = String(format: "%.2f, %.2f, ± %.0f m", geoLocation!.coordinate.latitude, geoLocation!.coordinate.longitude, geoLocation!.horizontalAccuracy)
        geoLocationSpinner.stopAnimating()
        validate()
    }

    func geoLocator(_ geoLocator: GeoLocator, didFailWithError error: GeoLocatorError) {
        switch error {
        case .noLocationFound:
            let alert = UIAlertController(title: "Couldn't obtain geolocation", message: "Try moving to a slightly different spot, for better GPS or WiFi coverage.", preferredStyle: .alert)
            let action = UIAlertAction(title: "Retry", style: .default) { action in
                geoLocator.requestLocation()
            }
            alert.addAction(action)
            self.present(alert, animated: true, completion: nil)

        case .insufficientPermissions:
            let alert = UIAlertController(title: "Couldn't obtain geolocation", message: "This app is not authorized to access Location Services. Go to Settings and set Location access to While Using the App.", preferredStyle: .alert)
            let action = UIAlertAction(title: "Go to Settings", style: .default) { action in
                UIApplication.shared.openURL(URL(string: UIApplicationOpenSettingsURLString)!)
            }
            alert.addAction(action)
            self.present(alert, animated: true, completion: nil)
        }
    }

}
