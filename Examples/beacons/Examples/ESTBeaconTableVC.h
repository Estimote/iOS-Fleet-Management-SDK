//
//  ESTBeaconTableVC.h
//  DistanceDemo
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ESTBeacon.h"

typedef enum : int
{
    ESTScanTypeBluetooth,
    ESTScanTypeBeacon
    
} ESTScanType;

/*
 * Lists all Estimote beacons in range and returns selected beacon.
 */
@interface ESTBeaconTableVC : UITableViewController

/*
 * Selected beacon is returned on given completion handler.
 */
- (id)initWithScanType:(ESTScanType)scanType completion:(void (^)(ESTBeacon *))completion;

@end
