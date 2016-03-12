//
//  ViewController.m
//  Showroom
//

#import "ViewController.h"

#import "ShowroomManager.h"

@interface ViewController () <ShowroomManagerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UILabel *descriptionLabel;

@property (strong, nonatomic) ShowroomManager *showroomManager;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeAlert | UIUserNotificationTypeSound) categories:nil]];

    // TODO: replace with identifiers of your own nearables
    self.showroomManager = [[ShowroomManager alloc] initWithProducts:@{
        [NearableID IDString:@"abcdef0000000001"]
            : [[Product alloc] initWithName:@"Sweeft Headphones" summary:@"These super cool headphones will make sure you'll re-discover your favorite Taylor Swift song anew. You just can't put a price tag on that!"],
        [NearableID IDString:@"abcdef0000000002"]
            : [[Product alloc] initWithName:@"Nyan Bicycle 3x14" summary:@"Rush down the local streets with this amazing bike, leaving a trail of rainbow behind you, to the awe of everyone around."]
    }];
    self.showroomManager.delegate = self;
    [self.showroomManager startUpdates];
}

- (void)showroomManager:(ShowroomManager *)showroomManager didDetectPickupForProduct:(Product *)product {
    self.titleLabel.text = product.name;
    self.descriptionLabel.text = product.summary;
    self.descriptionLabel.hidden = NO;

    // Nearable detection works even if the app is not running!
    // Try it: run the app, lock your phone, and pick up a nearable. You should see a notification show up on your lock screen.
    if ([UIApplication sharedApplication].applicationState != UIApplicationStateActive) {
        UILocalNotification *notification = [UILocalNotification new];
        notification.soundName = UILocalNotificationDefaultSoundName;
        notification.alertBody = [NSString stringWithFormat:@"It looks like you're interested in %@. Swipe here to learn more.", product.name];
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
}

- (void)showroomManager:(ShowroomManager *)showroomManager didDetectPutdownForProduct:(Product *)product {
    self.titleLabel.text = @"Pick up an object to learn more about it";
    self.descriptionLabel.hidden = YES;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
