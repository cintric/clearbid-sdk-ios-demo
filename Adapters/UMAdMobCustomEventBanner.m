//
//  UMAdMobCustomEventBanner.m
//  UberMedia SDK Custom Event for Google Mobile Ads
//
//  Created by Joel Green on 8/7/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import "UMAdMobCustomEventBanner.h"

@import Foundation;

#import <UberMedia/UberMedia.h>

/// Constant for Sample Ad Network custom event error domain.
static NSString *const customEventErrorDomain = @"com.google.CustomEvent";

@interface UMAdMobCustomEventBanner () <UMAdViewDelegate>

/// The Sample Ad Network banner.
@property(nonatomic, strong) UMAdView *bannerAd;

@end

@implementation UMAdMobCustomEventBanner

@synthesize delegate;

#pragma mark GADCustomEventBanner implementation

- (void)requestBannerAd:(GADAdSize)adSize
              parameter:(NSString *)serverParameter
                  label:(NSString *)serverLabel
                request:(GADCustomEventRequest *)request {
    
    NSLog(@"[UberMedia] Using adUnitId from Google server param: %@", serverParameter);
    
    self.bannerAd = [[UMAdView alloc] initWithFrame:CGRectMake(0, 0, adSize.size.width, adSize.size.height)];
    self.bannerAd.delegate = self;
    
    [self.bannerAd changeAdRefreshRate:0];
    [self.bannerAd loadAd:serverParameter forSize:adSize.size];
}

#pragma mark UMAdView delegate implementation

- (void)adViewDidLoadAd:(UMAdView *)view
{
    [self.delegate customEventBanner:self didReceiveAd:view];
}

- (void)adViewDidFailToLoadAd:(UMAdView *)view withMessage:(NSString *)message
{
    NSError *error = [NSError errorWithDomain:customEventErrorDomain code:0 userInfo:@{}];
    [self.delegate customEventBanner:self didFailAd:error];
}

- (void)willLeaveApplicationFromAd:(UMAdView *)view
{
    [self.delegate customEventBannerWasClicked:self];
    [self.delegate customEventBannerWillLeaveApplication:self];
}

@end
