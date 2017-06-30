//
// Please report any problems with this app template to contact@estimote.com
//

#import "CachingContentFactory.h"

@interface CachingContentFactory ()

@property (nonatomic, readonly) id<BeaconContentFactory> beaconContentFactory;

@property (nonatomic) NSMutableDictionary *cachedContent;

@end

@implementation CachingContentFactory

- (instancetype)initWithBeaconContentFactory:(id<BeaconContentFactory>)beaconContentFactory {
    self = [super init];
    if (self) {
        _beaconContentFactory = beaconContentFactory;
        _cachedContent = [NSMutableDictionary new];
    }
    return self;
}

- (void)contentForBeacon:(CLBeacon *)beacon completion:(void (^)(id content))completion {
    id content = [self.cachedContent objectForKey:beacon.beaconID];
    if (content) {
        completion(content);
    } else {
        [self.beaconContentFactory contentForBeacon:beacon completion:^(id content) {
            self.cachedContent[beacon.beaconID] = content;
            completion(content);
        }];
    }
}

@end
