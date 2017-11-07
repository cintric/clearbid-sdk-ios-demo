//
//  UberMedia.h
//  UberMedia
//
//  Created by Joel Green on 6/13/17.
//  Copyright © 2017 UberMedia. All rights reserved.
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

#import <UberMedia/UMAdView.h>

//------------------------------------------------
// Cintric Class Interface
//------------------------------------------------

//! Project version number for UberMedia.
FOUNDATION_EXPORT double UberMediaVersionNumber;

//! Project version string for UberMedia.
FOUNDATION_EXPORT const unsigned char UberMediaVersionString[];

@interface UberMedia : NSObject

/**
 Initalize the UberMedia SDK with your key and secret.
 Call this method in application:didFinishLaunchingWithOptions: before requesting an ad.
 
 @param sdkKey The sdk key associated with your account.
 @param secret The secret key associated with your account. (Keep this secure!)
 */
+ (void)initWithSDKKey:(NSString *)sdkKey andSecret:(NSString *)secret;

/**
 Call this method to pre-cache an ad (usually in your app delegate or primary view controller).

 @param adUnitId Your UberMedia ad unit id. Use test_ad_placement_id to get test ads.
 @param size The size of your desired banner ad.
 */
+ (void)preCacheAd:(NSString *)adUnitId forSize:(CGSize)size;


/**
 If you precache an ad you can pass targeting parameters in with ad requests to DFP (or other exchanges) for targeted line items.
 These parameters should be included with your DFP request when using line items with preset price bands.

 @param adUnitId Your UberMedia ad unit id associated with a precached ad.
 @return Dictionary of all key value targeting parameters.
 */
+ (NSDictionary *)getTargetingParametersForAd:(NSString *)adUnitId;

/**
 Same as getTargetingParemetersForAd but returns them as a string as form: "key1:value1,key2:value2". This is required for mopub.
 
 @param adUnitId Your UberMedia ad unit id associated with a precached ad.
 @return Dictionary of all key value targeting parameters.
 */
+ (NSString *)getTargetingParametersAsStringForAd:(NSString *)adUnitId;

/**
 If you have precached an ad this will return it an ad view ready for display. It will also immediately cache another ad.

 @param adUnitId Your UberMedia ad unit id associated with a precached ad.
 @param adSize The size of your banner ad.
 @return Ad view ready for display.
 */
+ (UMAdView *)getAdViewForCachedAd:(NSString *)adUnitId andSize:(CGSize)adSize;

@end
