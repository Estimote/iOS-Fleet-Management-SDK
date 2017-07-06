//
//  DetailViewController.h
//  AccelerometerExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 05.01.2015.
//  Copyright (c) 2015 Estimote Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>

@interface DetailViewController : UIViewController

@property (nonatomic, strong) ESTNearable *nearable;

@property (nonatomic, weak) IBOutlet UILabel *typeLabel;
@property (nonatomic, weak) IBOutlet UILabel *orientationLabel;
@property (nonatomic, weak) IBOutlet UILabel *accelerometerLabel;

@end

