//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

#import "ESTCloudCredentials.h"
#import "ESTProximityRange.h"
#import "ESTProximityDeviceAttachment.h"

NS_ASSUME_NONNULL_BEGIN


/**
 Observes and reports proximity of Estimote devices. 
 Uses Estimote Monitoring under the hood. Encapsulates it under tag-based beacon identification and callback blocks.
 */
@interface ESTProximityObserver : NSObject

/**
 Init is disabled for this class.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 New is disabled for this class.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initializer.

 @param credentials Cloud Credentials object. You can use `+[ESTCloudCredentials sharedInstance]` to get it.
 @param errorHandler Block called every time an error occurs.
 @param didStartHandler Block called after proximity observing is started.
 */
- (instancetype)initWithCredentials:(ESTCloudCredentials *)credentials
                       errorHandler:(void (^)(NSError *error))errorHandler
                    didStartHandler:(void (^ _Nullable)())didStartHandler NS_DESIGNATED_INITIALIZER;

/**
 Register block to be called when user enters proximity of Estimote devices with matching attachment.
 Beacon identification is attachment-based (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).
 
 Calling this method causes the block to be copied. To get rid of the copy, use `-removeAllHandlers`.

 @param range Range where the action should be reported.
 @param attachmentKey Key that should be in a beacon's attachment JSON so it's classified for reporting.
 @param handler Block to be invoked when an enter occurs. The block parameter is attachment of the beacon 
                that triggered the enter (i.e. the first beacon with matching attachment in range).
 */
- (void)onEnterRange:(ESTProximityRange *)range ofBeaconsWithAttachmentKey:(NSString *)attachmentKey handler:(void(^)(ESTProximityDeviceAttachment *triggeringBeaconAttachment))handler
NS_SWIFT_NAME(onEnter(range:ofBeaconsWithAttachmentKey:handler:));

/**
 Register block to be called when user exits proximity of Estimote devices with matching attachment.
 Beacon identification is attachment-based (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).
 
 Calling this method causes the block to be copied. To get rid of the copy, use `-removeAllHandlers`.
 
 @param range Range where the action should be reported.
 @param attachmentKey Key that should be in a beacon's attachment JSON so it's classified for reporting.
 @param handler Block to be invoked when an exit occurs. The block parameter is attachment of the beacon 
                that triggered the exit (i.e. the last beacon with matching attachment in range).
 */
- (void)onExitRange:(ESTProximityRange *)range ofBeaconsWithAttachmentKey:(NSString *)attachmentKey handler:(void(^)(ESTProximityDeviceAttachment *triggeringBeaconAttachment))handler
NS_SWIFT_NAME(onExit(range:ofBeaconsWithAttachmentKey:handler:));

/**
 Register block to be called each time a new beacon is detected in user's range and each time a beacon disappears
 from user's range.
 
 Beacon identification is attachment-based (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).

 @param range Range where the action should be reported.
 @param attachmentKey Key that should be in a beacon's attachment JSON so it's classified for reporting.
 @param handler Block to be invoked when some beacon's proximity status change occurs. 
                The block parameter is a set of attachments of all beacons that are inside range after the change.
 */
- (void)onChangeBeaconsInRange:(ESTProximityRange *)range withAttachmentKey:(NSString *)attachmentKey handler:(void (^)(NSSet<ESTProximityDeviceAttachment *> *attachmentsInRange))handler
NS_SWIFT_NAME(onBeaconsInRangeChange(range:attachmentKey:handler:));

/**
 Remove all registered blocks. Releases the blocks registered with `-onEnterRange:ofBeaconsWithAttachmentKey:handler:`,
 `-onExitRange:ofBeaconsWithAttachmentKey:handler:`, and `-onBeaconsInRangeChange:withAttachmentKey:handler:`.
 
 Use it when Proximity Observer is no longer needed to avoid strong reference cycles.
 */
- (void)removeAllHandlers;

/**
 Start observing and reporting proximity events for rules defined by `-onEnterRange:ofBeaconsWithAttachmentKey:handler:`
 and `-onExitRange:ofBeaconsWithAttachmentKey:handler:`:
 - request device details for all user's devices from Estimote Cloud,
 - start Estimote Monitoring at registered ranges,
 - call `didStartHandler` when starting is complete,
 - call registered enter/exit handlers when proximity event occurs.
 */
- (void)start;

@end

NS_ASSUME_NONNULL_END
