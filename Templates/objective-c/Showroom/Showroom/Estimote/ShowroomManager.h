//
//  ShowroomManager.h
//  Showroom
//

#import <Foundation/Foundation.h>

#import "NearableID.h"
#import "Product.h"

@class ShowroomManager;

NS_ASSUME_NONNULL_BEGIN

@protocol ShowroomManagerDelegate <NSObject>

- (void)showroomManager:(ShowroomManager *)showroomManager didDetectPickupForProduct:(Product *)product;
- (void)showroomManager:(ShowroomManager *)showroomManager didDetectPutdownForProduct:(Product *)product;

@end

@interface ShowroomManager : NSObject

@property (weak, nonatomic, nullable) id<ShowroomManagerDelegate> delegate;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithProducts:(NSDictionary<NearableID *, Product *> *)products;

- (void)startUpdates;
- (void)stopUpdates;

@end

NS_ASSUME_NONNULL_END
