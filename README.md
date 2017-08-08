# Demo app for the UberMedia Header Bidding SDK (v0.1.5)

To integrate the sdk drag and drop the UberMedia.bundle and UberMedia.framework files into your project.

In your application delegate initalize the sdk:
```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // Always initalize the ubermedia sdk before requesting advertisements.
    [UberMedia initWithSDKKey:@"YOUR_SDK_KEY_HERE" andSecret:@"YOUR_SECRET_KEY_HERE"];
    
    // Override point for customization after application launch.
    return YES;
}
```
Put in your own sdk key and secret here.

### Displaying an ad.
To display a banner ad, initalize the UMAdView class like so:
```objective-c
    CGRect frame = CGRectMake(0, [UIApplication sharedApplication].statusBarFrame.size.height, self.view.frame.size.width, 50);
    UMAdView *adView = [[UMAdView alloc] initWithFrame:frame];
    [self.view addSubview:adView];
    self.adView = adView;
    
    // Call this to load your ad (IMPORTANT: change the placement_id or you will only get test ads.)
    [self.adView loadAd:@"test_ad_placement_id" forSize:CGSizeMake(320, 50)];
    
    // The ad will default to a 30 second refresh rate, you can use this method to change the refresh rate. Set to 0 to disable refreshing.
    [self.adView changeAdRefreshRate:60];
```
