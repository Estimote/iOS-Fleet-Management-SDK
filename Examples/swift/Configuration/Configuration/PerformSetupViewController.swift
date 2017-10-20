//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit
import MessageUI

/**
 This view controller takes the `BeaconConfig` prepared by the `BeaconSetupViewController` and performs the setup by going through these steps:

   1. [optional] Update beacon's firmware, if there's an update available. Controlled by shouldUpdateFirmware constant.
   2. Use `beaconSettingsForConfig:` and the `BeaconConfig` object passed by the `BeaconSetupViewController` to determine what settings to write to the beacon and Estimote Cloud, and do write them.
   3. [optional integration point] Save custom beacon data in your own backend. (See: `saveToCustomBackend` method below.)

 In case of an error, this view controller gives the user an option to retry, go back to the scanning screen to try with another beacon, and email the error log to the deployment support crew.

 **WHAT TO CUSTOMIZE HERE?** You will rarely need to customize anything but the 3rd point in the setup flow outlined above. For steps 1 and 2, you'll rather want to customize the `beaconSettingsForConfig:` method.
 */
class PerformSetupViewController: UIViewController, MFMailComposeViewControllerDelegate {

    // If true the app will check for firmware updates and then update beacon's firmware, if there's an update available
    @objc let shouldUpdateFirmware = false
    
    @objc var beacon: ESTDeviceLocationBeacon!
    var beaconConfig: BeaconConfig!

    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!

    @IBOutlet weak var mainStatusLabel: UILabel!
    @IBOutlet weak var detailStatusLabel: UILabel!
    @IBOutlet weak var statusIconLabel: UILabel!

    @IBOutlet weak var errorActionsView: UIView!
    @IBOutlet weak var emailErrorLogButton: UIButton!
    @IBOutlet weak var retryButton: UIButton!

    @IBOutlet weak var actionsView: UIView!
    @IBOutlet weak var nextBeaconButton: UIButton!

    @objc var lastErrorLog: String!

    @objc var initialAppeareance = true

    override func viewDidLoad() {
        super.viewDidLoad()

        let blurView = UIVisualEffectView(effect: UIBlurEffect(style: .dark))
        blurView.frame = view.bounds
        view.insertSubview(blurView, at: 0)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        // quick hack to make it so that when after a failed setup the MailComposeVC is invoked, and then dismissed, and this VC appears again, it won't automatically re-trigger the setup process
        if initialAppeareance {
            initialAppeareance = false
            startSetup()
        }
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "NextBeacon" {
            beacon.disconnect()
        }
    }

    // MARK: Setup flow

    fileprivate func startSetup() {
        activityIndicator.startAnimating()

        mainStatusLabel.text = "Starting setup"
        detailStatusLabel.text = "..."
        statusIconLabel.isHidden = true

        errorActionsView.isHidden = true
        actionsView.isHidden = true
        
        if self.shouldUpdateFirmware{
            updateFirmware()
        }
        else{
            self.writeSettings()
        }
    }

    fileprivate func updateFirmware() {
        self.mainStatusLabel.text = "Checking for firmware update"
        self.detailStatusLabel.text = "..."

        updateFirmwareIfUpdateAvailable(beacon,
            progress: { progressPercentage in
                self.mainStatusLabel.text = "Updating firmware"
                self.detailStatusLabel.text = "\(progressPercentage)% done"
            },
            completion: { maybeError in
                if let error = maybeError {
                    self.onSetupError("Firmware update failed", errorLog: error.description)
                } else {
                    self.writeSettings()
                }
            }
        )
    }

    fileprivate func writeSettings() {
        self.mainStatusLabel.text = "Writing settings"
        self.detailStatusLabel.text = "..."

        let beaconSettings = beaconSettingsForConfig(beaconConfig)

        // if changing the power level of the connectivity packet, invalidate the entry in the global cache
        if let newPowerLevel = beaconSettings.filter({ $0 is ESTSettingConnectivityPower }).first as? ESTSettingConnectivityPower, newPowerLevel.getValue() != beacon.settings!.connectivity.power.getValue() {
            cachedTxPowers.removeValue(forKey: beacon.identifier)
        }

        writeSettingsToBeacon(beacon,
            settings: beaconSettings,
            progress: { finishedOperationsCount in
                self.mainStatusLabel.text = "Writing settings"
                self.detailStatusLabel.text = "\(finishedOperationsCount) of \(beaconSettings.count) done"
            }, completion: { failedOperations in
                if failedOperations.count > 0 {
                    self.onSetupError("Writing settings failed",
                        errorLog: failedOperations.map { "===> \($0.operationIdentifier)\n\($0.error)" }.joined(separator: "\n\n"))
                } else {
                    self.onSetupSuccess()
                }
            }
        )
    }

    fileprivate func saveToCustomBackend() {
//        self.mainStatusLabel.text = "Saving data in ACME backend"
//        self.detailStatusLabel.text = "..."

        self.onSetupSuccess()
    }

    // MARK: Setup completion

    fileprivate func onSetupError(_ shortDescription: String, errorLog: String) {
        activityIndicator.stopAnimating()

        mainStatusLabel.text = shortDescription
        detailStatusLabel.text = "Try again, or try another beacon"

        statusIconLabel.isHidden = false
        statusIconLabel.text = "✗"

        errorActionsView.isHidden = false
        actionsView.isHidden = false

        lastErrorLog = errorLog
    }

    fileprivate func onSetupSuccess() {
        activityIndicator.stopAnimating()

        mainStatusLabel.text = "Done!"
        detailStatusLabel.text = "You can install the beacon now"

        statusIconLabel.isHidden = false
        statusIconLabel.text = "✔"

        actionsView.isHidden = false

        beacon.disconnect()
    }

    // MARK: UI handling

    @IBAction func emailErrorLogTapped(_ sender: AnyObject) {
        let recipientEmail = "piotr@estimote.com"

        if MFMailComposeViewController.canSendMail() {
            let mailComposeVC = MFMailComposeViewController()
            mailComposeVC.mailComposeDelegate = self
            mailComposeVC.setSubject("Setup problem for beacon \(beacon.identifier)")
            mailComposeVC.setToRecipients([recipientEmail])
            mailComposeVC.setMessageBody(lastErrorLog, isHTML: false)
            present(mailComposeVC, animated: true, completion: nil)
        } else {
            UIPasteboard.general.string = lastErrorLog
            let alert = UIAlertController(title: "Can't email the error log", message: "This device is not configured for sending email. The error log was copied to the clipboard instead—please send it to \(recipientEmail) yourself.", preferredStyle: .alert)
            let action = UIAlertAction(title: "OK", style: .default, handler: nil)
            alert.addAction(action)
            present(alert, animated: true, completion: nil)
        }
    }

    @IBAction func retryTapped(_ sender: AnyObject) {
        startSetup()
    }

    func mailComposeController(_ controller: MFMailComposeViewController, didFinishWith result: MFMailComposeResult, error: Error?) {
        dismiss(animated: true, completion: nil)
    }

}
