//
//  ViewController.swift
//  BulkUpdate
//
//  Created by Dawid Rączka on 02/09/16.
//  Copyright © 2016 Dawid Rączka. All rights reserved.
//

import UIKit

class ViewController: UIViewController, ESTLocationBeaconBulkUpdaterDelegate, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet weak var beaconListTableView: UITableView!
    @IBOutlet weak var updateCountLabel: UILabel!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var sessionProgressLabel: UILabel!
    @IBOutlet weak var updateStatusLabel: UILabel!
   
    /**
     *  Setting up variables to count and save data
     @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
     */
    var successCount: Int = 0
    var failuresCount: Int = 0
    var allCount: Int = 0
    var statusesDictionary: [String:String] = [:]
    var bulkUpdater: ESTLocationBeaconBulkUpdater = ESTLocationBeaconBulkUpdater.init()
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        
        beaconListTableView.tableFooterView = UIView()
        beaconListTableView.alwaysBounceVertical = false
        beaconListTableView.allowsSelection = false
        bulkUpdater = ESTLocationBeaconBulkUpdater.init()
        bulkUpdater.delegate = self
  
        bulkUpdater.startCloudUpdate()
    }
    
    // MARK: - Bulk Updater
    
    /**
     *  bulk bulkUpdaterDidFinish informs that update of beacons was successfull
     */
    func bulkUpdaterDidFinish(bulkUpdater: ESTLocationBeaconBulkUpdater!) {
        
        self.updateStatusLabel.text = "Beacons update finished."
        self.activityIndicator.stopAnimating()
    }
    
    /**
     *  bulkUpdater:didUpdateStatus:forDeviceWithIdentifier
     *  Informs bulkUpdater delegate about a change of status for certain device.
     */
    func bulkUpdater(bulkUpdater: ESTLocationBeaconBulkUpdater!, didUpdateStatus updateStatus: ESTBulkUpdaterDeviceUpdateStatus, forDeviceWithIdentifier deviceIdentifier: String!) {
        
        /**
         *  Setting up allCount variable as the number of elements in array updateConfigurations
         *  and increasing counters failuresCount or successCount according to update status
         */
        if bulkUpdater.updateConfigurations != nil {
            
            allCount = bulkUpdater.updateConfigurations.count
        }
        
        /**
         *  updateStatus is a new update status of a device and deviceIdentifier is an
         *  Identifier of a device for which the update status was changed.
         */
        switch updateStatus {
         
        /**
         *  When updateStatus is Failed we are increasing failuresCount and when updateStatus
         *  is Succeeded we are increasing successesCount
         *
         *  Saving update status for each identifier in dictionary to show it later in UITableView
         */
        case .Failed:
            failuresCount = failuresCount + 1
            statusesDictionary[deviceIdentifier] = "Failed"
            break;
        case.Succeeded:
            successCount = successCount + 1
            statusesDictionary[deviceIdentifier] = "Succeded"
            break
        case.Scanning:
            statusesDictionary[deviceIdentifier] = "Scanning"
            break
        case.PendingUpdate:
            statusesDictionary[deviceIdentifier] = "Pending update"
            break
        case.Updating:
            statusesDictionary[deviceIdentifier] = "Updating"
            break
        case.OutOfRange:
            statusesDictionary[deviceIdentifier] = "Out of range"
            break
        default:
            statusesDictionary[deviceIdentifier] = "Unknown"
            break
        }
        
        /**
         *  Updating Status and Count labels and varibles after status update
         */
        dispatch_async(dispatch_get_main_queue(), {
            
            self.beaconListTableView.reloadData()
            self.updateCountLabel.text = "\(self.successCount + self.failuresCount)/\(self.allCount)"
            self.sessionProgressLabel.text = "During this session: \(self.failuresCount) fails, \(self.successCount) successes."
            self.updateStatusLabel.text = "Beacons update in progrss"
        })
    }
    
    // MARK: - UITableViewDelegate
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cell = self.beaconListTableView.dequeueReusableCellWithIdentifier("cell", forIndexPath: indexPath)
        
        cell.textLabel?.text = bulkUpdater.updateConfigurations[indexPath.row].deviceIdentifier
        cell.detailTextLabel?.text = statusesDictionary[bulkUpdater.updateConfigurations[indexPath.row].deviceIdentifier]
        
        return cell
    }
    
    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        if self.bulkUpdater.updateConfigurations != nil {
            return self.bulkUpdater.updateConfigurations.count
        }
        else {
            return 0
        }
    }
 
    override func didReceiveMemoryWarning() {
        
        super.didReceiveMemoryWarning()
    }
    
}

