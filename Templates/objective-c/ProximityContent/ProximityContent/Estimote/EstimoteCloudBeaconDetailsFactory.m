//
//  EstimoteCloudBeaconDetailsFactory.m
//  ProximityContent
//

#import "EstimoteCloudBeaconDetailsFactory.h"

#import "EstimoteCloudBeaconDetails.h"

@interface EstimoteCloudBeaconDetailsFactory ()

- (UIColor *)backgroundColorForBeaconColor:(ESTColor)beaconColor;

@end

@implementation EstimoteCloudBeaconDetailsFactory

- (void)contentForBeaconID:(BeaconID *)beaconID completion:(void (^)(id))completion {
    ESTRequestBeaconDetails *beaconDetailsRequest = [[ESTRequestBeaconDetails alloc] initWithProximityUUID:beaconID.proximityUUID major:beaconID.major minor:beaconID.minor];

    [beaconDetailsRequest sendRequestWithCompletion:^(ESTBeaconVO *beaconVO, NSError *error) {
        if (!error) {
            completion([[EstimoteCloudBeaconDetails alloc] initWithBeaconName:beaconVO.name backgroundColor:[self backgroundColorForBeaconColor:beaconVO.color]]);
        } else {
            NSLog(@"Couldn't fetch data from Estimote Cloud for beacon %@, will use default values instead. Double-check if the app ID and app token provided in the AppDelegate are correct, and if the beacon with such ID is assigned to your Estimote Account. The error was: %@", beaconID, error);
            completion([[EstimoteCloudBeaconDetails alloc] initWithBeaconName:@"beacon" backgroundColor:[self backgroundColorForBeaconColor:ESTColorUnknown]]);
        }
    }];
}

- (UIColor *)backgroundColorForBeaconColor:(ESTColor)beaconColor {
    static NSDictionary *backgroundColors = nil;
    if (backgroundColors == nil) {
        backgroundColors =
        [[NSDictionary alloc] initWithObjectsAndKeys:
         [UIColor colorWithRed: 109/255.0 green: 170/255.0 blue: 199/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorIcyMarshmallow],
         [UIColor colorWithRed:  36/255.0 green:  24/255.0 blue:  93/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorBlueberryPie],
         [UIColor colorWithRed: 155/255.0 green: 186/255.0 blue: 160/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorMintCocktail],
         nil];
    }
    UIColor *backgroundColor = [backgroundColors objectForKey:[NSNumber numberWithInt:beaconColor]];
    if (backgroundColor) {
        return backgroundColor;
    }
    return [EstimoteCloudBeaconDetails neutralColor];
}

@end
