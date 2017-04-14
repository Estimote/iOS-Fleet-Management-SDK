//
//  MasterViewController.m
//  TemperatureExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 24.12.2014.
//  Copyright (c) 2014 Estimote Inc. All rights reserved.
//

#import "MasterViewController.h"
#import "DetailViewController.h"
#import <EstimoteSDK/EstimoteSDK.h>

@interface MasterViewController () <ESTNearableManagerDelegate>

@property (nonatomic, strong) ESTNearableManager *nearableManager;
@property (nonatomic, strong) NSArray *nearables;

@end

@implementation MasterViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.nearableManager = [ESTNearableManager new];
    self.nearableManager.delegate = self;
    
    [self.nearableManager startRangingForType:ESTNearableTypeAll];
}

#pragma mark - Segues

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"showDetail"])
    {
        NSIndexPath *indexPath = [self.tableView indexPathForSelectedRow];
        ESTNearable *selectedNearable = self.nearables[indexPath.row];
        [[segue destinationViewController] setNearable:selectedNearable];
    }
}

#pragma mark - Table View

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.nearables.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];

    ESTNearable *nearable = self.nearables[indexPath.row];
   
    cell.textLabel.text         = [ESTNearableDefinitions nameForType:nearable.type];
    cell.detailTextLabel.text   = nearable.identifier;
    return cell;
}

#pragma mark - ESTNearableManaer delegae

- (void)nearableManager:(ESTNearableManager *)manager didRangeNearables:(NSArray *)nearables withType:(ESTNearableType)type
{
    self.nearables = nearables;
    [self.tableView reloadData];
}

@end
