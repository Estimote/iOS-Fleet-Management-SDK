//
// Please report any problems with this app template to contact@estimote.com
//

#import "CloudManager.h"
#import <EstimoteSDK/EstimoteSDK.h>
#import "UIColor+Additions.h"

@implementation CloudManager

- (void)fetchColorsForBeaconsWithIdentifiers:(NSArray<NSString *> *)identifiers completion:(RequestCompletionBlock)completion {
    ESTRequestGetBeaconsDetails *request = [[ESTRequestGetBeaconsDetails alloc] initWithMacAddresses:identifiers andFields: ESTBeaconDetailsFieldColor];
    [request sendRequestWithCompletion:^(NSArray<ESTBeaconVO *> *beaconVOs, NSError *error) {
        if (error) {
            completion(false, nil);
            return;
        }
        
        NSMutableDictionary<NSString *, UIColor *> *colorByIdentifier = [NSMutableDictionary new];
        for (ESTBeaconVO *beaconVO in beaconVOs) {
            UIColor *color = [UIColor colorForEstimoteColor:beaconVO.color];
            colorByIdentifier[beaconVO.macAddress] = color;
        }
        
        completion(true, colorByIdentifier);
    }];
}

@end
