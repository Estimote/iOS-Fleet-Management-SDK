//
//  ESTTriggerRule.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTTrigger.h"

/**
 * The ESTRule class defines single rule of ESTTrigger object. Each rule has state value that indicates if it was fulfilled or not.
 */
@interface ESTRule : NSObject

/**
 *  Current state of the rule.
 */
@property (nonatomic, assign) BOOL state;

/**
 *  Method that is invoked by trigger manager object to update state of the rule.
 *  
 *  When creating custom rule, this method should be implemented to update state property of this class, 
 *  based on developer defined conditions.
 */
- (void)update;

@end
