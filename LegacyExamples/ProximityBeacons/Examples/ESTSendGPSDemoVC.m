//
//  ESTSendGPSDemoVC.m
//  Examples
//
//  Created by Marcin Klimek on 25/03/15.
//  Copyright (c) 2015 com.estimote. All rights reserved.
//

#import "ESTSendGPSDemoVC.h"
#import <MapKit/MapKit.h>

@interface ESTSendGPSDemoVC ()

@property (nonatomic, strong) IBOutlet MKMapView *mapView;

@property (nonatomic, strong) CLBeacon *beacon;

@end

@implementation ESTSendGPSDemoVC

- (id)initWithBeacon:(CLBeacon*)beacon
{
    self = [super init];
    if (self)
    {
        self.beacon = beacon;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"GPS Location";
    
    [self assignGPSLocation];
}

- (void)assignGPSLocation
{
    // Request object will automatically collect current GPS location
    // and send it to Estimote Cloud
    
    ESTRequestAssignGPSLocation *request = [[ESTRequestAssignGPSLocation alloc] initWithBeacon:self.beacon
                                                                                      location:nil];
    
    [request sendRequestWithCompletion:^(CLLocation *location, NSError *error) {
        
        if (!error)
        {
            // We can show it easily on Map View
            MKPointAnnotation *annotation = [[MKPointAnnotation alloc] init];
            annotation.coordinate = CLLocationCoordinate2DMake(location.coordinate.latitude,
                                                               location.coordinate.longitude);
            annotation.title = @"Beacon Location";
            annotation.subtitle = [NSString stringWithFormat:@"(%i, %i)",
                                   [self.beacon.major unsignedShortValue],
                                   [self.beacon.minor unsignedShortValue]];
            [self.mapView addAnnotation:annotation];
            
            MKMapRect zoomRect = MKMapRectNull;
            MKMapPoint annotationPoint = MKMapPointForCoordinate(annotation.coordinate);
            MKMapRect pointRect = MKMapRectMake(annotationPoint.x, annotationPoint.y, 0.1, 0.1);
            zoomRect = MKMapRectUnion(zoomRect, pointRect);
            
            [self.mapView setVisibleMapRect:zoomRect animated:YES];
            [self.mapView selectAnnotation:annotation animated:FALSE];
        }
        else
        {
            // GPS coordinates assigning error occured
            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Location assign error!"
                                                                message:error.localizedDescription
                                                               delegate:nil
                                                      cancelButtonTitle:@"OK"
                                                      otherButtonTitles: nil];
            [alertView show];
        }
    }];
}


@end
