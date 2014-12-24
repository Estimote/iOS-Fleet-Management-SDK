//
//  ESTAccelerometerDemoVC.h
//  Examples
//
//  Created by Łukasz Pikor on 24.03.2014.
//  Copyright (c) 2014 com.estimote. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ESTBeacon.h"

@interface ESTAccelerometerDemoVC : UIViewController <ESTBeaconDelegate>

- (id)initWithBeacon:(ESTBeacon*)beacon;

@end
