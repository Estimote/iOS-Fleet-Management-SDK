//
// Please report any problems with this app to contact@estimote.com
//

import UIKit

/**
This class controls the flow when developer uses one of GPIO ports as input.
*/

class ViewControllerInput: UIViewController, ESTDeviceManagerDelegate, ESTDeviceConnectableDelegate {
    
    @IBOutlet weak var infoLabel: UILabel!
    @IBOutlet weak var lightbulbOnImage: UIImageView!
    @IBOutlet weak var lightbulbOffImage: UIImageView!
    
    var checkPortZeroStateTimer: Timer?
    var portZeroStateCheckInterval: TimeInterval = 0.02
    // TODO: put input beacon's identifier here
    let deviceUsedForInputIdentifier: String = <#Identifier of your input beacon#>
    var deviceUsedForInput: ESTDeviceLocationBeacon?
    lazy var deviceManagerForInput: ESTDeviceManager = {
        let manager = ESTDeviceManager()
        manager.delegate = self
        return manager
    }()

    enum LightBulbState {
        case on, off
    }
    
    var currentLightbulbState = LightBulbState.off {
        didSet {
            if currentLightbulbState == .off {
                self.lightbulbOnImage.alpha = 0
            } else if currentLightbulbState == .on {
                self.lightbulbOnImage.alpha = 1
            }
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let deviceFilter = ESTDeviceFilterLocationBeacon(identifier: self.deviceUsedForInputIdentifier)
        self.deviceManagerForInput.startDeviceDiscovery(with: deviceFilter)
        self.currentLightbulbState = .off
    }
    
    func deviceManager(_ manager: ESTDeviceManager, didDiscover devices: [ESTDevice]) {
        guard let device = devices.first as? ESTDeviceLocationBeacon else { return }
        self.deviceManagerForInput.stopDeviceDiscovery()
        self.deviceUsedForInput = device
        self.deviceUsedForInput?.delegate = self
        self.deviceUsedForInput?.connect()
    }
    
    func turnLightbulbOnOff () {
        self.deviceUsedForInput?.settings?.gpio.portsData.readValue(completion: { (gpioData, error) in
        if self.deviceUsedForInput?.settings?.gpio.portsData.getValue().getValueFor(ESTGPIOPort.port0) == .low {
            self.currentLightbulbState = .off
        } else {
            self.currentLightbulbState = .on
            }
        })
    }
    
    func estDeviceConnectionDidSucceed(_ device: ESTDeviceConnectable) {
        print("Connection Input Status: Connected")
        self.infoLabel.text = "Manipulate the light with your breadboard button"
        self.checkPortZeroStateTimer = Timer.scheduledTimer(timeInterval: TimeInterval(self.portZeroStateCheckInterval), target: self, selector: #selector(self.turnLightbulbOnOff), userInfo: nil, repeats: true)
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didFailConnectionWithError error: Error) {
        print("Connection Input Status: \(error.localizedDescription)")
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didDisconnectWithError error: Error?) {
        print("Connection Input Status: Disconected")
    }

}
