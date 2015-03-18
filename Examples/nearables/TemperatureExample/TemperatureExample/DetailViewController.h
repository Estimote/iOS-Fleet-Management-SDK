//
//  DetailViewController.h
//  TemperatureExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 24.12.2014.
//  Copyright (c) 2014 Estimote Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>

@interface DetailViewController : UIViewController

@property (nonatomic, strong) ESTNearable *nearable;

@property (nonatomic, weak) IBOutlet UILabel *temperatureLabel;
@property (nonatomic, weak) IBOutlet UILabel *typeLabel;

@end

