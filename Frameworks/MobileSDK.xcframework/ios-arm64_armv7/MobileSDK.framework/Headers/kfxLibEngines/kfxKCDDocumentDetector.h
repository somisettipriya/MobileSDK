//
//  kfxKCDDocumentDetector.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKCDDocumentBaseDetector.h"
#import "kfxKEDDocumentDetectionResult.h"
#import "kfxKEDDocumentDetectionSettings.h"
#import <CoreMedia/CMSampleBuffer.h>

//! Document Detector class
/**
 Document Detector is a standalone processing class for determining if a given image contains
 a document. When a document is found, a result object will be returned.
 Since detection is based on super-resolution technique, the high accuracy results will be returned after multiply runs.
 For better performance recommended to use CMSampleBufferRef input, instead of UIImage.
 */
@interface kfxKCDDocumentDetector : kfxKCDDocumentBaseDetector

//! Determines if a given image contains a document.
/**
 Given an image, this method will determine if a document is present or not. If a document is found,
 a result object containing the document's bounding coordinates along with guidance will be returned.
 This is not recommended to use due performance overhead. Consider to use sample buffer input implementation.

 @param image  The image for searching a document
 @param settings  A collection of settings to control detector behavior. If nil than default settings will be used.
 @param error  On return, if detection could not be performed, a pointer to an error object that encapsulates the reason for failure. The detect method will also return nil in this instance. Pass nil for this argument if you are not interested in specific error information.
 @return A result containing document detection data and guidance, or nil if no information could be produced.
 
 @see kfxKEDDocumentDetectionSettings
 @see kfxKEDDocumentDetectionResult
 */
- (kfxKEDDocumentDetectionResult*)detectImage:(UIImage*)image withSettings:(kfxKEDDocumentDetectionSettings*)settings andError:(NSError**)error;

//! Determines if a given sample buffer contains a document.
/**
 Given a sample buffer in kCVPixelFormatType_32BGRA format, this method will determine if a document is present or not. If a document is found,
 a result object containing the document's bounding coordinates along with guidance will be returned.
 
 @param sample  The sample buffer in kCVPixelFormatType_32BGRA format for searching a document
 @param settings  A collection of settings to control detector behavior. If nil than default settings will be used.
 @param error  On return, if detection could not be performed, a pointer to an error object that encapsulates the reason for failure. The detect method will also return nil in this instance. Pass nil for this argument if you are not interested in specific error information.
 @return A result containing document detection data and guidance, or nil if no information could be produced.
 
 @see kfxKEDDocumentDetectionSettings
 @see kfxKEDDocumentDetectionResult
 */
- (kfxKEDDocumentDetectionResult*)detectSample:(CMSampleBufferRef)sample withSettings:(kfxKEDDocumentDetectionSettings*)settings andError:(NSError**)error;

@end
