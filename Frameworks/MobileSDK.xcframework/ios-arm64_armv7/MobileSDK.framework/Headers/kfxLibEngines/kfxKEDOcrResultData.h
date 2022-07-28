/// @cond NODOXYGEN
//
//  kfxKEDOcrResultData.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "kfxKEDOcrWord.h"

@interface kfxKEDOcrResultData : NSObject

// Properties

// ==========================================================
// imageID
/*
 This GUID contains the ID of the image used for OCR.
 */
@property (nonatomic, strong) NSString* imageID;

// ==========================================================
// errorCode
/*
 This status variable contains the result code returned. A value of KMC_SUCCESS (zero) = normal success.
 */
@property (nonatomic) int resultCode;


// TODO - Remove this, once the OCRWords are populated...
@property (nonatomic, strong) NSString* resultText;

// Methods

// ==========================================================
// getText method
/*
 The getText method returns a single string containing all OCR detected text.
 */
- (NSString *) getText;

// ==========================================================
// getWords method
/*
 The getWords method returns the detected OCR data as an NSArray of kfxKEDOcrWord objects
 */
- (NSArray *) getWords;

// ==========================================================
// getWordAtPoint method
/*
 The getWordAtPoint method returns a kfxKEDOcrWord object containing the word at the given coordinates. If no word is found at the specified location, a nil value is returned.
 */
- (kfxKEDOcrWord *) getWordAtPoint: (int) x andYPos: (int) y;

// ==========================================================
// getWordsinRect method
/*
 The getWordsinRect method returns a NSArray containing kfxKEDOcrWord objects. The returned words are those found in the specified rectangle.
 */
- (NSArray *) getWordsinRect: (int) x andYPos: (int) y andWidth: (int) width andHeight: (int) height;

@end
/// @endcond
