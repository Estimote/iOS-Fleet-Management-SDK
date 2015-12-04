//
//  EstimoteCloudBeaconDetails.h
//  ProximityContent
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface EstimoteCloudBeaconDetails : NSObject

@property (nonatomic, readonly) NSString *beaconName;
@property (nonatomic, readonly) UIColor *backgroundColor;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithBeaconName:(NSString *)beaconName backgroundColor:(UIColor *)backgroundColor NS_DESIGNATED_INITIALIZER;

+ (UIColor *)neutralColor;

@end
