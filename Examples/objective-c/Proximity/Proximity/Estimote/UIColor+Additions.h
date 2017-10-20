//
// Please report any problems with this app template to contact@estimote.com
//

#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>

NS_ASSUME_NONNULL_BEGIN

// Adds support for Estimote Colors to UIColor class.
@interface UIColor (Additions)

+ (UIColor *)colorForEstimoteColor:(ESTColor)estimoteColor;

@end

NS_ASSUME_NONNULL_END
