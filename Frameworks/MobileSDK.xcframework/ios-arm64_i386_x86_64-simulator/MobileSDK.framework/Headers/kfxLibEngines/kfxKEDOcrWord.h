/// @cond NODOXYGEN
//
//  kfxKEDOcrWord.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface kfxKEDOcrWord : NSObject

// ==========================================================
// text
/*
 Contains the text of the word found during OCR.
 */
@property (nonatomic, strong) NSString *text;

// ==========================================================
// x
/*
 Specifies the x-coordinate of the word bounding box.
 */
@property (nonatomic) int x;

// ==========================================================
// y
/*
 Specifies the y-coordinate of the word bounding box.
 */
@property (nonatomic) int y;

// ==========================================================
// width
/*
 Specifies the width of the word bounding box.
 */
@property (nonatomic) int width;

// ==========================================================
// height
/*
 Specifies the height of the word bounding box.
 */
@property (nonatomic) int height;

@end
/// @endcond
