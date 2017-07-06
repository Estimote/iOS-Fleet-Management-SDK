//
//  DetailViewController.m
//  TemperatureExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 24.12.2014.
//  Copyright (c) 2014 Estimote Inc. All rights reserved.
//

#import "DetailViewController.h"

@interface DetailViewController () <ESTNearableManagerDelegate>

@property (nonatomic, strong) ESTNearableManager *nearableManager;

@end

@implementation DetailViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    self.nearableManager = [ESTNearableManager new];
    self.nearableManager.delegate = self;
    
    [self.nearableManager startRangingForIdentifier:self.nearable.identifier];
    
    self.typeLabel.text = [ESTNearableDefinitions nameForType:self.nearable.type];
}

#pragma mark - ESTNearableManager delegate

- (void)nearableManager:(ESTNearableManager *)manager didRangeNearable:(ESTNearable *)nearable
{
    self.temperatureLabel.text = [NSString stringWithFormat:@"%.1f°C", nearable.temperature];
}

@end
