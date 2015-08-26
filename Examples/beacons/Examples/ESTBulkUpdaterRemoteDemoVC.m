//
//  ESTBulkUpdaterRemoteDemoVC.m
//  Examples
//
//  Copyright (c) 2015 com.estimote. All rights reserved.
//

#import "ESTBulkUpdaterRemoteDemoVC.h"

@interface ESTBulkUpdaterRemoteDemoVC ()

@property (nonatomic, strong) IBOutlet UILabel *statusLabel;
@property (nonatomic, strong) IBOutlet UILabel *cloudLabel;

@end

@implementation ESTBulkUpdaterRemoteDemoVC


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Remote Bulk Update Demo";
    
    if ([ESTConfig isAuthorized])
    {
        // Bulk update can be performed only when you are
        // authorized with App ID and App Token
        
        // listen for events from Bulk updater
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(bulkUpdateBegin:)
                                                     name:ESTBulkUpdaterBeginNotification
                                                   object:nil];
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(bulkUpdateProgress:)
                                                     name:ESTBulkUpdaterProgressNotification
                                                   object:nil];
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(bulkUpdateComplete:)
                                                     name:ESTBulkUpdaterCompleteNotification
                                                   object:nil];
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(bulkUpdateTimeout:)
                                                     name:ESTBulkUpdaterTimeoutNotification
                                                   object:nil];
        
        // Perform pending settings fetch from Estimote Cloud
        ESTRequestGetPendingSettings *request = [ESTRequestGetPendingSettings new];
        [request sendRequestWithCompletion:^(NSArray *beaconUpdateInfos, NSError *error) {
            
            self.cloudLabel.text = [NSString stringWithFormat:@"%tu beacons updated\nin Estimote Cloud", beaconUpdateInfos.count];
            
            if (beaconUpdateInfos.count > 0)
            {
                // start performing beacons update based on information fetched
                // from Estimote Cloud
                [[ESTBulkUpdater sharedInstance] startWithBeaconInfos:beaconUpdateInfos timeout:60 * 60];
            }
            else
            {
                self.statusLabel.text = @"Nothing to update!";
            }
        }];
    }
    else
    {
        UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Update error"
                                                            message:@"You have to be authorized to perform Remote bulk update."
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
        
        [errorView show];
    }
}

#pragma mark - ESBulkUpdater notifications handling

- (void)bulkUpdateBegin:(NSNotification *)note
{
    self.statusLabel.text = @"Bulk Updater did begin!";
}

- (void)bulkUpdateProgress:(NSNotification *)note
{
    NSNumber *progress = [note.userInfo objectForKey:@"progress"];
    self.statusLabel.text = [NSString stringWithFormat:@"Update progress ... %.0f\%%", 100. * progress.floatValue];
}

- (void)bulkUpdateComplete:(NSNotification *)note
{
    self.statusLabel.text = @"Bulk Updater complete!";
}

- (void)bulkUpdateTimeout:(NSNotification *)note
{
    self.statusLabel.text = @"Bulk Updater timeout!";
}


@end
