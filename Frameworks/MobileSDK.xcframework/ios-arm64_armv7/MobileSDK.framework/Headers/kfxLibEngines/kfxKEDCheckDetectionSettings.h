//
//  kfxKEDCheckDetectionSettings.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKEDDocumentBaseDetectionSettings.h"
#import "kfxKEDCheckDetectionResult.h"

//! A configuration object for controlling the kfxKCDCheckDetector object.
@interface kfxKEDCheckDetectionSettings : kfxKEDDocumentBaseDetectionSettings

/// The side of the check to be searched.
/**
 The side of the check for detection.
 By default is KED_CHECK_SIDE_FRONT.

 @see KEDCheckSide
 */
@property (nonatomic) KEDCheckSide checkSide;

/// The tolerance that needs to check the aspect ratio value while detection of check back side.
/**
 The tolerance is specified as a fraction of the target frame aspect ratio.
 Default value 0 means that this check is disabled.

 The default tolerance value is 0.
 */
@property (nonatomic) CGFloat aspectRatioTolerance;

/// The aspect ratio of the rectangular frame that should match the check being searched.
/**
 The aspect ratio is presented in the format of longEdge/shortEdge, and is used to construct the target frame.
 
 If targetFrameAspectRatio is in range (0, 1) it will be inverted.
 For example: the ratio 0.4 (2.0/5.0) will be inverted to 2.5 (5.0/2.0).
 
 If the targetFrameAspectRatio is set to 0, then it will be automatically reset to an image aspect ratio.
 Setting negative values has the same effect as if 0 was set.
 
 The default value is 2.18 (6.0 / 2.75).
 */
@property (nonatomic) CGFloat targetFrameAspectRatio;

/// Initializes a new object using the specified document base detection settings.
/**
 Returns the newly initialized object with the specifide properties.
 */
- (instancetype)initWithSettings:(kfxKEDDocumentBaseDetectionSettings*)settings;

@end
