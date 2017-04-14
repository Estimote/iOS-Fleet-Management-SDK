//
// Please report any problems with this app template to contact@estimote.com
//

#import "ProximityContentManager.h"

#import "BeaconContentFactory.h"
#import "NearestBeaconManager.h"

@interface ProximityContentManager () <NearestBeaconManagerDelegate>

@property (nonatomic) id<BeaconContentFactory> beaconContentFactory;
@property (nonatomic) NearestBeaconManager *nearestBeaconManager;

@end

@implementation ProximityContentManager

- (instancetype)initWithBeaconRegions:(NSArray *)beaconRegions beaconContentFactory:(id<BeaconContentFactory>)beaconContentFactory {
    self = [super init];
    if (self) {
        self.beaconContentFactory = beaconContentFactory;
        self.nearestBeaconManager = [[NearestBeaconManager alloc] initWithBeaconRegions:beaconRegions];
        self.nearestBeaconManager.delegate = self;
    }
    return self;
}

- (instancetype)initWithBeaconIDs:(NSArray *)beaconIDs beaconContentFactory:(id<BeaconContentFactory>)beaconContentFactory {
    NSMutableArray *beaconRegions = [[NSMutableArray alloc] initWithCapacity:beaconIDs.count];
    for (BeaconID *beaconID in beaconIDs) {
        [beaconRegions addObject:beaconID.asBeaconRegion];
    }
    return [self initWithBeaconRegions:beaconRegions beaconContentFactory:beaconContentFactory];
}

- (void)startContentUpdates {
    [self.nearestBeaconManager startNearestBeaconUpdates];
}

- (void)stopContentUpdates {
    [self.nearestBeaconManager stopNearestBeaconUpdates];
}

- (void)nearestBeaconManager:(NearestBeaconManager *)nearestBeaconManager didUpdateNearestBeaconID:(BeaconID *)beaconID {
    if (beaconID) {
        [self.beaconContentFactory contentForBeaconID:beaconID completion:^(id content) {
            [self.delegate proximityContentManager:self didUpdateContent:content];
        }];
    } else {
        [self.delegate proximityContentManager:self didUpdateContent:nil];
    }
}

@end
