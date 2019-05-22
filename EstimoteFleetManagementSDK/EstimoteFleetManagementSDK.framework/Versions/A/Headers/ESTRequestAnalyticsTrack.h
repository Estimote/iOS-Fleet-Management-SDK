//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTRequestPostJSON.h"
#import "ESTBeaconDefinitions.h"
#import "ESTAnalyticsEventVO.h"

typedef void(^ESTRequestAnalyticsGroupTrackBlock)(NSError *error);


@interface ESTRequestAnalyticsTrack : ESTRequestPostJSON

- (instancetype)initWithEvents:(NSArray *)events;

- (void)sendRequestWithCompletion:(ESTRequestAnalyticsGroupTrackBlock)completion;

@end
