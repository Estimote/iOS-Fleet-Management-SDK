//
//  ESTUpdateFirmwareDemoVC.m
//  Examples
//
//  Created by Łukasz Pikor on 31.03.2014.
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTUpdateFirmwareDemoVC.h"
#import <EstimoteSDK/EstimoteSDK.h>

@interface ESTUpdateFirmwareDemoVC () <ESTBeaconConnectionDelegate>

@property (nonatomic, strong) ESTBeaconConnection *beaconConnection;

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
        //In order to update beacon firmware we need to connect to it.
        self.beaconConnection = [[ESTBeaconConnection alloc] initWithIdentifier:macAddress
                                                                   delegate:self
                                                           startImmediately:YES];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    [self.beaconConnection cancelConnection];
}

#pragma mark - Update Firmware Model

- (void)beaconConnectionDidSucceed:(ESTBeaconConnection *)connection
{
    __weak typeof(self) selfRef = self;
    self.navigationItem.hidesBackButton = YES;

    [self.beaconConnection updateFirmwareWithProgress:^(NSInteger value, NSString *description, NSError *error) {
        
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

- (void)beaconConnection:(ESTBeaconConnection *)connection didFailWithError:(NSError *)error
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
