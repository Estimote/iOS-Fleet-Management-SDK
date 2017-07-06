//
//  Copyright © 2016 Estimote. All rights reserved.
//

#import "ESTStyle.h"

#import <UIKit/UIKit.h>
#import "ESTStyleSheet.h"

@implementation ESTStyle

// MARK: - Singleton

+ (ESTStyle *)sharedInstance
{
    static ESTStyle *sharedInstance = nil;
    @synchronized(self)
    {
        if (sharedInstance == nil)
        {
            sharedInstance = [[self alloc] init];
        }
    }
    return sharedInstance;
}

- (id)init
{
    if (self = [super init])
    {
        _shouldStyleNavigationBar = YES;
        _shouldStyleStatusBar = YES;
    }
    return self;
}

// MARK: - Applying style - Public

- (void)apply
{
    if (self.shouldStyleNavigationBar) { [self applyNavigationBarStyle]; }
    if (self.shouldStyleStatusBar) { [self applyStatusBarStyle]; }
        
    return;
}

// MARK: - Applying style - Private

- (void)applyNavigationBarStyle
{
    [[UINavigationBar appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName: [UIColor whiteColor],
            NSFontAttributeName: [UIFont systemFontOfSize:17]}];
    [[UINavigationBar appearance] setBarTintColor:[ESTStyleSheet darkGreyBarColor]];
    [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
}

- (void)applyStatusBarStyle
{
    [UIApplication sharedApplication].statusBarStyle = UIStatusBarStyleLightContent;
}

@end
