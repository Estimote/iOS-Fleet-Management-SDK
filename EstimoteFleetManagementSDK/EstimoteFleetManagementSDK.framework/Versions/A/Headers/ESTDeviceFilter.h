//  Estimote Fleet Management SDK
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Protocol that every filter class used by ESTDeviceManager should conform to.
 *
 *  Defines predicate to be evaluated on ESTDevice subclass objects resulting from scanning
 *  and scan classes to be used by a bluetooth scanner underneath the ESTDeviceManager.
 *
 *  @see ESTDeviceManager, ECOScanInfoIBeacon.
 */
@protocol ESTDeviceFilter <NSObject>

/**
 *  Predicate that ESTDeviceManager evaluates on scan result objects to execute filtering by attribute (i.e. identifier).
 */
@property (nonatomic, strong, readonly) NSPredicate *devicesPredicate;

/**
 *  Method returns array of packet classes needed by bluetooth scanner.
 *
 *  @return Array of ECOScanInfo subclasses.
 */
- (NSArray<Class> *)getScanInfoClasses;

@end

NS_ASSUME_NONNULL_END
