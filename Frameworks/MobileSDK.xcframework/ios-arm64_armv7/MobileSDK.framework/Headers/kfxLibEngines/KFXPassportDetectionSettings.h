//
//  KFXPassportDetectionSettings.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKEDDocumentBaseDetectionSettings.h"

//! A configuration object for controlling the KFXPassportDetector object.
@interface KFXPassportDetectionSettings : kfxKEDDocumentBaseDetectionSettings

/// The aspect ratio of the rectangular frame that should match the passport being searched.
/**
 The aspect ratio is presented in the format of longEdge/shortEdge, and is used to construct the target frame.
 
 If targetFrameAspectRatio is in range (0, 1) it will be inverted.
 For example: the ratio 0.4 (2.0/5.0) will be inverted to 2.5 (5.0/2.0).
 
 If the targetFrameAspectRatio is set to 0, then it will be automatically reset to an image aspect ratio.
 Setting negative values has the same effect as if 0 was set.
 
 The default value is 1.45.
 */
@property (nonatomic) CGFloat targetFrameAspectRatio;

/// Initializes a new object using the specified document base detection settings.
/**
 Returns the newly initialized object with the specifide properties.
 */
- (instancetype)initWithSettings:(kfxKEDDocumentBaseDetectionSettings*)settings;

@end
