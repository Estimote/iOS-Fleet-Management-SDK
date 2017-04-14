//
//  Copyright © 2016 Estimote. All rights reserved.
//

#import "ESTButton.h"
#import "ESTStylesheet.h"

@implementation ESTButton

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self)
    {
        self.layer.borderWidth = 2.0;
        self.layer.cornerRadius = 4.0;
        self.filled = NO;
    }
    return self;
}

- (void)awakeFromNib
{
    [super awakeFromNib];
    
    self.layer.borderWidth = 2.0;
    self.layer.cornerRadius = 4.0;
    
    // if not previously set in interface builder
    if (!self.filled) {
        self.filled = NO;
    }
}

- (void)setFilled:(BOOL)filled
{
    _filled = filled;

    if (_filled)
    {
        self.backgroundColor       = [ESTStyleSheet purplePinkButtonColor];
        self.layer.borderColor     = [[ESTStyleSheet purplePinkButtonColor] CGColor];
        [self setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [self setTitleColor:[UIColor colorWithRed:128/255.0f green:52/255.0f blue:108/255.0f alpha:1.0f]
                   forState:UIControlStateHighlighted];
    }
    else
    {
        self.backgroundColor       = [UIColor clearColor];
        self.layer.borderColor     = [[ESTStyleSheet purplePinkButtonColor] CGColor];
        [self setTitleColor:[ESTStyleSheet purplePinkButtonColor] forState:UIControlStateNormal];
        [self setTitleColor:[UIColor colorWithRed:224/255.0f green:205/255.0f blue:218/255.0f alpha:1.0f]
                   forState:UIControlStateHighlighted];
    }
    
    // Set common title color for disabled state
    [self setTitleColor: [UIColor lightGrayColor] forState:UIControlStateDisabled];
}

- (void)layoutSubviews
{
    [super layoutSubviews];

    if (self.titleLabel.text
        && self.titleLabel.font.pointSize > 20
        && [self.titleLabel.font.fontName isEqualToString:@"SlatePro-Bk"])
    {
        self.titleLabel.attributedText = [[NSAttributedString alloc]
                initWithString:self.titleLabel.text
                    attributes:@{ NSBaselineOffsetAttributeName : @-2 }];
    }
    else if (self.titleLabel.text
        && [self.titleLabel.font.fontName isEqualToString:@"SlatePro-Bk"])
    {
        self.titleLabel.attributedText = [[NSAttributedString alloc]
                                          initWithString:self.titleLabel.text
                                          attributes:@{ NSBaselineOffsetAttributeName : @-1 }];
    }

}

@end
