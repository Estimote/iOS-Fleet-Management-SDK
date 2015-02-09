//
//  ESTTrigger.h
//  EstimoteSDK
//
//  Version: 2.4.0
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTNearable.h"

@class ESTTrigger;

@protocol ESTTriggerDelegate <NSObject>

@optional
- (void)triggerDidChangeState:(ESTTrigger *)trigger;

@end

/**
 * The ESTTrigger class defines the trigger object that is a part of Estimote Trigger Engine. Trigger allows to create real life situation definition based on particular set of rules. Trigger should be passed to ESTTriggerManager class object to start monitoring for its state changes.
 */
@interface ESTTrigger : NSObject

@property (nonatomic, assign) id <ESTTriggerDelegate> delegate;

/**
 *  Set of rules that should be fulfilled to change trigger state to YES. In all other cases state value is NO.
 */
@property (nonatomic, strong, readonly) NSArray *rules;

/**
 *  Unique trigger identifier allows to reference particular object.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  State of trigger. Its value is YES when all defined rules are fulfilled.
 */
@property (nonatomic, assign, readonly) BOOL state;

/**
 *  Initialization method that allows to create trigger obejct.
 *
 *  @param rules      Array of ESTRule rule objects
 *  @param identifier Unique identifier of trigger
 *
 *  @return create trigger object
 */
- (instancetype)initWithRules:(NSArray *)rules identifier:(NSString *)identifier;

@end
