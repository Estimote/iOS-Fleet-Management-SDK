//
//  DetailViewController.m
//  AccelerometerExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 05.01.2015.
//  Copyright (c) 2015 Estimote Inc. All rights reserved.
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
    NSString *orientationString = @"";
    if (!nearable.isMoving)
    {
        switch (nearable.orientation)
        {
            case ESTNearableOrientationHorizontal:
                orientationString = @"Sticker is on its back";
                break;
            case ESTNearableOrientationHorizontalUpsideDown:
                orientationString = @"Sticker is on its front";
                break;
            case ESTNearableOrientationVertical:
                orientationString = @"Sticker is on its legs";
                break;
            case ESTNearableOrientationVerticalUpsideDown:
                orientationString = @"Sticker is on its head";
                break;
            case ESTNearableOrientationLeftSide:
                orientationString = @"Sticker is on its left side";
                break;
            case ESTNearableOrientationRightSide:
                orientationString = @"Sticker is on its right side";
                break;
            case ESTNearableOrientationUnknown:
                orientationString = @"Sticker orientation unknown";
                break;
                
            default:
                break;
        }
    }
    else
    {
        orientationString = @"Sticker is moving";
    }
    
    self.orientationLabel.text = orientationString;
    
    self.accelerometerLabel.text = [NSString stringWithFormat:@"x axis: %ldmG \n y axis: %ldmG \n z axis: %ldmG \n",
                                    (long) nearable.xAcceleration,
                                    (long) nearable.yAcceleration,
                                    (long) nearable.zAcceleration];
}

@end
