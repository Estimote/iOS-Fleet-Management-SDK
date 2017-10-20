//
// Please report any problems with this app template to contact@estimote.com
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ProximityManager;

@protocol ProximityManagerDelegate <NSObject>

- (void)proximityManager:(ProximityManager *)manager didUpdateBeaconsInRange:(NSArray<NSString *> *)identifiers;
- (void)proximityManager:(ProximityManager *)manager didFailWithError:(NSError *)error;

@end

/// Monitors proximity of beacons using Estimote Monitoring to inform which beacons are currently in range.
@interface ProximityManager : NSObject

@property (nonatomic, weak) id<ProximityManagerDelegate> delegate;

- (void)startMonitoringProximityOfBeaconsWithIdentifiers:(NSArray<NSString *> *)identifiers;

@end

NS_ASSUME_NONNULL_END
