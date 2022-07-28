//
//  KFXPassportDetector.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMedia/CMSampleBuffer.h>

#import "KFXPassportDetectionResult.h"
#import "KFXPassportDetectionSettings.h"
#import "kfxKCDDocumentBaseDetector.h"

//! Passport Detector class
/**
 Passport Detector is a standalone processing class for determining if a given image or sample
 buffer contains a passport. When a passport is found, a result object will be returned containing its
 coordinates. Since this class is limited in scope to detecting passports, the results will not include
 any data from the passport itself.
 */
@interface KFXPassportDetector : kfxKCDDocumentBaseDetector

//! Determines if a given image contains a passport.
/**
 Given an image, this method will determine if a passport is present or not. If a passport is found,
 a result object containing the passport's bounding coordinates will be returned.

 @param image The image to search for passport within.
 @param settings Passport detection settings. If nil than default settings will be used.
 @param error On return, if detection could not be performed, a pointer to an error object that encapsulates the reason for failure. The detect method will also return nil in this instance. Pass nil for this argument if you are not interested in specific error information.
 @return A result containing passport detection data and guidance, or nil if no information could be produced.

 @see KFXPassportDetectionSettings
 @see KFXPassportDetectionResult
 */
- (KFXPassportDetectionResult*)detectImage:(UIImage*)image withSettings:(KFXPassportDetectionSettings*)settings andError:(NSError**)error;

//! Determines if a given sample buffer contains a passport.
/**
 Given a sample buffer in kCVPixelFormatType_32BGRA format, this method will determine if a passport is present or not. If a passport
 is found, a result object containing the passport's bounding coordinates will be returned.

 @param sample The sample buffer in kCVPixelFormatType_32BGRA format to search for passport within.
 @param settings Passport detection settings. If nil than default settings will be used.
 @param error On return, if detection could not be performed, a pointer to an error object that encapsulates the reason for failure. The detect method will also return nil in this instance. Pass nil for this argument if you are not interested in specific error information.
 @return A result containing passport detection data and guidance, or nil if no information could be produced.

 @see KFXPassportDetectionSettings
 @see KFXPassportDetectionResult
 */
- (KFXPassportDetectionResult*)detectSample:(CMSampleBufferRef)sample withSettings:(KFXPassportDetectionSettings*)settings andError:(NSError**)error;

@end
