//
//  MonitoringDetailsViewController.h
//  MonitoringExample
//
//  Created by Marcin Klimek on 09/01/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>

@interface MonitoringDetailsViewController : UIViewController <ESTNearableManagerDelegate>

@property (nonatomic, strong) ESTNearableManager *nearableManager;
@property (nonatomic, strong) ESTNearable *nearable;

@end
