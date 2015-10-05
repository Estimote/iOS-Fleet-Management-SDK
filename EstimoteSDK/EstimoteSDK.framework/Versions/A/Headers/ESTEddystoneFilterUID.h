//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import "ESTEddystoneFilter.h"
#import "ESTEddystoneUID.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Eddystone-UID based filter used by `ESTEddystoneManager` in discovery process.
 *  Filter should be initialized with `ESTEddystoneUID` object that is matching device(s)
 *  should be discovered. In ESTEddystoneUID object only Namespace ID is required,
 *  Instance ID can be provided optionally for better flexibility.
 */

@interface ESTEddystoneFilterUID : ESTEddystoneFilter

@property (nonatomic, strong, readonly) ESTEddystoneUID *eddystoneUID;

/**
* Initialize filter with `ESTEddystoneUID` object providing NamespaceID and optional InstanceID;
*/
- (instancetype)initWithUID:(ESTEddystoneUID *)eddystoneUID;

@end

NS_ASSUME_NONNULL_END
