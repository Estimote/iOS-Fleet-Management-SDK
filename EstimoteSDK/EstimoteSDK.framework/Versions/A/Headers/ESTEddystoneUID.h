//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Version: 3.3.1
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

#define ESTIMOTE_EDDYSTONE_NAMESPACE_ID @"EDD1EBEAC04E5DEFA017"


/**
 * According to Google documentation Eddystone device is identified
 * by UUID that consists of Namespace ID and Instance ID.
 *
 * The Eddystone namespace serves to ensure ID uniqueness across 
 * multiple Eddystone implementers. It consisting of a 10-byte.
 *
 * The Eddystone instance serves to ensure ID uniqueness across
 * devices having the same namespace.
 *
 */
@interface ESTEddystoneUID : NSObject

@property (nonatomic, strong, readonly) NSString *namespaceID;
@property (nonatomic, strong, readonly) NSString *instanceID;

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
