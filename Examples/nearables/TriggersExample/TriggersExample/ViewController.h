//
//  ViewController.h
//  TriggersExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 23.12.2014.
//  Copyright (c) 2014 Estimote Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (nonatomic, strong) IBOutlet UIPickerView *firstHourPicker;
@property (nonatomic, strong) IBOutlet UIPickerView *secondHourPicker;
@property (nonatomic, strong) IBOutlet UISwitch *reminderSwitch;

@end

