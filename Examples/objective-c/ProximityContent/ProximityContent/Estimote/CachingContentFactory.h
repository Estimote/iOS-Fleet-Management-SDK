//
// Please report any problems with this app template to contact@estimote.com
//

#import <Foundation/Foundation.h>

#import "BeaconContentFactory.h"
#import "BeaconID.h"

@interface CachingContentFactory : NSObject <BeaconContentFactory>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithBeaconContentFactory:(id<BeaconContentFactory>)beaconContentFactory NS_DESIGNATED_INITIALIZER;

- (void)contentForBeaconID:(BeaconID *)beaconID completion:(void (^)(id content))completion;

@end
