//
//  BeaconDetailsStaticFactory.h
//  ProximityContent
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
