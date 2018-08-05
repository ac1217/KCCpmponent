//
//  KCNavigationView.h
//  KuShow
//
//  Created by iMac on 2017/6/6.
//  Copyright © 2017年 Rex. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KSNavigationButtonItem : NSObject <UIAppearance>

@property (nonatomic,copy) NSString *title;

@property (nonatomic,strong) UIFont *titleFont; // apprance
@property (nonatomic,strong) UIColor *titleColor; // apprance
@property (nonatomic,strong) UIColor *highlightedTitleColor; // apprance
@property (nonatomic,strong) UIColor *selectedTitleColor; // apprance
@property (nonatomic,strong) UIColor *disabledTitleColor; // apprance

@property (nonatomic,strong) UIImage *image;
@property (nonatomic,strong) UIImage *highlightedImage;
@property (nonatomic,strong) UIImage *disabledImage;
@property (nonatomic,strong) UIImage *selectedImage;

@property (nonatomic,assign, getter=isEnabled) BOOL enabled;
@property (nonatomic,assign, getter=isSelected) BOOL selected;
@property (nonatomic,copy) void(^handle)(KSNavigationButtonItem * buttonItem);

+ (instancetype)itemWithTitle:(NSString *)title handle:(void(^)(KSNavigationButtonItem * item))handle;;
- (instancetype)initWithTitle:(NSString *)title handle:(void(^)(KSNavigationButtonItem * item))handle;;


+ (instancetype)itemWithImage:(UIImage *)image handle:(void(^)(KSNavigationButtonItem * item))handle;
- (instancetype)initWithImage:(UIImage *)image handle:(void(^)(KSNavigationButtonItem * item))handle;

+ (instancetype)itemWithImage:(UIImage *)image highlightedImage:(UIImage *)highlightedImage handle:(void(^)(KSNavigationButtonItem * item))handle;
- (instancetype)initWithImage:(UIImage *)image highlightedImage:(UIImage *)highlightedImage handle:(void(^)(KSNavigationButtonItem * item))handle;

+ (instancetype)itemWithTitle:(NSString *)title image:(UIImage *)image highlightedImage:(UIImage *)highlightedImage handle:(void(^)(KSNavigationButtonItem * item))handle;

- (instancetype)initWithTitle:(NSString *)title image:(UIImage *)image highlightedImage:(UIImage *)highlightedImage handle:(void(^)(KSNavigationButtonItem * item))handle;

@end


@interface KCNavigationView : UIView
// 此类方法返回的实例会带apprance效果
+ (instancetype)navigationView;

@property (nonatomic,assign, getter=isTranslucent) BOOL translucent;

// 状态栏
@property (nonatomic,strong) UIImageView *statusBar;

@property (nonatomic,strong) UILabel *titleLabel;
/**** 背景色默认白色，也可以设置图片，可设置alpha透明度 ****/
@property (nonatomic,strong) UIImageView *backgroundView;
@property (nonatomic,strong) UIImageView *shadowView;

@property (nonatomic,strong) UIImage *backgroundImage;
@property (nonatomic,strong) UIImage *shadowImage;
@property (nonatomic,strong) UIImage *statusBarImage;

@property (nonatomic,assign) CGFloat itemSpacing; // apprance
@property (nonatomic,assign) CGFloat itemInset; // apprance

/*** 设置背景透明度，同时设置backgroundView和shadowView, statusBar **/
@property (nonatomic,assign) CGFloat backgroundAlpha;


@property (nonatomic,strong) UIFont *titleFont; // apprance
@property (nonatomic,strong) UIColor *titleColor; // apprance
@property (nonatomic,copy) NSString *title;
@property (nonatomic,strong) NSAttributedString *attributedTitle;
@property (nonatomic,strong) UIView *titleView;

@property (nonatomic,strong) KSNavigationButtonItem *leftButtonItem;
@property (nonatomic,strong) KSNavigationButtonItem *rightButtonItem;

@property (nonatomic,strong) NSArray <KSNavigationButtonItem *>*leftButtonItems;
@property (nonatomic,strong) NSArray <KSNavigationButtonItem *>*rightButtonItems;


- (void)addLeftButtonItem:(KSNavigationButtonItem *)buttonItem;
- (void)addRightButtonItem:(KSNavigationButtonItem *)buttonItem;
-(void)removeButtonItem:(KSNavigationButtonItem *)buttonItem;

- (void)insertLeftButtonItem:(KSNavigationButtonItem *)buttonItem atIndex:(NSUInteger)index;
- (void)removeLeftButtonItemAtIndex:(NSUInteger)index;
- (void)insertRightButtonItem:(KSNavigationButtonItem *)buttonItem atIndex:(NSUInteger)index;
- (void)removeRightButtonItemAtIndex:(NSUInteger)index;

- (UIButton *)buttonWithButtonItem:(KSNavigationButtonItem *)buttonItem;
- (UIButton *)leftButtonAtIndex:(NSUInteger)index;
- (UIButton *)rightButtonAtIndex:(NSUInteger)index;

@end