//
//  ESTCloudBeaconTableVC.m
//  DistanceDemo
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTCloudBeaconTableVC.h"
#import "ESTBeaconManager.h"
#import "ESTBeaconVO.h"
#import "ESTViewController.h"

@interface ESTCloudBeaconTableVC () <UITextFieldDelegate>

@property (nonatomic, strong) ESTBeaconManager *beaconManager;
@property (nonatomic, strong) NSArray *beaconsArray;

@property (nonatomic, strong) IBOutlet UITableView *beaconsTable;

@end

@interface ESTCloudTableViewCell : UITableViewCell

@end

@implementation ESTCloudTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    if (self)
    {
        
    }
    return self;
}
@end

@implementation ESTCloudBeaconTableVC

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.beaconManager = [[ESTBeaconManager alloc] init];
    self.title = @"Cloud Beacons";
    
    self.beaconsTable.delegate = self;
    self.beaconsTable.dataSource = self;
    
    [self.beaconsTable registerClass:[ESTCloudTableViewCell class]
              forCellReuseIdentifier:@"CellIdentifier"];

    // Get list of beacons from the Estimote Cloud
    __weak ESTCloudBeaconTableVC *selfRef = self;
    [self.beaconManager fetchEstimoteBeaconsWithCompletion:^(NSArray *value, NSError *error) {
        
        if (!error)
        {
            selfRef.beaconsArray = value;
            [selfRef.beaconsTable reloadData];
        }
        else
        {
            UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Connection error"
                                                                message:error.localizedDescription
                                                               delegate:nil
                                                      cancelButtonTitle:@"OK"
                                                      otherButtonTitles:nil];
            
            [errorView show];
        }
    }];
}

- (void)dismiss
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.beaconsArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ESTCloudTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CellIdentifier" forIndexPath:indexPath];
    
    /*
     * Fill the table with beacon data.
     */
    ESTBeaconVO *beacon = [self.beaconsArray objectAtIndex:indexPath.row];
    
    cell.textLabel.text         = [NSString stringWithFormat:@"Major: %@, Minor: %@", beacon.major, beacon.minor];
    cell.detailTextLabel.text   = [NSString stringWithFormat:@"UUID: %@", beacon.UUID ];
    
    cell.imageView.image = [UIImage imageNamed:@"beacon"];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
	return 80;
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{

}

@end
