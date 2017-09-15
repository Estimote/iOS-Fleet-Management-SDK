//
// Please report any problems with this app template to contact@estimote.com
//


import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var blueberryDeskLabel: UILabel!
    @IBOutlet weak var mintDeskLabel: UILabel!
    @IBOutlet weak var venueLabel: UILabel!
    
    let blueberryColor = UIColor(red:  36/255.0, green:  24/255.0, blue:  93/255.0, alpha: 1.0)
    let mintColor = UIColor(red: 155/255.0, green: 186/255.0, blue: 160/255.0, alpha: 1.0)
    let venueColor = UIColor.darkGray
    
    var proximityObserver: ESTProximityObserver!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // ---- UI config ----
        
        // There are three labels with different text & border colors. 
        // They reverse text color and background color depending on proximity changes.
        
        let labels = [self.blueberryDeskLabel!, self.mintDeskLabel!, self.venueLabel!]
        for label in labels {
            label.backgroundColor = UIColor.white
            label.layer.borderWidth = 3.0
        }
        
        self.blueberryDeskLabel.layer.borderColor = self.blueberryColor.cgColor
        self.blueberryDeskLabel.textColor = self.blueberryColor
        
        self.mintDeskLabel.layer.borderColor = mintColor.cgColor
        self.mintDeskLabel.textColor = self.mintColor
        
        self.venueLabel.layer.borderColor = venueColor.cgColor
        self.venueLabel.textColor = self.venueColor
        
        // ---- Proximity config ----
        
        // There's just a one Proximity Observer object used to configure reactions to proximity changes.
        // The configuration of a zone consists of defining a desired approximate range (0.5m or 1.5m in this example), 
        // attachment key ("blueberry_desk", "mint_desk" or "venue" in this example) and a handler block called when 
        // a zone "enter" / "exit" / "change of beacons in range" happens.
        //
        // For more info on attachment-based beacon identification, check out the README in this repository
        // ( https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md ).
        
        // TODO: The demo assumes proper settings configuration in Estimote Cloud. Make sure that:
        // - you have at least 2 beacons assigned to your Estimote Cloud account
        // - one of the beacons has a tag `{"attachment":{"blueberry_desk":true,"venue":"office"}}`
        // - another beacon has a tag `{"attachment":{"mint_desk":true,"venue":"office"}}`
        
        self.proximityObserver = ESTProximityObserver(credentials: ESTCloudCredentials.shared!, errorHandler: { (error) in
            print("Ooops! \(error.localizedDescription)")
        }, didStartHandler: { 
            print("Proximity observer did start")
        })
        
        // Enters handling
        
        self.proximityObserver.onEnter(range: ESTProximityRange.custom(meanTriggerDistance: 0.5)!, ofBeaconsWithAttachmentKey: "blueberry_desk") { _attachment in
            self.blueberryDeskLabel.backgroundColor = self.blueberryColor
            self.blueberryDeskLabel.textColor = UIColor.white
        }
        
        self.proximityObserver.onEnter(range: ESTProximityRange.custom(meanTriggerDistance: 0.5)!, ofBeaconsWithAttachmentKey: "mint_desk") { _attachment in
            self.mintDeskLabel.backgroundColor = self.mintColor
            self.mintDeskLabel.textColor = UIColor.white
        }
        
        self.proximityObserver.onEnter(range: ESTProximityRange.custom(meanTriggerDistance: 1.5)!, ofBeaconsWithAttachmentKey: "venue") { attachment in
            self.venueLabel.backgroundColor = self.venueColor
            self.venueLabel.textColor = UIColor.white
        }
        
        // Exits handling
        
        self.proximityObserver.onExit(range: ESTProximityRange.custom(meanTriggerDistance: 0.5)!, ofBeaconsWithAttachmentKey: "blueberry_desk") { _attachment in
            self.blueberryDeskLabel.backgroundColor = UIColor.white
            self.blueberryDeskLabel.textColor = self.blueberryColor
        }
        
        self.proximityObserver.onExit(range: ESTProximityRange.custom(meanTriggerDistance: 0.5)!, ofBeaconsWithAttachmentKey: "mint_desk") { _attachment in
            self.mintDeskLabel.backgroundColor = UIColor.white
            self.mintDeskLabel.textColor = self.mintColor
        }
        
        self.proximityObserver.onExit(range: ESTProximityRange.custom(meanTriggerDistance: 1.5)!, ofBeaconsWithAttachmentKey: "venue") { _attachment in
            self.venueLabel.backgroundColor = UIColor.white
            self.venueLabel.textColor = self.venueColor
        }
        
        // Beacons in range change handling - for debug purposes
        
        self.proximityObserver.onBeaconsInRangeChange(range: ESTProximityRange.custom(meanTriggerDistance: 0.5)!, attachmentKey: "venue") { (attachments) in
            print("Currently, there are \(attachments.count) attachments in ~0.5m range:")
            print("\(attachments.map({ $0.attachmentJSON.description }).joined(separator: "\n"))")
            print("")
        }
        
        self.proximityObserver.onBeaconsInRangeChange(range: ESTProximityRange.custom(meanTriggerDistance: 1.5)!, attachmentKey: "venue") { (attachments) in
            print("Currently, there are \(attachments.count) attachments in ~1.5m range:")
            print("\(attachments.map({ $0.attachmentJSON.description }).joined(separator: "\n"))")
            print("")
        }
        
        self.proximityObserver.start()
    }
}

