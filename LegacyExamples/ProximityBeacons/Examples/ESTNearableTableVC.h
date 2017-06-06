//
//  ESTBeaconTableVC.h
//  DistanceDemo
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>

/*
 * Lists all Estimote beacons in range and returns selected beacon.
 */
@interface ESTNearableTableVC : UITableViewController

/*
 * Selected beacon is returned on given completion handler.
 */
- (id)initWithCompletion:(void (^)(id))completion;

@end
