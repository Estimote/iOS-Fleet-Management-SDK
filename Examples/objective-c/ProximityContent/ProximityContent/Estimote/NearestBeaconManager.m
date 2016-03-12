//
//  NearestBeaconManager.m
//  ProximityContent
//

#import "NearestBeaconManager.h"

@interface NearestBeaconManager () <ESTBeaconManagerDelegate>

@property (copy, nonatomic) NSArray *beaconRegions;

@property (nonatomic) ESTBeaconManager *beaconManager;

@property (nonatomic) BeaconID *nearestBeaconID;
@property (nonatomic) BOOL firstEventSent;

@end

@implementation NearestBeaconManager

- (instancetype)initWithBeaconRegions:(NSArray *)beaconRegions {
    self = [super init];
    if (self) {
        self.beaconRegions = beaconRegions;

        self.beaconManager = [ESTBeaconManager new];
        self.beaconManager.delegate = self;
        self.beaconManager.returnAllRangedBeaconsAtOnce = YES;
        [self.beaconManager requestWhenInUseAuthorization];

        self.firstEventSent = false;
    }
    return self;
}

- (void)startNearestBeaconUpdates {
    for (CLBeaconRegion *beaconRegion in self.beaconRegions) {
        [self.beaconManager startRangingBeaconsInRegion:beaconRegion];
    }
}

- (void)stopNearestBeaconUpdates {
    for (CLBeaconRegion *beaconRegion in self.beaconRegions) {
        [self.beaconManager stopRangingBeaconsInRegion:beaconRegion];
    }
}

- (void)beaconManager:(id)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region {
    CLBeacon *nearestBeacon = beacons.firstObject;

    if (!(nearestBeacon.beaconID == nil && self.nearestBeaconID == nil)
            || ![nearestBeacon.beaconID isEqual:self.nearestBeaconID]
            || !self.firstEventSent) {
        self.nearestBeaconID = nearestBeacon.beaconID;
        [self.delegate nearestBeaconManager:self didUpdateNearestBeaconID:self.nearestBeaconID];
        self.firstEventSent = true;
    }
}

- (void)beaconManager:(id)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if (status == kCLAuthorizationStatusDenied || status == kCLAuthorizationStatusRestricted) {
        NSLog(@"Location Services are disabled for this app, which means it won't be able to detect beacons.");
    }
}

- (void)beaconManager:(id)manager rangingBeaconsDidFailForRegion:(CLBeaconRegion *)region withError:(NSError *)error {
    NSLog(@"Ranging failed for region: %@. Make sure that Bluetooth and Location Services are on, and that Location Services are allowed for this app. Beacons require a Bluetooth Low Energy compatible device: <http://www.bluetooth.com/Pages/Bluetooth-Smart-Devices-List.aspx>. Note that the iOS simulator doesn't support Bluetooth at all. The error was: %@", region.identifier, error);
}


@end
