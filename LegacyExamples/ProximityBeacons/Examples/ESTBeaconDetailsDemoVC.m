//
//  ESTBeaconDetailsDemoVC.m
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "ESTBeaconDetailsDemoVC.h"


@interface ESTBeaconDetailsDemoVC () <UITextFieldDelegate, ESTBeaconConnectionDelegate>

@property (nonatomic, strong) ESTBeaconConnection *beaconConnection;

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

@property (nonatomic, strong) IBOutlet UITextField *eddystoneNamespaceTextField;
@property (nonatomic, strong) IBOutlet UITextField *eddystoneInstanceTextField;
@property (nonatomic, strong) IBOutlet UITextField *eddystoneURLTextField;

@property (nonatomic, strong) IBOutlet UISwitch *basicPowerModeSwitch;
@property (nonatomic, strong) IBOutlet UISwitch *smartPowerModeSwitch;

@property (nonatomic, strong) IBOutlet UISwitch *secureUUIDSwitch;
@property (nonatomic, strong) IBOutlet UISegmentedControl *conditionalBroadcastingSegment;
@property (nonatomic, strong) IBOutlet UISegmentedControl *broadcastingSchemeSegment;

@property (nonatomic, strong) IBOutlet UITextView *mac;
@property (nonatomic, strong) IBOutlet UILabel *batteryLevel;
@property (nonatomic, strong) IBOutlet UILabel *softwareVersion;
@property (nonatomic, strong) IBOutlet UILabel *hardwareVersion;

@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;

@property (nonatomic, strong) IBOutlet UIButton* resetBtn;

@end

@implementation ESTBeaconDetailsDemoVC

- (id)initWithMacAddress:(NSString *)macAddress
{
    self = [super init];
    if (self)
    {
        //In order to update beacon firmware we need to connect to it.
        self.beaconConnection = [[ESTBeaconConnection alloc] initWithMacAddress:macAddress
                                                                        delegate:self
                                                                startImmediately:NO];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Device Details";
    
    [self enableView:NO];
    
    self.resetBtn.layer.cornerRadius = 5;
    self.resetBtn.layer.masksToBounds = YES;
    
    self.mainScrollView.frame = CGRectMake(0, 0,
                                       [UIScreen mainScreen].bounds.size.width,
                                       [UIScreen mainScreen].bounds.size.height);
    
    self.mainScrollView.contentSize = CGSizeMake(320, 1200);
    self.mainScrollView.contentOffset = CGPointMake(0, 10);
    
    //In order to read beacon accelerometer we need to connect to it.
    [self.activityIndicator startAnimating];
    
    [self.beaconConnection startConnection];
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
    if (self.beaconConnection.connectionStatus == ESTConnectionStatusConnected || self.beaconConnection.connectionStatus == ESTConnectionStatusConnecting)
    {
        [self.beaconConnection cancelConnection];
    }
}

- (void)updateDataLabels
{
    self.resetBtn.enabled = YES;
    self.resetBtn.alpha = 1;
    
    if (self.beaconConnection.proximityUUID)
    {
        self.UUIDTextFiled.text = [NSString stringWithFormat:@"%@", [self.beaconConnection.proximityUUID UUIDString]];
        self.UUIDTextFiled.enabled = YES;
    }
    else
    {
        self.UUIDTextFiled.text = @"--";
        self.UUIDTextFiled.enabled = NO;
    }
    
    if (self.beaconConnection.motionProximityUUID)
    {
        self.motinoUUIDTextFiled.text = [NSString stringWithFormat:@"%@", [self.beaconConnection.motionProximityUUID UUIDString]];
    }
    else
    {
        self.motinoUUIDTextFiled.text = @"--";
    }
    
    if (self.beaconConnection.major)
    {
        self.majorTextFiled.text = [NSString stringWithFormat:@"%i", [self.beaconConnection.major unsignedShortValue]];
        self.majorTextFiled.enabled = YES;
    }
    else
    {
        self.majorTextFiled.text = @"--";
        self.majorTextFiled.enabled = NO;
    }
    
    if (self.beaconConnection.minor)
    {
        self.minorTextFiled.text = [NSString stringWithFormat:@"%i", [self.beaconConnection.minor unsignedShortValue]];
        self.minorTextFiled.enabled = YES;
    }
    else
    {
        self.minorTextFiled.text = @"--";
        self.minorTextFiled.enabled = NO;
    }
    
    if (self.beaconConnection.advInterval)
    {
        self.advertisingTextField.text = [NSString stringWithFormat:@"%d", [self.beaconConnection.advInterval unsignedShortValue]];
    }
    else
    {
        self.advertisingTextField.text = @"--";
    }
    
    if (self.beaconConnection.power)
    {
        self.powerTextField.text = [NSString stringWithFormat:@"%i", [self.beaconConnection.power shortValue]];
        self.powerTextField.enabled = YES;
    }
    else
    {
        self.powerTextField.text = @"--";
    }
    
    if (self.beaconConnection.batteryLevel)
    {
        self.batteryLevel.text = [NSString stringWithFormat:@"%i%%", [self.beaconConnection.batteryLevel unsignedCharValue]];
    }
    else
    {
        self.batteryLevel.text = @"--";
    }
    
    if (self.beaconConnection.firmwareVersion)
    {
        self.softwareVersion.text = self.beaconConnection.firmwareVersion;
    }
    else
    {
        self.softwareVersion.text = @"--";
    }
    
    if (self.beaconConnection.hardwareVersion)
    {
        self.hardwareVersion.text = self.beaconConnection.hardwareVersion;
    }
    else
    {
        self.hardwareVersion.text = @"--";
    }
    
    if (self.beaconConnection.macAddress)
    {
        self.mac.text = [NSString stringWithFormat:@"%@", self.beaconConnection.macAddress];
    }
    else
    {
        self.mac.text = @"--";
    }
    
    self.broadcastingSchemeSegment.enabled = YES;
    switch (self.beaconConnection.broadcastingScheme)
    {
        case ESTBroadcastingSchemeUnknown:
            self.broadcastingSchemeSegment.enabled = NO;
            self.broadcastingSchemeSegment.selectedSegmentIndex = UISegmentedControlNoSegment;
            break;
        case ESTBroadcastingSchemeEstimote:
            self.broadcastingSchemeSegment.selectedSegmentIndex = 0;
            break;
        case ESTBroadcastingSchemeIBeacon:
            self.broadcastingSchemeSegment.selectedSegmentIndex = 1;
            break;
        case ESTBroadcastingSchemeEddystoneUID:
            self.broadcastingSchemeSegment.selectedSegmentIndex = 2;
            break;
        case ESTBroadcastingSchemeEddystoneURL:
            self.broadcastingSchemeSegment.selectedSegmentIndex = 3;
            break;
            
        default:
            break;
    }
    
    if (self.beaconConnection.basicPowerMode == ESTBeaconPowerSavingModeOn)
    {
        self.basicPowerModeSwitch.enabled = YES;
        self.basicPowerModeSwitch.on = YES;
    }
    else if (self.beaconConnection.basicPowerMode == ESTBeaconPowerSavingModeOff)
    {
        self.basicPowerModeSwitch.enabled = YES;
        self.basicPowerModeSwitch.on = NO;
    }
    
    if (self.beaconConnection.smartPowerMode == ESTBeaconPowerSavingModeOn)
    {
        self.smartPowerModeSwitch.enabled = YES;
        self.smartPowerModeSwitch.on = YES;
    }
    else if (self.beaconConnection.smartPowerMode == ESTBeaconPowerSavingModeOff)
    {
        self.smartPowerModeSwitch.enabled = YES;
        self.smartPowerModeSwitch.on = NO;
    }
    
    if (self.beaconConnection.estimoteSecureUUIDState == ESTBeaconEstimoteSecureUUIDOn)
    {
        self.secureUUIDSwitch.enabled = YES;
        self.secureUUIDSwitch.on = YES;
    }
    else if (self.beaconConnection.estimoteSecureUUIDState == ESTBeaconEstimoteSecureUUIDOff)
    {
        self.secureUUIDSwitch.enabled = YES;
        self.secureUUIDSwitch.on = NO;
    }
    
    self.conditionalBroadcastingSegment.enabled = YES;
    switch (self.beaconConnection.conditionalBroadcastingState)
    {
        case ESTBeaconConditionalBroadcastingOff:
            self.conditionalBroadcastingSegment.selectedSegmentIndex = 0;
            break;
        case ESTBeaconConditionalBroadcastingMotionOnly:
            self.conditionalBroadcastingSegment.selectedSegmentIndex = 1;
            break;
        case ESTBeaconConditionalBroadcastingFlipToStop:
            self.conditionalBroadcastingSegment.selectedSegmentIndex = 2;
            break;
        default:
            self.conditionalBroadcastingSegment.selectedSegmentIndex = UISegmentedControlNoSegment;
            self.conditionalBroadcastingSegment.enabled = NO;
    }
    
    if (self.beaconConnection.eddystoneNamespace)
    {
        self.eddystoneNamespaceTextField.text = self.beaconConnection.eddystoneNamespace;
    }
    else
    {
        self.eddystoneNamespaceTextField.text = @"--";
    }
    
    if (self.beaconConnection.eddystoneInstance)
    {
        self.eddystoneInstanceTextField.text = self.beaconConnection.eddystoneInstance;
    }
    else
    {
        self.eddystoneInstanceTextField.text = @"--";
    }
    
    if (self.beaconConnection.eddystoneURL)
    {
        self.eddystoneURLTextField.text = self.beaconConnection.eddystoneURL;
    }
    else
    {
        self.eddystoneURLTextField.text = @"--";
    }
}

////////////////////////////////////////////////////////
# pragma mark - UI Button handling

- (IBAction)resetBtnTapped:(id)sender
{    
    __weak typeof(self) selfRef = self;
    [self.beaconConnection resetToFactorySettingsWithCompletion:^(NSError *error)
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
        
        [selfRef updateDataLabels];
    }];
}

- (IBAction)switchBasicPowerModeState:(UISwitch*)sender
{
    self.basicPowerModeSwitch.enabled = NO;
    self.smartPowerModeSwitch.enabled = NO;
    
    __weak typeof(self) selfRef = self;
    [self.beaconConnection writeBasicPowerModeEnabled:sender.isOn
                                           completion:^(BOOL value, NSError *error) {
                                               
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
    [self.beaconConnection writeSmartPowerModeEnabled:sender.isOn
                                           completion:^(BOOL value, NSError *error) {
                                               
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
    
    [self.beaconConnection writeEstimoteSecureUUIDEnabled:sender.isOn
                                               completion:^(BOOL value, NSError *error) {
                                                   
        selfRef.basicPowerModeSwitch.enabled = YES;
        selfRef.smartPowerModeSwitch.enabled = YES;
        selfRef.secureUUIDSwitch.enabled = YES;
        
        if (error)
        {
            selfRef.secureUUIDSwitch.on = !selfRef.secureUUIDSwitch.isOn;
        }
        
    }];
}

- (IBAction)changeConditionalBroadcastingType:(UISegmentedControl *)sender
{
    self.conditionalBroadcastingSegment.enabled = NO;
    
    ESTBeaconConditionalBroadcasting conditionalBroadcasting;
    
    switch ([sender selectedSegmentIndex])
    {
        case 0:
            conditionalBroadcasting = ESTBeaconConditionalBroadcastingOff;
            break;
        case 1:
            conditionalBroadcasting = ESTBeaconConditionalBroadcastingMotionOnly;
            break;
        case 2:
            conditionalBroadcasting = ESTBeaconConditionalBroadcastingFlipToStop;
            break;
        default:
            conditionalBroadcasting = ESTBeaconConditionalBroadcastingUnknown;
    }
    
    if (conditionalBroadcasting)
    {
        __weak typeof(self) selfRef = self;
        [self.beaconConnection writeConditionalBroadcastingType:conditionalBroadcasting
                                                 completion:^(BOOL value, NSError *error)
         {
             selfRef.conditionalBroadcastingSegment.enabled = YES;
             
             if (error)
             {
                 selfRef.conditionalBroadcastingSegment.selectedSegmentIndex = UISegmentedControlNoSegment;
             }
         }];
    }
}

- (IBAction)changeBroadcastingScheme:(UISegmentedControl *)sender
{
    self.broadcastingSchemeSegment.enabled = NO;
    
    ESTBroadcastingScheme broadcastingScheme;
    
    switch ([sender selectedSegmentIndex])
    {
        case 0:
            broadcastingScheme = ESTBroadcastingSchemeEstimote;
            break;
        case 1:
            broadcastingScheme = ESTBroadcastingSchemeIBeacon;
            break;
        case 2:
            broadcastingScheme = ESTBroadcastingSchemeEddystoneUID;
            break;
        case 3:
            broadcastingScheme = ESTBroadcastingSchemeEddystoneURL;
            break;
        default:
            broadcastingScheme = ESTBroadcastingSchemeUnknown;
    }
    
    if (broadcastingScheme)
    {
        __weak typeof(self) selfRef = self;
        [self.beaconConnection writeBroadcastingScheme:broadcastingScheme
                                            completion:^(unsigned short value, NSError *error)
         {
             selfRef.broadcastingSchemeSegment.enabled = YES;
             [self updateDataLabels];
         }];
    }
}

#pragma mark - ESTBeacon connection handling

- (void)beaconConnectionDidSucceed:(ESTBeaconConnection *)connection
{
    [self.activityIndicator stopAnimating];
    self.activityIndicator.alpha = 0.;
    self.activityLabel.text = @"Connected!";
    
    [self enableView:YES];
    [self updateDataLabels];
}

- (void)beaconConnection:(ESTBeaconConnection *)connection didFailWithError:(NSError *)error
{
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
    [self updateDataLabels];
}

#pragma mark - UITextField delgate

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    if (textField == self.majorTextFiled)
    {
        unsigned short newMajor = (unsigned short)[self.majorTextFiled.text intValue];
        
        [self.beaconConnection writeMajor:newMajor completion:^(unsigned short major, NSError *error)
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
        
        [self.beaconConnection writeMinor:newMinor completion:^(unsigned short minor, NSError *error)
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
        [self.beaconConnection writeProximityUUID:textField.text completion:^(NSString *value, NSError *error)
        {
            if (error)
            {
                NSLog(@"Error UUID write: %@", error.localizedDescription);
            }
            
            self.UUIDTextFiled.text = [NSString stringWithFormat:@"%@", value];
            self.motinoUUIDTextFiled.text = [self.beaconConnection.motionProximityUUID UUIDString];
        }];
    }
    else if (textField == self.advertisingTextField)
    {
        [self.beaconConnection writeAdvInterval:[textField.text integerValue] completion:^(unsigned short value, NSError *error)
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
        [self.beaconConnection writePower:[textField.text integerValue] completion:^(ESTBeaconPower power, NSError *error)
        {
            if (error)
            {
                NSLog(@"Error Power write: %@", error.localizedDescription);
            }
            
            self.powerTextField.text = [NSString stringWithFormat:@"%tx", power];
        }];
    }
    else if (textField == self.eddystoneInstanceTextField)
    {
        [self.beaconConnection writeEddystoneInstance:self.eddystoneInstanceTextField.text
                                         completion:^(NSString *value, NSError *error) {
                                             
                                             if (error)
                                             {
                                                 NSLog(@"Error eddystoneInstance write: %@", error.localizedDescription);
                                             }
                                             
                                             self.eddystoneInstanceTextField.text = value;
                                             
                                         }];
    }
    else if (textField == self.eddystoneNamespaceTextField)
    {
        [self.beaconConnection writeEddystoneHexNamespace:self.eddystoneNamespaceTextField.text
                                         completion:^(NSString *value, NSError *error) {
                                             
                                             if (error)
                                             {
                                                 NSLog(@"Error eddystoneNamespace write: %@", error.localizedDescription);
                                             }
                                             
                                             self.eddystoneNamespaceTextField.text = value;
                                             
                                         }];
    }
    else if (textField == self.eddystoneURLTextField)
    {
        [self.beaconConnection writeEddystoneURL:self.eddystoneURLTextField.text
                                    completion:^(NSString *value, NSError *error) {
                                              
                                              if (error)
                                              {
                                                  NSLog(@"Error eddystoneURI write: %@", error.localizedDescription);
                                              }
                                              
                                              self.eddystoneURLTextField.text = value;
                                              
                                          }];
    }
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

@end
