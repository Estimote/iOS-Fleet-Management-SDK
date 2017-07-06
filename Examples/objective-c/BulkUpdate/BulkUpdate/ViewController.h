//
//  ViewController.h
//  BulkUpdate
//
//  Created by Dawid Rączka on 07/09/16.
//  Copyright © 2016 Dawid Rączka. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (weak, nonatomic) IBOutlet UITableView *beaconListTableView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (weak, nonatomic) IBOutlet UILabel *updateCountLabel;
@property (weak, nonatomic) IBOutlet UILabel *updateStatusLabel;
@property (weak, nonatomic) IBOutlet UILabel *sessionProgressLabel;
@end
