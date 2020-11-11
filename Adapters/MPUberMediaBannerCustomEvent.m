//
//  MPUberMediaBannerCustomEvent.m
//  UberMediaTestApp
//
//  Created by Joel Green on 6/14/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import "MPUberMediaBannerCustomEvent.h"
#import <ClearBid/ClearBid.h>

@interface MPUberMediaBannerCustomEvent () <CBAdViewDelegate>

@property(nonatomic, strong) CBAdView *bannerAd;

@end

@implementation MPUberMediaBannerCustomEvent

- (void)requestAdWithSize:(CGSize)size customEventInfo:(NSDictionary *)info {
    [self requestAdWithSize:size adapterInfo:info adMarkup:nil];
}

- (void)requestAdWithSize:(CGSize)size adapterInfo:(NSDictionary *)info adMarkup:(NSString * _Nullable)adMarkup;
{
    NSLog(@"[ClearBid] Using MoPub adapter custom event info: %@ and size %dx%d", info, (int)size.width, (int)size.height);
    
    self.bannerAd = [ClearBid getAdViewForCachedAd:[info objectForKey:@"ad_unit_id"] andSize:size];
    self.bannerAd.frame = CGRectMake(0, 0, size.width, size.height);
    self.bannerAd.delegate = self;
    
    if (self.bannerAd) {
        [self.delegate inlineAdAdapter:self didLoadAdWithAdView:self.bannerAd];
    } else {
        [self.delegate inlineAdAdapter:self didFailToLoadAdWithError:nil];
    }
}

- (void)willLeaveApplicationFromAd:(CBAdView *)view
{
    [self.delegate bannerCustomEventWillLeaveApplication:self];
}

@end
