//
//  CBInterstitialAdViewController.h
//  UberMedia
//
//  Created by Joel Green on 12/20/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CBInterstitialAdViewControllerDelegate;

@interface CBInterstitialAdViewController : UIViewController

+ (CBInterstitialAdViewController *)displayInterstitialForAdUnitId:(NSString *)adUnitId andSize:(CGSize)size fromViewController:(UIViewController *)viewController;

- (void)presentInterstitialFromViewController:(UIViewController *)viewController;

/**
 The delegate for interstitial methods.
 */
@property (nonatomic, weak) id<CBInterstitialAdViewControllerDelegate> delegate;

@end

@protocol CBInterstitialAdViewControllerDelegate <NSObject>

@required
@optional

- (void)interstitialWillAppear:(CBInterstitialAdViewController *)interstitial;

- (void)interstitialDidAppear:(CBInterstitialAdViewController *)interstitial;

- (void)interstitialWillDismiss:(CBInterstitialAdViewController *)controller;

- (void)interstitialDidDismiss:(CBInterstitialAdViewController *)interstitial;

- (void)interstitialWillLeaveApplication:(CBInterstitialAdViewController *)interstitial;

@end

