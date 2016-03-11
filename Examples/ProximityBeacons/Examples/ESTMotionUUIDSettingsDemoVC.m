//
//  ESTMotionUUIDSettingsDemoVC.m
//  Examples
//
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTMotionUUIDSettingsDemoVC.h"
#import <AudioToolbox/AudioToolbox.h>

@interface ESTMotionUUIDSettingsDemoVC () <ESTBeaconConnectionDelegate>

@property (nonatomic, strong) ESTBeaconConnection *beaconConnection;

//UI properties
@property (nonatomic, strong) IBOutlet UISwitch *accelerometerSwitch;
@property (nonatomic, strong) IBOutlet UISwitch *motionUUIDSwitch;

@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;

@end

@implementation ESTMotionUUIDSettingsDemoVC

- (id)initWithBeacon:(CLBeacon *)beacon
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
    self.title = @"Motion Detection Settings";
    
    /**
     *  In order to adjust beacon accelerometer and motion UUID settings
     *  you need to connect to it first.
     */
    
    [self.beaconConnection startConnection];
    
    [self.activityIndicator startAnimating];
    
    self.accelerometerSwitch.enabled = NO;
    self.motionUUIDSwitch.enabled = NO;
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    [self.beaconConnection cancelConnection];
}

#pragma mark - ESTBeaconDelegate

- (void)beaconConnectionDidSucceed:(ESTBeaconConnection *)connection
{
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    self.activityLabel.text = @"Connected!";
    
    if (self.beaconConnection.motionDetectionState != ESTBeaconMotionDetectionUnsupported)
    {
        self.accelerometerSwitch.enabled = YES;
        [self.accelerometerSwitch setOn: self.beaconConnection.motionDetectionState == ESTBeaconMotionDetectionOn];
    }
    
    if (self.beaconConnection.motionUUIDState != ESTBeaconMotionUUIDUnsupported)
    {
        self.motionUUIDSwitch.enabled = YES;
        [self.motionUUIDSwitch setOn: self.beaconConnection.motionUUIDState == ESTBeaconMotionUUIDOn];
    }
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

#pragma mark - Switch tap handling

- (IBAction)accelerometerSwitchValueChanged
{
    self.accelerometerSwitch.enabled = NO;
    
    /**
     *  Here you can see how simple it is to enable beacons's accelerometer.
     *  As you can see this method can be invoked only when phone is connected
     *  to the beacon.
     */
    __weak typeof(self) selfRef = self;
    [self.beaconConnection writeMotionDetectionEnabled:self.accelerometerSwitch.on
                                            completion:^(BOOL value, NSError *error) {
       
        [selfRef.accelerometerSwitch setOn:value];
        selfRef.accelerometerSwitch.enabled = YES;
        
    }];
}

- (IBAction)motionUUIDSwitchValueChanged
{
    self.motionUUIDSwitch.enabled = NO;
    
    /**
     *  Here you can see how simple it is to enable beacons's motion UUID feature.
     *  As you can see this method can be invoked only when phone is connected
     *  to the beacon.
     */
    __weak typeof(self) selfRef = self;
    [self.beaconConnection writeMotionUUIDEnabled:self.motionUUIDSwitch.on
                                       completion:^(BOOL value, NSError *error) {
        
        [selfRef.motionUUIDSwitch setOn:value];
        selfRef.motionUUIDSwitch.enabled = YES;
        
    }];
}


@end
