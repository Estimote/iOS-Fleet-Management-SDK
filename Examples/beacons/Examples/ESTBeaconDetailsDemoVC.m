//
//  ESTBeaconDetailsDemoVC.m
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "ESTBeaconDetailsDemoVC.h"
#import <ESTBeaconManager.h>

@interface ESTBeaconDetailsDemoVC () <ESTBeaconDelegate, UITextFieldDelegate>

/*
 * UI elements
 */

@property (nonatomic, strong) IBOutlet UIScrollView *mainScrollView;
@property (nonatomic, strong) IBOutlet UIView *mainView;

@property (nonatomic, strong) IBOutlet UIImageView* beaconImage;

@property (nonatomic, strong) IBOutlet UITextField *UUIDTextFiled;
@property (nonatomic, strong) IBOutlet UITextField *motinoUUIDTextFiled;
@property (nonatomic, strong) IBOutlet UITextField *majorTextFiled;
@property (nonatomic, strong) IBOutlet UITextField *minorTextFiled;

@property (nonatomic, strong) IBOutlet UITextField *advertisingTextField;
@property (nonatomic, strong) IBOutlet UITextField *powerTextField;

@property (nonatomic, strong) IBOutlet UISwitch *basicPowerModeSwitch;
@property (nonatomic, strong) IBOutlet UISwitch *smartPowerModeSwitch;

@property (nonatomic, strong) IBOutlet UISwitch *secureUUIDSwitch;

@property (nonatomic, strong) IBOutlet UITextView *mac;
@property (nonatomic, strong) IBOutlet UILabel *batteryLevel;
@property (nonatomic, strong) IBOutlet UILabel *softwareVersion;
@property (nonatomic, strong) IBOutlet UILabel *hardwareVersion;

@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;

@property (nonatomic, strong) IBOutlet UIButton* resetBtn;

/*
 * Class elements
 */

@property (nonatomic, strong) ESTBeacon* beaconData;

@end

@implementation ESTBeaconDetailsDemoVC

- (id)initWithBeacon:(ESTBeacon*)beacon
{
    self = [super init];
    if (self)
    {
        self.beaconData = beacon;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Beacon Details";
    
    [self enableView:NO];
    
    self.resetBtn.layer.cornerRadius = 5;
    self.resetBtn.layer.masksToBounds = YES;
    
    self.mainScrollView.frame = CGRectMake(0, 0,
                                       [UIScreen mainScreen].bounds.size.width,
                                       [UIScreen mainScreen].bounds.size.height);
    
    self.mainScrollView.contentSize = CGSizeMake(320, 700);
    self.mainScrollView.contentOffset = CGPointMake(0, 10);
    
    //In order to read beacon accelerometer we need to connect to it.
    self.beaconData.delegate = self;
    [self.beaconData connect];
    [self.activityIndicator startAnimating];
}


- (void)enableView:(BOOL)enable
{
    self.mainView.userInteractionEnabled = enable;
    self.mainView.alpha = enable ? 1. : .5;
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    /*
     * Disconnect beacon when leaving screen
     */
    
    if (self.beaconData.connectionStatus == ESTConnectionStatusConnected)
    {
        [self.beaconData disconnect];
    }
}

- (void)setData:(ESTBeacon*)data
{
    self.beaconData = data;
    self.beaconData.delegate = self;
    
    [self updateDataLabels];
}

- (void)updateDataLabels
{
    self.resetBtn.enabled = YES;
    self.resetBtn.alpha = 1;
    
    if (self.beaconData.proximityUUID)
    {
        self.UUIDTextFiled.text = [NSString stringWithFormat:@"%@", [self.beaconData.proximityUUID UUIDString]];
        self.UUIDTextFiled.enabled = YES;
    }
    else
    {
        self.UUIDTextFiled.text = @"--";
        self.UUIDTextFiled.enabled = NO;
    }
    
    if (self.beaconData.motionProximityUUID)
    {
        self.motinoUUIDTextFiled.text = [NSString stringWithFormat:@"%@", [self.beaconData.motionProximityUUID UUIDString]];
    }
    else
    {
        self.motinoUUIDTextFiled.text = @"--";
    }
    
    if (self.beaconData.major)
    {
        self.majorTextFiled.text = [NSString stringWithFormat:@"%i", [self.beaconData.major unsignedShortValue]];
        self.majorTextFiled.enabled = YES;
    }
    else
    {
        self.majorTextFiled.text = @"--";
        self.majorTextFiled.enabled = NO;
    }
    
    if (self.beaconData.minor)
    {
        self.minorTextFiled.text = [NSString stringWithFormat:@"%i", [self.beaconData.minor unsignedShortValue]];
        self.minorTextFiled.enabled = YES;
    }
    else
    {
        self.minorTextFiled.text = @"--";
        self.minorTextFiled.enabled = NO;
    }
    
    if (self.beaconData.advInterval)
    {
        self.advertisingTextField.text = [NSString stringWithFormat:@"%d", [self.beaconData.advInterval unsignedShortValue]];
    }
    else
    {
        self.advertisingTextField.text = @"--";
    }
    
    if (self.beaconData.power)
    {
        self.powerTextField.text = [NSString stringWithFormat:@"%i", [self.beaconData.power shortValue]];
        self.powerTextField.enabled = YES;
    }
    else
    {
        self.powerTextField.text = @"--";
    }
    
    if (self.beaconData.batteryLevel)
    {
        self.batteryLevel.text = [NSString stringWithFormat:@"%i%%", [self.beaconData.batteryLevel unsignedCharValue]];
    }
    else
    {
        self.batteryLevel.text = @"--";
    }
    
    if (self.beaconData.firmwareVersion)
    {
        self.softwareVersion.text = self.beaconData.firmwareVersion;
    }
    else
    {
        self.softwareVersion.text = @"--";
    }
    
    if (self.beaconData.hardwareVersion)
    {
        self.hardwareVersion.text = self.beaconData.hardwareVersion;
    }
    else
    {
        self.hardwareVersion.text = @"--";
    }
    
    if (self.beaconData.macAddress)
    {
        self.mac.text = [NSString stringWithFormat:@"%@", self.beaconData.macAddress];
    }
    else
    {
        self.mac.text = @"--";
    }
    
    if (self.beaconData.basicPowerMode == ESTBeaconPowerSavingModeOn)
    {
        self.basicPowerModeSwitch.enabled = YES;
        self.basicPowerModeSwitch.on = YES;
    }
    else if (self.beaconData.basicPowerMode == ESTBeaconPowerSavingModeOff)
    {
        self.basicPowerModeSwitch.enabled = YES;
        self.basicPowerModeSwitch.on = NO;
    }
    
    if (self.beaconData.smartPowerMode == ESTBeaconPowerSavingModeOn)
    {
        self.smartPowerModeSwitch.enabled = YES;
        self.smartPowerModeSwitch.on = YES;
    }
    else if (self.beaconData.smartPowerMode == ESTBeaconPowerSavingModeOff)
    {
        self.smartPowerModeSwitch.enabled = YES;
        self.smartPowerModeSwitch.on = NO;
    }
    
    if (self.beaconData.estimoteSecureUUID == ESTBeaconEstimoteSecureUUIDOn)
    {
        self.secureUUIDSwitch.enabled = YES;
        self.secureUUIDSwitch.on = YES;
    }
    else if (self.beaconData.estimoteSecureUUID == ESTBeaconEstimoteSecureUUIDOff)
    {
        self.secureUUIDSwitch.enabled = YES;
        self.secureUUIDSwitch.on = NO;
    }

}

////////////////////////////////////////////////////////
# pragma mark - UI Button handling

- (IBAction)switchBasicPowerModeState:(UISwitch*)sender
{
    self.basicPowerModeSwitch.enabled = NO;
    self.smartPowerModeSwitch.enabled = NO;
    
    __weak typeof(self) selfRef = self;
    
    [self.beaconData enableBasicPowerMode:sender.isOn completion:^(BOOL value, NSError *error) {
        selfRef.basicPowerModeSwitch.enabled = YES;
        selfRef.smartPowerModeSwitch.enabled = YES;
        if (error)
        {
            selfRef.basicPowerModeSwitch.on = !selfRef.basicPowerModeSwitch.isOn;
        }
    }];
}

- (IBAction)switchSmartPowerModeState:(UISwitch *)sender
{
    self.basicPowerModeSwitch.enabled = NO;
    self.smartPowerModeSwitch.enabled = NO;
    
    __weak typeof(self) selfRef = self;
    [self.beaconData enableSmartPowerMode:sender.isOn completion:^(BOOL value, NSError *error) {
        selfRef.basicPowerModeSwitch.enabled = YES;
        selfRef.smartPowerModeSwitch.enabled = YES;
        if (error)
        {
            selfRef.smartPowerModeSwitch.on = !selfRef.smartPowerModeSwitch.isOn;
        }
    }];
}

- (IBAction)switchSecureUUIDState:(UISwitch *)sender
{
    self.basicPowerModeSwitch.enabled = NO;
    self.smartPowerModeSwitch.enabled = NO;
    self.secureUUIDSwitch.enabled = NO;
    
    __weak typeof(self) selfRef = self;
    
    [self.beaconData enableEstimoteSecureUUID:sender.isOn completion:^(BOOL value, NSError *error) {
        selfRef.basicPowerModeSwitch.enabled = YES;
        selfRef.smartPowerModeSwitch.enabled = YES;
        selfRef.secureUUIDSwitch.enabled = YES;
        
        if (error)
        {
            selfRef.secureUUIDSwitch.on = !selfRef.secureUUIDSwitch.isOn;
        }
        
    }];
}

- (IBAction)resetBtnTapped:(id)sender
{
    [self.beaconData resetToFactorySettingsWithCompletion:^(NSError *error)
    {
        NSString *message = @"Beacon was successfuly reseted.";
        
        if (error)
        {
            message = error.localizedDescription;
        }
        
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Reset Finished!"
                                                        message:message
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        
        [alert show];
    }];
}

#pragma mark - ESTBeacon connection handling

- (void)beaconAuthorizationDidFail:(ESTBeacon *)beacon withError:(NSError *)error
{
    [self beacon:beacon didDisconnectWithError:nil];
    
    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Authorization Failed"
                                                    message:error.localizedDescription
                                                   delegate:nil
                                          cancelButtonTitle:@"OK"
                                          otherButtonTitles: nil];
    [alert show];
}

- (void)beaconConnectionDidSucceeded:(ESTBeacon *)beacon
{
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    self.activityLabel.text = @"Connected!";
    
    [self enableView:YES];
    [self updateDataLabels];
}

- (void)beaconConnectionDidFail:(ESTBeacon*)beacon withError:(NSError *)error
{
    NSLog(@"Something went wrong. Beacon connection Did Fail. Error: %@", error);
    
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    
    self.activityLabel.text = @"Connection failed";
    self.activityLabel.textColor = [UIColor redColor];
}

- (void)beacon:(ESTBeacon*)beacon didDisconnectWithError:(NSError*)error
{
    [self updateDataLabels];
}

#pragma mark - UITextField delgate

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    if (textField == self.majorTextFiled)
    {
        unsigned short newMajor = (unsigned short)[self.majorTextFiled.text intValue];
        
        [self.beaconData writeMajor:newMajor completion:^(unsigned short major, NSError *error)
        {
            if (error)
            {
                NSLog(@"Error major write: %@", error.localizedDescription);
            }
            
            self.majorTextFiled.text = [NSString stringWithFormat:@"%i", major];
        }];
    }
    else if (textField == self.minorTextFiled)
    {
        unsigned short newMinor = (unsigned short)[self.minorTextFiled.text intValue];
        
        [self.beaconData writeMinor:newMinor completion:^(unsigned short minor, NSError *error)
        {
            if (error)
            {
                NSLog(@"Error minor write: %@", error.localizedDescription);
            }
            
            self.minorTextFiled.text = [NSString stringWithFormat:@"%i", minor];
        }];
    }
    else if (textField == self.UUIDTextFiled)
    {
        [self.beaconData writeProximityUUID:textField.text completion:^(NSString *value, NSError *error)
        {
            if (error)
            {
                NSLog(@"Error UUID write: %@", error.localizedDescription);
            }
            
            self.UUIDTextFiled.text = [NSString stringWithFormat:@"%@", value];
        }];
    }
    else if (textField == self.advertisingTextField)
    {
        [self.beaconData writeAdvInterval:[textField.text integerValue] completion:^(unsigned short value, NSError *error)
        {
            if (error)
            {
                NSLog(@"Error Advertising Interval write: %@", error.localizedDescription);
            }

            self.advertisingTextField.text = [NSString stringWithFormat:@"%i", value];
        }];
    }
    else if (textField == self.powerTextField)
    {
        [self.beaconData writePower:[textField.text integerValue] completion:^(ESTBeaconPower power, NSError *error)
        {
            if (error)
            {
                NSLog(@"Error Power write: %@", error.localizedDescription);
            }
            
            self.powerTextField.text = [NSString stringWithFormat:@"%tx", [self.beaconData.power integerValue]];
        }];
    }
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

@end
