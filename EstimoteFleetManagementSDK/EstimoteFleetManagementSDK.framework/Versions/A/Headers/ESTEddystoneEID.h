//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTEddystone.h"
#import "ESTEddystoneEID.h"
#import "ESTEddystoneAttachment.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ESTEddystoneEID represents Eddystone Ephemeral ID packet coming from `ESTEddystoneManager` class. When device is registered
 *  packet will contain Namespace ID and Instance ID resolved from secure payload.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTEddystoneEID : ESTEddystone

/**
 *  Ephemeral identifier broadcasted in Eddystone Ephemeral ID packet.
 */
@property (nonatomic, strong, readonly) NSString *ephemeralID;

/**
 *  Flag indicating that Eddystone Ephemeral ID packet was resolved.
 */
@property (nonatomic, readonly) BOOL isResolved;

/**
 *  Array of Eddystone attachments set by user using Google Beacon Proximity API.
 */
@property (nonatomic, strong) NSArray<ESTEddystoneAttachment *> *_Nullable attachments;

/**
 *  Initialize Eddystone EID object with registered namespace and instance identifiers.
 *
 *  @param  ephemeralID  Ephemeral identifier broadcasted in Eddystone Ephemeral ID packet.
 *  @param  resolved    Flag indicating if Eddystone was resolved.
 *
 */
- (instancetype)initWithEphemeralID:(nullable NSString *)ephemeralID resolved:(BOOL)resolved;

@end

NS_ASSUME_NONNULL_END
