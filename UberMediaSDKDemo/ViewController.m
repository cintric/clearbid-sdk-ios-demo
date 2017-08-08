//
//  ViewController.m
//  UberMediaSDKDemo
//
//  Created by Joel Green on 8/7/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import "ViewController.h"
#import <UberMedia/UberMedia.h>

@interface ViewController ()

@property (weak, nonatomic) UMAdView *adView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self setupAdView];
}

- (void)setupAdView
{
    CGRect frame = CGRectMake(0, [UIApplication sharedApplication].statusBarFrame.size.height, self.view.frame.size.width, 50);
    UMAdView *adView = [[UMAdView alloc] initWithFrame:frame];
    [self.view addSubview:adView];
    self.adView = adView;
    
    // Call this to load your ad (IMPORTANT: change the placement_id or you will only get test ads.)
    [self.adView loadAd:@"test_ad_placement_id" forSize:CGSizeMake(320, 50)];
    
    // The ad will default to a 30 second refresh rate, you can use this method to change the refresh rate. Set to 0 to disable refreshing.
    [self.adView changeAdRefreshRate:60];
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    // This is a very simple way to handle rotations, but you will probably want to use a more sophisticated approach.
    if (self.adView) {
        CGRect frame = CGRectMake(0, [UIApplication sharedApplication].statusBarFrame.size.height, self.view.frame.size.width, 50);
        self.adView.frame = frame;
        // When layoutSubviews is called on the adView it will automatically center the ad in the frame (if the set frame is larger than the banner width).
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
