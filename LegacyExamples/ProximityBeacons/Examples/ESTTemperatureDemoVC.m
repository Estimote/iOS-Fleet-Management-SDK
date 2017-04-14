//
//  ESTTemperatureDemoVC.m
//  Examples
//
//  Created by Łukasz Pikor on 24.03.2014.
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTTemperatureDemoVC.h"

@interface ESTTemperatureDemoVC () <ESTBeaconConnectionDelegate>

@property (nonatomic, strong) ESTBeaconConnection *beaconConnection;

//UI properties
@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UILabel *temperatureLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) NSTimer *readTemperatureWithInterval;

@end

@implementation ESTTemperatureDemoVC

- (instancetype)initWithBeacon:(CLBeacon *)beacon
{
    self = [self init];
    if (self)
    {
        self.beaconConnection = [[ESTBeaconConnection alloc] initWithBeacon:beacon
                                                                   delegate:self
                                                           startImmediately:NO];
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
    [self.beaconConnection startConnection];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    if (self.beaconConnection.connectionStatus == ESTConnectionStatusConnected || self.beaconConnection.connectionStatus == ESTConnectionStatusConnecting)
    {
        if (self.readTemperatureWithInterval)
        {
            [self.readTemperatureWithInterval invalidate];
            self.readTemperatureWithInterval = nil;
        }
        
        [self.beaconConnection cancelConnection];
    }
}

#pragma mark - Beacon Operations
- (void)readBeaconTemperature
{
    //Reading temperature is asynchronous task, so we need to wait for completion block to be called.
    [self.beaconConnection readTemperatureWithCompletion:^(NSNumber* value, NSError *error) {
        
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
- (void)beaconConnectionDidSucceed:(ESTBeaconConnection *)connection
{
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    self.activityLabel.text = @"Connected!";
    
    //After successful connection, we can start reading temperature.
    self.readTemperatureWithInterval = [NSTimer scheduledTimerWithTimeInterval:2.0f
                                                                        target:self
                                                                      selector:@selector(readBeaconTemperature)
                                                                      userInfo:nil repeats:YES];
    
    [self readBeaconTemperature];
}

- (void)beaconConnection:(ESTBeaconConnection *)connection didFailWithError:(NSError *)error
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

- (void)beaconConnection:(ESTBeaconConnection *)connection didDisconnectWithError:(NSError *)error
{
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    
    self.activityLabel.text = @"Disconnected!";
    self.activityLabel.textColor = [UIColor redColor];
    
    self.temperatureLabel.text = @"--°C";
}

@end
