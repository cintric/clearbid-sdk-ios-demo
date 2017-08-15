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

@end
