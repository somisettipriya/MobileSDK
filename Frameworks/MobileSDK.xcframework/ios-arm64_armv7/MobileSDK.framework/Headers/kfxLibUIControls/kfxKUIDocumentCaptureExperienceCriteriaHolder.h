//
//  kfxKUIDocumentCaptureExperienceCriteriaHolder.h
//  kfxLibUIControls
//
//  Copyright (c) 2017 Kofax. All rights reserved.
//

#import <kfxLibUIControls/kfxKUIDocumentBaseCaptureExperienceCriteriaHolder.h>

@class kfxKEDDocumentDetectionSettings;

//! This class allows the document related criteria to be configured.
/**
 This class allows all of the capture related parameters to be configured.
 */
@interface kfxKUIDocumentCaptureExperienceCriteriaHolder : kfxKUIDocumentBaseCaptureExperienceCriteriaHolder

/// Document detection settings object.
/**
 A collection of values that control the behavior of document detection experience. Pass nil for the experience of default setting.
 */
@property (nonatomic, strong) kfxKEDDocumentDetectionSettings* documentDetectionSettings;

/// The reference threshold that indicates how much glare fraction should be configured on the captured Image.

/** Configuring the Glare Threshold value will control the launch of second capture experience(Tilt capture) when glareDetectionEnabled/launchGlareRemoverExperience is set to true.
 The default value is 0.015
 
 Valid values are in the range [0, 1].
 */

@property (nonatomic, assign) double glareThreshold;

/// The default threshold for the glareThreshold property.
/** Gives the default threshold for the device. Value is 0.015
 */

@property (nonatomic, readonly) double defaultGlareThreshold;

/// Not supported for this experience.
/**
 Not supported. Setting this property does nothing.
 */

@property (nonatomic, assign) BOOL flashCaptureEnabled;


@end
