//
//  kfxKUICheckCaptureExperienceCriteriaHolder.h
//  kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <kfxLibUIControls/kfxKUIDocumentBaseCaptureExperienceCriteriaHolder.h>

@class kfxKEDCheckDetectionSettings;

//! This class allows the check related criteria to be configured.
/**
 This class allows all of the capture related parameters to be configured.
 */
@interface kfxKUICheckCaptureExperienceCriteriaHolder : kfxKUIDocumentBaseCaptureExperienceCriteriaHolder

/// Check detection settings object.
/**
 A collection of values that control the behavior of check detection experience. Pass nil for the experience of default setting.
 */
@property (nonatomic, retain) kfxKEDCheckDetectionSettings* checkDetectionSettings;

/// Whether Glare Detection is enabled when using the capture experience.
/**
 Not supported. Setting this property does nothing. Returns nil whatever is set.
 */
@property (nonatomic, assign) BOOL glareDetectionEnabled;


/// Whether Glare Remover experience is enabled.
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

/// Not supported for this experience.
/**
 Not supported. Setting this property does nothing.
 */

@property (nonatomic, assign) BOOL flashCaptureEnabled;

@end
