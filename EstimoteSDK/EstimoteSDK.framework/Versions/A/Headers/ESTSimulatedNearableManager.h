//
//  ESTSimulatedNearableManager.h
//  EstimoteSDK
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "ESTNearableManager.h"

/**
* ESTSimulatedNearableManager is a class for simulating Nearables (ESTNearable) objects.
*/
@interface ESTSimulatedNearableManager : ESTNearableManager <ESTNearableManagerDelegate>

/**
* Simulated ESTNearable object. Same object will be returned by
* nearableManager:didRangeNearable method.
*/
@property (nonatomic, readonly) ESTNearable *nearable;

/**
* Array with simulated ESTNearable objects.
* Returned by nearableManager:didRangeNearables:withType method.
*/
@property (nonatomic, readonly) NSArray *nearables;

/**
*  Use this initializer if you want to simulate only one nearable.
*
*  @param delegate       Set delegate for ESTNearableManagerDelegate updates.
*  @param identifier     Identifier you want to set for your nearable object.
*  @param zone           Zone you want to set for your nearable object.
*
*  @return Instance of this object.
*/
- (instancetype)initWithDelegate:(id<ESTNearableManagerDelegate>)delegate
                      identifier:(NSString *)identifier
                            zone:(ESTNearableZone)zone;

/**
*  Use this initializer if you want to specify nearables in JSON.
*  Providing only filename is sufficient, but remember that your file
*  should be *.json type and accessible from MainBundle.
*  By default, order of nearables in the list will be reflected in nearables array,
*  which means, this class do not provide simulation of fluctuating RSSI or proximity.
*  However, you can set those values in JSON file, they will be parsed into ESTNearable object.
*
*  @param delegate        Set delegate for ESTNearableManagerDelegate updates.
*  @param pathForJSON     Path for json file with description of nearables you want to simulate.
*
*  @return Instance of this object.
*/
- (instancetype)initWithDelegate:(id<ESTNearableManagerDelegate>)delegate
                     pathForJSON:(NSString *)path;

/**
 *  Set desired zone for your simulated ESTNearableObject.
 *
 *  @param zone ESTNearableZone to set.
 */
- (void)simulateZoneForNearable:(ESTNearableZone)zone;

/**
 *  Simulate enter region event for your nearable.
 *  Ranging will automatically start after calling this method.
 *  Callback method is nearableManager:didEnterIdentifierRegion from ESTNearableManagerDelegate protocol.
 *  If you do not implement didEnterIdentifierRegion code will crash,
 *  it's not checking whether delegate implemented method or not.
 *  This is 'by design'. During testing you probably want to know
 *  when your class don't implement ESTNearableManager delegates.
 *
 *  @param nearable Nearable object for this event.
 */
- (void)simulateDidEnterRegionForNearable:(ESTNearable *)nearable;

/**
 *  Simulate exit region event for your nearable.
 *  Ranging will automatically stop after calling this method.
 *  Callback method is nearableManager:didExitIdentifierRegion from ESTNearableManagerDelegate protocol.
 *  If you do not implement didExitIdentifierRegion code will crash,
 *  it's not checking whether delegate implemented method or not.
 *  This is 'by design'. During testing you probably want to know
 *  when your class don't implement ESTNearableManager delegates.
 *
 *  @param nearable Nearable object for this event.
 */
- (void)simulateDidExitRegionForNearable:(ESTNearable *)nearable;

@end
