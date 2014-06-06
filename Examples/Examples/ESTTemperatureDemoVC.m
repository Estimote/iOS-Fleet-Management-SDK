//
//  ESTTemperatureDemoVC.m
//  Examples
//
//  Created by Łukasz Pikor on 24.03.2014.
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTTemperatureDemoVC.h"

@interface ESTTemperatureDemoVC ()

@property (nonatomic, strong) ESTBeacon *beacon;

//UI properties
@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UILabel *temperatureLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) NSTimer *readTemperatureWithInterval;

@end

@implementation ESTTemperatureDemoVC

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
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"Temperature demo";
    [self.activityIndicator startAnimating];
    
    //In order to read beacon temperature we need to connect to it.
    self.beacon.delegate = self;
    [self.beacon connect];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    if (self.beacon.connectionStatus == ESTBeaconConnectionStatusConnected)
    {
        [self.readTemperatureWithInterval invalidate];
        [self.beacon disconnect];
    }
}

#pragma mark - Beacon Operations
- (void)readBeaconTemperature
{
    //Reading temperature is asynchronous task, so we need to wait for completion block to be called.
    [self.beacon readTemperatureWithCompletion:^(NSNumber* value, NSError *error) {
        
        if (!error)
        {
            self.temperatureLabel.text = [NSString stringWithFormat:@"%.1f°C", [value floatValue]];
            [self.activityIndicator stopAnimating];
        }
        else
        {
            self.activityLabel.text = [NSString stringWithFormat:@"Error:%@", [error localizedDescription]];
            self.activityLabel.textColor = [UIColor redColor];
        }
    }];
}

#pragma mark - ESTBeaconDelegate
- (void)beaconConnectionDidSucceeded:(ESTBeacon *)beacon
{
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    self.activityLabel.text = @"Connected!";
    
    //After successful connection, we can start reading temperature.
    self.readTemperatureWithInterval = [NSTimer scheduledTimerWithTimeInterval:1.0f
                                                                        target:self
                                                                      selector:@selector(readBeaconTemperature)
                                                                      userInfo:nil repeats:YES];
    
    [self readBeaconTemperature];
}

- (void)beaconConnectionDidFail:(ESTBeacon *)beacon withError:(NSError *)error
{
    NSLog(@"Something went wrong. Beacon connection Did Fail. Error: %@", error);
    
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    
    self.activityLabel.text = @"Connection failed";
    self.activityLabel.textColor = [UIColor redColor];
    
    UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Connection error"
                                                        message:error.localizedDescription
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
    
    [errorView show];
}

@end
