//
//  KFXTesseractOCR.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2018 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>

//! Tesseract OCR initializer
@interface KFXTesseractOCR : NSObject

/// Enable Tesseract OCR
/**
 By default Tesseract OCR is disabled and its binaries will not influence application size.
 In order to enable Tesseract OCR, call enable class method before run kfxKOEIDExtractor's extract.
 
 @see kfxKOEIDExtractor
 */
+ (void)enable;

@end
