//
// Please report any problems with this app template to contact@estimote.com
//

#import <Foundation/Foundation.h>

#import "BeaconContentFactory.h"
#import "BeaconDetails.h"
#import "BeaconID.h"

@interface BeaconDetailsStaticFactory : NSObject <BeaconContentFactory>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithStaticContent:(NSDictionary<BeaconID *, BeaconDetails *> *)staticContent NS_DESIGNATED_INITIALIZER;

@end
