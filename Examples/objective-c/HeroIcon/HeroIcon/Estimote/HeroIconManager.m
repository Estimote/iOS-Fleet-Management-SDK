//
//  HeroIconManager.m
//  HeroIcon
//

#import "HeroIconManager.h"

@interface HeroIconManager () <ESTBeaconManagerDelegate>

@property (nonatomic) ESTBeaconManager *beaconManager;

@end

@implementation HeroIconManager

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.beaconManager = [ESTBeaconManager new];
        self.beaconManager.delegate = self;
        [self.beaconManager requestAlwaysAuthorization];
    }
    return self;
}

- (void)enableHeroIconForBeaconID:(BeaconID *)beaconID {
    [self.beaconManager startMonitoringForRegion:beaconID.asBeaconRegion];
}

- (void)beaconManager:(id)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if (status == kCLAuthorizationStatusDenied || status == kCLAuthorizationStatusRestricted) {
        NSLog(@"Location Services are disabled for this app, which means it won't be able to detect beacons.");
    }
}

- (void)beaconManager:(id)manager monitoringDidFailForRegion:(CLBeaconRegion *)region withError:(NSError *)error {
    NSLog(@"Monitoring failed for region: %@. Make sure that Bluetooth and Location Services are on, and that Location Services are allowed for this app. Beacons require a Bluetooth Low Energy compatible device: <http://www.bluetooth.com/Pages/Bluetooth-Smart-Devices-List.aspx>. Note that the iOS simulator doesn't support Bluetooth at all. The error was: %@", region.identifier, error);
}

@end
