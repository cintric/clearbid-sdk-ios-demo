//
//  ClearBidMPInterstitialCustomEvent.m
//  UberMediaTestApp
//
//  Created by Joel Green on 1/12/18.
//  Copyright © 2018 UberMedia. All rights reserved.
//

#import "ClearBidMPInterstitialCustomEvent.h"
#import <UberMedia/UberMedia.h>

@interface ClearBidMPInterstitialCustomEvent () <CBInterstitialAdViewControllerDelegate>

@property (strong, nonatomic) CBInterstitialAdViewController *interstitial;

@end

@implementation ClearBidMPInterstitialCustomEvent

#pragma mark - MPInterstitialCustomEvent Subclass Methods

- (void)requestInterstitialWithCustomEventInfo:(NSDictionary *)info
{
    CGSize size = CGSizeMake(320, 480);
    if ([info objectForKey:@"h"]) {
        size.height = (CGFloat)[[info objectForKey:@"h"] integerValue];
    }
    if ([info objectForKey:@"w"]) {
        size.width = (CGFloat)[[info objectForKey:@"w"] integerValue];
    }
    
    NSLog(@"[UberMedia] Using MoPub interstitial adapter custom event info: %@ and size %dx%d", info, (int)size.width, (int)size.height);
    
    NSString *adUnitId = [info objectForKey:@"ad_unit_id"];
    if (!adUnitId) {
        NSLog(@"[UberMedia] No ad_unit_id in server parameters for mopub interstital.");
    }
    
    self.interstitial = [UberMedia getInterstitialForCachedAd:adUnitId andSize:size];
    self.interstitial.delegate = self;
    if (self.interstitial) {
        [self.delegate interstitialCustomEvent:self didLoadAd:self];
    } else {
        [self.delegate interstitialCustomEvent:self didFailToLoadAdWithError:nil];
    }
}

- (void)showInterstitialFromRootViewController:(UIViewController *)rootViewController
{
    [self.interstitial presentInterstitialFromViewController:rootViewController];
}

- (void)dealloc
{
    self.interstitial.delegate = nil;
}

#pragma mark - CBInterstitialAdViewControllerDelegate


- (void)interstitialWillAppear:(CBInterstitialAdViewController *)interstitial
{
    [self.delegate interstitialCustomEventWillAppear:self];
}

- (void)interstitialDidAppear:(CBInterstitialAdViewController *)interstitial
{
    [self.delegate interstitialCustomEventDidAppear:self];
}

- (void)interstitialWillDismiss:(CBInterstitialAdViewController *)controller
{
    [self.delegate interstitialCustomEventWillDisappear:self];
}

- (void)interstitialDidDismiss:(CBInterstitialAdViewController *)interstitial
{
    [self.delegate interstitialCustomEventDidDisappear:self];
}

- (void)interstitialWillLeaveApplication:(CBInterstitialAdViewController *)interstitial
{
    [self.delegate interstitialCustomEventDidReceiveTapEvent:self];
    [self.delegate interstitialCustomEventWillLeaveApplication:self];
}


@end
