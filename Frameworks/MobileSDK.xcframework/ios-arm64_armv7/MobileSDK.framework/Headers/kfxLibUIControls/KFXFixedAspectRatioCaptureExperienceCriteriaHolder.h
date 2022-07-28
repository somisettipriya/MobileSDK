//
//  KFXFixedAspectRatioCaptureExperienceCriteriaHolder.h
//  kfxLibUIControls
//
//  Copyright (c) 2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <kfxLibUIControls/kfxKUIDocumentBaseCaptureExperienceCriteriaHolder.h>

@class KFXFixedAspectRatioDetectionSettings;

//! This class allows the Fixed Aspect Ratio detection related criteria to be configured.
/**
 This class allows all of the capture related parameters to be configured.
 */
@interface KFXFixedAspectRatioCaptureExperienceCriteriaHolder : kfxKUIDocumentBaseCaptureExperienceCriteriaHolder

/// Fixed Aspect Ratio detection settings object.
/**
 A collection of values that control the behavior of Fixed Aspect Ratio capture experience. Pass nil for the experience of default setting.
 */
@property (nonatomic, strong) KFXFixedAspectRatioDetectionSettings* farDetectionSettings;

/// Whether the Pitch threshold is enabled.
/**
 A boolean that indicates whether the Pitch threshold is enabled. If enabled this criteria is checked before taking a picture.
 By default is OFF.
 */
@property (nonatomic, assign) BOOL pitchThresholdEnabled;

/// Whether the Roll threshold is enabled.
/**
 A boolean that indicates whether the Roll threshold is enabled. If enabled this criteria is checked before taking a picture.
 By default is OFF.
 */
@property (nonatomic, assign) BOOL rollThresholdEnabled;

/// Whether to detect if the orientation of page results in optimum overlap of page and ImageCaptureControl.
/**
 Not supported. Setting this property do nothing. Returns NO whatever is set.
 */
@property (nonatomic, assign) BOOL pageOrientationEnabled;

/// The reference threshold that indicates how much glare fraction should be configured on the captured Image.

/** Configuring the Glare Threshold value will control the launch of second capture experience(Tilt capture) when glareDetectionEnabled/launchGlareRemoverExperience is set to true.
 The default value is 0.03
 
 Valid values are in the range [0, 1].
 */

@property (nonatomic, assign) double glareThreshold;

/// The default threshold for the glareThreshold property.
/** Gives the default threshold for the device. Value is 0.03
 */

@property (nonatomic, readonly) double defaultGlareThreshold;

@end
