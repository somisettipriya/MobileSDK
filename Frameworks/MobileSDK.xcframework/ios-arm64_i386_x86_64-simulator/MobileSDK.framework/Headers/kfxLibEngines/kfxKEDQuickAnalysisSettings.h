//  API Reference
//
//  kfxKEDQuickAnalysisSettings.h
//  KMCEngineData Objects
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "kfxKEDImagePerfectionProfile.h"

@interface kfxKEDQuickAnalysisSettings : NSObject <NSCoding>

//! Enable/Disable the legacy blur detection in quick analysis process
/**
 This is to switch on/off legacy blur detection in quick analysis process, when enabled, the analysis is performed on legacy algorithm. If user enables this and wants to set a threshold of his own, user should be using legacyBlurThreshold property.
 
 The default value is false.
 */

@property (nonatomic) bool enableLegacyBlurDetection;

//! Enable/Disable the blur detection in quick analysis process
/**
 This is to switch on/off blur detection in quick analysis process, when off, the    kfxKEDQuickAnalysisFeedback will always return isBlurry as false
 
 The default value is true.
 */
@property (nonatomic) bool enableBlurDetection;

//! Set the blur threshold for blur detection. Valid values: 0-100.
/**
The default value is 50.
 */
@property (nonatomic) int blurThreshold;
//! Set the blur threshold for legacy blur detection. Valid values: 0-100.
/**
 The default value is 15.
 */
@property (nonatomic) int legacyBlurThreshold;

//! Set the blur count percent threshold for blur detection. Valid values: 0-100.
/**
This is applied only for Legacy Blur Detection. Reserved for future use.
 */
@property (nonatomic) int blurCountPercentThreshold;


//! Enable/Disable the saturation detection in quick analysis process
/**
 This is to switch on/off saturation detection in quick analysis process, when off, the    kfxKEDQuickAnalysisFeedback will always return isOverSaturated and isUnderSaturated as false
 
 The default value is true.
 */
@property (nonatomic) bool enableSaturationDetection;

//! Enable/Disable the glare detection in quick analysis process
/**
 This is to switch on/off glare detection in quick analysis process, when off, the    kfxKEDQuickAnalysisFeedback will always return isGlareDetected as false
 
 The default value is true.
 */
@property (nonatomic) bool enableGlareDetection;

//! Settings used in the glare detection algorithm
/** 
 The fraction of pixels with the highest intensity that are assumed to be glare. Valid values: 0.01-0.99.
 
 The default value is 0.03
 */
@property (nonatomic)  double glareDetectionIntensityFraction;

//! Settings used in the glare detection algorithm
/**
 The absolute lower threshold for high intensity pixels. No pixel below this threshold is perceived as glare. Valid values: 0-255.
 The default value is 230
 */
@property (nonatomic)  int    glareDetectionIntensityThreshold;

//! Settings used in the glare detection algorithm
/**
 The minimum are of an image that needs to be affected by glare to be included in the glare area. Valid values: 0.01-0.99.
 
 The default value is 0.01
 */
@property (nonatomic)  double glareDetectionMinimumGlareAreaFraction;

//! Settings used in the glare detection algorithm
/**
 The number of tiles into which an edge of the image is divided for glare detection. Valid values: 1-1000
 
 The default value is 100
 */
@property (nonatomic)  int    glareDetectionNumberOfTiles;

//! Settings used in the glare detection algorithm
/**
 The processed image is considered as detected with glare if the glare fraction area ration is equal or larger than the threshold value. Valid values: 0.01-0.99.
 
 The default value is 0.05
 */
@property (nonatomic)  double glareDetectedThreshold;
//! Enable/Disable skew detection in the quick analysis process
/**
 This is to switch on/off skew detection in the quick analysis process. When off, the    kfxKEDQuickAnalysisFeedback will always return isOverlySkewed as false.
 
 The default value is true.
 */
@property (nonatomic) bool enableSkewDetection;


//! Enable/Disable shadow detection in the quick analysis process
/**
 This is to switch on/off shadow detection in the quick analysis process. When off, the    kfxKEDQuickAnalysisFeedback will always return isShadowed as false.
 
 The default value is true.
 */
@property (nonatomic) bool enableShadowDetection;


//! Enable/Disable missing borders detection in the quick analysis process
/**
 This is to switch on/off missing borders detection in the quick analysis process. When off, the    kfxKEDQuickAnalysisFeedback will always return isMissingBorders as false.
 
 The default value is true.
 */
@property (nonatomic) bool enableMissingBordersDetection;


//! Enable/Disable low contrast background detection in the quick analysis process
/**
 This is to switch on/off low contrast background detection in the quick analysis process. When off, the kfxKEDQuickAnalysisFeedback will always return isLowContrastBackground as false.
 
 The default value is true.
 */
@property (nonatomic) bool enableLowContrastBackgroundDetection;


//! Specify quick analysis to use MRZ passport detection for cropping process or not
/*
 Application should set the property to KED_USEMRZDETECTION_ON to enable MRZ passport detection during quick analysis.
 Default:KED_USEMRZDETECTION_OFF
 */
@property (atomic) KEDMRZDetectionOptions useMRZPassportDetection;

//! Specify quick analysis to run target frame cropping prior to page detection
/**
 Set it to KED_USETARGETFRAMECROP_ON to enable target frame cropping during quick analysis; kfxKEDImage's targetFrame property is used as cropping region.
 Turn it ON to run crop based on targetFrame from kfxKEDImage.
 By default is KED_USETARGETFRAMECROP_OFF.
 */
@property (atomic) KEDTargetFrameCropOptions useTargetFrameCrop;

//! Specify quick analysis to run document detection based cropping prior to page detection
/**
 Set it to KED_USEDOCUMENTDETECTIONBASEDCROP_ON to enable document detection based cropping during quick analysis.
 By default is KED_USEDOCUMENTDETECTIONBASEDCROP_OFF.
 */
@property (atomic) KEDDocumentDetectionBasedCropOptions useDocumentDetectionBasedCrop;

@end
