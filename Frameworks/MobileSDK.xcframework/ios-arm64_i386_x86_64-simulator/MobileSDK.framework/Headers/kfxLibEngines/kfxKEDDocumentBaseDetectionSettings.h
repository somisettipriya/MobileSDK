//
//  kfxKEDDocumentBaseDetectionSettings.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

//! Base class for detector settings
/**
 The primary purpose of the settings object is to define properties of a rectangular target frame.  The target frame is a rectangular area confined within the bounds of the image, and represents the the ideal area that should be covered by a document.  Results returned from the document detector will provide adjustment guidance relative to the target frame.
 
 A target frame is constructed from a center point, an aspect ratio, and a minimum edge padding.  The size of the target frame is the largest possible rectangle that can be made without violating any of these constraints.
 
 Additional settings properties set tolerances on the guidance available from a result object.
 */
@interface kfxKEDDocumentBaseDetectionSettings : NSObject

/// The center point within the image of the target frame.
/**
 The center point is any point within the image that the target frame will be constructed around and centered over.  This value will be clamped the valid area of the image being searched, and by default is set to the center of the image.
 */
@property (nonatomic) CGPoint targetFrameCenter;

/// The minimum padding in percent length to be maintained between the edges of the target frame and image.
/**
 Given a center point and aspect ratio, a rectangular frame will be constructed to cover as much of the image as possible without any the distances between a frame edge and image edge falling below the padding distance, calculated as percent of the perpendicular image edge length.  Values will be clamped to the range [1-50].  The default value is 5.
 
 For example:
 - Given detection settings with a frame center at the center of the image, and a personal check aspect ratio, the constructed frame will fill the width of the image, leaving a space on the left and right equal to the padding percent of the image width.
 
 - Given detection settings with a frame center shifted to the left of the image center, the gap on the right side of the constructed frame will exceed the gap on the left.
 
 @see targetFrameCenter
 @see targetFrameAspectRatio
 */
@property (nonatomic) CGFloat targetFramePaddingPercent;

/// The aspect ratio of the rectangular frame that should match the document being searched.
/**
 The aspect ratio is used to construct the target frame that should match the document being searched.
 
 If targetFrameAspectRatio > 1, the long edge of the target frame will align with the long edge of the camera preview. If 0 < targetFrameAspectRatio < 1, the long edge of the target frame will align with the short edge of the camera preview.

 If the targetFrameAspectRatio is set to 0, then it will be automatically reset to an image aspect ratio.
 Setting negative values has the same effect as if 0 was set.
 
 The default value is 1.45.
 
 */
@property (nonatomic) CGFloat targetFrameAspectRatio;

/// The minimum fill area as a fraction of the target frame.
/**
 The minimum fill fraction puts a lower bound on what is considered an acceptable zoom level.  If the area of a detected document is less then the area of the target frame multiplied by the minimum fill fraction, guidance will suggest zooming in on the document.  The default value is 0.65.
 */
@property (nonatomic) CGFloat zoomMinFillFraction;

/// The maximum fill area as a fraction of the target frame.
/**
 The maximum fill fraction puts an upper bound on what is considered an acceptable zoom level.  If the area of a detected document is greater then the area of the target frame multiplied by the minimum fill fraction, guidance will suggest zooming out from the document.  The default value is 1.5.
 */
@property (nonatomic) CGFloat zoomMaxFillFraction;

/// The maximum angle the document can be rotated off from the target frame.
/**
 The skew angle tolerance puts an upper bound on how far a document can be rotated clockwise or counter-clockwise relative to the target frame and still be considered acceptable.  Angles of rotation greater than the tolerance will result in guidance to turn the document.  The default value is 10, specified in degrees.
 */
@property (nonatomic) CGFloat turnSkewAngleTolerance;

/// The maximum distance the document can be shifted above or below the target frame.
/**
 The vertical movement tolerance puts an upper bound on how far a document can be shifted above or below the target frame and still be considered acceptable.  The tolerance is specified as a fraction of the target height, and the comparison is made between the center of the target frame and the center of the detected document bounds.
 
 The default tolerance value is 0.15.
 */
@property (nonatomic) CGFloat verticalMovementTolerance;

/// The maximum distance the document can be shifted left of right of the target frame.
/**
 The horizontal movement tolerance puts an upper bound on how far a document can be shifted left of right of the target frame and still be considered acceptable.  The tolerance is specified as a fraction of the target width, and the comparison is made between the center of the target frame and the center of the detected document bounds.
 
 The default tolerance value is 0.15.
 */
@property (nonatomic) CGFloat horizontalMovementTolerance;

@end
