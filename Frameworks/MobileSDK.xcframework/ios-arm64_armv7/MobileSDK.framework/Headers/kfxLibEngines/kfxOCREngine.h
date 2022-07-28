/// @cond NODOXYGEN
//
//  kfxOCREngine.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "kfxKEDImage.h"
#import "kfxKEDOcrParameters.h"
#import "kfxKIPImageProcessor.h"
#import "kfxKEDOcrEngineDelegate.h"

@interface kfxOCREngine : NSObject <kfxKIPDelegate>

// ==========================================================
// performOCR method
/*
 The performOCR method performs OCR recognition on the provided image using the provided parameters.
 */
- (int) performOCR:(kfxKEDImage *) sourceImage withParams:(kfxKEDOcrParameters *) parameters;

// ===================================================
// This delegate notifies you about the results of OCR operations.
/*
 The OCR Engine calls your delegates to report the results (success or failure) of OCR operations. The required methods to implement the protocol are: ocrFailed and ocrSucceeded. \n
 You must set this delegate to "self" in order for your app to receive the processing delegate calls.
 */
@property (atomic, assign) id<kfxKEDOcrEngineDelegate>      delegate;

@end
/// @endcond
