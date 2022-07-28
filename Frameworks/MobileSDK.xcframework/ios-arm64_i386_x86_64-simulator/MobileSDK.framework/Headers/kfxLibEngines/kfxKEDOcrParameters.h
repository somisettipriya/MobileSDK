/// @cond NODOXYGEN
//
//  kfxKEDOcrParameters.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "kfxKEDOcrRegion.h"

typedef NS_ENUM(NSUInteger, KEDOcrFont)
{
    DEFAULT_OCR_FONT = 0,
    GENERIC_OCR_FONT,
    FARRINGTON_OCR_FONT
};

@interface kfxKEDOcrParameters : NSObject


// ==========================================================
// region
/*
 Specifies region of image to perform OCR. If nil, then entire Image will be used.
*/
@property (nonatomic, retain) kfxKEDOcrRegion * region;


// ==========================================================
// fixedWidth
/*
 This boolean indicates whether or not the font to be processed has a fixed-width.
 */
@property (nonatomic) BOOL fixedWidth;

// ==========================================================
// font
/*
 This enumerated type identifies the font to be processed for OCR.
 */
@property (nonatomic) KEDOcrFont font;

@end
/// @endcond
