//
//  API Reference
//  kfxCaptureData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>

//! Base class for document data objects.
/**
 Represents images captured by kfxCaptureViewController inherited classes and processed image by image processor.
 
 @see kfxCaptureViewController
 */
@interface kfxCaptureData : NSObject

/// Identifier for the image captured by capture view controller classes.
/**
 Default value is nil.
 */
@property (nonatomic, strong) NSString* originalImage;

/// Identifier for the image processed by image processor.
/**
 Will be nil if processing is disabled.
 Default value is nil.
 */
@property (nonatomic, strong) NSString* processedImage;

@end
