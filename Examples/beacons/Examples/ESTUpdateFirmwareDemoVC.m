//
//  ESTUpdateFirmwareDemoVC.m
//  Examples
//
//  Created by Łukasz Pikor on 31.03.2014.
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTUpdateFirmwareDemoVC.h"
#import <EstimoteSDK/ESTBeaconFirmwareUpdate.h>

@interface ESTUpdateFirmwareDemoVC () <ESTBeaconConnectionDelegate>

@property (nonatomic, strong) NSString *macAddress;
@property (nonatomic, strong) ESTBeaconFirmwareUpdate *beaconUpdate;

//UI properties
@property (strong, nonatomic) IBOutlet UILabel *updateStateLabel;
@property (strong, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (strong, nonatomic) IBOutlet UILabel *updateProgressLabel;

@end

@implementation ESTUpdateFirmwareDemoVC

- (id)initWithMacAddress:(NSString *)macAddress
{
    self = [self init];
    if (self)
    {
        self.macAddress = macAddress;
        
        //In order to update beacon firmware we need to connect to it.
        self.beaconUpdate = [[ESTBeaconFirmwareUpdate alloc] initWithMacAddress:macAddress];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self updateBeaconFirmware];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

#pragma mark - Update Firmware Model

- (void)updateBeaconFirmware
{
    __weak typeof(self) selfRef = self;
    self.navigationItem.hidesBackButton = YES;

    [self.beaconUpdate updateFirmwareWithProgress:^(NSInteger value, NSString *description, NSError *error) {
        
        selfRef.updateStateLabel.text = description;
        selfRef.updateProgressLabel.text = [NSString stringWithFormat:@"%ld %%", (long)value];

    } completion:^(NSError *error) {
        
        selfRef.navigationItem.hidesBackButton = NO;

        if (!error)
        {
            selfRef.updateStateLabel.text = @"";
            selfRef.updateProgressLabel.text = @"Updated!";
            selfRef.updateProgressLabel.font = [UIFont boldSystemFontOfSize:50];
        }
        else
        {
            NSLog(@"Update failed.");
            selfRef.updateStateLabel.text = [error localizedDescription];
            selfRef.updateProgressLabel.text = @"Failed!";
            selfRef.updateProgressLabel.font = [UIFont boldSystemFontOfSize:50];
        }
        
        [selfRef.activityIndicator stopAnimating];
    }];
}

@end
