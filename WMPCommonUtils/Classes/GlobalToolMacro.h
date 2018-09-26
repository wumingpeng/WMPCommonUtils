//
//  GlobalToolMacro.h
//  YWBaseLibrary
//
//  Created by yibin on 2016/10/26.
//  Copyright © 2016年 yibin. All rights reserved.
//

#ifndef GlobalToolMacro_h
#define GlobalToolMacro_h

// Screen
#define APP_SCREEN_WIDTH            [UIScreen mainScreen].bounds.size.width
#define APP_SCREEN_HEIGHT           [UIScreen mainScreen].bounds.size.height
#define APP_SCREEN_SIZE             (CGSize){APP_SCREEN_WIDTH,APP_SCREEN_HEIGHT}


// UI Size
#define kStatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height
#define kNavigationHeight 64
#define kTabBarHeight    (isIPHONE6Plus?64:49)

// --------------------device--------------------

//判断是否为iPhone
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad(或iPad模拟器)
#define IS_iPAD ([[[UIDevice currentDevice] model] isEqualToString:@"iPad"]||[[[UIDevice currentDevice] model] isEqualToString:@"iPad Simulator"])
//判断是否为ipod
#define IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

//----------------iPhone 机型判断---------------
// iPhone5以下设备
#define IS_PreThaniPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
// iPhone5 5s或SE
#define IS_iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
// iPhone6或7（4.7寸屏幕设备）
#define IS_iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
// plus设备（5.5寸设备）
#define IS_iPhone6plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

//--------------------系统版本号---------------------

#define IS_iOS7OrLater ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define IS_iOS8OrLater ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define IS_iOS9OrLater ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)

#define kSystemVersion  [[UIDevice currentDevice].systemVersion doubleValue]

// -------------------Shortcuts---------------------
#define USER_DEFAULT                [NSUserDefaults standardUserDefaults]
#define NOTIFICATION_CENTER         [NSNotificationCenter defaultCenter]
#define STR(key)                    NSLocalizedString(key, nil)

// -------------------Singleton---------------------
#define SINGLETON_GCD(classname)                        \
\
+ (classname *)shared##classname {                      \
\
static dispatch_once_t pred;                        \
__strong static classname * shared##classname = nil;\
dispatch_once( &pred, ^{                            \
shared##classname = [[self alloc] init]; });    \
return shared##classname;                           \
}

// ------------------block self--------------------
#define WEAKSELF __weak __typeof(self)weakSelf = self;
#define STRONGSELF __strong __typeof(weakSelf)strongSelf = weakSelf;

// ----------------------Paths-----------------------
#define APP_CACHES_PATH             [NSSearchPathForDirectoriesInDomains (NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define APP_DOC_PATH                [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]
#define APP_TEMP_PATH               NSTemporaryDirectory()

// --------------------------logout-----------------------------

// if debug
#ifdef DEBUG

#define DLog(fmt, ...)  NSLog(fmt, ##__VA_ARGS__);

#define DLogShowMe      DLog(@"--- %@", NSStringFromSelector(_cmd));

#define DLogStack       DLog(@"Call Stack: %@", [NSThread callStackSymbols]);

#define DLogRect(rect) \
DLog(@"%s x=%f, y=%f, w=%f, h=%f", #rect, rect.origin.x, rect.origin.y, \
rect.size.width, rect.size.height)

#define DLogPoint(pt) \
DLog(@"%s x=%f, y=%f", #pt, pt.x, pt.y)

#define DLogSize(size) \
DLog(@"%s w=%f, h=%f", #size, size.width, size.height)

#define DLogBOOL(value) DLog(@"%s=%@", #value, value ? @"YES" : @"NO");

#define DLogColor(_COLOR) \
DLog(@"%s h=%f, s=%f, v=%f", #_COLOR, _COLOR.hue, _COLOR.saturation, _COLOR.value)

#define DLogSuperViews(_VIEW) \
{ for (UIView* view = _VIEW; view; view = view.superview) { DLog(@"%@", view); } }

#define DLogSubViews(_VIEW) \
{ for (UIView* view in [_VIEW subviews]) { DLog(@"%@", view); } }

// else (release)
#else

#define DLog(fmt, ...)  ((void)0)
#define DLogShowMe      ((void)0);

#define NSLog(FORMAT, ...) nil

#endif

#endif /* GlobalToolMacro_h */
