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

#import "ESTNearableFirmwareUpdateDemoVC.h"


@interface ESTNearableFirmwareUpdateDemoVC () <ESTDeviceConnectableDelegate>

@property (nonatomic, strong) ESTDeviceNearable *device;

@property (nonatomic, strong) IBOutlet UILabel *identifier;
@property (nonatomic, strong) IBOutlet UILabel *progressLabel;
@property (nonatomic, strong) IBOutlet UILabel *activityLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *activityIndicator;

@end


@implementation ESTNearableFirmwareUpdateDemoVC

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
    self.title = @"Nearable Firmware";
    
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
    
    /**
     *  Disconnect device when leaving screen
     */
    [self.device disconnect];
}

- (void)estDeviceConnectionDidSucceed:(ESTDeviceConnectable *)device
{
    self.activityLabel.text = @"Connected!";
    self.activityIndicator.alpha = 0.;
    [self.activityIndicator stopAnimating];
    
    
    /**
     *  Perform device update
     */
    [self.device updateFirmwareWithProgress:^(NSInteger value, NSString * _Nullable description, NSError * _Nullable error) {
        
        /**
         *  Report progress of firmware update
         */
        
        self.progressLabel.text = [NSString stringWithFormat:@"%zd %%", value];
        
    } completion:^(NSError * _Nullable error) {
        
        if (error)
        {
            UIAlertView *errorView = [[UIAlertView alloc] initWithTitle:@"Update error"
                                                                message:error.localizedDescription
                                                               delegate:nil
                                                      cancelButtonTitle:@"OK"
                                                      otherButtonTitles:nil];
            
            [errorView show];
        }
    }];

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
}

@end
