//
//  RNGridMenu.h
//  RNGridMenu
//
//  Created by Ryan Nystrom on 6/11/13.
//  Copyright (c) 2013 Ryan Nystrom. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, RNGridMenuStyle) {
    RNGridMenuStyleDefault,
    RNGridMenuStyleList
};

@class RNGridMenu;
@protocol RNGridMenuDelegate <NSObject>
@optional
- (void)gridMenu:(RNGridMenu *)gridMenu willDismissWithButtonIndex:(NSInteger)buttonIndex option:(NSString *)option;
@end

@interface RNGridMenu : UIViewController

// A list of NSStrings
@property (nonatomic, strong, readonly) NSArray *options;

// A list of UIImages
@property (nonatomic, strong, readonly) NSArray *images;

// An optional delegate to receive information about what items were selected
@property (nonatomic, weak) id <RNGridMenuDelegate> delegate;

// Initialize the menu with a list of strings. Note this changes the view to style RNGridMenuStyleList since there are no images
- (id)initWithOptions:(NSArray *)options delegate:(id <RNGridMenuDelegate>)delegate;

// Initialize the menu with a list of images. Maintains style RNGridMenuStyleDefault
- (id)initWithImages:(NSArray *)images delegate:(id <RNGridMenuDelegate>)delegate;

// Initialize the menu with images and options. The count of both params must be equal (caught with assert)
- (id)initWithOptions:(NSArray *)options images:(NSArray *)images delegate:(id <RNGridMenuDelegate>)delegate;

// The color that items will be highlighted with on selection.
// default table view selection blue
@property (nonatomic, copy) UIColor *highlightColor;

// The background color of the main view (note this is a UIViewController subclass)
// default black with 0.7 alpha
@property (nonatomic, strong, readonly) UIColor *backgroundColor;

// The size of an item
// default {100, 100}
@property (nonatomic, assign) CGSize itemSize;

// The level of blur for the background image. Range is 0.0 to 1.0
// default 0.3
@property (nonatomic, assign) CGFloat blurLevel;

// default NO
@property (nonatomic, assign) BOOL addsToWindow;

// The time in seconds for the show and dismiss animation
// default 0.25f
@property (nonatomic, assign) CGFloat animationDuration;

// The text color for list items
// default white
@property (nonatomic, copy) UIColor *itemTextColor;

// The font used for list items
// default bold size 14
@property (nonatomic, copy) UIFont *itemFont;

// The text alignment of the item titles
// default center
@property (nonatomic, assign) NSTextAlignment itemTextAlignment;

// The list layout
// default RNGridMenuStyleDefault
@property (nonatomic, assign) RNGridMenuStyle menuStyle;

// An optional header view. Make sure to set the frame height when setting.
@property (nonatomic, strong) UIView *headerView;

// Show the menu
- (void)show;

// Dismiss the menu
// This is called when the window is tapped. If tapped inside the view an item will be selected.
// If tapped outside the view, the menu is simply dismissed.
- (void)dismiss;

@end
