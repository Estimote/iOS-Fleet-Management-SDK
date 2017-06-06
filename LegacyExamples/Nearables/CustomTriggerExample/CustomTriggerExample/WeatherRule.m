//
//  WeatherRule.m
//  CustomTriggerExample
//
//  Created by Grzegorz Krukiewicz-Gacek on 07.01.2015.
//  Copyright (c) 2015 Estimote Inc. All rights reserved.
//

#import "WeatherRule.h"
#import <CoreLocation/CoreLocation.h>

/* 
 * If the set of rules delivered in EstimoteSDK is not enough for you, you can easily create your own rules.
 * Than, you can include them in the array of rules you use to initialize an ESTTrigger object.
 *
 * If you want to create a custom rule that takes advantage of nearable data, your rule should be a subclass of ESTNearableRule.
 * If you want to create a rule that takes data from a different source (for example: web api, time, other device) 
 * your rule should be a subclass of ESTRule.
 */
@interface WeatherRule () <CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, copy) void (^locationCompletion)(CLLocation *, NSError *);

@end


@implementation WeatherRule

/*
 * When creating your custom rule it is good to create nice readable initializers
 */
+ (instancetype)currentLocationTemperatureGraterThan:(double)value
{
    WeatherRule *rule = [WeatherRule new];
    rule.minValue = @(value);
    return rule;
}

+ (instancetype)currentLocationTemperatureLowerThan:(double)value
{
    WeatherRule *rule = [WeatherRule new];
    rule.maxValue = @(value);
    return rule;
}

/*
 * When creating your rule, -(void)update is the method you want to override. 
 * It will be called every time, a ESTTrigger is woken up, so that your rules
 * can be checked even when your app is in the background!
 *
 * Depending on the data your custom rule uses, you should change the STATE property to YES or NO.
 * Based on that ESTTrigger will decide if it should change it's state. 
 * If such change happens, you will be informed about it by your ESTTriggerManager instance through
 * - (void)triggerManager:(ESTTriggerManager *)manager triggerChangedState:(ESTTrigger *)trigger 
 * delegate method.
 */
- (void)update
{
    [super update];
    
    __weak WeatherRule *weakSelf = self;
    [self getCurrentLocationWithCompletion:^(CLLocation *location, NSError *error) {
       
        if (error)
        {
            weakSelf.state = NO;
            return;
        }
        
        [weakSelf getTemperatureForLocation:location withCompletion:^(double temperature, NSError *error) {
           
            if (error)
            {
                weakSelf.state = NO;
                return;
            }
            
            if (self.minValue)
            {
                if (temperature >= [self.minValue doubleValue])
                {
                    weakSelf.state = YES;
                    return;
                }
                else
                {
                    weakSelf.state = NO;
                    return;
                }
            }
            else if (self.maxValue)
            {
                if (temperature <= [self.maxValue doubleValue])
                {
                    weakSelf.state = YES;
                    return;
                }
                else
                {
                    weakSelf.state = NO;
                    return;
                }
            }
        }];
    }];
}

// Getting temperature

- (void)getTemperatureForLocation:(CLLocation *)location
                   withCompletion:(void (^)(double temperature, NSError *error))completion
{
    /*
     * We use the openweathermap api to fetch weather data for our current location.
     */
    NSURL *currentLocationWeatherURL =
    [NSURL URLWithString:[NSString stringWithFormat:@"http://api.openweathermap.org/data/2.5/weather?lat=%.5f&lon=%.5f",
                                         location.coordinate.latitude, location.coordinate.longitude]];
    
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *dataTask =
    [session dataTaskWithURL:currentLocationWeatherURL
           completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        
               NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
               double currentTemperature = [[[json objectForKey:@"main"] objectForKey:@"temp"] doubleValue];
               currentTemperature = currentTemperature - 272; //Kelvin to Celsius conversion
               
               if (completion)
               {
                   completion(currentTemperature, error);
               }
    }];
    
    [dataTask resume];
}

// Getting current location

- (void)getCurrentLocationWithCompletion:(void (^)(CLLocation *location, NSError *error))completion
{
    self.locationCompletion = completion;
    if (!self.locationManager)
    {
        self.locationManager = [CLLocationManager new];
        self.locationManager.delegate = self;
        
        [self.locationManager requestAlwaysAuthorization];
    }
    
    [self.locationManager startUpdatingLocation];
}

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
{
    [self.locationManager stopUpdatingLocation];
    if (self.locationCompletion)
    {
        CLLocation *currentLocation = [locations firstObject];
        self.locationCompletion(currentLocation, nil);
        self.locationCompletion = nil;
    }
}

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error
{
    [self.locationManager stopUpdatingLocation];
    if (self.locationCompletion)
    {
        self.locationCompletion(nil, error);
        self.locationCompletion = nil;
    }
}

@end
