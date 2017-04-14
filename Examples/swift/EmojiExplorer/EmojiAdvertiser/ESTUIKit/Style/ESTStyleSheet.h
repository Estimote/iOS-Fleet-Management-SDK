//
//  Copyright © 2016 Estimote. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Represents a style sheet that provides information on design elements such as colors and fonts.
 */
@interface ESTStyleSheet : NSObject

// TODO(Wiktor): move it from here later
+ (void)playWallBumpSound;

+ (UIColor *)purpleButtonColor;
+ (UIColor *)purplePinkButtonColor;
+ (UIColor *)mintCocktailButtonColor;
+ (UIColor *)greyTextColor;
+ (UIColor *)lightGreyTextColor;
+ (UIColor *)darkGreyBarColor;
+ (UIColor *)whiteTextColor;
+ (UIColor *)wallColor;
+ (UIColor *)windowColor;
+ (UIColor *)traceColor;
+ (UIColor *)scanAnimationCirclesColor;
+ (UIColor *)errorRedColor;

+ (UIColor *)mintCocktailBackgroundColor;
+ (UIColor *)lighterMintCocktailBackgroundColor;

+ (UIFont *)systemFontForInstructions;
+ (UIFont *)systemFontForButton;
+ (UIFont *)smallParagraphFontWithSize;
+ (UIFont *)regularParagraphFontWithSize;
+ (UIFont *)buttonFontWithSize;
+ (UIFont *)topBarButtonFontWithSize;
+ (UIFont *)topBarTitleFontWithSize;
+ (UIFont *)listItemMainFontWithSize;
+ (UIFont *)listItemSubFontWithSize;
+ (UIFont *)listItemDateFontWithSize;
+ (UIFont *)mapBoundarySizeFontWithSize;
+ (UIFont *)textFieldDescriptionFontWithSize;
+ (UIFont *)textFieldContentFontWithSize;
+ (UIFont *)navigationViewPositionLabelFontWithSize;

// Screen dimensions. Screen is green upper green content part and lower explanation text area.
+ (NSInteger)largerExplanationHeight;
+ (NSInteger)smallerExplanationHeight;

// Table views.
+ (NSInteger)tableViewHeaderHeightSmall;
+ (NSInteger)tableViewHeaderHeightSmaller;

// UI helpers.
+ (NSString *)formattedStringForBatteryLifetime:(NSNumber *)lifetime;


@end
