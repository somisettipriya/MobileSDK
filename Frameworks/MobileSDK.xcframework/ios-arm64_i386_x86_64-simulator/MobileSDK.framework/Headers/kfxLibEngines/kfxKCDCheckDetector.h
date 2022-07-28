//
//  kfxKCDCheckDetector.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMedia/CMSampleBuffer.h>

#import "kfxKEDCheckDetectionResult.h"
#import "kfxKEDCheckDetectionSettings.h"
#import "kfxKCDDocumentBaseDetector.h"

//! Check Detector clss
/**
 Check Detector is a standalone processing  class for determining if a given image or sample
 buffer contains a check.  When a check is found,  a result object  will be returned  containing its
 coordinates. Since this class is limited in scope to detecting checks, the results will not include
 any data from the check itself.
 */
@interface kfxKCDCheckDetector : kfxKCDDocumentBaseDetector

//! Determines if a given image contains a check.
/**
 Given an image, this method will determine if a check is present or not. If a check is found,
 a result object containing the check's bounding coordinates will be returned. The result will
 also specify whether the front or back side was detected.

 @param image The image to search for checks within.
 @param settings Check detection settings. If nil than default settings will be used.
 @param error On return, if detection could not be performed, a pointer to an error object that encapsulates the reason for failure.  The detect method will also return nil in this instance.  Pass nil for this argument if you are not interested in specific error information.
 @return A result containing check detection data and guidance, or nil if no information could be produced.

 @see kfxKEDCheckDetectionSettings
 @see kfxKEDCheckDetectionResult
 */
- (kfxKEDCheckDetectionResult*)detectImage:(UIImage*)image withSettings:(kfxKEDCheckDetectionSettings*)settings andError:(NSError**)error;

//! Determines if a given sample buffer contains a check.
/**
 Given a sample buffer in kCVPixelFormatType_32BGRA format,  this method will determine  if a check is present or not.  If a check
 is found,  a result  object containing  the check's  bounding coordinates  will be  returned.
 The result will also specify whether the front  or back side was detected.

 @param sample The sample buffer in kCVPixelFormatType_32BGRA format to search for checks within.
 @param settings Check detection settings. If nil than default settings will be used.
 @param error On return, if detection could not be performed, a pointer to an error object that encapsulates the reason for failure.  The detect method will also return nil in this instance.  Pass nil for this argument if you are not interested in specific error information.
 @return A result containing check detection data and guidance, or nil if no information could be produced.

 @see kfxKEDCheckDetectionSettings
 @see kfxKEDCheckDetectionResult
 */
- (kfxKEDCheckDetectionResult*)detectSample:(CMSampleBufferRef)sample withSettings:(kfxKEDCheckDetectionSettings*)settings andError:(NSError**)error;

@end
