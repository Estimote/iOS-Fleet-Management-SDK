//
//  ESTConfig.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 20/11/14.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ESTConfig : NSObject

/**
 * Sets App ID and App Token, enabling communication with the Estimote Cloud API.
 *
 * You can find your API App ID and API App Token in the Account Settings section of the Estimote Cloud.
 *
 * @param appID The API App ID.
 * @param appToken The API App Token.
 */
+ (void)setupAppID:(NSString*)appID andAppToken:(NSString*)appToken;

/**
 * Checks if App ID and App Token were set.
 */
+ (BOOL)isAuthorized;

/**
 *  Enables analytics requests on Enter/Exit monitoring events. Analytics data
 *  is collected in the Estimote Cloud.
 *
 *  @param enable flag indicating if analytics should be enabled
 */
+ (void)enableAnalytics:(BOOL)enable;

/**
 *  Indicates current state of analytics.
 *
 *  @return flag that indicates if analytics is enabled
 */
+ (BOOL)isAnalyticsEnabled;


@end
