//
//  UMAdView.h
//  UberMedia
//
//  Created by Joel Green on 6/26/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Initalize this view in your code or via the storyboard/nib. Then call loadAd:forSize: to request and ad and start the refresh rate of 30 seconds.
 Change or disable refreshing via changeAdRefreshRate:
 
 @discussion Your adUnitId should be unique for the ad placement. For most use cases you will only need one adUnitId for your banner ad.
             The adUnitId can be used to track performance of different ad placements.
 */
@interface UMAdView : UIView


/**
 After initalizing your view call this method to load an ad of your desired size.

 @param adUnitId The identifier for the ad placement. All impressions in this space should have the same adUnitId.
 @param size The default size of the ad you want to display. 320x50 is the recommended default size.
 */
- (void)loadAd:(NSString *)adUnitId forSize:(CGSize)size;


/**
 Change the refresh rate in seconds of your ad placement. This defaults to 30 seconds. This may range between 10 and 120 seconds. Setting to 0 will disable ad refreshing entirely.

 @param adRefreshRate Refresh rate in seconds as an int. Valid between 10 to 120. 0 Disables refreshing.
 */
- (void)changeAdRefreshRate:(int)adRefreshRate;

@end
