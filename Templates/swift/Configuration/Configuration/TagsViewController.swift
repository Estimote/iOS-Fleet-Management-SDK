//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

/**
 Utility view controller to allow the user to pick tags to associate with the beacon currently being configured.

 **WHAT TO CUSTOMIZE HERE?** The tags are taken from the `tagsAndMajorsMapping` constant defined in "BeaconConfig.swift". You will likely want to adjust them, or maybe populate the list dynamically from your own backend. You might also want to add custom logic to allow more than one tag picked for a beacon.
 */
class TagsViewController: UITableViewController {

    var selectedTag: String?

    let sortedTags = Array(tagsAndMajorsMapping.keys).sort()

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return sortedTags.count
    }

    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("Tag", forIndexPath: indexPath)
        let tag = sortedTags[indexPath.row]
        cell.textLabel!.text = tag
        if tag == selectedTag {
            cell.accessoryType = .Checkmark
        } else {
            cell.accessoryType = .None
        }
        return cell
    }

    override func tableView(tableView:  UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        let tag = sortedTags[indexPath.row]
        selectedTag = tag
        tableView.reloadData()
    }

}
