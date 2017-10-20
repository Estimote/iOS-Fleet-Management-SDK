//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit
import SwiftState

enum ScanningState: StateType {
    case initial, stopped, scanning, connecting, error
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

    @objc var immediateBeaconDetector: ImmediateBeaconDetector!
    @objc var immediateBeacon: ESTDeviceLocationBeacon!

    @objc var connectionRetries = 0

    // MARK: User Interface

    @IBOutlet weak var statusLabel: UILabel!
    @IBOutlet weak var restartButton: UIButton!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!

    var machine: StateMachine<ScanningState, NoEvent>!

    override func viewDidLoad() {
        super.viewDidLoad()

        self.immediateBeaconDetector = ImmediateBeaconDetector(delegate: self)

        machine = StateMachine<ScanningState, NoEvent>(state: .initial) { machine in
            machine.addRoute(.any => .scanning) { context in
                self.statusLabel.text = "Scanning for beacons..."

                self.restartButton.isHidden = true
                self.activityIndicator.isHidden = false

                self.immediateBeaconDetector.start()
            }

            machine.addRoute(.scanning => .connecting) { context in
                self.statusLabel.text = "Connecting to beacon..."

                self.immediateBeaconDetector.stop()
            }

            machine.addRoute(.any => .stopped) { context in
                self.statusLabel.text = (context.userInfo as? String) ?? "Scanning stopped."

                self.restartButton.isHidden = false
                self.activityIndicator.isHidden = true

                self.immediateBeaconDetector.stop()
            }

            machine.addRoute(.any => .error) { context in
                let errorMessage = context.userInfo as! ErrorMessage

                let alert = UIAlertController(title: errorMessage.title, message: errorMessage.message, preferredStyle: .alert)
                let action = UIAlertAction(title: "OK", style: .default, handler: nil)
                alert.addAction(action)
                self.present(alert, animated: true, completion: nil)

                machine <- .stopped
            }

            machine.addErrorHandler { (event, fromState, toState, userInfo) in
                
                NSLog("StateMachine 'error', event = \(String(describing: event)), fromState = \(fromState), toState = \(toState), userInfo = \(String(describing: userInfo))")
            }
        }
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        machine <- .scanning
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)

        machine <- .stopped
    }

    @IBAction func restartScanning(_ sender: AnyObject) {
        machine <- .scanning
    }

    // MARK: Navigation

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let navigationVC = segue.destination as! UINavigationController
        let beaconSetupVC = navigationVC.topViewController as! BeaconSetupViewController
        beaconSetupVC.beacon = immediateBeacon
    }

    @IBAction func backToScanning(_ segue: UIStoryboardSegue) {
    }

    // MARK: Immediate Beacon Detector

    @objc func immediateBeaconDetector(_ immediateBeaconDetector: ImmediateBeaconDetector, didDiscoverBeacon beacon: ESTDeviceLocationBeacon) {
        machine <- .connecting

        immediateBeacon = beacon
        immediateBeacon.delegate = self
        immediateBeacon.connect()
    }

    func immediateBeaconDetector(_ immediateBeaconDetector: ImmediateBeaconDetector, didFailDiscovery error: ImmediateBeaconDetectorError) {
        switch error {
        case .bluetoothDisabled:
            machine <- (.stopped, "Turn Bluetooth on.")
        default:
            machine <- (.error, ErrorMessage(title: "There was a problem scanning for beacons", message: "Try starting scanning again. If the problem persists, try turning Bluetooth off, then on again."))
        }
    }

    // MARK: Beacon connection

    @objc func retryConnection() -> Bool {
        if connectionRetries < 3 {
            connectionRetries += 1
            immediateBeacon.connect()
            return true
        } else {
            connectionRetries = 0
            return false
        }
    }

    func estDeviceConnectionDidSucceed(_ device: ESTDeviceConnectable) {
        connectionRetries = 0

        immediateBeacon.delegate = nil

        performSegue(withIdentifier: "ShowBeaconSetup", sender: self)
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didFailConnectionWithError error: Error) {
        if (error as NSError).code == ESTDeviceLocationBeaconError.cloudVerificationFailed.rawValue {
            if estimoteCloudReachable() {
                machine <- (.error, ErrorMessage(title: "Couldn't connect to beacon", message: "Beacon ownership verification failed. Try again, and if the problem persists, set this beacon aside and try another one."))
            } else {
                machine <- (.error, ErrorMessage(title: "Couldn't connect to beacon", message: "Couldn't reach Estimote Cloud. Check your Internet connection, then try again."))
            }
        } else {
            if !retryConnection() {
                machine <- (.error, ErrorMessage(title: "Couldn't connect to beacon", message: "Try again. If the problem persists, try restarting Bluetooth. If that doesn't help either, set this beacon aside and try another one. [Code \((error as NSError).code)]"))
            }
        }
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didDisconnectWithError error: Error?) {
        if !retryConnection() {
            machine <- (.error, ErrorMessage(title: "Beacon disconnected while connecting", message: "Try again. If the problem persists, try restarting Bluetooth. If that doesn't help either, set this beacon aside and try another one."))
        }
    }
}
