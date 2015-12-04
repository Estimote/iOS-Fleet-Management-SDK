//
//  BeaconContentCache.m
//  ProximityContent
//

#import "BeaconContentCache.h"

@interface BeaconContentCache ()

@property (nonatomic, readonly) id<BeaconContentFactory> beaconContentFactory;

@property (nonatomic) NSMutableDictionary *cachedContent;

@end

@implementation BeaconContentCache

- (instancetype)initWithBeaconContentFactory:(id<BeaconContentFactory>)beaconContentFactory {
    self = [super init];
    if (self) {
        _beaconContentFactory = beaconContentFactory;
        _cachedContent = [NSMutableDictionary new];
    }
    return self;
}

- (void)contentForBeaconID:(BeaconID *)beaconID completion:(void (^)(id))completion {
    id content = [self.cachedContent objectForKey:beaconID];
    if (content) {
        completion(content);
    } else {
        [self.beaconContentFactory contentForBeaconID:beaconID completion:^(id content) {
            self.cachedContent[beaconID] = content;
            completion(content);
        }];
    }
}

@end
