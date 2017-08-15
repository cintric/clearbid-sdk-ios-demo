//
// Copyright (C) 2015 Google, Inc.
//
// SampleCustomEventBanner.m
// Sample Ad Network Custom Event
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
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

- (id)init
{
    self = [super init];
    NSLog(@"initializing UMAdMobCUstomeEventBanner");
    return self;
}

#pragma mark GADCustomEventBanner implementation

- (void)requestBannerAd:(GADAdSize)adSize
              parameter:(NSString *)serverParameter
                  label:(NSString *)serverLabel
                request:(GADCustomEventRequest *)request {
    
    NSLog(@"%f, %f, %@, %@, %@", adSize.size.width, adSize.size.height, serverParameter, serverLabel, request);
    
    self.bannerAd = [[UMAdView alloc] initWithFrame:CGRectMake(0, 0, adSize.size.width, adSize.size.height)];
    self.bannerAd.delegate = self;
    
    [self.bannerAd changeAdRefreshRate:0];
    [self.bannerAd loadAd:@"test_ad_placement_id" forSize:adSize.size];
}

#pragma mark UMAdView delegate implementation

#pragma mark - UMAdViewDelegate methods

- (void)adViewDidLoadAd:(UMAdView *)view
{
    [self.delegate customEventBanner:self didReceiveAd:view];
}

- (void)adViewDidFailToLoadAd:(UMAdView *)view withMessage:(NSString *)message
{
    NSError *error = [NSError errorWithDomain:customEventErrorDomain code:0 userInfo:@{@"message": message}];
    [self.delegate customEventBanner:self didFailAd:error];
}

- (void)willLeaveApplicationFromAd:(UMAdView *)view
{
    [self.delegate customEventBannerWasClicked:self];
    [self.delegate customEventBannerWillLeaveApplication:self];
}

@end
