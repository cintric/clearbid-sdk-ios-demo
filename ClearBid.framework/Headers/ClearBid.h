//
//  ClearBid.h
//  ClearBid
//
//  Created by Joel Green on 6/13/17.
//  Copyright © 2017 ClearBid. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AdSupport/AdSupport.h>

//------------------------------------------------
// Dependencies
//------------------------------------------------

#import <CoreLocation/CoreLocation.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <SystemConfiguration/SystemConfiguration.h>

//------------------------------------------------
// Public Imports
//------------------------------------------------

#import <ClearBid/CBAdView.h>
#import <ClearBid/CBInterstitialAdViewController.h>

//------------------------------------------------
// Cintric Class Interface
//------------------------------------------------

//! Project version number for ClearBid.
FOUNDATION_EXPORT double ClearBidVersionNumber;

//! Project version string for ClearBid.
FOUNDATION_EXPORT const unsigned char ClearBidVersionString[];

@protocol ClearBidDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface ClearBid : NSObject

/**
 Initalize the ClearBid SDK with your key and secret.
 Call this method in application:didFinishLaunchingWithOptions: before requesting an ad.
 
 @param sdkKey The sdk key associated with your account.
 @param secret The secret key associated with your account. (Keep this secure!)
 */
+ (void)initWithSDKKey:(NSString *)sdkKey andSecret:(NSString *)secret;

/**
 DEPRECATED: Use preCacheAd:forSize:interstitial:
 Call this method to pre-cache an ad (usually in your app delegate or primary view controller).

 @param adUnitId Your ClearBid ad unit id. Use test_ad_placement_id to get test ads.
 @param size The size of your desired banner ad.
 */
+ (void)preCacheAd:(NSString *)adUnitId forSize:(CGSize)size __deprecated_msg("Use preCacheAd:forSize:interstitial: instead.");

/**
 Call this method to pre-cache an ad (usually in your app delegate or primary view controller).
 
 @param adUnitId Your ClearBid ad unit id. Use test_ad_placement_id to get test ads.
 @param size The size of your desired banner ad.
 @pram isInterstitial Whether this is an interstitial ad or not
 */
+ (void)preCacheAd:(NSString *)adUnitId forSize:(CGSize)size interstitial:(BOOL)isInterstitial;


/**
 If you precache an ad you can pass targeting parameters in with ad requests to DFP (or other exchanges) for targeted line items.
 These parameters should be included with your DFP request when using line items with preset price bands.

 @param adUnitId Your ClearBid ad unit id associated with a precached ad.
 @return Dictionary of all key value targeting parameters.
 */
+ (nullable NSDictionary *)getTargetingParametersForAd:(NSString *)adUnitId;

/**
 Same as getTargetingParemetersForAd but returns them as a string as form: "key1:value1,key2:value2". This is required for mopub.
 
 @param adUnitId Your ClearBid ad unit id associated with a precached ad.
 @return Dictionary of all key value targeting parameters.
 */
+ (NSString *)getTargetingParametersAsStringForAd:(NSString *)adUnitId;

/**
 If you have precached an ad this will return it an ad view ready for display. It will also immediately cache another ad.

 @param adUnitId Your ClearBid ad unit id associated with a precached ad.
 @param adSize The size of your banner ad.
 @return Ad view ready for display.
 */
+ (nullable CBAdView *)getAdViewForCachedAd:(NSString *)adUnitId andSize:(CGSize)adSize;


+ (nullable CBInterstitialAdViewController *)getInterstitialForCachedAd:(NSString *)adUnitId andSize:(CGSize)adSize;

+ (BOOL)adIsCachedForAd:(NSString *)adUnitId andSize:(CGSize)adSize;

+ (void)setClearBidDelegate:(nullable id<ClearBidDelegate>)delegate;

/**
 Sets the US Privacy string which is included with each ad request.
 @see https://iabtechlab.com/wp-content/uploads/2019/11/U.S.-Privacy-String-v1.0-IAB-Tech-Lab.pdf
 */
+ (void)setUSPrivacyString:(nullable NSString *)usPrivacyString;

/**
 A boolean value that determines if CPM-based ad caching is disabled. If enabled, the cached ad response will only
 be replaced if a newer response has an equal or greater CPM. If disabled, the newer response will always replace the
 previously cached value.
 @note: CPM-based caching is enabled by default.
 */
+ (void)setCpmBasedCachingDisabled:(BOOL)cpmBasedCachingDisabled;

@end

@protocol ClearBidDelegate <NSObject>

@required
@optional

- (void)newAdIsCachedForId:(NSString *)adUnitId andSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
