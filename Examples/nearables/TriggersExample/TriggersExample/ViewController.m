//
//  ViewController.m
//  TriggersExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 23.12.2014.
//  Copyright (c) 2014 Estimote Inc. All rights reserved.
//

#import "ViewController.h"
#import <EstimoteSDK/EstimoteSDK.h>

#define FORGOT_BAG_TRIGGER_ID @"forgotBagTriggerId"

@interface ViewController () <ESTTriggerManagerDelegate, UIPickerViewDataSource, UIPickerViewDelegate>

@property (nonatomic, strong) ESTTriggerManager *triggerManager;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    self.firstHourPicker.dataSource     = self;
    self.firstHourPicker.delegate       = self;
    self.secondHourPicker.dataSource    = self;
    self.secondHourPicker.delegate      = self;
    
    [self.reminderSwitch addTarget:self action:@selector(reminderSwitchStateChanged:) forControlEvents:UIControlEventValueChanged];
}

- (void)startReminderTrigger
{
    /*
     * Now that the user turned on the reminder, it's a good ocasion to ask him for 
     * permission to display notifications.
     */
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)])
    {
        [[UIApplication sharedApplication] registerUserNotificationSettings:
         [UIUserNotificationSettings settingsForTypes:
          UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }
    
    /*
     * When the switch changes it's state to on, first we take the selected hours from pickerViews.
     *
     * Than we create rules that will define a situation when, because of the time, you are probably going to work,
     * you enter your car, you don't have your bag with you.
     *
     * Next, we create a trigger object that is defined by those rules and a specific identifier.
     *
     * Finally we create the triggerManager (if it doesn't exist) tell the triggerManager to 
     * start monitoring for this trigger.
     * This means, triggerManager will send you and update every time the trigger changes it's state.
     */
    int firstHour   = (int)[self.firstHourPicker selectedRowInComponent:0];
    int secondHour  = (int)[self.secondHourPicker selectedRowInComponent:0];
    
    ESTDateRule *goingToWorkRule    = [ESTDateRule hourBetween:firstHour and:secondHour];
    ESTProximityRule *insideCarRule = [ESTProximityRule inRangeOfNearableType:ESTNearableTypeCar];
    ESTProximityRule *noBagRule     = [ESTProximityRule outsideRangeOfNearableType:ESTNearableTypeBag];
    
    ESTTrigger *forgotBagTrigger = [[ESTTrigger alloc] initWithRules:@[goingToWorkRule, insideCarRule, noBagRule]
                                                          identifier:FORGOT_BAG_TRIGGER_ID];
    
    if (!self.triggerManager)
    {
        self.triggerManager = [ESTTriggerManager new];
        self.triggerManager.delegate = self;
    }
    [self.triggerManager startMonitoringForTrigger:forgotBagTrigger];
}

- (void)stopReminderTrigger
{
    /*
     * When the switch changes it's state to off, the only thing we have to do is
     * tell the triggerManager to stop monitoring for trigger with specific identifier.
     */
    [self.triggerManager stopMonitoringForTriggerWithIdentifier:FORGOT_BAG_TRIGGER_ID];
}

#pragma mark - UISwitch

- (void)reminderSwitchStateChanged:(id)sender
{
    if (self.reminderSwitch.isOn)
    {
        [self startReminderTrigger];
    }
    else
    {
        [self stopReminderTrigger];
    }
}

#pragma mark - UIPickerView

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return 24;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    return [NSString stringWithFormat:@"%ld", (long)row];
}

#pragma mark - ESTTriggerManager delegate

- (void)triggerManager:(ESTTriggerManager *)manager triggerChangedState:(ESTTrigger *)trigger
{
    /*
     * In this delegate method we receive updates about states of all triggers that are currently being monitored.
     */
    if ([trigger.identifier isEqualToString:FORGOT_BAG_TRIGGER_ID] && trigger.state == YES)
    {
        NSLog(@"You forgot your bag!");
        
        UILocalNotification *notification = [UILocalNotification new];
        notification.alertBody = @"You forgot your bag!";
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
}

@end
