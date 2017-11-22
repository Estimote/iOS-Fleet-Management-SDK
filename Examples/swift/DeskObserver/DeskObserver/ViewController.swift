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

        // TODO: put your App ID and App Token here
        // You can get them by adding your app on https://cloud.estimote.com/#/apps
        let credentials = ESTCloudCredentials(appID: <#your-app-id#>, appToken: <#your-app-token#>)
        
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
        
        self.proximityObserver = ESTProximityObserver(credentials: credentials, errorBlock: { error in
            print("Ooops! \(error)")
        })
        
        let blueberryZone = ESTProximityZone(range: ESTProximityRange.custom(desiredMeanTriggerDistance: 0.5)!,
                                             attachmentKey: "desk",
                                             attachmentValue: "blueberry")
        blueberryZone.onEnterAction = { attachment in
            print("Enter blueberry 0.5")
            self.blueberryDeskLabel.backgroundColor = self.blueberryColor
            self.blueberryDeskLabel.textColor = UIColor.white
        }
        blueberryZone.onExitAction = { attachment in
            print("Exit blueberry 0.5")
            self.blueberryDeskLabel.backgroundColor = UIColor.white
            self.blueberryDeskLabel.textColor = self.blueberryColor
        }
        
        let mintZone = ESTProximityZone(range: ESTProximityRange.custom(desiredMeanTriggerDistance: 0.5)!,
                                        attachmentKey: "desk",
                                        attachmentValue: "mint")
        mintZone.onEnterAction = { attachment in
            print("Enter mint 0.5")
            self.mintDeskLabel.backgroundColor = self.mintColor
            self.mintDeskLabel.textColor = UIColor.white
        }
        mintZone.onExitAction = { attachment in
            print("Exit mint 0.5")
            self.mintDeskLabel.backgroundColor = UIColor.white
            self.mintDeskLabel.textColor = self.mintColor
        }
        
        let closeVenueZone = ESTProximityZone(range: ESTProximityRange.custom(desiredMeanTriggerDistance: 0.5)!,
                                              attachmentKey: "venue",
                                              attachmentValue: "office")
        closeVenueZone.onChangeAction = { attachmentsInside in
            print("Currently, there are \(attachmentsInside.count) attachments in ~0.5m range:")
            print("\(attachmentsInside.map({ $0.json.description }).joined(separator: "\n"))")
            print("")
        }
        
        let midVenueZone = ESTProximityZone(range: ESTProximityRange.custom(desiredMeanTriggerDistance: 1.5)!,
                                            attachmentKey: "venue",
                                            attachmentValue: "office")
        midVenueZone.onEnterAction = { attachment in
            print("Enter venue 1.5")
            self.venueLabel.backgroundColor = self.venueColor
            self.venueLabel.textColor = UIColor.white
        }
        midVenueZone.onExitAction = { attachment in
            print("Exit venue 1.5")
            self.venueLabel.backgroundColor = UIColor.white
            self.venueLabel.textColor = self.venueColor
        }
        midVenueZone.onChangeAction = { attachmentsInside in
            print("Currently, there are \(attachmentsInside.count) attachments in ~1.5m range:")
            print("\(attachmentsInside.map({ $0.json.description }).joined(separator: "\n"))")
            print("")
        }
        
        self.proximityObserver.startObserving([mintZone, blueberryZone, closeVenueZone, midVenueZone])
    }
}

