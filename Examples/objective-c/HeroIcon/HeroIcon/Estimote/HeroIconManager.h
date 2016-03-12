//
//  HeroIconManager.h
//  HeroIcon
//

#import <Foundation/Foundation.h>
#import <EstimoteSDK/EstimoteSDK.h>

#import "BeaconID.h"

@interface HeroIconManager : NSObject

- (void)enableHeroIconForBeaconID:(BeaconID *)beaconID;

@end
