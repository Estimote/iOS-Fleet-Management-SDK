//
// Please report any problems with this app template to contact@estimote.com
//

#import <EstimoteSDK/ESTRequestBeaconDetails.h>

#import "BeaconDetailsCloudFactory.h"

#import "BeaconDetails.h"

@implementation BeaconDetailsCloudFactory

- (void)contentForBeaconID:(BeaconID *)beaconID completion:(void (^)(id))completion {
    ESTRequestBeaconDetails *beaconDetailsRequest = [[ESTRequestBeaconDetails alloc] initWithProximityUUID:beaconID.proximityUUID major:beaconID.major minor:beaconID.minor];

    [beaconDetailsRequest sendRequestWithCompletion:^(ESTBeaconVO *beaconVO, NSError *error) {
        if (!error) {
            completion([[BeaconDetails alloc] initWithBeaconName:beaconVO.name beaconColor:beaconVO.color]);
        } else {
            NSLog(@"Couldn't fetch data from Estimote Cloud for beacon %@, will use default values instead. Double-check if the app ID and app token provided in the AppDelegate are correct, and if the beacon with such ID is assigned to your Estimote Account. The error was: %@", beaconID, error);
            completion([[BeaconDetails alloc] initWithBeaconName:@"beacon" beaconColor:ESTColorUnknown]);
        }
    }];
}



@end
