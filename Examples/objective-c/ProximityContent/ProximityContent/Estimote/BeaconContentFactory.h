//
// Please report any problems with this app template to contact@estimote.com
//

#import "BeaconID.h"

@protocol BeaconContentFactory <NSObject>

- (void)contentForBeacon:(CLBeacon *)beacon completion:(void (^)(id content))completion;

@end
