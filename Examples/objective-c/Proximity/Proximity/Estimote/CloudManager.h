//
// Please report any problems with this app template to contact@estimote.com
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^RequestCompletionBlock)(BOOL success, NSDictionary<NSString *, UIColor *> * _Nullable colorByIdentifier);

/// Provides an API for fetching content related to beacons, in this simple case it's colors.
@interface CloudManager : NSObject

- (void)fetchColorsForBeaconsWithIdentifiers:(NSArray<NSString *> *)identifiers completion:(RequestCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
