//
//  ESTAccelerometerDemoVC.m
//  Examples
//
//  Created by Łukasz Pikor on 24.03.2014.
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import "ESTAccelerometerDemoVC.h"
#import <AudioToolbox/AudioToolbox.h>

@interface ESTAccelerometerDemoVC ()

@property (nonatomic, strong) ESTBeacon *beacon;

//UI properties
@property (nonatomic, strong) IBOutlet UILabel *counterTextLabel;
@property (nonatomic, strong) IBOutlet UILabel *counterLabel;
@property (nonatomic, strong) IBOutlet UIImageView *beaconImage;

@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;

@end

@implementation ESTAccelerometerDemoVC

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
    self.title = @"Accelerometer Demo";
    
    //In order to read beacon accelerometer we need to connect to it.
    self.beacon.delegate = self;
    [self.beacon connect];
    [self.activityIndicator startAnimating];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    [self.beacon disconnect];
}

#pragma mark - Other Methods

- (void)readAccelerometerCount
{
    [self.beacon readAccelerometerCountWithCompletion:^(NSNumber* value, NSError *error) {
        self.counterLabel.text = [NSString stringWithFormat:@"Beacon moves count: %tu", [value integerValue]];
    }];
}

- (void)vibrateEffect
{
    if (self.beacon.isMoving && self.beacon.connectionStatus == ESTBeaconConnectionStatusConnected)
    {
        AudioServicesPlayAlertSound(kSystemSoundID_Vibrate);
        
        CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"transform.translation.x"];
        animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionLinear];
        animation.duration = 0.6;
        animation.values = @[ @(-20), @(20), @(-20), @(20), @(-10), @(10), @(-5), @(5), @(0) ];
        [self.beaconImage.layer addAnimation:animation forKey:@"shake"];
        
        [self performSelector:@selector(vibrateEffect) withObject:nil afterDelay:0.6];
    }
}

#pragma mark - ESTBeaconDelegate
- (void)beaconConnectionDidSucceeded:(ESTBeacon *)beacon
{
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    self.activityLabel.text = @"Connected!";
    
    //After successful connection, we can read or reset accelerometer data.
    [self.beacon resetAccelerometerCountWithCompletion:^(unsigned short value, NSError *error) {
        
        NSLog(@"Error: %@", error);
        
        if (!error)
        {
            self.counterLabel.text = [NSString stringWithFormat:@"Beacon move count: %hu", value];
        }
        else
        {
            self.activityLabel.text = [NSString stringWithFormat:@"Error:%@", [error localizedDescription]];
            self.activityLabel.textColor = [UIColor redColor];
        }
        
    }];
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

- (void)beacon:(ESTBeacon *)beacon accelerometerStateChanged:(BOOL)state
{
    //State is updated after beacon accelerometer was stabilised.
    if (state)
    {
        [self vibrateEffect];
    }
    else
    {
        [self readAccelerometerCount];
    }
}




@end
