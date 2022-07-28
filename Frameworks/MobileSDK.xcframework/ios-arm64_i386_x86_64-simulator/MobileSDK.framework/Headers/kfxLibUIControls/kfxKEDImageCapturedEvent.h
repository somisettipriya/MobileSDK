//
//  kfxKEDImageCapturedEvent.h
//  kfxLibUIControls
//
//  Created by Kofax on 26/03/19.
//  Copyright © 2019 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
@class kfxKEDImage;

//! This class would have  primary, glare free and flash images.
/**
 This event is raised in response to glareDetection being enabled and glare being detected in the camera preview and when “flashCaptureEnabled” is set to TRUE in the criteria holder,
 
 See -(void)imageCaptureControl:imageCapturedEvent: from kfxKUIImageCaptureControl for sample code.
 */

@interface kfxKEDImageCapturedEvent : NSObject

/// Initializes a new object using the specified parameters.
/**
 @param primaryImage kfxKEDImage object.
 @param glareFreeImage kfxKEDImage object.
 @param errorStatus of galre removal.
 */

- (instancetype)initWithPrimaryImage:(kfxKEDImage*)primaryImage glareFreeImage:(kfxKEDImage*)glareFreeImage errorStatus:(int)errorStatus;

//! The image captured from the first of two captures in the experience.
/**
 The image returned by the experience. This can be used for authentication
 
 */
@property (nonatomic,readonly) kfxKEDImage* primaryImage;

//! The image after glare removal.
/**
 The image returned by the experience. This cannot be used for authentication as it might have anomalies during stitching.
 
 */
@property (nonatomic,readonly) kfxKEDImage* glareFreeImage;


//! The image captured from the second of two captures in the experience when "flashCaptureEnabled" is enabled in the criteria holder.
/**
 The image can not be used for extraction, can be used for verifcation to get better test results for both paper detection and screen photo detector.
 This image will be available only when “flashCaptureEnabled” is set to TRUE in the criteria holder class.

 */
@property (nonatomic,strong) kfxKEDImage* flashImage;

//! The image captured from the second of two captures in the experience when "nearAndFarCaptureEnabled" is enabled in the KFXSelfieCaptureExperience.
/**
 This image will be available only when “nearAndFarCaptureEnabled” is set to TRUE in the KFXSelfieCaptureExperience class.

 */
@property (nonatomic,strong) kfxKEDImage* secondaryImage;


//! Error status of glare removal.
/**
 The "errorStatus" will be returned as KMC_SUCCESS if glare removal is successful. If there is a problem while removing glare then "errorStatus" will be returned as KMC_UI_INVALID_IMAGES.
 
 */
@property (nonatomic,readonly) int errorStatus;

@end


