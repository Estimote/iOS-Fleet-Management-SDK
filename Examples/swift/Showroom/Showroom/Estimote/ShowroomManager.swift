//
// Please report any problems with this app template to contact@estimote.com
//

protocol ShowroomManagerDelegate: class {

    func showroomManager(_ showroomManager: ShowroomManager, didDetectPickupForProduct product: Product)

    func showroomManager(_ showroomManager: ShowroomManager, didDetectPutdownForProduct product: Product)

}

class ShowroomManager: NSObject, ESTTriggerManagerDelegate {

    weak var delegate: ShowroomManagerDelegate?

    private let products: [NearableID: Product]

    private let triggerManager = ESTTriggerManager()
    private var triggers = [ESTTrigger]()

    init(products: [NearableID: Product]) {
        self.products = products

        super.init()

        self.triggerManager.delegate = self

        for nearableID in products.keys {
            let motionRule = ESTMotionRule.motionStateEquals(true, forNearableIdentifier: nearableID.nearableIDString)
            let motionTrigger = ESTTrigger(rules: [motionRule], identifier: nearableID.nearableIDString)
            self.triggers.append(motionTrigger)
        }
    }

    func startUpdates() {
        for trigger in self.triggers {
            self.triggerManager.startMonitoring(for: trigger)
        }
    }

    func stoptUpdates() {
        for trigger in self.triggers {
            self.triggerManager.stopMonitoringForTrigger(withIdentifier: trigger.identifier)
        }
    }

    func triggerManager(_ manager: ESTTriggerManager, triggerChangedState trigger: ESTTrigger) {
        if let nearableID = NearableID(nearableIDString: trigger.identifier), let product = self.products[nearableID] {
            if trigger.state == true {
                self.delegate?.showroomManager(self, didDetectPickupForProduct: product)
            } else {
                self.delegate?.showroomManager(self, didDetectPutdownForProduct: product)
            }
        }
    }

}
