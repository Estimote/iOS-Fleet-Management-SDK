//
//  ShowroomManager.m
//  Showroom
//

#import "ShowroomManager.h"

#import <EstimoteSDK/EstimoteSDK.h>

@interface ShowroomManager () <ESTTriggerManagerDelegate>

@property (nonatomic) NSDictionary<NearableID *,Product *> *products;

@property (nonatomic) ESTTriggerManager *triggerManager;
@property (nonatomic) NSMutableArray<ESTTrigger *> *triggers;

@end

@implementation ShowroomManager

- (instancetype)initWithProducts:(NSDictionary<NearableID * ,Product *> *)products {
    self = [super init];
    if (self) {
        _products = products;

        self.triggerManager = [ESTTriggerManager new];
        self.triggerManager.delegate = self;

        self.triggers = [NSMutableArray new];

        for (NearableID *nearableID in self.products.keyEnumerator) {
            ESTMotionRule *motionRule = [ESTMotionRule motionStateEquals:YES forNearableIdentifier:nearableID.nearableIDString];
            ESTTrigger *motionTrigger = [[ESTTrigger alloc] initWithRules:@[motionRule] identifier:nearableID.nearableIDString];
            [self.triggers addObject:motionTrigger];
        }
    }
    return self;
}

- (void)startUpdates {
    for (ESTTrigger *trigger in self.triggers) {
        [self.triggerManager startMonitoringForTrigger:trigger];
    }
}

- (void)stopUpdates {
    for (ESTTrigger *trigger in self.triggers) {
        [self.triggerManager stopMonitoringForTriggerWithIdentifier:trigger.identifier];
    }
}

- (void)triggerManager:(ESTTriggerManager *)manager triggerChangedState:(ESTTrigger *)trigger {
    NearableID *nearableID = [[NearableID alloc] initWithNearableIDString:trigger.identifier];
    if (!nearableID) { return; }

    Product *product = [self.products objectForKey:nearableID];
    if (!product) { return; }

    if (trigger.state == YES) {
        [self.delegate showroomManager:self didDetectPickupForProduct:product];
    } else {
        [self.delegate showroomManager:self didDetectPutdownForProduct:product];
    }
}

@end
