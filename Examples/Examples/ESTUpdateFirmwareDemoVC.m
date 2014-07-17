//
//  ESTUpdateFirmwareDemoVC.m
//  Examples
//
//  Created by Łukasz Pikor on 31.03.2014.
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTUpdateFirmwareDemoVC.h"
#import <ESTBeaconManager.h>

@interface ESTUpdateFirmwareDemoVC () <ESTBeaconDelegate>

@property (nonatomic, strong) ESTBeacon *beacon;

//UI properties
@property (strong, nonatomic) IBOutlet UILabel *updateStateLabel;
@property (strong, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (strong, nonatomic) IBOutlet UILabel *updateProgressLabel;

@end

@implementation ESTUpdateFirmwareDemoVC

- (id)initWithBeacon:(ESTBeacon*)beacon
{
    self = [self init];
    if (self)
    {
        self.beacon = beacon;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    //In order to update beacon firmware we need to connect to it.
    self.beacon.delegate = self;
    [self.beacon connect];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    [self.beacon disconnect];
}

#pragma mark - Update Firmware Model
- (void)checkFirmwareAvailability
{
    ESTUpdateFirmwareDemoVC __weak *selfReference = self;
    
    //You need to be connected to the Internet.
    [self.beacon checkFirmwareUpdateWithCompletion:^(ESTBeaconFirmwareInfoVO *result, NSError *error) {

        if (!error && result.isUpdateAvailable)
        {
            //Update is available
            [self updateBeaconFirmware];
        }
        else if (!error && !result.isUpdateAvailable)
        {
            selfReference.updateProgressLabel.text = @"Up to date!";
            selfReference.updateProgressLabel.font = [UIFont boldSystemFontOfSize:50];
        }
        else if (error)
        {
            NSLog(@"Error while checking firmware update: %@", [error localizedDescription]);
        }
    }];
}

- (void)updateBeaconFirmware
{
    ESTUpdateFirmwareDemoVC __weak *selfReference = self;
    
    self.navigationItem.hidesBackButton = YES;

    [self.beacon updateFirmwareWithProgress:^(NSInteger value, NSString *description, NSError *error) {
        
        selfReference.updateStateLabel.text = description;
        selfReference.updateProgressLabel.text = [NSString stringWithFormat:@"%ld %%", (long)value];

    } completion:^(NSError *error) {
        
        selfReference.navigationItem.hidesBackButton = NO;

        if (!error)
        {
            selfReference.updateStateLabel.text = @"";
            selfReference.updateProgressLabel.text = @"Updated!";
            selfReference.updateProgressLabel.font = [UIFont boldSystemFontOfSize:50];
        }
        else
        {
            NSLog(@"Update failed.");
            selfReference.updateStateLabel.text = [error localizedDescription];
            selfReference.updateProgressLabel.text = @"Failed!";
            selfReference.updateProgressLabel.font = [UIFont boldSystemFontOfSize:50];
        }
    }];
}

#pragma mark - ESTBeacon Delegate
- (void)beaconConnectionDidSucceeded:(ESTBeacon *)beacon
{
    self.updateStateLabel.text = @"Connected!";
    [self.activityIndicator stopAnimating];
    
    //After succesful connection we check if update for our beacon is available.
    [self checkFirmwareAvailability];
}

- (void)beaconConnectionDidFail:(ESTBeacon *)beacon withError:(NSError *)error
{
    //Beacon connection did fail. Try again.
    
    NSLog(@"Something went wrong. Beacon connection Did Fail. Error: %@", error);
    
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    
    self.updateStateLabel.text = @"Connection failed";
    self.updateStateLabel.textColor = [UIColor redColor];
    
    UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Connection error"
                                                        message:error.localizedDescription
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
    
    [errorView show];
}

@end
