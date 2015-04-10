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
@property (nonatomic, strong) ESTCloudManager *cloudManager;

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
    // ESTCloudManager is responsible for assinging
    // GPS location to the beacons
    self.cloudManager = [ESTCloudManager new];
    
    // inoked method will automaticaly collect current GPS location
    // and send it to Estimote Cloud
    [self.cloudManager assignCurrentGPSLocationToBeacon:self.beacon
                                             completion:^(id result, NSError *error)
    {
         if (!error)
         {
             // Assigned location is delevered in completion block
             CLLocation *location = (CLLocation *)result;
             
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
