//
//  ViewController.m
//  RangingExample
//
//  Created by Marcin Klimek on 24/12/14.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ViewController.h"
#import <EstimoteSDK/EstimoteSDK.h>
#import "MonitoringDetailsViewController.h"

@interface ESTTableViewCell : UITableViewCell

@end
@implementation ESTTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    if (self)
    {
        
    }
    return self;
}
@end

@interface ViewController () <UITableViewDelegate, UITableViewDataSource, ESTNearableManagerDelegate>

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, strong) NSArray *nearablesArray;
@property (nonatomic, strong) ESTNearableManager *nearableManager;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Pick Nearable to monitor for:";
    
    self.tableView = [[UITableView alloc] initWithFrame:self.view.frame];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.tableView registerClass:[ESTTableViewCell class] forCellReuseIdentifier:@"CellIdentifier"];
    
    [self.view addSubview:self.tableView];
    
    /*
    * Initialize nearables manager and start ranging
    * devices around with any possible type. When nearables are ranged
    * propper delegate method is invoke. Delegate method updates
    * nearables array and reload table view.
    */
    self.nearableManager = [ESTNearableManager new];
    self.nearableManager.delegate = self;
    [self.nearableManager startRangingForType:ESTNearableTypeAll];
}

#pragma mark - ESTNearableManager delegate

- (void)nearableManager:(ESTNearableManager *)manager
      didRangeNearables:(NSArray *)nearables
               withType:(ESTNearableType)type
{
    /*
     * Update local nearables array and reload table view
     */
    self.nearablesArray = nearables;
    [self.tableView reloadData];
}

#pragma mark - UITableView delegate and data source

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
    ESTTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CellIdentifier" forIndexPath:indexPath];
    
    /*
     * Fill the table with beacon data.
     */
    ESTNearable *nearable = [self.nearablesArray objectAtIndex:indexPath.row];
    
    cell.textLabel.text = [NSString stringWithFormat:@"Identifier: %@", nearable.identifier];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"Type: %@ / RSSI: %zd", [ESTNearableDefinitions nameForType:nearable.type], nearable.rssi];
    
    cell.imageView.image = [[UIImage alloc] init];
    cell.imageView.contentMode = UIViewContentModeScaleAspectFill;

    UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(self.view.frame.size.width - 60, 30, 30, 30)];
    imageView.contentMode = UIViewContentModeScaleAspectFill;
    [imageView setImage:[self imageForNearableType:nearable.type]];
    [cell.contentView addSubview:imageView];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 80;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self performSegueWithIdentifier:@"details" sender:indexPath];
}

-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if([[segue identifier] isEqualToString:@"details"])
    {
        MonitoringDetailsViewController *monitVC = (MonitoringDetailsViewController *)segue.destinationViewController;
        monitVC.nearable = [self.nearablesArray objectAtIndex:((NSIndexPath *)sender).row];
    }
}

#pragma mark - Utility methods

- (UIImage *)imageForNearableType:(ESTNearableType)type
{
    switch (type)
    {
        case ESTNearableTypeBag:
            return [UIImage imageNamed:@"sticker_bag"];
            break;
        case ESTNearableTypeBike:
            return [UIImage imageNamed:@"sticker_bike"];
            break;
        case ESTNearableTypeCar:
            return [UIImage imageNamed:@"sticker_car"];
            break;
        case ESTNearableTypeFridge:
            return [UIImage imageNamed:@"sticker_fridge"];
            break;
        case ESTNearableTypeBed:
            return [UIImage imageNamed:@"sticker_bed"];
            break;
        case ESTNearableTypeChair:
            return [UIImage imageNamed:@"sticker_chair"];
            break;
        case ESTNearableTypeShoe:
            return [UIImage imageNamed:@"sticker_shoe"];
            break;
        case ESTNearableTypeDoor:
            return [UIImage imageNamed:@"sticker_door"];
            break;
        case ESTNearableTypeDog:
            return [UIImage imageNamed:@"sticker_dog"];
            break;
        default:
            return [UIImage imageNamed:@"sticker_grey"];
            break;
    }
}

@end
