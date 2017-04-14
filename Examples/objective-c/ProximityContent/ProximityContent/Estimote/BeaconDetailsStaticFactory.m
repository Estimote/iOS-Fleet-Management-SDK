//
// Please report any problems with this app template to contact@estimote.com
//

#import "BeaconDetailsStaticFactory.h"

@interface BeaconDetailsStaticFactory ()

@property (nonatomic, strong) NSDictionary<BeaconID *,BeaconDetails *> *staticContent;

@end

@implementation BeaconDetailsStaticFactory

- (instancetype)initWithStaticContent:(NSDictionary<BeaconID *,BeaconDetails *> *)staticContent {
    self = [super init];
    if (self) {
        _staticContent = staticContent;
    }
    return self;
}

- (void)contentForBeaconID:(BeaconID *)beaconID completion:(void (^)(id))completion {
    BeaconDetails *beaconDetails = [self.staticContent objectForKey:beaconID];
    if (beaconDetails) {
        completion(beaconDetails);
    } else {
        NSLog(@"No static content found for beacon %@, will use default values instead. Make sure there's some content defined for this beacon.", beaconID);
        completion([[BeaconDetails alloc] initWithBeaconName:@"beacon" beaconColor:ESTColorUnknown]);
    }
}

@end
