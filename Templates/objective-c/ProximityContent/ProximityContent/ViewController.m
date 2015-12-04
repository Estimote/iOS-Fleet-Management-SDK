//
//  ViewController.m
//  ProximityContent
//

#import "ViewController.h"

#import "EstimoteCloudBeaconDetails.h"
#import "EstimoteCloudBeaconDetailsFactory.h"
#import "ProximityContentManager.h"

@interface ViewController () <ProximityContentManagerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UIImageView *image;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;

@property (nonatomic) ProximityContentManager *proximityContentManager;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self.activityIndicator startAnimating];

    self.proximityContentManager = [[ProximityContentManager alloc]
        initWithBeaconIDs:@[
            // TODO: replace with UUIDs, majors and minors of your own beacons
            [[BeaconID alloc] initWithUUIDString:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D" major:1 minor:1],
            [[BeaconID alloc] initWithUUIDString:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D" major:2 minor:2],
            [[BeaconID alloc] initWithUUIDString:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D" major:3 minor:3]
        ]
        beaconContentFactory:[EstimoteCloudBeaconDetailsFactory new]];
    self.proximityContentManager.delegate = self;
    [self.proximityContentManager startContentUpdates];
}

- (void)proximityContentManager:(ProximityContentManager *)proximityContentManager didUpdateContent:(id)content {
    [self.activityIndicator stopAnimating];
    [self.activityIndicator removeFromSuperview];

    EstimoteCloudBeaconDetails *beaconDetails = content;
    if (beaconDetails) {
        self.view.backgroundColor = beaconDetails.backgroundColor;
        self.label.text = [NSString stringWithFormat:@"You're in %@'s range!", beaconDetails.beaconName];
        self.image.hidden = NO;
    } else {
        self.view.backgroundColor = EstimoteCloudBeaconDetails.neutralColor;
        self.label.text = @"No beacons in range.";
        self.image.hidden = YES;
    }
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
