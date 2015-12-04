//
//  EstimoteCloudBeaconDetails.m
//  ProximityContent
//

#import "EstimoteCloudBeaconDetails.h"

@implementation EstimoteCloudBeaconDetails

- (instancetype)initWithBeaconName:(NSString *)beaconName backgroundColor:(UIColor *)backgroundColor {
    self = [super init];
    if (self) {
        _beaconName = [beaconName copy];
        _backgroundColor = backgroundColor;
    }
    return self;
}

+ (UIColor *)neutralColor {
    return [UIColor colorWithRed: 160/255.0 green: 169/255.0 blue: 172/255.0 alpha: 1.0];
}

@end
