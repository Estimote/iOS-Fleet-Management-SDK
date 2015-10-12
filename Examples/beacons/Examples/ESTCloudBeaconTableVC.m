//
//  ESTCloudBeaconTableVC.m
//  DistanceDemo
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTCloudBeaconTableVC.h"
#import "ESTViewController.h"

@interface ESTCloudBeaconTableVC () <UITextFieldDelegate>

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
    self.title = @"Cloud Beacons";
    
    self.beaconsTable.delegate = self;
    self.beaconsTable.dataSource = self;
    
    [self.beaconsTable registerClass:[ESTCloudTableViewCell class]
              forCellReuseIdentifier:@"CellIdentifier"];

    // Get list of beacons from the Estimote Cloud
    ESTRequestGetBeacons *request = [[ESTRequestGetBeacons alloc] init];
    
    [request sendRequestWithCompletion:^(id result, NSError *error) {
        
        if (!error)
        {
            self.beaconsArray = result;
            [self.beaconsTable reloadData];
        }
        else
        {
            NSString *errorMessage = [error.localizedDescription stringByAppendingString:error.localizedRecoverySuggestion];
            
            UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Connection error"
                                                                message:errorMessage
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
    cell.detailTextLabel.text   = [NSString stringWithFormat:@"UUID: %@", beacon.proximityUUID ];
    
    cell.imageView.image = beacon.security.integerValue ? [UIImage imageNamed:@"beacon_secure"] : [UIImage imageNamed:@"beacon"];
    
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
