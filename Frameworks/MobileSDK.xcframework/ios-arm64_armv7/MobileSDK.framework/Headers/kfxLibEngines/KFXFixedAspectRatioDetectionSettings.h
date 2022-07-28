//
//  KFXFixedAspectRatioDetectionSettings.h
//  kfxLibEngines
//
//  Copyright (c) 2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKEDDocumentBaseDetectionSettings.h"

//! A configuration object for controlling the Fixed Aspect Ratio Detector.
@interface KFXFixedAspectRatioDetectionSettings : kfxKEDDocumentBaseDetectionSettings

/// Initializes a new object using the specified document base detection settings.
/**
 Returns the newly initialized object with the specified properties.
 */
- (instancetype)initWithSettings:(kfxKEDDocumentBaseDetectionSettings*)settings;

/// The aspect ratio of the rectangular frame that should match the document being searched.
/**
 The aspect ratio is used to construct the target frame that should match the document being searched.
 If targetFrameAspectRatio > 1, the long edge of the target frame will align with the long edge of the camera preview. If 0 < targetFrameAspectRatio < 1, the long edge of the target frame will align with the short edge of the camera preview.
 
 If the targetFrameAspectRatio is set to 0, then it will be automatically reset to an image aspect ratio.
 Setting negative values has the same effect as if 0 was set.
 
 The default value is 2.125 / 3.375.
 */
@property (nonatomic, assign) CGFloat targetFrameAspectRatio;

/// The minimum padding in percent length to be maintained between the edges of the target frame and image.
/**
 Given a center point and aspect ratio, a rectangular frame will be constructed to cover as much of the image as possible without any the distances between a frame edge and image edge falling below the padding distance, calculated as percent of the perpendicular image edge length.  Values will be clamped to the range [1-50].
 
 The default value is 8.
 */
@property (nonatomic, assign) CGFloat targetFramePaddingPercent;

/// The minimum fill area as a fraction of the target frame.
/**
 Not supported. Setting this property do nothing. Returns 0 whatever is set.
 */
@property (nonatomic, assign) CGFloat zoomMinFillFraction;

/// The maximum fill area as a fraction of the target frame.
/**
 Not supported. Setting this property do nothing. Returns 0 whatever is set.
 */
@property (nonatomic, assign) CGFloat zoomMaxFillFraction;

/// The maximum angle the document can be rotated off from the target frame.
/**
 Not supported. Setting this property do nothing. Returns 0 whatever is set.
 */
@property (nonatomic, assign) CGFloat turnSkewAngleTolerance;

/// The maximum distance the document can be shifted above or below the target frame.
/**
 Not supported. Setting this property do nothing. Returns 0 whatever is set.
 */
@property (nonatomic, assign) CGFloat verticalMovementTolerance;

/// The maximum distance the document can be shifted left of right of the target frame.
/**
 Not supported. Setting this property do nothing. Returns 0 whatever is set.
 */
@property (nonatomic, assign) CGFloat horizontalMovementTolerance;

@end
