//
// Please report any problems with this app template to contact@estimote.com
//

#import "UIColor+Additions.h"

@implementation UIColor (Additions)

+ (UIColor *)colorForEstimoteColor:(ESTColor)estimoteColor {
    switch (estimoteColor) {
        case ESTColorIcyMarshmallow:
            return [UIColor colorWithRed: 109.0/255.0 green: 170.0/255.0 blue: 199.0/255.0 alpha: 1.0];
        case ESTColorBlueberryPie:
            return [UIColor colorWithRed: 36.0/255.0 green: 24.0/255.0 blue: 93.0/255.0 alpha: 1.0];
        case ESTColorCandyFloss:
            return [UIColor colorWithRed: 219.0/255.0 green: 122.0/255.0 blue: 167.0/255.0 alpha: 1.0];
        case ESTColorMintCocktail:
            return [UIColor colorWithRed: 155.0/255.0 green: 186.0/255.0 blue: 160.0/255.0 alpha: 1.0];
        case ESTColorSweetBeetroot:
            return [UIColor colorWithRed: 84.0/255.0 green: 0.0/255.0 blue: 61.0/255.0 alpha: 1.0];
        case ESTColorLemonTart:
            return [UIColor colorWithRed: 195.0/255.0 green: 192.0/255.0 blue: 16.0/255.0 alpha: 1.0];
        case ESTColorCoconutPuff:
            return [UIColor whiteColor];
        default:
            return [UIColor colorWithRed: 160.0/255.0 green: 169.0/255.0 blue: 172.0/255.0 alpha: 1.0];
    }
}

@end
