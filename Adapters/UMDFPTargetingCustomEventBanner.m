//
//  UMDFPTargetingCustomEventBanner.m
//  UberMediaTestApp
//
//  Created by Joel Green on 8/28/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import "UMDFPTargetingCustomEventBanner.h"
#import <UberMedia/UberMedia.h>

@interface UMDFPTargetingCustomEventBanner () <UMAdViewDelegate>

@property(nonatomic, strong) UMAdView *bannerAd;

@end

@implementation UMDFPTargetingCustomEventBanner

static NSString *const customEventErrorDomain = @"com.google.CustomEvent";

@synthesize delegate;

#pragma mark GADCustomEventBanner implementation

- (void)requestBannerAd:(GADAdSize)adSize
              parameter:(NSString *)serverParameter
                  label:(NSString *)serverLabel
                request:(GADCustomEventRequest *)request {
    
    NSLog(@"[UberMedia] Using adUnitId from Google server param: %@ and size %dx%d", serverParameter, (int)adSize.size.width, (int)adSize.size.height);
    
    self.bannerAd = [UberMedia getAdViewForCachedAd:serverParameter andSize:adSize.size];
    self.bannerAd.frame = CGRectMake(0, 0, adSize.size.width, adSize.size.height);
    
    self.bannerAd.delegate = self;
    
    if (self.bannerAd) {
        [self.delegate customEventBanner:self didReceiveAd:self.bannerAd];
    } else {
        NSError *error = [NSError errorWithDomain:customEventErrorDomain code:0 userInfo:@{}];
        [self.delegate customEventBanner:self didFailAd:error];
    }
}

#pragma mark UMAdView delegate implementation

- (void)willLeaveApplicationFromAd:(UMAdView *)view
{
    [self.delegate customEventBannerWasClicked:self];
    [self.delegate customEventBannerWillLeaveApplication:self];
}

@end
