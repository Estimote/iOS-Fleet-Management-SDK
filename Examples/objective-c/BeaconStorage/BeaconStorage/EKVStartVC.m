//
//  EKVStartVC.m
//  KeyValueApp
//
//  Created by Filip Chwastowski on 24/10/2016.
//  Copyright © 2016 Estimote. All rights reserved.
//

#import "EKVStartVC.h"

@interface EKVStartVC ()
@property (weak, nonatomic) IBOutlet UIButton *startButton;

@end

@implementation EKVStartVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.startButton.layer.cornerRadius = 3.f;
    UIBarButtonItem *backButton = [[UIBarButtonItem alloc] initWithTitle:@"Back"
                                                                   style:UIBarButtonItemStylePlain
                                                                  target:nil
                                                                  action:nil];
    [self.navigationItem setBackBarButtonItem:backButton];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
