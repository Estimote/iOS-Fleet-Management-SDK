//
//  ViewController.m
//  BulkUpdate
//
//  Created by Dawid Rączka on 07/09/16.
//  Copyright © 2016 Dawid Rączka. All rights reserved.
//

#import "ViewController.h"
#import <EstimoteSDK/EstimoteSDK.h>

@interface ViewController () <ESTLocationBeaconBulkUpdaterDelegate, UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) ESTLocationBeaconBulkUpdater *bulkUpdater;
@property (nonatomic, assign) NSInteger successCount;
@property (nonatomic, assign) NSInteger failuresCount;
@property (nonatomic, assign) NSInteger allCount;
@property (nonatomic, strong) NSMutableDictionary <NSString *, NSString *> *statusesDictionary;
@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    _beaconListTableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectZero];
    _beaconListTableView.alwaysBounceVertical = NO;
    _beaconListTableView.allowsSelection = NO;
    
    self.successCount = 0;
    self.failuresCount = 0;
    self.allCount = 0;
    self.statusesDictionary = [NSMutableDictionary dictionary];
    self.bulkUpdater = [[ESTLocationBeaconBulkUpdater alloc] init];
    self.bulkUpdater.delegate = self;

    [self.bulkUpdater startCloudUpdate];
}

#pragma mark - Bulk Updater

/**
 *  bulk bulkUpdaterDidFinish informs that update of beacons was successfull
 */
- (void) bulkUpdaterDidFinish:(ESTLocationBeaconBulkUpdater *)bulkUpdater {
    
    self.updateStatusLabel.text = @"Beacons update finished.";
    [self.activityIndicator stopAnimating];
}

/**
 *  bulkUpdater:didUpdateStatus:forDeviceWithIdentifier
 *  Informs bulkUpdater delegate about a change of status for certain device.
 */
- (void)bulkUpdater:(ESTLocationBeaconBulkUpdater *)bulkUpdater
    didUpdateStatus:(ESTBulkUpdaterDeviceUpdateStatus)updateStatus
forDeviceWithIdentifier:(NSString *)deviceIdentifier {
    
    /**
     *  Setting up allCount variable as the number of elements in array updateConfigurations
     *  and increasing counters failuresCount or successCount according to update status
     */
    self.allCount = bulkUpdater.updateConfigurations.count;
    
    /**
     *  updateStatus is a new update status of a device and deviceIdentifier is an
     *  Identifier of a device for which the update status was changed.
     */
    switch (updateStatus) {
            
       /**
        *  When updateStatus is Failed we are increasing failuresCount and when updateStatus
        *  is Succeeded we are increasing successesCount
        *
        *  Saving update status for each identifier in dictionary to show it later in UITableView
        */
        case ESTBulkUpdaterDeviceUpdateStatusFailed:
        {
            self.failuresCount++;
            [self.statusesDictionary setObject:@"Failed" forKey:deviceIdentifier];
        }
            break;
        case ESTBulkUpdaterDeviceUpdateStatusSucceeded:
        {
            self.successCount++;
            [self.statusesDictionary setObject:@"Succeeded" forKey:deviceIdentifier];
        }
            break;
        case ESTBulkUpdaterDeviceUpdateStatusScanning:
        {
            [self.statusesDictionary setObject:@"Scanning" forKey:deviceIdentifier];
        }
            break;
        case ESTBulkUpdaterDeviceUpdateStatusPendingUpdate:
        {
            [self.statusesDictionary setObject:@"Pending update" forKey:deviceIdentifier];
        }
            break;
        case ESTBulkUpdaterDeviceUpdateStatusUpdating:
        {
            [self.statusesDictionary setObject:@"Updating" forKey:deviceIdentifier];
        }
            break;
        case ESTBulkUpdaterDeviceUpdateStatusOutOfRange:
        {
            [self.statusesDictionary setObject:@"Out of range" forKey:deviceIdentifier];
        }
            break;
        default:
            [self.statusesDictionary setObject:@"Unknown" forKey:deviceIdentifier];
            break;
    }

    /**
     *  Updating Status and Count labels and varibles after status update
     */
    dispatch_async(dispatch_get_main_queue(), ^{
        
        [self.beaconListTableView reloadData];
        self.updateCountLabel.text = [NSString stringWithFormat:@"%ld/%ld", self.successCount + self.failuresCount, (long)self.allCount];
        self.sessionProgressLabel.text = [NSString stringWithFormat:@"During this session: %ld fails, %ld successes.", (long)self.failuresCount, (long)self.successCount];
        self.updateStatusLabel.text = @"Beacons update in progrss";
    });
}

#pragma mark - UITableViewDelegate

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    
    cell.textLabel.text = self.bulkUpdater.updateConfigurations[indexPath.row].deviceIdentifier;
    cell.detailTextLabel.text = [self.statusesDictionary objectForKey: self.bulkUpdater.updateConfigurations[indexPath.row].deviceIdentifier];
    return cell;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return self.bulkUpdater.updateConfigurations.count;
}

@end
