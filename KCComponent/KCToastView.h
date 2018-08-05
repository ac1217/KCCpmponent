//
//  KCToastView.h
//  KCCommon
//
//  Created by Erica on 2018/8/2.
//  Copyright © 2018年 Erica. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    KCToastViewPositionCenter,
    KCToastViewPositionTop,
    KCToastViewPositionBottom
} KCToastViewPosition;

typedef enum : NSUInteger {
    KCToastViewLayoutDirectionHorizontal,
    KCToastViewLayoutDirectionVertical
} KCToastViewLayoutDirection;

typedef enum : NSUInteger {
    KCToastViewStyleLoading,
    KCToastViewStyleSuccess,
    KCToastViewStyleError,
    KCToastViewStyleInfo,
    KCToastViewStyleProgress
} KCToastViewStyle;

typedef enum : NSUInteger {
    KCToastViewMaskTypeNone,
    KCToastViewMaskTypeClear,
    KCToastViewMaskTypeBlack
} KCToastViewMaskType;

typedef enum : NSUInteger {
    KCToastViewLoadingTypeDefault,
    KCToastViewLoadingTypeGif
} KCToastViewLoadingType;


@interface KCToastView : UIControl

+ (instancetype)toastView;

@property (nonatomic,assign) KCToastViewStyle style;
@property (nonatomic,copy) NSString *text;
@property (nonatomic,assign) float progress;
 /**
  * toast展示的位置
  */
@property (nonatomic,assign) KCToastViewPosition position;// apprance
/**
 * loading类型：gif或者菊花
 */
@property (nonatomic,assign) KCToastViewLoadingType loadingType;// apprance
/**
 * 背景颜色以及是否允许交互
 */
@property (nonatomic,assign) KCToastViewMaskType maskType;// apprance
/**
 * 布局方向
 */
@property (nonatomic,assign) KCToastViewLayoutDirection layoutDirection;// apprance
/**
 * 内容背景颜色
 */
@property (nonatomic,strong) UIColor *contentBackgroundColor;// apprance
@property (nonatomic,strong) UIFont *textFont;// apprance
@property (nonatomic,strong) UIColor *textColor;// apprance
@property (nonatomic,strong) NSArray *loadingImages;// apprance
@property (nonatomic,strong) UIImage *successImage;// apprance
@property (nonatomic,strong) UIImage *errorImage;// apprance
@property (nonatomic,strong) UIImage *infoImage;// apprance
/**
 * 限制image最大尺寸
 */
@property (nonatomic,assign) CGSize maxImageSize;// apprance
/**
 * 显示市场。到时自动消失，大于0时有效
 */
@property (nonatomic,assign) NSTimeInterval duration;

- (void)showInView:(UIView *)view;
- (void)dismiss;

@end