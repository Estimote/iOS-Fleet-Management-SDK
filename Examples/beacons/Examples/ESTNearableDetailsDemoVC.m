//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTNearableDetailsDemoVC.h"


@interface ESTNearableDetailsDemoVC () <ESTDeviceConnectableDelegate>

@property (nonatomic, strong) ESTDeviceNearable *device;

@property (nonatomic, strong) IBOutlet UITextField *advertisingTextField;
@property (nonatomic, strong) IBOutlet UITextField *powerTextField;

@property (nonatomic, strong) IBOutlet UITextView *identifier;
@property (nonatomic, strong) IBOutlet UILabel *softwareVersion;
@property (nonatomic, strong) IBOutlet UILabel *hardwareVersion;

@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;

@end


@implementation ESTNearableDetailsDemoVC

- (instancetype)initWithNearableDevice:(ESTDeviceNearable *)device
{
    self = [super init];
    
    if (self)
    {
        /**
         *  Initialize view with ESTDeviceNearable
         */
        
        _device = device;
        _device.delegate = self;
    }
    
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"Nearable Details";
    
    /**
     *  Perform connection to the device
     */
    [self.device connect];
    
    /**
     *  Display identifier of the device
     */
    self.identifier.text = self.device.identifier;
    
    self.activityLabel.text = @"Connecting ...";
    [self.activityIndicator startAnimating];
    self.activityIndicator.alpha = 1.;
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [self.device disconnect];
}

- (void)estDeviceConnectionDidSucceed:(ESTDeviceConnectable *)device
{
    self.activityLabel.text = @"Connected!";
    self.activityIndicator.alpha = 0.;
    [self.activityIndicator stopAnimating];
    
    /**
     * With nearables we introduce new model for settings read/write operations. Each settings 
     * has its own dedicated class now. If you want to read a setting you should create an instance
     * of setting you are interested in (for read you don't need to initialize it with value) and then 
     * perform read `readSettings:` method of ESTDeviceNearable object. After operation completion
     * block provided in init method is fired.
    */
    
    ESTNearableSettingAdvertisingIntervalStill *interval = [[ESTNearableSettingAdvertisingIntervalStill alloc] initWithCompletion:^(NSNumber *advertisingInterval, NSError *error) {

        self.advertisingTextField.text = [NSString stringWithFormat:@"%i", [advertisingInterval intValue]];
    }];
    
    ESTNearableSettingBroadcastingPower *power = [[ESTNearableSettingBroadcastingPower alloc] initWithCompletion:^(NSNumber *power, NSError *error) {

        self.powerTextField.text = [NSString stringWithFormat:@"%i", [power intValue]];
    }];
    
    ESTNearableSettingAppVersion *appVersion = [[ESTNearableSettingAppVersion alloc] initWithCompletion:^(NSString *version, NSError *error) {

        self.softwareVersion.text = version;
    }];
    
    ESTNearableSettingHardwareVersion *hardwareVersion = [[ESTNearableSettingHardwareVersion alloc] initWithCompletion:^(NSString *version, NSError *error) {
        self.hardwareVersion.text = version;
    }];
    
    [self.device readSettings:@[power, appVersion, interval, hardwareVersion]];
}

- (void)estDevice:(ESTDeviceConnectable *)device didFailConnectionWithError:(NSError *)error
{
    /**
     *  Report connection error
     */
    
    self.activityLabel.text = @"Connection Failed!";
    self.activityIndicator.alpha = 0.;
    
    UIAlertView* errorView = [[UIAlertView alloc] initWithTitle:@"Connection error"
                                                        message:error.localizedDescription
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
    
    [errorView show];
}

- (void)estDevice:(ESTDeviceConnectable *)device didDisconnectWithError:(NSError *)error
{
    /**
     *  Update UI after disconnect.
     */
    
    self.activityLabel.text = @"Disconnected!";
    self.activityIndicator.alpha = 0.;
    
    self.powerTextField.text = @"";
    self.advertisingTextField.text = @"";
    
    self.hardwareVersion.text = @"";
    self.softwareVersion.text = @"";
}

#pragma mark - UITextField delgate

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    /**
     * When writing settings in new model you should create instance of setting class and provided value
     * you want to set in initialization method `initWithValue:completion:` and perform `writeSettings:`
     * method of `ESTDeviceNerable` object. After operation completio block provided in init method is fired.
     */
    
    if (textField == self.advertisingTextField)
    {
        ESTNearableSettingAdvertisingIntervalStill *interval = [[ESTNearableSettingAdvertisingIntervalStill alloc] initWithValue:@([textField.text intValue])
                                                                                                                      completion:^(NSNumber *advertisingInterval, NSError *error) {

            self.advertisingTextField.text = [NSString stringWithFormat:@"%i", [advertisingInterval intValue]];
        }];
        
        [self.device writeSetting:interval];
    }
    else if (textField == self.powerTextField)
    {
        ESTNearableSettingBroadcastingPower *power = [[ESTNearableSettingBroadcastingPower alloc] initWithValue:[textField.text intValue]
                                                                                                     completion:^(NSNumber *power, NSError *error) {
            
            self.powerTextField.text = [NSString stringWithFormat:@"%i", [power intValue]];
        }];
        
        [self.device writeSetting:power];
    }
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    
    return YES;
}

@end
