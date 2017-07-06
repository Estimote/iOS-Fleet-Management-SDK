//
//  EKVSavingVC.m
//  KeyValueApp
//
//  Created by Filip Chwastowski on 24/10/2016.
//  Copyright © 2016 Estimote. All rights reserved.
//

#import "EKVSavingVC.h"
#import "EKVReadingVC.h"

typedef NS_ENUM(NSInteger, EKVStatus) {
    EKVStatusDisconnected,
    EKVStatusConnecting,
    EKVStatusSaving
};

@interface EKVSavingVC () <ESTDeviceConnectableDelegate, UITextViewDelegate>
@property (nonatomic, weak) IBOutlet UITextView *textView;
@property (nonatomic, weak) IBOutlet UIButton *saveButton;
@property (nonatomic, weak) IBOutlet UIActivityIndicatorView *spinner;
@property (nonatomic, weak) IBOutlet UILabel *statusLabel;
@property (nonatomic, assign) EKVStatus status;
@end

@implementation EKVSavingVC

- (void)viewDidLoad {
    [super viewDidLoad];
    UIBarButtonItem *backButton = [[UIBarButtonItem alloc] initWithTitle:@"Back"
                                                                   style:UIBarButtonItemStylePlain
                                                                  target:nil
                                                                  action:nil];
    [self.navigationItem setBackBarButtonItem:backButton];
    
    // Do any additional setup after loading the view.
    self.textView.layer.cornerRadius = 3.f;
    self.textView.layer.borderColor = [UIColor colorWithRed:.1 green:1. blue:.1 alpha:1.].CGColor;
    self.saveButton.layer.cornerRadius = 3.f;
    self.status = EKVStatusDisconnected;
    [self updateUI];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)saveToBeacon:(id)sender {
    if (self.textView.text.length) {
        self.status = EKVStatusConnecting;
        [self updateUI];
        
        self.selectedBeacon.delegate = self;
        [self.selectedBeacon connect];
    } else {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Oops!"
                                                                       message:@"Nothing to save! Type in text you want to save to Estimote Storage."
                                                                preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK"
                                                         style:UIAlertActionStyleCancel
                                                       handler:nil];
        [alert addAction:action];
        [self presentViewController:alert animated:YES completion:nil];
    }
}

#pragma  mark - ESTDeviceConnectableDelegate

- (void)estDeviceConnectionDidSucceed:(ESTDeviceConnectable *)device {
    __weak typeof (self) welf = self;
    NSDictionary *storageDictionary = @{ @"content": self.textView.text };
    self.status = EKVStatusSaving;
    [self updateUI];
    [self.selectedBeacon.storage saveStorageDictionary:storageDictionary
                                        withCompletion:^(NSError * _Nullable error) {
                                            if (!error) {
                                                [welf.selectedBeacon disconnect];
                                                NSLog(@"Saved text view's content under key \"content\"");
                                            } else {
                                                NSLog(@"Something went wrong with saving: %@", error.localizedDescription);
                                            }
                                        }];
}

-(void)estDevice:(ESTDeviceConnectable *)device didFailConnectionWithError:(NSError *)error {
    NSLog(@"Failed to connect due to: %@", error.localizedDescription);
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Ooops!"
                                                                   message:@"Failed to connect :( Try again!"
                                                            preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK"
                                                     style:UIAlertActionStyleCancel
                                                   handler:nil];
    [alert addAction:action];
    [self presentViewController:alert animated:YES completion:nil];
    self.status = EKVStatusDisconnected;
    [self updateUI];
}

- (void)estDevice:(ESTDeviceConnectable *)device didDisconnectWithError:(NSError *)error {
    NSLog(@"Disconnected due to: %@", error.localizedDescription);
    if (!error) {
        [NSTimer scheduledTimerWithTimeInterval:2.0 target:self selector:@selector(goNext) userInfo:nil repeats:NO];
    }
}

#pragma mark - UI

- (void)updateUI {
    switch (self.status) {
        case EKVStatusDisconnected: {
            self.textView.alpha = 1.0;
            self.textView.userInteractionEnabled = YES;
            self.saveButton.hidden = NO;
            self.spinner.hidden = YES;
            self.statusLabel.text = nil;
            self.statusLabel.hidden = NO;
        }
            break;
        case EKVStatusConnecting: {
            self.textView.alpha = 0.5;
            self.textView.userInteractionEnabled = NO;
            self.saveButton.hidden = YES;
            self.spinner.hidden = NO;
            [self.spinner startAnimating];
            self.statusLabel.text = @"Connecting...";
            self.statusLabel.hidden = NO;
        }
            break;
        case EKVStatusSaving: {
            self.textView.alpha = 0.5;
            self.textView.userInteractionEnabled = NO;
            self.saveButton.hidden = YES;
            self.spinner.hidden = NO;
            [self.spinner startAnimating];
            self.statusLabel.text = @"Saving...";
            self.statusLabel.hidden = NO;
        }
        default:
            break;
    }
}

#pragma mark - IBActions

- (IBAction)goRead:(id)sender {
    [self.selectedBeacon disconnect];
}

- (IBAction)dismissKeyboard:(id)sender {
    [self.textView resignFirstResponder];
}

- (void)goNext {
    [self performSegueWithIdentifier:@"goRead" sender:self];
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"goRead"]) {
        EKVReadingVC *vc = (EKVReadingVC *)segue.destinationViewController;
        vc.selectedBeacon = self.selectedBeacon;
    }
}

@end
