//
//  ViewController.m
//  CustomTriggerExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 07.01.2015.
//  Copyright (c) 2015 Estimote Inc. All rights reserved.
//

#import "ViewController.h"
#import "WeatherRule.h"
#import <EstimoteSDK/EstimoteSDK.h>

#define COLD_OUTSIDE_TRIGGER_ID @"coldOutsideTriggerId"
#define HOT_OUTSIDE_TRIGGER_ID  @"hotOutsideTriggerId"

@interface ViewController () <ESTTriggerManagerDelegate>

@property (nonatomic, strong) ESTTriggerManager *triggerManager;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    if (!self.triggerManager)
    {
        self.triggerManager = [ESTTriggerManager new];
        self.triggerManager.delegate = self;
    }
}

- (IBAction)hotOutsideSwitchValueChanged:(id)sender
{
    UISwitch *hotOutsideSwitch = (UISwitch *)sender;
    if (hotOutsideSwitch.isOn)
    {
        /*
         * Now that the user turned on the reminder, it's a good ocasion to ask him for
         * permission to display notifications.
         */
        [self askForNotificationsPermission];
        
        /*
         * When the switch changes it's state to on, first we create rules that will define a situation
         * when you move your shoe (so you are probably going outside) and the weather is hot.
         *
         * For checking the weather we use our great custom rule.
         *
         * Next, we create a trigger object that is defined by those rules and a specific identifier.
         *
         * Finally we tell the triggerManager to start monitoring for this trigger.
         * This means, triggerManager will send you and update every time the trigger changes it's state.
         */
        WeatherRule *hotWeatherRule     = [WeatherRule currentLocationTemperatureGraterThan:25];
        ESTMotionRule *shoeMotionRule   = [ESTMotionRule motionStateEquals:YES forNearableType:ESTNearableTypeShoe];
        
        ESTTrigger *hotTrigger  = [[ESTTrigger alloc] initWithRules:@[hotWeatherRule, shoeMotionRule]
                                                         identifier:HOT_OUTSIDE_TRIGGER_ID];
        [self.triggerManager startMonitoringForTrigger:hotTrigger];
    }
    else
    {
        /*
         * When the switch changes it's state to off, we have to stop monitoring for a specific trigger identifier.
         */
        [self.triggerManager stopMonitoringForTriggerWithIdentifier:HOT_OUTSIDE_TRIGGER_ID];
    }
}

- (IBAction)coldOutsideSwitchValueChanged:(id)sender
{
    UISwitch *coldOutsideSwitch = (UISwitch *)sender;
    if (coldOutsideSwitch.isOn)
    {
        /*
         * Now that the user turned on the reminder, it's a good ocasion to ask him for
         * permission to display notifications.
         */
        [self askForNotificationsPermission];
        
        /*
         * When the switch changes it's state to on, first we create rules that will define a situation 
         * when you move your shoe (so you are probably going outside) and the weather is cold.
         *
         * For checking the weather we use our great custom rule.
         *
         * Next, we create a trigger object that is defined by those rules and a specific identifier.
         *
         * Finally we tell the triggerManager to start monitoring for this trigger.
         * This means, triggerManager will send you and update every time the trigger changes it's state.
         */
        WeatherRule *coldWeatherRule    = [WeatherRule currentLocationTemperatureLowerThan:0];
        ESTMotionRule *shoeMotionRule   = [ESTMotionRule motionStateEquals:YES forNearableType:ESTNearableTypeShoe];
        
        ESTTrigger *coldTrigger  = [[ESTTrigger alloc] initWithRules:@[coldWeatherRule, shoeMotionRule]
                                                         identifier:COLD_OUTSIDE_TRIGGER_ID];
        [self.triggerManager startMonitoringForTrigger:coldTrigger];
    }
    else
    {
        /*
         * When the switch changes it's state to off, we have to stop monitoring for a specific trigger identifier.
         */
        [self.triggerManager stopMonitoringForTriggerWithIdentifier:COLD_OUTSIDE_TRIGGER_ID];
    }
}

- (void)askForNotificationsPermission
{
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)])
    {
        [[UIApplication sharedApplication] registerUserNotificationSettings:
         [UIUserNotificationSettings settingsForTypes:
          UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }
}

#pragma mark - ESTTriggerManager delegate

- (void)triggerManager:(ESTTriggerManager *)manager triggerChangedState:(ESTTrigger *)trigger
{
    /*
     * In this delegate method we receive updates about states of all triggers that are currently being monitored.
     *
     * Depending on the identifier and the trigger state, we decide to show appropriate notification to the user.
     */
    if ([trigger.identifier isEqualToString:COLD_OUTSIDE_TRIGGER_ID])
    {
        if (trigger.state == YES)
        {
            NSLog(@"It's cold!");
            
            UILocalNotification *notification = [UILocalNotification new];
            notification.alertBody = @"It's cold outside! Don't forget to wear warm clothes.";
            [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
        }
    }
    else if ([trigger.identifier isEqualToString:HOT_OUTSIDE_TRIGGER_ID])
    {
        if (trigger.state == YES)
        {
            NSLog(@"It's hot!");
            
            UILocalNotification *notification = [UILocalNotification new];
            notification.alertBody = @"It's hot outside! You should take some water with you.";
            [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
        }
    }
}

@end
