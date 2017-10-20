//
// Please report any problems with this app template to contact@estimote.com
//

#import <Foundation/Foundation.h>

@interface NotificationManager : NSObject

- (void)enableNotificationsForDeviceIdentifier:(NSString *)beaconIdentifier
                                  enterMessage:(NSString *)enterMessage
                                   exitMessage:(NSString *)exitMessage;

@end
