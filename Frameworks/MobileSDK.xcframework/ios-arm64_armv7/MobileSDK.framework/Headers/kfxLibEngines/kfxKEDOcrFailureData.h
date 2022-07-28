/// @cond NODOXYGEN
//
//  kfxKEDOcrFailureData.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface kfxKEDOcrFailureData : NSObject

// ==========================================================
// imageID
/*
 This GUID contains the ID of the image used for OCR.
 */
@property (nonatomic, strong) NSString* imageID;

// ==========================================================
// errorCode
/*
 This status variable contains the error code returned following OCR failure.
 */
@property (nonatomic) int errorCode;

@end
/// @endcond
