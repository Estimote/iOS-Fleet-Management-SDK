//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class ViewController: UIViewController, ShowroomManagerDelegate {

    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var descriptionLabel: UILabel!

    var showroomManager: ShowroomManager!

    override func viewDidLoad() {
        super.viewDidLoad()

        UIApplication.sharedApplication().registerUserNotificationSettings(UIUserNotificationSettings(forTypes: [.Sound, .Alert], categories: nil))

        // TODO: replace with identifiers of your own nearables
        self.showroomManager = ShowroomManager(
            products: [
                NearableID(nearableIDString: "abcdef0000000001")!
                    : Product(name: "Sweeft Headphones", summary: "These super cool headphones will make sure you'll re-discover your favorite Taylor Swift song anew. You just can't put a price tag on that!"),
                NearableID(nearableIDString: "abcdef0000000002")!
                    : Product(name: "Nyan Bicycle 3x14", summary: "Rush down the local streets with this amazing bike, leaving a trail of rainbow behind you, to the awe of everyone around."),
            ]
        )
        self.showroomManager.delegate = self
        self.showroomManager.startUpdates()
    }

    func showroomManager(showroomManager: ShowroomManager, didDetectPickupForProduct product: Product) {
        self.titleLabel.text = product.name
        self.descriptionLabel.text = product.summary
        self.descriptionLabel.hidden = false

        // Nearable detection works even if the app is not running!
        // Try it: run the app, lock your phone, and pick up a nearable. You should see a notification show up on your lock screen.
        if UIApplication.sharedApplication().applicationState != .Active {
            let notification = UILocalNotification()
            notification.soundName = UILocalNotificationDefaultSoundName
            notification.alertBody = "It looks like you're interested in \(product.name). Swipe here to learn more."
            UIApplication.sharedApplication().presentLocalNotificationNow(notification)
        }
    }

    func showroomManager(showroomManager: ShowroomManager, didDetectPutdownForProduct product: Product) {
        self.titleLabel.text = "Pick up an object to learn more about it"
        self.descriptionLabel.hidden = true
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}
