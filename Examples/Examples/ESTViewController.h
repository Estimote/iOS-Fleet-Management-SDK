//
//  ESTViewController.h
//  Examples
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ESTViewController : UIViewController

@property (nonatomic, strong) IBOutlet UIButton *proximityDemoButton;
@property (nonatomic, strong) IBOutlet UIButton *distanceDemoButton;
@property (nonatomic, strong) IBOutlet UIButton *notificationDemoButton;

- (IBAction)showProximityDemo:(id)sender;
- (IBAction)showDistanceDemo:(id)sender;
- (IBAction)showNotificationDemo:(id)sender;

@end
