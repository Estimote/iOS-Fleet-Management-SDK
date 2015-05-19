//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.2.4
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTNearable.h"

@class ESTTrigger;

@protocol ESTTriggerDelegate <NSObject>

@optional
- (void)triggerDidChangeState:(ESTTrigger *)trigger;

@end

/**
 * The `ESTTrigger` class defines the trigger object that is a part of Estimote Trigger Engine. Trigger allows to create real life situation definition based on particular set of rules. Trigger should be passed to `<ESTTriggerManager>` class object to start monitoring for its state changes.
 */
@interface ESTTrigger : NSObject

@property (nonatomic, weak) id <ESTTriggerDelegate> delegate;

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
 *  @param rules      Array of `<ESTRule>` rule objects
 *  @param identifier Unique identifier of trigger
 *
 *  @return create trigger object
 */
- (instancetype)initWithRules:(NSArray *)rules identifier:(NSString *)identifier;

@end
