//
//  ESTBulkUpdaterDemoVC.m
//  Examples
//
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTBulkUpdaterDemoVC.h"

@interface ESTBulkUpdaterDemoVC ()

@property (nonatomic, strong) IBOutlet UILabel *statusLabel;

@property (nonatomic, strong) ESTBluetoothBeacon *beacon;

@end

@implementation ESTBulkUpdaterDemoVC

- (id)initWithBeacon:(ESTBluetoothBeacon *)beacon
{
    self = [super init];
    if (self)
    {
        self.beacon = beacon;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Bulk Update Demo";
    
    if ([ESTConfig isAuthorized])
    {
        // Bulk update can be performed only when you are
        // authorized with App ID and App Token
        
        // define configuration that will update power to Level8
        // and advertising interval to 600 ms
        
        ESTBeaconUpdateConfig *sampleConfig = [ESTBeaconUpdateConfig new];
        sampleConfig.power = [NSNumber numberWithChar:ESTBeaconPowerLevel7];
        sampleConfig.advInterval = [NSNumber numberWithInt:700];
        
        // create update info object based on config and localy keept beacon
        
        ESTBeaconUpdateInfo *info = [[ESTBeaconUpdateInfo alloc] initWithMacAddress:self.beacon.identifier config:sampleConfig];
        
    
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
        
        // start performing update of the beacon
        
        [[ESTBulkUpdater sharedInstance] startWithBeaconInfos:@[info] timeout:60 * 60];
    }
    else
    {
        UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Update error"
                                                            message:@"You have to be authorized to perform Bulk update."
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
