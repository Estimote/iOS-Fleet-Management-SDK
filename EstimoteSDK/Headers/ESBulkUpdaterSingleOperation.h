//
//  ESBulkUpdaterSingleOperation.h
//  EstimoteSDK
//
//  Version: 2.2.0
//  Created by Marcin Klimek on 16/10/14.
//  Copyright (c) 2014 Estimote. All rights reserved.

#import "ESTBeacon.h"
#import "ESBeaconUpdateConfig.h"
#import "ESConcurrentOperation.h"
#import "ESBeaconUpdateInfo.h"

/**
 * The ESBulkUpdaterSingleOperationDelegate protocol defines the delegate method used to confirm when ESBulkUpdaterSingleOperation was performed. It provides information about the result of operation.
 */

@protocol ESBulkUpdaterSingleOperationDelegate <NSObject>

/**
 *  Confirms when update operation was performed. Error message is provided 
 *  is something went wrong.
 *
 *  @param operation reference to self
 *  @param error     optional error message if something went wrong
 */
- (void)updatePerformedWithOperation:(id)operation
                               error:(NSError *)error;

@end

/**
 *  Operation that updates single beacon. It is intended to be executed on NSOperationQueue. If you want to executed it manually, read "Executing Operations Manually" chapter from Apple's Concurrency Programming Guide.
 *
 *  Flow of execution:
 *  - connects to a beacon
 *  - updates beacon's properties as defined in given config object
 *  - disconnects from a beacon
 *
 *  In order to get notified when operation finishes, set completionBlock on it.
 */

@interface ESBulkUpdaterSingleOperation : ESConcurrentOperation

@property (nonatomic, strong) id<ESBulkUpdaterSingleOperationDelegate> delegate;

/**
 *  Initialize object with ESBeaconUpdateInfo that describe all the details
 *  for update procedure including beacon and config.
 *
 *  @param beacon Beacon information
 *
 *  @return instance of operation object
 */
- (instancetype)initWithBeaconInfo:(ESBeaconUpdateInfo *)beacon;

/**
 *  Method used to perform opeartion outside of operation queue
 *
 *  @param completion completion block containing reference to operation (self)
 */
- (void)startOperation;

- (ESBeaconUpdateInfo *)beaconInfo;

@end
