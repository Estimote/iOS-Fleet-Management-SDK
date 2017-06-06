//
// Please report any problems with this app template to contact@estimote.com
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <EstimoteSDK/EstimoteSDK.h>

@interface BeaconDetails : NSObject

@property (nonatomic, readonly) NSString *beaconName;
@property (nonatomic, readonly) UIColor *backgroundColor;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithBeaconName:(NSString *)beaconName backgroundColor:(UIColor *)backgroundColor NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithBeaconName:(NSString *)beaconName beaconColor:(ESTColor)beaconColor;

+ (UIColor *)neutralColor;

@end
