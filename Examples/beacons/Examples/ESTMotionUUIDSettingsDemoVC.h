//
//  ESTMotionUUIDSettingsDemoVC.h
//  Examples
//
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ESTBeacon.h"

@interface ESTMotionUUIDSettingsDemoVC : UIViewController <ESTBeaconDelegate>

- (id)initWithBeacon:(ESTBeacon*)beacon;

@end
