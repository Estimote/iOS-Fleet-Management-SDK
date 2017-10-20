//
// Please report any problems with this app template to contact@estimote.com
//

#import "ViewController.h"
#import "CloudManager.h"
#import "ProximityManager.h"

@interface ViewController () <ProximityManagerDelegate>

@property (nonatomic, strong) ProximityManager *proximityManager;
@property (nonatomic, strong) CloudManager *cloudManager;

@property (nonatomic, strong) NSMutableDictionary<NSString *, UIView *> *zoneViewByBeaconIdentifier;
@property (nonatomic, strong) NSArray<NSString *> *beaconIdentifiers;

@property (weak, nonatomic) IBOutlet UIStackView *stackView;
@property (weak, nonatomic) IBOutlet UIView *noBeaconsView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    /** TODO: Make sure your beacons have Estimote Monitoring feature set enabled:
     https://community.estimote.com/hc/en-us/articles/226144728
     */
    
    /** TODO: Replace with identifiers of your beacons.
     You can find identifiers of your beacon at https://cloud.estimote.com/#/beacons
     */
    self.beaconIdentifiers = @[@"B34C0N-1-CL0UD-1D3NT1F13R",
                               @"B34C0N-2-CL0UD-1D3NT1F13R",
                               @"B34C0N-3-CL0UD-1D3NT1F13R"];
    
    self.zoneViewByBeaconIdentifier = [NSMutableDictionary new];
    self.cloudManager = [CloudManager new];
    
    // Step 1: Pre-fetch content related to your beacons
    __weak ViewController *weakSelf = self;
    [self.cloudManager fetchColorsForBeaconsWithIdentifiers:self.beaconIdentifiers
                                                 completion:^(BOOL success, NSDictionary<NSString *, UIColor *> *colorByIdentifier)
     {
         if (!success || !colorByIdentifier) {
             [weakSelf presentFetchingColorsFailedAlert];
             return;
         }
         
         [weakSelf addBeaconZoneViewsForBeaconColorIdentifier:colorByIdentifier];
         
         // Step 2: Start monitoring proximity of your beacons
         weakSelf.proximityManager = [ProximityManager new];
         weakSelf.proximityManager.delegate = weakSelf;
         [weakSelf.proximityManager startMonitoringProximityOfBeaconsWithIdentifiers:weakSelf.beaconIdentifiers];
     }];
}

#pragma mark - ProximityManagerDelegate

- (void)proximityManager:(ProximityManager *)manager didUpdateBeaconsInRange:(NSArray<NSString *> *)identifiers {
    
    // Step 3: Update UI dependant on which beacons are in range
    [self updateBeaconZoneViewsWithBeaconIdentifiersInRange:identifiers];
}

- (void)proximityManager:(ProximityManager *)manager didFailWithError:(NSError *)error {
    [self presentMonitoringFailedAlert];
}

#pragma mark - UI-related methods

- (void)addBeaconZoneViewsForBeaconColorIdentifier:(NSDictionary<NSString *, UIColor *> *)colorByIdentifier {
    
    for (NSString *identifier in colorByIdentifier.allKeys) {
        
        UIView *zoneView = [UIView new];
        zoneView.translatesAutoresizingMaskIntoConstraints = false;
        zoneView.backgroundColor = colorByIdentifier[identifier];
        
        UIImageView *beaconImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Beacon"]];
        beaconImageView.contentMode = UIViewContentModeScaleAspectFit;
        beaconImageView.translatesAutoresizingMaskIntoConstraints = false;
        [zoneView addSubview:beaconImageView];
        
        UILabel *identifierLabel = [UILabel new];
        identifierLabel.translatesAutoresizingMaskIntoConstraints = false;
        identifierLabel.textAlignment = NSTextAlignmentCenter;
        identifierLabel.font = [UIFont boldSystemFontOfSize:18.0];
        identifierLabel.numberOfLines = 0;
        identifierLabel.textColor = UIColor.whiteColor;
        identifierLabel.text = identifier;
        [zoneView addSubview:identifierLabel];
        
        // Setup constraints
        NSArray<NSLayoutConstraint *> *verticalAlignmentConstraints = [NSLayoutConstraint constraintsWithVisualFormat: @"V:|-24-[beacon]-8@999-[identifier]-|"
                                                                                                              options: NSLayoutFormatAlignAllCenterX
                                                                                                              metrics: nil
                                                                                                                views: @{@"beacon": beaconImageView, @"identifier": identifierLabel}];
        [NSLayoutConstraint activateConstraints:verticalAlignmentConstraints];
        [[beaconImageView.centerXAnchor constraintEqualToAnchor:zoneView.centerXAnchor] setActive:true];
        [identifierLabel setContentHuggingPriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisVertical];
        [identifierLabel setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisVertical];
        
        self.zoneViewByBeaconIdentifier[identifier] = zoneView;
        [self.stackView addArrangedSubview:zoneView];
        [self hide:true viewIfNeeded:zoneView];
    }
    
}

- (void)updateBeaconZoneViewsWithBeaconIdentifiersInRange:(NSArray<NSString *> *)identifiersInRange {
    [UIView animateWithDuration:0.2 animations:^{
        
        BOOL thereAreBeaconsInRange = identifiersInRange.count != 0;
        [self hide:thereAreBeaconsInRange viewIfNeeded:self.noBeaconsView];
        
        for (NSString *identifier in self.beaconIdentifiers) {
            UIView *zoneView;
            if ((zoneView = self.zoneViewByBeaconIdentifier[identifier]) == nil) { return; }
            
            BOOL identifierIsNotInRange = ![identifiersInRange containsObject:identifier];
            [self hide:identifierIsNotInRange viewIfNeeded:zoneView];
        }
    }];
}

- (void)hide:(BOOL)shouldBeHidden viewIfNeeded:(UIView *)view {
    if (view.isHidden != shouldBeHidden) {
        [view setHidden:shouldBeHidden];
    }
}

- (void)presentMonitoringFailedAlert {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle: @"Monitoring failed" message: @"Make sure bluetooth is on and the app has permission to use it." preferredStyle: UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil]];
    [self presentViewController:alert animated:true completion:nil];
}

- (void)presentFetchingColorsFailedAlert {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle: @"Fetching colors failed" message: @"Check your internet connection, App ID and App Token." preferredStyle: UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil]];
    [self presentViewController:alert animated:true completion:nil];
}

@end
