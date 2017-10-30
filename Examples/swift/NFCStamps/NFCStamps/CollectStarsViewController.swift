//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit
import CoreNFC


class CollectStarsViewController: UIViewController {
    
    // MARK: IBOutlets
    
    @IBOutlet weak var collectStarsButton: UIButton!
    @IBOutlet weak var starStackView: UIStackView!

    // MARK: Predefined parameters
    
    struct PredefinedParameters {
        static let starsToCollect: Int = 5
        static let estimoteNFCrecordType: String = "estimote.com:id"
    }
    
    // MARK: Properties
    
    var nfcReaderSession: NFCNDEFReaderSession?
    var starsCounter: Int = 0
    
    // MARK: ViewController's lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.setupUI()
    }
    
    // MARK: Core logic
    
    func performActionOnStarCounterValue() {
        switch self.starsCounter {
        case 0...(PredefinedParameters.starsToCollect - 1):
            for _ in self.starStackView.arrangedSubviews {
                self.starStackView.arrangedSubviews[starsCounter - 1].alpha = 1
            }
            
        default:
            for star in self.starStackView.arrangedSubviews {
                star.alpha = 0.2
            }
            self.starsCounter = 0
            self.performSegue(withIdentifier: "ExtraCoffee", sender: self)
        }
    }
    
    // MARK: UI setup
    
    func setupUI() {
        self.collectStarsButton.layer.borderColor = UIColor(displayP3Red: 222/255, green: 222/255, blue: 222/255, alpha: 1).cgColor
    }
    
    // MARK: IBActions
    
    @IBAction func collectStarsTapped(_ sender: Any) {
        self.nfcReaderSession = NFCNDEFReaderSession(delegate: self, queue: nil, invalidateAfterFirstRead: true)
        self.nfcReaderSession?.alertMessage = "Tap your phone to the beacon to collect stars."
        // Step 1 - Begin NFC reader session
        self.nfcReaderSession?.begin()
    }
}

// MARK: NFCNDEFReaderSession delegate methods

extension CollectStarsViewController: NFCNDEFReaderSessionDelegate {
    
    // MARK: NFCNDEFReaderSessionDelegate methods
    
    func readerSession(_ session: NFCNDEFReaderSession, didDetectNDEFs messages: [NFCNDEFMessage]) {
        
        // Step 2 - Read information that beacon carries
        for message in messages {
            for record in message.records {
                let recordType = String(data: record.type, encoding: .utf8)
                
                if (PredefinedParameters.estimoteNFCrecordType == recordType) {
                    self.nfcReaderSession?.alertMessage = "To confirm approach your phone to the beacon and collect points."
                    self.starsCounter += 1
                    
                    // Step 3 - Take action based on beacon info
                    DispatchQueue.main.async {
                        self.performActionOnStarCounterValue()
                    }
                }
            }
        }
    }
    
    func readerSession(_ session: NFCNDEFReaderSession, didInvalidateWithError error: Error) {
        print("Reader session invalidated with error: \(error.localizedDescription)")
    }
}
