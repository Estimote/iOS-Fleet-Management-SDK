//
//  EKVReadingVC.m
//  KeyValueApp
//
//  Created by Filip Chwastowski on 24/10/2016.
//  Copyright © 2016 Estimote. All rights reserved.
//

#import "EKVReadingVC.h"

@interface EKVReadingVC () <ESTDeviceConnectableDelegate, ESTDeviceManagerDelegate>
@property (nonatomic, weak) IBOutlet UITextView *textView;
@property (nonatomic) ESTDeviceManager *manager;
@property (weak, nonatomic) IBOutlet UIButton *startButton;
@property (weak, nonatomic) IBOutlet UIButton *finishButton;
@end

@implementation EKVReadingVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIBarButtonItem *backButton = [[UIBarButtonItem alloc] initWithTitle:@"Back"
                                                                   style:UIBarButtonItemStylePlain
                                                                  target:nil
                                                                  action:nil];
    [self.navigationItem setBackBarButtonItem:backButton];
    
    // Do any additional setup after loading the view.
    self.textView.layer.cornerRadius = 3.f;
    self.startButton.layer.cornerRadius = 3.f;
    self.finishButton.layer.cornerRadius = 3.f;
    self.finishButton.hidden = YES;
    self.selectedBeacon.delegate = self;
    self.manager = [ESTDeviceManager new];
    self.manager.delegate = self;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - ESTDeviceConnectableDelegate

- (void)estDeviceConnectionDidSucceed:(ESTDeviceConnectable *)device {
    __weak typeof (self) welf = self;
    [self.selectedBeacon.storage readStorageDictionaryWithCompletion:^(NSDictionary * _Nullable value, NSError * _Nullable error) {
        if (!error) {
            NSString *key = value.allKeys[0];
            welf.textView.text = value[key];
            welf.textView.hidden = NO;
            welf.textView.alpha = 1.0;
            welf.finishButton.hidden = NO;
        }
        else {
            NSLog(@"Couldn't read: %@", error.localizedDescription);
        }
    }];
}

- (void)estDevice:(ESTDeviceConnectable *)device didDisconnectWithError:(NSError *)error {
    NSLog(@"Disconnected: %@", error.localizedDescription);
}

- (void)estDevice:(ESTDeviceConnectable *)device didFailConnectionWithError:(NSError *)error {
    NSLog(@"Failed to connect: %@", error.localizedDescription);
}

#pragma mark - ESTDeviceManagerDelegate

- (void)deviceManager:(ESTDeviceManager *)manager didDiscoverDevices:(NSArray<ESTDevice *> *)devices {
    if (devices.count && devices[0].rssi > -50 && !self.selectedBeacon) {
        NSLog(@"Let's read something!");
        self.selectedBeacon = (ESTDeviceLocationBeacon *)devices[0];
        self.selectedBeacon.delegate = self;
        [self.selectedBeacon connectForStorageRead];
        self.textView.text = @"Reading Storage...";
        self.textView.hidden = NO;
        self.textView.alpha = 0.5;
    } else {
        NSLog(@"Found devices: %lu", (unsigned long)devices.count);
    }
}

- (void)deviceManagerDidFailDiscovery:(ESTDeviceManager *)manager {
    NSLog(@"Failed discovery");
}

#pragma mark - IBAction

- (IBAction)startRanging:(id)sender {
    ESTDeviceFilterLocationBeacon *filter = [[ESTDeviceFilterLocationBeacon alloc] initWithIdentifier:self.selectedBeacon.identifier];
    [self.manager startDeviceDiscoveryWithFilter:filter];
    self.startButton.hidden = YES;
    self.selectedBeacon = nil;
}

- (IBAction)finishDemo:(id)sender {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"How you like'em apples?"
                                                                   message:@"If you like it just dance for 5 minutes!"
                                                            preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK"
                                                     style:UIAlertActionStyleCancel
                                                   handler:nil];
    [alert addAction:action];
    [self presentViewController:alert animated:YES completion:nil];
}


@end
