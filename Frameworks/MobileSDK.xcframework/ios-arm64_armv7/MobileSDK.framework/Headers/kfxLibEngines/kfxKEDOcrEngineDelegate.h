/// @cond NODOXYGEN
//  Kofax Mobile Capture API Reference File
//
//  kfxKEDOcrEngineDelegate.h
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKEDOcrFailureData.h"
#import "kfxKEDOcrResultData.h"

@protocol kfxKEDOcrEngineDelegate<NSObject>

@required

// ==========================================================
// ocrFailed delegate method
/*
 The ocrFailed delegate method reports the failure of an OCR operation. It provides a parameter object which provides an error code.
 */
- (void) ocrFailed : (kfxKEDOcrFailureData *) failure;

// ==========================================================
// ocrSucceeded delegate method
/*
 The ocrSucceeded delegate method reports the success of an OCR operation. It provides a parameter object which provides result information.
 */
- (void) ocrSucceeded : (kfxKEDOcrResultData *) results;

@end
/// @endcond
