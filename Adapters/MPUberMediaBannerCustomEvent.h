//
//  MPUberMediaBannerCustomEvent.h
//  UberMediaTestApp
//
//  Created by Joel Green on 6/14/17.
//  Copyright © 2017 UberMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#else
#import "MPInlineAdAdapter.h"
#endif

@interface MPUberMediaBannerCustomEvent : MPInlineAdAdapter

@end
