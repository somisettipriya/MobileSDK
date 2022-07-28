//
//  kfxKEDDocumentDetectionSettings.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKEDDocumentBaseDetectionSettings.h"

//! An enumeration containing the possible edge detection algorithms.
/**
 Use one of the values of this enumeration to set the edge detection algorithm.
 */
typedef NS_ENUM(NSInteger, kfxKEDDocumentEdgeDetection)
{
    kfxKEDDocumentEdgeDetection_ISG DEPRECATED_ATTRIBUTE,
    kfxKEDDocumentEdgeDetection_GPUBased,
    //kfxKEDDocumentEdgeDetection_CIRectangleDetector __OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0)
};

/// A configuration object for controlling the kfxKCDDocumentDetector object.
@interface kfxKEDDocumentDetectionSettings : kfxKEDDocumentBaseDetectionSettings

/// The minimum page size threshold for the long axis of the control.
/**
 This property is a percent value.  The valid range is [0 - 100].  Any values outside this range
 will be interpreted as the closest valid value (0 or 100).
 When page detection is enabled, this property specifies the minimum size of the page that spans the
 long axis of the ImageCaptureControl preview area.  If the page is smaller than the threshold, it
 will not be captured.  If the detected page is rotated in the preview, it will be aligned to the
 closest 90 degree orientation before any comparison is made.
 
 The value 0 will disable page long axis threshold check.
 The default value is 85.
 
 Because page detection requires some margin around a page to properly detect it, the useful upper
 limit of this property is around 90%.
 */
@property (nonatomic) int longAxisThreshold;

/// The minimum page size threshold for the short axis of the control.
/**
 This property is a percent value.  The valid range is [0 - 100].  Any values outside this range
 will be interpreted as the closest valid value (0 or 100).
 When page detection is enabled, this property specifies the minimum size of the page that spans the
 short axis of the ImageCaptureControl preview area.  If the page is smaller than the threshold, it
 will not be captured.  If the detected page is rotated in the preview, it will be aligned to the
 closest 90 degree orientation before any comparison is made.
 
 The value 0 will disable page short axis threshold check.
 The default value is 85.
 
 Because page detection requires some margin around a page to properly detect it, the useful upper
 limit of this property is around 90%.
 */
@property (nonatomic) int shortAxisThreshold;

/// The minimum fill area as a fraction of the target frame.
/**
 The minimum fill fraction puts a lower bound on what is considered an acceptable zoom level. If the area of a detected document is less then the area of the target frame multiplied by the minimum fill fraction, guidance will suggest zooming in on the document.
 The default value is 0.2.
 */
@property (nonatomic) CGFloat zoomMinFillFraction;

/// The document edge detection algorithm.
/**
 The supported algorithms are:
 kfxKEDDocumentEdgeDetection_ISG. Deprecated in 3.3. ISG document detection algorithm, which is a legacy.
 kfxKEDDocumentEdgeDetection_GPUBased. GPU based document detection algorithm. Can't be used while application is in background state, since it's using OpenGLES rendering.
 
 The default algorithm is kfxKEDDocumentEdgeDetection_GPUBased.
 */
@property (nonatomic) kfxKEDDocumentEdgeDetection edgeDetection;

/// Initializes a new object using the specified document base detection settings.
/**
 Returns the newly initialized object with the specifide properties.
 */
- (instancetype)initWithSettings:(kfxKEDDocumentBaseDetectionSettings*)settings;

@end
