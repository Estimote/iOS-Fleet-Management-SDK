//
// Please report any problems with this app template to contact@estimote.com
//

#import "BeaconID.h"

@implementation BeaconID

- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor {
    self = [super init];
    if (self) {
        _proximityUUID = proximityUUID;
        _major = major;
        _minor = minor;
    }
    return self;
}

- (instancetype)initWithUUIDString:(NSString *)UUIDString major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor {
    return [self initWithProximityUUID:[[NSUUID alloc] initWithUUIDString:UUIDString] major:major minor:minor];
}

- (NSString *)asString {
    return [NSString stringWithFormat:@"%@:%hu:%hu", self.proximityUUID.UUIDString, self.major, self.minor];
}

- (CLBeaconRegion *)asBeaconRegion {
    return [[CLBeaconRegion alloc] initWithProximityUUID:self.proximityUUID major:self.major minor:self.minor identifier:self.asString];
}

- (BOOL)isEqualToBeaconID:(BeaconID *)beaconID {
    return [self.proximityUUID isEqual:beaconID.proximityUUID] && self.major == beaconID.major && self.minor == beaconID.minor;
}

- (BOOL)isEqual:(id)object {
    if (self == object) {
        return YES;
    }

    if (![object isKindOfClass:[BeaconID class]]) {
        return NO;
    }

    return [self isEqualToBeaconID:(BeaconID *)object];
}

- (NSString *)description {
    return self.asString;
}

- (NSUInteger)hash {
    return self.asString.hash;
}

- (id)copyWithZone:(NSZone *)zone {
    return self; // BeaconID is immutable
}

@end

@implementation CLBeacon (BeaconID)

- (BeaconID *)beaconID {
    return [[BeaconID alloc] initWithProximityUUID:self.proximityUUID major:self.major.unsignedShortValue minor:self.minor.unsignedShortValue];
}

@end
