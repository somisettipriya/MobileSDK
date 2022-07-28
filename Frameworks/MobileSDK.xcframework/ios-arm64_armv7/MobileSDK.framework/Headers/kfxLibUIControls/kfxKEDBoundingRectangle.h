//  API Reference
//
//  kfxKEDBoundingRectangle.h
//
//  KMCEngineData Objects
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
//! Bounding Rectangle of four coordinates.
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 An instance of this class contains the bounding rectangle (in pixels) for an item in an image.
 These rectangle coordinates should always be less than or equal to the image width and height.
 See also: kfxKEDBoundingTetragon
 */
@interface kfxKEDBoundingRectangle : NSObject

// ===================================================
//! Represents the left side of a rectangle
/**
 This left side of the rectangle references the least X coordinate.
 */
@property (assign, atomic) int rectLeft;


// ===================================================
//! Represents the top edge of a rectangle
/**
 This top side of the rectangle references the least Y coordinate.
 */
@property (assign, atomic) int rectTop;


// ===================================================
//! Represents the right side of a rectangle
/**
 This right side of the rectangle references the largest X coordinate.
 */
@property (assign, atomic) int rectRight;


// ===================================================
//! Represents the bottom edge of a rectangle
/**
 This bottom side of the rectangle references the largest Y coordinate.
 */
@property (assign, atomic) int rectBottom;

// ===================================================
//! Initialize bounding rectangle with left, top, width, and height values
/** Use this method to initialize an object of kfxKEDBoundingRectangle when you have values of left, top, width, and height.
 @code
 kfxKEDBoundingRectangle* boundingRect = [[kfxKEDBoundingRectangle alloc] initWithLeft:0 top:0 width:100 height:30];
 @endcode
 */
-(id)initWithLeft:(int)left top:(int)top width:(int)width height:(int)height;

@end
