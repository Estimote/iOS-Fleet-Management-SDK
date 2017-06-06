//
//  Copyright © 2016 Estimote. All rights reserved.
//

#import "ESTStyleSheet.h"
#import <AudioToolbox/AudioToolbox.h>

@implementation ESTStyleSheet

/* Event sounds */
+ (void)playWallBumpSound
{
    static SystemSoundID sound;
    if (!sound)
    {
        NSString *wallBumpPath = [[NSBundle mainBundle] pathForResource:@"wall_bump" ofType:@"wav"];
        NSURL *wallBumpURL = [NSURL fileURLWithPath:wallBumpPath];
        AudioServicesCreateSystemSoundID((__bridge CFURLRef)wallBumpURL, &sound);
    }
    AudioServicesPlaySystemSound(sound);
    AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
}

/* Colors */

+ (UIColor *)purpleButtonColor
{
    return [UIColor colorWithRed:99/255.0f green:0/255.0f blue:74/255.0f alpha:1.0f];
}

+ (UIColor *)purplePinkButtonColor
{
    return [UIColor colorWithRed:172/255.0f green:0/255.0f blue:124/255.0f alpha:1.0];
}

+ (UIColor *)mintCocktailButtonColor
{
    return [UIColor colorWithRed:173.0f/255.0f green:210.0f/255.0f blue:180.0f/255.0f alpha:1.0];
}

+ (UIColor *)greyTextColor
{
    return [UIColor colorWithRed:51/255.0f green:49/255.0f blue:50/255.0f alpha:1.0f];
}

+ (UIColor *)lightGreyTextColor
{
    return [UIColor colorWithRed:0.796 green:0.89 blue:0.839 alpha:1];
}

+ (UIColor *)darkGreyBarColor
{
    return [UIColor colorWithRed:0.388 green:0.388 blue:0.388 alpha:1.00];
}

+ (UIColor *)whiteTextColor
{
    return [UIColor whiteColor];
}

+ (UIColor *)mintCocktailBackgroundColor
{
    return [UIColor colorWithRed:122.0f/255.0f green:176.0f/255.0f blue:146.0f/255.0f alpha:1.000];
}

+ (UIColor *)lighterMintCocktailBackgroundColor
{
    return [UIColor colorWithRed:182.0f/255.0f green:215.0f/255.0f blue:192.0f/255.0f alpha:1.000];
}

+ (UIColor *)wallColor
{
    return [UIColor colorWithRed:90/255.0 green:116/255.0 blue:99/255.0 alpha:1.0];
}

+ (UIColor *)windowColor
{
    return [UIColor colorWithRed:198/255.0 green:232/255.0 blue:249/255.0 alpha:1.0];
}

+ (UIColor *)traceColor
{
    return [UIColor colorWithRed:205/255.0 green:201/255.0 blue:15/255.0 alpha:1.0];
}

+ (UIColor *)scanAnimationCirclesColor
{
    return [UIColor colorWithRed:0.871 green:1 blue:0.918 alpha:1];
}

+ (UIColor *)errorRedColor
{
    return [UIColor colorWithRed:0.906 green:0.31 blue:0.341 alpha:1];
}

/* Elements fonts and sizes */

+ (UIFont *)systemFontForInstructions
{
    return [UIFont systemFontOfSize:15];
}

+ (UIFont *)systemFontForButton
{
    return [UIFont systemFontOfSize:20];
}

+ (UIFont *)regularParagraphFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Light" size:16];
}

+ (UIFont *)smallParagraphFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Light" size:14];
}

+ (UIFont *)buttonFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Book" size:20];
}

+ (UIFont *)topBarButtonFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Light" size:16];
}

+ (UIFont *)topBarTitleFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Roman" size:19];
}

+ (UIFont *)listItemMainFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Roman" size:19];
}

+ (UIFont *)listItemSubFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Light" size:15];
}

+ (UIFont *)listItemDateFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Book" size:11];
}

+ (UIFont *)mapBoundarySizeFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Light" size:11];
}

+ (UIFont *)textFieldDescriptionFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Light" size:17];
}

+ (UIFont *)textFieldContentFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Book" size:15];
}

+ (UIFont *)navigationViewPositionLabelFontWithSize
{
    return [UIFont fontWithName:@"Avenir-Light" size:15];
}

/* Elements dimensions */

+ (NSInteger)largerExplanationHeight {
    return 170;
}

+ (NSInteger)smallerExplanationHeight {
    return 115;
}

+ (NSInteger)tableViewHeaderHeightSmall {
    return 220;
}

+ (NSInteger)tableViewHeaderHeightSmaller {
    return 135;
}

/* UI helpers */

+ (NSString *)formattedStringForBatteryLifetime:(NSNumber *)lifetime {
    
    NSDate *endLifetimeDate = [NSDate dateWithTimeIntervalSinceNow:[lifetime intValue] * 24 * 60 * 60];
    NSCalendarUnit unitFlags = NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear;
    NSCalendar *sysCalendar = [NSCalendar currentCalendar];
    NSDateComponents *breakdownInfo = [sysCalendar components:unitFlags fromDate:[NSDate date]  toDate:endLifetimeDate  options:0];
    
    NSString *formattedString = @"";
    NSString *yearsString = [breakdownInfo year] == 1 ? [NSString stringWithFormat:@"%ld year", (long)[breakdownInfo year]] : [NSString stringWithFormat:@"%ld years", (long)[breakdownInfo year]];
    NSString *monthsString = [breakdownInfo month] == 1 ? [NSString stringWithFormat:@"%ld month", (long)[breakdownInfo month]] : [NSString stringWithFormat:@"%ld months", (long)[breakdownInfo month]];
    NSString *daysString = [breakdownInfo day] == 1 ? [NSString stringWithFormat:@"%ld day", (long)[breakdownInfo day]] : [NSString stringWithFormat:@"%ld days", (long)[breakdownInfo day]];
    
    if ([breakdownInfo year] > 0) {
        formattedString = [formattedString stringByAppendingString:yearsString];
        if ([breakdownInfo month] > 0) {
            formattedString = [formattedString stringByAppendingString:[NSString stringWithFormat:@" %@", monthsString]];
        }
    } else if ([breakdownInfo month] > 0) {
        formattedString = [formattedString stringByAppendingString:monthsString];
        if ([breakdownInfo day] > 0) {
            formattedString = [formattedString stringByAppendingString:[NSString stringWithFormat:@" %@", daysString]];
        }
    } else {
        formattedString = [formattedString stringByAppendingString:daysString];
    }
    
    return formattedString;
}

@end
