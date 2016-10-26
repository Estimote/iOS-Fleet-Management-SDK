//
//  EKVRangingVC.m
//  KeyValueApp
//
//  Created by Filip Chwastowski on 24/10/2016.
//  Copyright © 2016 Estimote. All rights reserved.
//

#import "EKVRangingVC.h"
#import <EstimoteSDK/EstimoteSDK.h>
#import "EKVSavingVC.h"

@interface EKVRangingVC () <UITableViewDelegate, UITableViewDataSource, ESTDeviceManagerDelegate>
@property (nonatomic) NSArray <ESTDeviceLocationBeacon *> *beaconsArray;
@property (nonatomic) ESTDeviceLocationBeacon *selectedBeacon;
@property (nonatomic) ESTDeviceManager *deviceManager;
@end

@implementation EKVRangingVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIBarButtonItem *backButton = [[UIBarButtonItem alloc] initWithTitle:@"Back"
                                                                   style:UIBarButtonItemStylePlain
                                                                  target:nil
                                                                  action:nil];
    [self.navigationItem setBackBarButtonItem:backButton];
    
    // Do any additional setup after loading the view.
    self.beaconsArray = @[];
    
    self.deviceManager = [[ESTDeviceManager alloc] init];
    self.deviceManager.delegate = self;
    ESTDeviceFilterLocationBeacon *filter = [[ESTDeviceFilterLocationBeacon alloc] init];
    [self.deviceManager startDeviceDiscoveryWithFilter:filter];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UITableView

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellID = @"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID forIndexPath:indexPath];
    
    cell.textLabel.text = self.beaconsArray[indexPath.row].identifier;
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    self.selectedBeacon = self.beaconsArray[indexPath.row];
    [self performSegueWithIdentifier:@"goStorage" sender:self];
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.beaconsArray.count;
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"goStorage"]) {
        EKVSavingVC *destinationVC = (EKVSavingVC *)segue.destinationViewController;
        destinationVC.selectedBeacon = self.selectedBeacon;
    }
}

#pragma mark - ESTDeviceManagerDelegate

- (void)deviceManager:(ESTDeviceManager *)manager didDiscoverDevices:(NSArray<ESTDevice *> *)devices {
    if (devices.count > 0) {
        self.beaconsArray = (NSArray <ESTDeviceLocationBeacon *> *)devices;
    }
    
    [self.tableView reloadData];
}

@end
