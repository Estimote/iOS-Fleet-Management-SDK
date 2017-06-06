//
// Please report any problems with this app template to contact@estimote.com
//

#import "BeaconDetails.h"

@implementation BeaconDetails

- (instancetype)initWithBeaconName:(NSString *)beaconName backgroundColor:(UIColor *)backgroundColor {
    self = [super init];
    if (self) {
        _beaconName = [beaconName copy];
        _backgroundColor = backgroundColor;
    }
    return self;
}

- (instancetype)initWithBeaconName:(NSString *)beaconName beaconColor:(ESTColor)beaconColor {
    return [self initWithBeaconName:beaconName backgroundColor:[self backgroundColorForBeaconColor:beaconColor]];
}

+ (UIColor *)neutralColor {
    return [UIColor colorWithRed: 160/255.0 green: 169/255.0 blue: 172/255.0 alpha: 1.0];
}

- (UIColor *)backgroundColorForBeaconColor:(ESTColor)beaconColor {
    static NSDictionary *backgroundColors = nil;
    if (backgroundColors == nil) {
        backgroundColors =
        [[NSDictionary alloc] initWithObjectsAndKeys:
         [UIColor colorWithRed: 109/255.0 green: 170/255.0 blue: 199/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorIcyMarshmallow],
         [UIColor colorWithRed:  36/255.0 green:  24/255.0 blue:  93/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorBlueberryPie],
         [UIColor colorWithRed: 155/255.0 green: 186/255.0 blue: 160/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorMintCocktail],
         [UIColor colorWithRed:  84/255.0 green:   0/255.0 blue:  61/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorSweetBeetroot],
         [UIColor colorWithRed: 195/255.0 green: 192/255.0 blue:  16/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorLemonTart],
         [UIColor colorWithRed: 219/255.0 green: 122/255.0 blue: 167/255.0 alpha: 1.0], [NSNumber numberWithInt:ESTColorCandyFloss],
         nil];
    }
    UIColor *backgroundColor = [backgroundColors objectForKey:[NSNumber numberWithInt:beaconColor]];
    if (backgroundColor) {
        return backgroundColor;
    }
    return [BeaconDetails neutralColor];
}

@end
