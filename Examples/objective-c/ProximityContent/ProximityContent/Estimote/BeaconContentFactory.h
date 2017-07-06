//
// Please report any problems with this app template to contact@estimote.com
//

#import "BeaconID.h"

@protocol BeaconContentFactory <NSObject>

- (void)contentForBeaconID:(BeaconID *)beaconID completion:(void (^)(id content))completion;

@end
