//
//  Copyright © 2016 Estimote. All rights reserved.
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE

/**
 Represents a simple square-shaped button.
 */
@interface ESTButton : UIButton

/**
 Decides whether the button should be filled with a color or just have a colored outline.
 */
@property (nonatomic, assign) IBInspectable BOOL filled;

@end
