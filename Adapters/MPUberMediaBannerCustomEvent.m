//
//  MPUberMediaBannerCustomEvent.m
//  UberMediaTestApp
//
//  Created by Joel Green on 6/14/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import "MPUberMediaBannerCustomEvent.h"
#import <UberMedia/UberMedia.h>

@interface MPUberMediaBannerCustomEvent () <UMAdViewDelegate>

@property(nonatomic, strong) UMAdView *bannerAd;

@end

@implementation MPUberMediaBannerCustomEvent

@synthesize delegate;

- (void)requestAdWithSize:(CGSize)size customEventInfo:(NSDictionary *)info
{
    NSLog(@"[UberMedia] Using MoPub adapter custom event info: %@ and size %dx%d", info, (int)size.width, (int)size.height);
    
    self.bannerAd = [UberMedia getAdViewForCachedAd:[info objectForKey:@"ad_unit_id"] andSize:size];
    self.bannerAd.frame = CGRectMake(0, 0, size.width, size.height);
    
    self.bannerAd.delegate = self;
    
    if (self.bannerAd) {
        [self.delegate bannerCustomEvent:self didLoadAd:self.bannerAd];
    } else {
        [self.delegate bannerCustomEvent:self didFailToLoadAdWithError:nil];
    }
}

- (void)willLeaveApplicationFromAd:(UMAdView *)view
{
    [self.delegate bannerCustomEventWillLeaveApplication:self];
}

@end
