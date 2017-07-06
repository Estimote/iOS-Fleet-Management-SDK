//
// Please report any problems with this app template to contact@estimote.com
//

#import "Product.h"

@implementation Product

- (instancetype)initWithName:(NSString *)name summary:(NSString *)summary {
    self = [super init];
    if (self) {
        _name = [name copy];
        _summary = [summary copy];
    }
    return self;
}

@end
