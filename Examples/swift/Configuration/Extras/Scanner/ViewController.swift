//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

/* ==> MODIFY THIS ==> */
let yourUUID = "B9407F30-F5F8-466E-AFF9-25556B57FE6D"
let aisleRegex = try! NSRegularExpression(pattern: "aisle (.+)", options: [])

struct BeaconCloudData {
    let tag: String?
    let aisle: String?
}
/* <== MODIFY THIS <== */

struct TableRowModel {
    let majorMinorID: MajorMinorID
    let rangedBeacon: CLBeacon
    let cloudData: BeaconCloudData?
}

/**
 This app is to help you test & evaluate your beacon setup—e.g., check the beacon range is okay, how is the signal bleed, see if the "enter" events trigger where you want them, etc.

 Use the Configuration app first to configure & tag your beacons. The ranging results will then include your custom tags, e.g., the aisle number & the department tag.

 The "nearest" beacon is highlighted in green, and there's an "ENTER" badge to show if an enter event has been triggered for the major value of the beacon. (This app assumes you're grouping your beacons for monitoring by their major values.)

 **WHAT TO CUSTOMIZE HERE?** Mostly, the code responsible for fetching the custom tags, which we've conveniently marked with "==> MODIFY THIS ==>". The app comes with example code for tagging beacons with aisle numbers ("aisle 13" tags) and department tags ("electronics", "toys", etc.)
 */
class ViewController: UIViewController, UITableViewDataSource, ESTBeaconManagerDelegate {

    let beaconManager = ESTBeaconManager() // change to ESTSecureBeaconManager if using Secure UUID
    let majorMonitor = MajorMonitor()

    var cloudData = [MajorMinorID: BeaconCloudData]()

    var tableRows = [TableRowModel]()
    var nearestIndex: Int?

    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var reloadTagsButton: UIBarButtonItem!

    override func viewDidLoad() {
        super.viewDidLoad()

        beaconManager.delegate = self
        beaconManager.requestAlwaysAuthorization()

        loadCloudData()
        beaconManager.startRangingBeaconsInRegion(CLBeaconRegion(proximityUUID: NSUUID(UUIDString: yourUUID)!, identifier: "all beacons"))
    }

    @IBAction func reloadTags(sender: UIBarButtonItem) {
        loadCloudData()
    }

    func loadCloudData() {
        let originalTitle = title

        title = "Loading tags…"
        reloadTagsButton.enabled = false

        cloudData.removeAll(keepCapacity: true)

        ESTRequestV2GetDevices().sendRequestWithCompletion { devices, error in
            guard let devices = devices else {
                self.title = "Failed loading tags"
                self.reloadTagsButton.enabled = true
                return
            }

            for device in devices {
                /* ==> MODIFY THIS ==> */
                let aisle = device.shadow.tags.map({ tag -> String? in
                    let entireTagRange = NSMakeRange(0, tag.utf16.count)
                    if let aisleRange = aisleRegex.firstMatchInString(tag, options: [], range: entireTagRange)?.rangeAtIndex(1) {
                        return (tag as NSString).substringWithRange(aisleRange)
                    } else {
                        return nil
                    }
                }).filter({ $0 != nil }).map({ $0! }).first

                let firstNonAisleTag = device.shadow.tags.filter({ tag in
                    let entireTagRange = NSMakeRange(0, tag.utf16.count)
                    return aisleRegex.firstMatchInString(tag, options: [], range: entireTagRange) == nil // include tags which DON'T match the aisle regex
                }).first

                let iBeacon = device.settings.iBeacon.first!
                let majorMinorID = MajorMinorID(major: iBeacon.major.unsignedShortValue, minor: iBeacon.minor.unsignedShortValue)
                self.cloudData[majorMinorID] = BeaconCloudData(tag: firstNonAisleTag, aisle: aisle)
                /* <== MODIFY THIS <== */
            }

            self.title = originalTitle
            self.reloadTagsButton.enabled = true
        }
    }

    // MARK: Table View

    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return tableRows.count
    }

    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("Beacon", forIndexPath: indexPath)

        let aisleLabel = tableView.viewWithTag(1) as! UILabel
        let tagLabel = tableView.viewWithTag(2) as! UILabel
        let majorMinorLabel = tableView.viewWithTag(3) as! UILabel
        let proximityLabel = tableView.viewWithTag(4) as! UILabel
        let rssiLabel = tableView.viewWithTag(5) as! UILabel
        let didEnterLabel = tableView.viewWithTag(6) as! UILabel

        let row = tableRows[indexPath.row]
        /* ==> MODIFY THIS ==> */
        aisleLabel.text = row.cloudData?.aisle ?? "??"
        tagLabel.text = row.cloudData?.tag ?? "(unknown)"
        /* <== MODIFY THIS <== */
        majorMinorLabel.text = "\(row.majorMinorID)"
        proximityLabel.text = "\(row.rangedBeacon.proximity.description) [\(String(format: "%.2f", row.rangedBeacon.accuracy)) acc]"
        rssiLabel.text = "\(row.rangedBeacon.rssi) dBm"

        if majorMonitor.isInsideMajor(row.majorMinorID.major) {
            didEnterLabel.hidden = false
        } else {
            didEnterLabel.hidden = true
        }

        if indexPath.row == nearestIndex {
            cell.backgroundColor = UIColor(red: 0.9, green: 1.0, blue: 0.9, alpha: 1.0)
        } else {
            cell.backgroundColor = UIColor.whiteColor()
        }

        if row.rangedBeacon.accuracy == -1 {
            majorMinorLabel.textColor = UIColor.grayColor()
            proximityLabel.textColor = UIColor.grayColor()
            rssiLabel.textColor = UIColor.grayColor()
        } else {
            majorMinorLabel.textColor = UIColor.blackColor()
            proximityLabel.textColor = UIColor.blackColor()
            rssiLabel.textColor = UIColor.blackColor()
        }

        return cell
    }

    // MARK: Ranging delegate

    func beaconManager(manager: AnyObject, didRangeBeacons beacons: [CLBeacon], inRegion region: CLBeaconRegion) {
        // ensure we're monitoring for the majors of beacons in range
        for beacon in beacons {
            majorMonitor.ensureMonitoringForMajor(beacon.major.unsignedShortValue)
        }

        // map ranging data to table rows, including corss-referencing with the cloud data
        tableRows = beacons.map({
            let majorMinorID = MajorMinorID(major: $0.major.unsignedShortValue, minor: $0.minor.unsignedShortValue)
            return TableRowModel(
                majorMinorID: majorMinorID,
                rangedBeacon: $0,
                cloudData: cloudData[majorMinorID]
            )
        }).sort({
            let aisle1 = $0.0.cloudData?.aisle
            let aisle2 = $0.1.cloudData?.aisle

            if aisle1 == aisle2 {
                return $0.0.majorMinorID.description < $0.1.majorMinorID.description
            } else {
                return aisle1 < aisle2
            }
        })

        // find the row index of the nearest beacon, so that we can highlight that table row
        var nearestIndex: Int?
        var nearestDistance = DBL_MAX
        for (index, row) in tableRows.enumerate() {
            let distance = row.rangedBeacon.accuracy
            if distance != -1 && distance < nearestDistance {
                nearestIndex = index
                nearestDistance = row.rangedBeacon.accuracy
            }
        }
        self.nearestIndex = nearestIndex

        // reload the table
        tableView.reloadData()
    }

}
