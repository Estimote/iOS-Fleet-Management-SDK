//
//  Product.h
//  Showroom
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Product : NSObject

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *summary;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithName:(NSString *)name summary:(NSString *)summary NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
