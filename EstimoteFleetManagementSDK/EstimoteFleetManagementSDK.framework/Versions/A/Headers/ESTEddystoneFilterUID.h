//  Estimote Fleet Management SDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTEddystoneFilter.h"
#import "ESTEddystoneUID.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Eddystone-UID based filter used by `ESTEddystoneManager` in discovery process.
 *  Filter should be initialized with namespaceID and instanceID
 *  that is matching device(s) should be discovered. Only Namespace ID is required,
 *  Instance ID can be provided optionally for better flexibility.
 */
DEPRECATED_MSG_ATTRIBUTE("Deprecated since 4.31.0.")
@interface ESTEddystoneFilterUID : ESTEddystoneFilter

/**
 *  Namespace ID required for device identification.
 *  Value usually defined on the company level.
 */
@property (nonatomic, strong, readonly) NSString *_Nullable namespaceID;

/**
 *  Instance ID required for device identification.
 *  Value defined per device.
 */
@property (nonatomic, strong, readonly) NSString *_Nullable instanceID;

/**
 * Initialize Eddystone UUID object instance with Namespace ID only.
 *
 * @param namespaceID Eddystone Namespace ID.
 */
- (instancetype)initWithNamespaceID:(NSString *)namespaceID;

/**
 * Initialize Eddystone UUID object instance with Namespace ID and Instance ID.
 *
 * @param namespaceID Eddystone Namespace ID.
 * @param instanceID Eddystone Instance ID.
 */
- (instancetype)initWithNamespaceID:(NSString *)namespaceID instanceID:(NSString *)instanceID;

@end

NS_ASSUME_NONNULL_END
