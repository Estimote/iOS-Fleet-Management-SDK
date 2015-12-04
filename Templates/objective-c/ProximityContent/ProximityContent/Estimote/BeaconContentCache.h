//
//  BeaconContentCache.h
//  ProximityContent
//

#import <Foundation/Foundation.h>

#import "BeaconContentFactory.h"
#import "BeaconID.h"

@interface BeaconContentCache : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithBeaconContentFactory:(id<BeaconContentFactory>)beaconContentFactory NS_DESIGNATED_INITIALIZER;

- (void)contentForBeaconID:(BeaconID *)beaconID completion:(void (^)(id content))completion;

@end
