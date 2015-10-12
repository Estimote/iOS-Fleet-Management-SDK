#import "ESTEddystoneTableVC.h"
#import "ESTViewController.h"
#import <EstimoteSDK/EstimoteSDK.h>

@interface ESTEddystoneTableVC () <ESTEddystoneManagerDelegate>

@property (nonatomic, copy) void (^completion)(ESTEddystone *);

@property (nonatomic, strong) ESTEddystoneManager *eddystoneManager;


@property (nonatomic, strong) ESTEddystoneFilterUID *uidFilter;
@property (nonatomic, strong) NSArray *devicesForUID;

@property (nonatomic, strong) ESTEddystoneFilterURL *urlFilter;
@property (nonatomic, strong) NSArray *devicesForURL;

@property (nonatomic, strong) ESTEddystoneFilterURLDomain *urlDomainFilter;
@property (nonatomic, strong) NSArray *devicesForURLDomain;

@end

@interface ESTGTableViewCell : UITableViewCell

@end

@implementation ESTGTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    return self;
}
@end

@implementation ESTEddystoneTableVC

- (id)initWithCompletion:(void (^)(id))completion
{
    self = [super init];
    if (self)
    {
        self.completion = [completion copy];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Eddystone devices";
    [self.tableView registerClass:[ESTGTableViewCell class] forCellReuseIdentifier:@"CellIdentifier"];
    
    self.eddystoneManager = [[ESTEddystoneManager alloc] init];
    self.eddystoneManager.delegate = self;
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    /*
     * UUID filter allows to discover devices working in Eddystone UUID mode.
     * You should provide NamespaceID and optionally InstanceID.
     */
    
    ESTEddystoneUID *eddystoneUID = [[ESTEddystoneUID alloc] initWithNamespaceID:ESTIMOTE_EDDYSTONE_NAMESPACE_ID];
    self.uidFilter = [[ESTEddystoneFilterUID alloc] initWithUID:eddystoneUID];
    
    /*
     * URL filter allows to to scan for all devices broadcasting particular web URL.
     * Address need to mach both prefix and suffix.
     */
    
    self.urlFilter = [[ESTEddystoneFilterURL alloc] initWithURL:@"http://go.esti.be"];
    
    /*
     * Domain filter allows you to provide general web domain. All devices that are broadcasting 
     * URL in that domain (including sub domains) will be return with relevant filter information.
     */
    
    self.urlDomainFilter = [[ESTEddystoneFilterURLDomain alloc] initWithURLDomain:@"go.esti.be"];
    
    /*
     * Eddystone discovery is based on filtering mechanism. `startEddystoneDiscoveryWithFilter:` method
     * can be invoked multiple times with different filters provided as a param.
     * Delegate method `eddystoneManager:didDiscoverEddystones:withFilter:` informs about device discovery
     * delivering both device details in `ESTEddystone` object as well as filter (`ESTFilter` subclass) that it fulfilled.
     */
    
    [self.eddystoneManager startEddystoneDiscoveryWithFilter:self.uidFilter];
    [self.eddystoneManager startEddystoneDiscoveryWithFilter:self.urlFilter];
    [self.eddystoneManager startEddystoneDiscoveryWithFilter:self.urlDomainFilter];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    /*
     * Stops Eddystone device discovery after exiting the view.
     */
    
    [self.eddystoneManager stopEddystoneDiscoveryWithFilter:self.uidFilter];
    [self.eddystoneManager stopEddystoneDiscoveryWithFilter:self.urlFilter];
    [self.eddystoneManager stopEddystoneDiscoveryWithFilter:self.urlDomainFilter];
}

- (void)dismiss
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - ESTEddystoneManagerDelegate

- (void)eddystoneManager:(ESTEddystoneManager *)manager
   didDiscoverEddystones:(NSArray *)eddystones
              withFilter:(ESTEddystoneFilter *)eddystoneFilter
{
    /*
     * Update local device list and update UI
     */
    
    if (eddystoneFilter == self.uidFilter)
    {
        self.devicesForUID = eddystones;
    }
    else if (eddystoneFilter == self.urlFilter)
    {
        self.devicesForURL = eddystones;
    }
    else if (eddystoneFilter == self.urlDomainFilter)
    {
        self.devicesForURLDomain = eddystones;
    }
    
    [self.tableView reloadData];
}

- (void)eddystoneManagerDidFailDiscovery:(ESTEddystoneManager *)manager
{
    NSLog(@"Eddyston discovery process failed.");
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 3;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    switch (section)
    {
        case 0:
            return @"UUID Filter";
            break;
        case 1:
            return @"URL Filter";
            break;
        case 2:
            return @"URL Domain Filter";
            break;
            
        default:
            return @"";
            break;
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self devicesForSection:section].count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ESTGTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CellIdentifier" forIndexPath:indexPath];
    
    /*
     * Fill the table section with beacon data.
     */
    
    ESTEddystone *cBeacon = [[self devicesForSection:indexPath.section] objectAtIndex:indexPath.row];
    
    if (cBeacon.url)
    {
        cell.textLabel.text = [NSString stringWithFormat:@"%@ / %@", cBeacon.macAddress, cBeacon.url];
    }
    else
    {
        cell.textLabel.text = [NSString stringWithFormat:@"%@", cBeacon.macAddress];
    }
    
    if (cBeacon.telemetry)
    {
        cell.detailTextLabel.text = [NSString stringWithFormat:@"RSSI: %zd Battery: %zd Temp: %.2f",
                                     [cBeacon.rssi integerValue],
                                     [cBeacon.telemetry.batteryVoltage integerValue],
                                     [cBeacon.telemetry.temperature floatValue]];
    }
    else
    {
        cell.detailTextLabel.text = [NSString stringWithFormat:@"RSSI: %zd", [cBeacon.rssi integerValue]];
    }
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
	return 80;
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    ESTEddystone *selectedEddystone = [[self devicesForSection:indexPath.section] objectAtIndex:indexPath.row];
    
    self.completion(selectedEddystone);
}

- (NSArray *)devicesForSection:(NSInteger)section
{
    switch (section)
    {
        case 0:
            return self.devicesForUID;
            break;
        case 1:
            return self.devicesForURL;
            break;
        case 2:
            return self.devicesForURLDomain;
            break;
    }
    
    return nil;
}

@end
