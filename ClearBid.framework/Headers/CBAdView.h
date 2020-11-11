//
//  CBAdView.h
//  ClearBid
//
//  Created by Bujar Muliqi on 19.02.18.
//  Copyright © 2018 ClearBid. All rights reserved.
//

// Vendor
#import <UIKit/UIKit.h>

@protocol CBAdViewDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 Initalize this view in your code or via the storyboard/nib. Then call loadAd:forSize: to request and ad and start the refresh rate of 30 seconds.
 Change or disable refreshing via changeAdRefreshRate:
 
 @discussion Your adUnitId should be unique for the ad placement. For most use cases you will only need one adUnitId for your banner ad.
 The adUnitId can be used to track performance of different ad placements.
 */
@interface CBAdView : UIView

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


/**
 The delegate of this ad view.
 */
@property (nonatomic, weak, nullable) id<CBAdViewDelegate> delegate;

@end

@protocol CBAdViewDelegate <NSObject>

@required

/**
 Represents the View Controller, from which the navigations further take place.
 */
- (nullable UIViewController *)hostingViewController;

@optional

/**
 Called when an ad view successfully loads
 
 @param view Reference to the instance of CBAdView which has successfully loaded an ad
 */
- (void)adViewDidLoadAd:(CBAdView *)view;


/**
 Called when an ad view fails to load. This may happen if there is an error, of if no bids are returned for the placement.
 
 @param view Reference to the instance of CBAdView which has failed to load an ad
 @param message A message describing why the ad has failed to load
 */
- (void)adViewDidFailToLoadAd:(CBAdView *)view withMessage:(nullable NSString *)message;


/**
 Called when the ad is clicked. The user will exit the application via the url provided by the advertisement.
 
 @param view Reference to the instance of CBAdView which has been clicked
 */
- (void)willLeaveApplicationFromAd:(CBAdView *)view;

/**
 Called when an ad view will close the ad
 
 @param view Reference to the instance of CBAdView which has successfully loaded an ad
 */
- (void)adViewWillCloseAd:(CBAdView *)view;

/**
 Called when an ad view did close the ad
 
 @param view Reference to the instance of CBAdView which has successfully loaded an ad
 */
- (void)adViewDidCloseAd:(CBAdView *)view;

@end

NS_ASSUME_NONNULL_END
