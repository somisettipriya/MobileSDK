//
//  kfxSelfieExperienceCriteriaHolder.h
//
//  Created by Kofax on 18/01/17.
//  Copyright © 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <kfxLibUIControls/KFXSelfieDetectionSettings.h>

@interface KFXSelfieCaptureExperienceCriteriaHolder : NSObject

/// Selfie detection settings object.
/**
 A collection of values that control the behavior of selfie detection experience. Pass nil for the experience of default setting.
 */
@property (nonatomic) KFXSelfieDetectionSettings* selfieDetectionSettings;


/// Whether to enable near and far capture.
/**
 A boolean to turn on/off near and far capture. If this is enabled then capture experience will not consider targetFrameCenter, targetFrameAspectRatio and targetFramePaddingPercent values.
 
 When this property is true, the user can capture Near and Far Selfies.
 The eyesBlinkInstruction is reused to showcase "Tap To Capture" Messages in Near and Far Selfie Experience.
 All the eyeBlinkInstruction Capture Message Properties are applicable for "Tap to Capture".
 "Tap to Capture" is not an Auto Capture experience.
 
 By default is NO.
 
 Note: To ensure the best selfie capture experience, users are encouraged to avoid moving while tapping to capture a selfie.
 */

@property (nonatomic) BOOL nearAndFarCaptureEnabled;

@end
