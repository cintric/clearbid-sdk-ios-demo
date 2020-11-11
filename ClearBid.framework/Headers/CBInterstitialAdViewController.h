//
//  CBInterstitialAdViewController.h
//  ClearBid
//
//  Created by Bujar Muliqi on 02.04.18.
//  Copyright © 2018 ClearBid. All rights reserved.
//

// Vendor
#import <UIKit/UIKit.h>

// Protocols
@protocol CBInterstitialAdViewControllerDelegate, CBOrientationForceProtocol;

NS_ASSUME_NONNULL_BEGIN

@interface CBInterstitialAdViewController : UIViewController

/**
 Creates interstitial ad view controller for unit id provided.
 
 The new object starts to load ad immediately.
 
 @param adUnitId The identifier for the ad placement.
 @param size The default size of the ad you want to display.
 @param viewController A root view controller for presenting interstitial.
 @return A newly constructed interstitial ad view controller.
 */
+ (CBInterstitialAdViewController *)newInterstitialForAdUnitId:(NSString *)adUnitId andSize:(CGSize)size fromViewController:(nullable UIViewController *)viewController;

/**
 Present interstitial controller using view contoller provided in fabric method.
 */
- (void)presentInterstitial;

/**
 Present interstitial controller using viewContoller.
 
 @param viewController A root view controller for presenting interstitial.
 */
- (void)presentInterstitialFromViewController:(UIViewController *)viewController;

/**
 The delegate for interstitial methods.
 */
@property (nonatomic, weak, nullable) id<CBInterstitialAdViewControllerDelegate> delegate;

@end

@protocol CBInterstitialAdViewControllerDelegate <NSObject>

@optional

- (void)interstitialReadyToAppear:(CBInterstitialAdViewController *)interstitial;

- (void)interstitialWillAppear:(CBInterstitialAdViewController *)interstitial;

- (void)interstitialDidAppear:(CBInterstitialAdViewController *)interstitial;

- (void)interstitialWillDismiss:(CBInterstitialAdViewController *)controller;

- (void)interstitialDidDismiss:(CBInterstitialAdViewController *)interstitial;

- (void)interstitialWillLeaveApplication:(CBInterstitialAdViewController *)interstitial;

@end

NS_ASSUME_NONNULL_END
