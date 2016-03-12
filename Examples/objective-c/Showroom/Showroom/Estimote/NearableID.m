//
//  NearableID.m
//  Showroom
//

#import "NearableID.h"

@implementation NearableID

+ (instancetype)IDString:(NSString *)nearableIDString {
    return [[NearableID alloc] initWithNearableIDString:nearableIDString];
}

- (instancetype)initWithNearableIDString:(NSString *)nearableIDString {
    self = [super init];
    if (self) {
        _nearableIDString = nearableIDString;
    }
    return self;
}

- (BOOL)isEqualToNearableID:(NearableID *)nearableID {
    return [self.nearableIDString isEqualToString:nearableID.nearableIDString];
}

- (BOOL)isEqual:(id)object {
    if (self == object) {
        return YES;
    }

    if (![object isKindOfClass:[NearableID class]]) {
        return NO;
    }

    return [self isEqualToNearableID:(NearableID *)object];
}

- (NSString *)description {
    return self.nearableIDString;
}

- (NSUInteger)hash {
    return self.nearableIDString.hash;
}

- (id)copyWithZone:(NSZone *)zone {
    return self; // NearableID is immutable
}

@end
