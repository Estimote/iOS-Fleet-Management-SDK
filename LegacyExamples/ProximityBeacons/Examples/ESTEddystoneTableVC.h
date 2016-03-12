#import <UIKit/UIKit.h>
#import <EstimoteSDK/EstimoteSDK.h>

/*
 * Lists all Estimote beacons in range and returns selected beacon.
 */
@interface ESTEddystoneTableVC : UITableViewController

/*
 * Selected beacon is returned on given completion handler.
 */
- (id)initWithCompletion:(void (^)(id))completion;

@end
