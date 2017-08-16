# Demo app for the UberMedia Header Bidding SDK (v0.1.7)

The UberMedia Header Bidding SDK for iOS allows you to optimize ad revenue by creating an open auction for your ad space instead of using the traditional waterfall method like other mediation SDKs. It is lightweight and optimized to minimize impact on your application.

### Initalize the sdk
To integrate the sdk drag and drop the `UberMedia.bundle` and `UberMedia.framework` files into your project.

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

### Configure your project

It is very critical to enable arbitrary loads in your `Info.plist` file. This is because advertisements pull content from websites that are not using ssl. To do so right click on your `Info.plist` file and select `Open As > Source Code` and paste this directly below the line that says `<dict>` (usually line 4):

```xml
<key>NSAppTransportSecurity</key>
<dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
</dict>
```

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

Optionally, you can also use the storyboard or a nib by setting your view class to `UMAdView` in the interface builder.
You will still need request an ad in your view controller.
```objective-c
[self.adView loadAd:@"test_ad_placement_id" forSize:CGSizeMake(320, 50)];
```

If using the interface builder `self.adView` should be an `IBOutlet` pointing to the view in your interface.

### (Optional) Delegate Methods

You can implement delegate methods via the `UMAdViewDelegate` protocol.

```objective-c
#pragma mark - UMAdViewDelegate methods

- (void)adViewDidLoadAd:(UMAdView *)view
{
    NSLog(@"UM Ad view did load %@", view);
}

- (void)adViewDidFailToLoadAd:(UMAdView *)view withMessage:(NSString *)message
{
    NSLog(@"UM Ad view failed to load %@ with message %@", view, message);
}

- (void)willLeaveApplicationFromAd:(UMAdView *)view
{
    NSLog(@"Will leave application from ad %@", view);
}
```

### (Optional) Adapters

To use the SDK with other mediation platforms will require adapters. Included in the [Adapters folder](https://github.com/cintric/ubermedia-sdk-ios-demo/tree/master/Adapters) is the adapter class for the google admob sdk (also compatible with Google's Double Click for Publishers.)

Just include the adapter in your project and set up a mediation layer in the console to invoke the custom class named `UMAdMobCustomEventBanner`. Set the server paramater to your ubermedia placement ID. For testing you can use `test_ad_placement_id`. 
