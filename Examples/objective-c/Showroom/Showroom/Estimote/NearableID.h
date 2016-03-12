//
//  NearableID.h
//  Showroom
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NearableID : NSObject <NSCopying>

@property (nonatomic, readonly) NSString *nearableIDString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)IDString:(NSString *)nearableIDString;
- (nullable instancetype)initWithNearableIDString:(NSString *)nearableIDString NS_DESIGNATED_INITIALIZER;

- (BOOL)isEqualToNearableID:(NearableID *)nearableID;

@end

NS_ASSUME_NONNULL_END
