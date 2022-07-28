//
//  KFXPassportCaptureExperienceCriteriaHolder.h
//  kfxLibUIControls
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <kfxLibUIControls/kfxKUIDocumentBaseCaptureExperienceCriteriaHolder.h>

@class KFXPassportDetectionSettings;

//! This class allows the passport related criteria to be configured.
/**
 This class allows all of the capture related parameters to be configured.
 */
@interface KFXPassportCaptureExperienceCriteriaHolder : kfxKUIDocumentBaseCaptureExperienceCriteriaHolder

/// Passport detection settings object.
/**
 A collection of values that control the behavior of passport detection experience. Pass nil for the experience of default setting.
 */
@property (nonatomic, retain) KFXPassportDetectionSettings* passportDetectionSettings;

/// Whether Glare Detection is enabled when using the capture experience.
/**
 Not supported. Setting this property does nothing. Returns nil whatever is set.
 */
@property (nonatomic, assign) BOOL glareDetectionEnabled;

/// Whether Glare Detection is enabled when using the capture experience.
/**
 Not supported. Setting this property does nothing. Returns nil whatever is set.
 */
@property (nonatomic, assign) BOOL launchGlareRemoverExperience;

/// The reference threshold that indicates how much glare fraction should be configured on the captured Image.
/**
 Not supported. Setting this property does nothing.
 */

@property (nonatomic, assign) double glareThreshold;

/// The default threshold for the glareThreshold property.
/** Not supported.
 */

@property (nonatomic, readonly) double defaultGlareThreshold;

@end
