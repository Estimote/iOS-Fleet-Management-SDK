//
//  Copyright © 2016 Estimote. All rights reserved.
//

#ifndef ESTStyle_h
#define ESTStyle_h

#import <Foundation/Foundation.h>

/**
 This class is used for managing the style and appearance of Estimote apps.
 
 @Note
 For status bar style to be applied, set "View controller-based status bar appearance" property in Info.plist as NO.
 */
@interface ESTStyle : NSObject

@property BOOL shouldStyleNavigationBar;

@property BOOL shouldStyleStatusBar;

+ (ESTStyle *)sharedInstance;

- (void)apply;

@end

#endif /* ESTStyle_h */
