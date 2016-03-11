//
//  ESTBeaconTableVC.m
//  DistanceDemo
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTNearableTableVC.h"
#import "ESTViewController.h"


@interface ESTNearableTableVC () <ESTBeaconManagerDelegate, ESTUtilityManagerDelegate>

@property (nonatomic, copy)     void (^completion)(ESTDeviceNearable *);

@property (nonatomic, strong) ESTBeaconManager *beaconManager;
@property (nonatomic, strong) ESTUtilityManager *utilityManager;
@property (nonatomic, strong) CLBeaconRegion *region;
@property (nonatomic, strong) NSArray *nearablesArray;

@end


@interface ESTNearableTableViewCell : UITableViewCell

@end


@implementation ESTNearableTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    if (self)
    {
        
    }
    return self;
}
@end

@implementation ESTNearableTableVC

- (id)initWithCompletion:(void (^)(id))completion
{
    self = [super init];
    if (self)
    {
        self.completion = [completion copy];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Select Nearable";
    [self.tableView registerClass:[ESTNearableTableViewCell class] forCellReuseIdentifier:@"CellIdentifier"];
    
    self.utilityManager = [[ESTUtilityManager alloc] init];
    self.utilityManager.delegate = self;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    /**
     *  Clear data in TableView on view appear
     */
    
    self.nearablesArray = @[];
    [self.tableView reloadData];
    
    /*
     * Starts looking for Estimote nearables.
     * All callbacks will be delivered to utilityManager delegate.
     */
    
    [self.utilityManager startEstimoteNearableDiscovery];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    /*
     * Stops scanning after exiting the view.
     */
    
    [self.utilityManager stopEstimoteNearableDiscovery];
}

- (void)dismiss
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - ESTBeaconManager delegate

- (void)utilityManager:(ESTUtilityManager *)manager didDiscoverNearables:(NSArray<ESTDeviceNearable *> *)nearables
{
    /**
     *  Update nearables list and reload view
     */
    self.nearablesArray = nearables;
    [self.tableView reloadData];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.nearablesArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ESTNearableTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CellIdentifier" forIndexPath:indexPath];
    
    ESTDeviceNearable *nearable = [self.nearablesArray objectAtIndex:indexPath.row];

    cell.textLabel.text = [NSString stringWithFormat:@"Nearable ID: %@", nearable.identifier];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"RSSI: %zd", nearable.rssi];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
	return 80;
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    /**
     *  Get Nearable device and return
     */
    ESTDeviceNearable *selectedBeacon = [self.nearablesArray objectAtIndex:indexPath.row];
    self.completion(selectedBeacon);
}

@end
