//
// Please report any problems with this app template to contact@estimote.com
//

#import <Foundation/Foundation.h>

#import <EstimoteSDK/EstimoteSDK.h>

@interface BeaconID : NSObject <NSCopying>

@property (nonatomic, readonly) NSUUID *proximityUUID;
@property (nonatomic, readonly) CLBeaconMajorValue major;
@property (nonatomic, readonly) CLBeaconMinorValue minor;

@property (nonatomic, readonly) NSString *asString;
@property (nonatomic, readonly) CLBeaconRegion *asBeaconRegion;

- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithUUIDString:(NSString *)UUIDString major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor;

- (BOOL)isEqualToBeaconID:(BeaconID *)beaconID;

@end

@interface CLBeacon (BeaconID)

@property (nonatomic, readonly) BeaconID *beaconID;

@end
