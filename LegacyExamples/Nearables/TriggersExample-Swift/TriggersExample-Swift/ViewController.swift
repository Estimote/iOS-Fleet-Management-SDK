//
//  ViewController.swift
//  TriggersExample-Swift
//
//  Created by Grzegorz Krukiewicz-Gacek on 23.12.2014.
//  Copyright (c) 2014 Estimote Inc. All rights reserved.
//

import UIKit

class ViewController: UIViewController, ESTTriggerManagerDelegate, UIPickerViewDataSource, UIPickerViewDelegate {
    
    @IBOutlet var firstHourPicker:UIPickerView!
    @IBOutlet var secondHourPicker:UIPickerView!
    @IBOutlet var reminderSwitch:UISwitch!
    
    var triggerManager:ESTTriggerManager!
    
    let forgotBagTriggerId:String = "forgotBagTriggerId"

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        self.firstHourPicker.dataSource     = self
        self.firstHourPicker.delegate       = self
        self.secondHourPicker.dataSource    = self
        self.secondHourPicker.delegate      = self
    
        self.reminderSwitch.addTarget(self, action:"reminderSwitchStateChanged:", forControlEvents: UIControlEvents.ValueChanged)
    }
    
    func startReminderTrigger() {
        
        /*
        * Now that the user turned on the reminder, it's a good ocasion to ask him for
        * permission to display notifications.
        */
        let notificationType    = UIUserNotificationType.Alert | UIUserNotificationType.Badge | UIUserNotificationType.Sound
        let settings            = UIUserNotificationSettings(forTypes: notificationType, categories: nil)
        if (UIApplication.sharedApplication().respondsToSelector("registerUserNotificationSettings:")) {
            UIApplication.sharedApplication().registerUserNotificationSettings(settings)
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
        let firstHour   = Int32(self.firstHourPicker.selectedRowInComponent(0))
        let secondHour  = Int32(self.secondHourPicker.selectedRowInComponent(0))
        
        let goingToWorkRule = ESTDateRule.hourBetween(firstHour, and: secondHour)
        let insideCarRule   = ESTProximityRule.inRangeOfNearableType(ESTNearableType.Car)
        let noBagRule       = ESTProximityRule.outsideRangeOfNearableType(ESTNearableType.Bag)
        
        let forgotBagTrigger = ESTTrigger(rules: [goingToWorkRule, insideCarRule, noBagRule], identifier: self.forgotBagTriggerId)
        
        if self.triggerManager == nil {
            self.triggerManager = ESTTriggerManager()
            self.triggerManager.delegate = self
        }
        self.triggerManager.startMonitoringForTrigger(forgotBagTrigger)
    }
    
    func stopReminderTrigger() {
        
        self.triggerManager.stopMonitoringForTriggerWithIdentifier(self.forgotBagTriggerId)
    }
    
    //MARK: UISwitch
    
    func reminderSwitchStateChanged(sender:AnyClass) {
        
        if (self.reminderSwitch.on == true) {
            self.startReminderTrigger()
        }
        else {
            self.stopReminderTrigger()
        }
    }
    
    //MARK: UIPickerView
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        
        return 1
    }
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        
        return 24
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        
        return "\(row)"
    }
    
    //MARK: ESTTriggerManager delegate
    
    func triggerManager(manager: ESTTriggerManager!, triggerChangedState trigger: ESTTrigger!) {
        
        if (trigger.identifier == self.forgotBagTriggerId) {
        
            if (trigger.state == true) {
                
                println("You forgot your bag!")
                
                let notification = UILocalNotification()
                notification.alertBody = "You forgot your bag!"
                UIApplication.sharedApplication().presentLocalNotificationNow(notification)
            }
        }
    }
}

