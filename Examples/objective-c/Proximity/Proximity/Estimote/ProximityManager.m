//
// Please report any problems with this app template to contact@estimote.com
//

#import "ProximityManager.h"
#import <EstimoteSDK/EstimoteSDK.h>


/// Desired distance from a beacon from which enter/exit events should be triggered, in meters.
static float const kDesiredDistance = 1.5;


@interface ProximityManager () <ESTMonitoringV2ManagerDelegate>

@property (nonatomic, strong) ESTMonitoringV2Manager *monitoringManager;

@end


@implementation ProximityManager

- (void)startMonitoringProximityOfBeaconsWithIdentifiers:(NSArray<NSString *> *)identifiers {
    self.monitoringManager = [[ESTMonitoringV2Manager alloc] initWithDesiredMeanTriggerDistance:kDesiredDistance delegate:self];
    [self.monitoringManager startMonitoringForIdentifiers:identifiers];
}

- (NSString *)nameForState:(ESTMonitoringState)state {
    switch (state) {
    case ESTMonitoringStateUnknown:
        return @"Unknown";
    case ESTMonitoringStateInsideZone:
        return @"Inside";
    case ESTMonitoringStateOutsideZone:
        return @"Outside";
    }
}

- (void)updateBeaconsInRange {
    NSArray<NSString *> *monitoredIdentifiers = self.monitoringManager.monitoredIdentifiers.allObjects;
    NSArray<NSString *> *identifiersInRange = [monitoredIdentifiers filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSString *identifier, NSDictionary<NSString *,id> * _Nullable bindings) {
        return [self.monitoringManager stateForBeaconWithIdentifier:identifier] == ESTMonitoringStateInsideZone;
    }]];
    
    [self.delegate proximityManager:self didUpdateBeaconsInRange:identifiersInRange];
}

#pragma mark - ESTMonitoringV2ManagerDelegate
    
- (void)monitoringManagerDidStart:(ESTMonitoringV2Manager *)manager {
    NSLog(@"Monitoring started successfully.");
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didFailWithError:(NSError *)error {
    NSLog(@"Monitoring failed: %@", error.localizedDescription);
    [self.delegate proximityManager:self didFailWithError:error];
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didDetermineInitialState:(ESTMonitoringState)state forBeaconWithIdentifier:(NSString *)identifier {
    NSLog(@"Determined initial state for %@ - %@.", identifier, [self nameForState:state]);
    [self updateBeaconsInRange];
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didEnterDesiredRangeOfBeaconWithIdentifier:(NSString *)identifier {
    NSLog(@"Monitoring failed: %@", identifier);
    [self updateBeaconsInRange];
}

- (void)monitoringManager:(ESTMonitoringV2Manager *)manager didExitDesiredRangeOfBeaconWithIdentifier:(NSString *)identifier {
    NSLog(@"Monitoring failed: %@", identifier);
    [self updateBeaconsInRange];
}

@end
