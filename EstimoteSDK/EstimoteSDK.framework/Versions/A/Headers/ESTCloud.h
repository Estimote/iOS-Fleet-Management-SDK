//
//  ESTCloud.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 20/01/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTDefinitions.h"
#import "ESTNearable.h"
#import "ESTBeaconVO.h"

@interface ESTCloud : NSObject

- (void)fetchEstimoteNearablesWithCompletion:(ESTArrayCompletionBlock)completion;
- (void)fetchEstimoteBeaconsWithCompletion:(ESTArrayCompletionBlock)completion;
- (void)updateNearable:(ESTNearable *)nearable completion:(ESTObjectCompletionBlock)completion;
- (void)updateNearable:(ESTNearable *)nearable type:(ESTNearableType)type completion:(ESTObjectCompletionBlock)completion;
- (void)getBeaconDetails:(NSString *)beaconUID completion:(ESTObjectCompletionBlock)completion;

@end
