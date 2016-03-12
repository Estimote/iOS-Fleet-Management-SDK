//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit
import SwiftState

enum ScanningState: StateType {
    case Initial, Stopped, Scanning, Connecting, Error
}

struct ErrorMessage {
    let title: String
    let message: String
}

/**
 This is the initial view controller that scans for beacons, and kicks off the configuration process if it detects that a beacon has been held in the immediate vicinity to the phone.

 **WHAT TO CUSTOMIZE HERE?** Nothing, unless of course you have some specific behavior in mind.
 */
class RootViewController: UIViewController, ImmediateBeaconDetectorDelegate, ESTDeviceConnectableDelegate {

    var immediateBeaconDetector: ImmediateBeaconDetector!
    var immediateBeacon: ESTDeviceLocationBeacon!

    var connectionRetries = 0

    // MARK: User Interface

    @IBOutlet weak var statusLabel: UILabel!
    @IBOutlet weak var restartButton: UIButton!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!

    var machine: StateMachine<ScanningState, NoEvent>!

    override func viewDidLoad() {
        super.viewDidLoad()

        self.immediateBeaconDetector = ImmediateBeaconDetector(delegate: self)

        machine = StateMachine<ScanningState, NoEvent>(state: .Initial) { machine in
            machine.addRoute(.Any => .Scanning) { context in
                self.statusLabel.text = "Scanning for beacons..."

                self.restartButton.hidden = true
                self.activityIndicator.hidden = false

                self.immediateBeaconDetector.start()
            }

            machine.addRoute(.Scanning => .Connecting) { context in
                self.statusLabel.text = "Connecting to beacon..."

                self.immediateBeaconDetector.stop()
            }

            machine.addRoute(.Any => .Stopped) { context in
                self.statusLabel.text = (context.userInfo as? String) ?? "Scanning stopped."

                self.restartButton.hidden = false
                self.activityIndicator.hidden = true

                self.immediateBeaconDetector.stop()
            }

            machine.addRoute(.Any => .Error) { context in
                let errorMessage = context.userInfo as! ErrorMessage

                let alert = UIAlertController(title: errorMessage.title, message: errorMessage.message, preferredStyle: .Alert)
                let action = UIAlertAction(title: "OK", style: .Default, handler: nil)
                alert.addAction(action)
                self.presentViewController(alert, animated: true, completion: nil)

                machine <- .Stopped
            }

            machine.addErrorHandler { event, fromState, toState, userInfo in
                NSLog("StateMachine 'error', event = \(event), fromState = \(fromState), toState = \(toState), userInfo = \(userInfo)")
            }
        }
    }

    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)

        machine <- .Scanning
    }

    override func viewDidDisappear(animated: Bool) {
        super.viewDidDisappear(animated)

        machine <- .Stopped
    }

    @IBAction func restartScanning(sender: AnyObject) {
        machine <- .Scanning
    }

    // MARK: Navigation

    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        let navigationVC = segue.destinationViewController as! UINavigationController
        let beaconSetupVC = navigationVC.topViewController as! BeaconSetupViewController
        beaconSetupVC.beacon = immediateBeacon
    }

    @IBAction func backToScanning(segue: UIStoryboardSegue) {
    }

    // MARK: Immediate Beacon Detector

    func immediateBeaconDetector(immediateBeaconDetector: ImmediateBeaconDetector, didDiscoverBeacon beacon: ESTDeviceLocationBeacon) {
        machine <- .Connecting

        immediateBeacon = beacon
        immediateBeacon.delegate = self
        immediateBeacon.connect()
    }

    func immediateBeaconDetector(immediateBeaconDetector: ImmediateBeaconDetector, didFailDiscovery error: ImmediateBeaconDetectorError) {
        switch error {
        case .BluetoothDisabled:
            machine <- (.Stopped, "Turn Bluetooth on.")
        default:
            machine <- (.Error, ErrorMessage(title: "There was a problem scanning for beacons", message: "Try starting scanning again. If the problem persists, try turning Bluetooth off, then on again."))
        }
    }

    // MARK: Beacon connection

    func retryConnection() -> Bool {
        if connectionRetries < 3 {
            connectionRetries += 1
            immediateBeacon.connect()
            return true
        } else {
            connectionRetries = 0
            return false
        }
    }

    func estDeviceConnectionDidSucceed(device: ESTDeviceConnectable) {
        connectionRetries = 0

        immediateBeacon.delegate = nil

        performSegueWithIdentifier("ShowBeaconSetup", sender: self)
    }

    func estDevice(device: ESTDeviceConnectable, didFailConnectionWithError error: NSError) {
        if error.code == ESTDeviceLocationBeaconError.CloudVerificationFailed.rawValue {
            if estimoteCloudReachable() {
                machine <- (.Error, ErrorMessage(title: "Couldn't connect to beacon", message: "Beacon ownership verification failed. Try again, and if the problem persists, set this beacon aside and try another one."))
            } else {
                machine <- (.Error, ErrorMessage(title: "Couldn't connect to beacon", message: "Couldn't reach Estimote Cloud. Check your Internet connection, then try again."))
            }
        } else {
            if !retryConnection() {
                machine <- (.Error, ErrorMessage(title: "Couldn't connect to beacon", message: "Try again. If the problem persists, try restarting Bluetooth. If that doesn't help either, set this beacon aside and try another one. [Code \(error.code)]"))
            }
        }
    }

    func estDevice(device: ESTDeviceConnectable, didDisconnectWithError error: NSError?) {
        if !retryConnection() {
            machine <- (.Error, ErrorMessage(title: "Beacon disconnected while connecting", message: "Try again. If the problem persists, try restarting Bluetooth. If that doesn't help either, set this beacon aside and try another one."))
        }

    }

}
