//
//  KFXQuickExtractionSettings.h
//  kfxLibUIControls
//
//  Copyright (c) 2014-2018 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

//! A configuration object for controlling the Quick Extractor behavior.
@interface KFXQuickExtractionSettings : NSObject

/// List of barcodes to be extracted.
/**
 Supported barcodes: PDF417, QR, Code39.
 By default are PDF and QR.
 
 @code
 // Objective-C
 quickExtractorSettings.barcodes = @[@(kfxKBRQRCode), @(kfxKBRPdf417), @(kfxKBRCode39)];
 
 // Swift
 quickExtractorSettings.barcodes = [Int(kfxKBRQRCode.rawValue), Int(kfxKBRPdf417.rawValue), Int(kfxKBRCode39.rawValue)]
 @endcode
 
 @see KBRSymbologies for all supported values.
 */
@property (nonatomic, strong) NSArray* barcodes;

/// Face left padding controls the amount of background returned on left face side.
/**
 Left padding in percent of found face width to control how much extra space needs to be added on left side.
 The valid values are in range 0 - 50. Values will be clamped to the valid range.
 By default is 0.
 */
@property (nonatomic, assign) CGFloat faceLeftPadding;

/// Face right padding controls the amount of background returned on right face side.
/**
 Right padding in percent of found face width to control how much extra space needs to be added on right side.
 The valid values are in range 0 - 50. Values will be clamped to the valid range.
 By default is 0.
 */
@property (nonatomic, assign) CGFloat faceRightPadding;

/// Face top padding controls the amount of background returned on top face side.
/**
 Top padding in percent of found face height to control how much extra space needs to be added from top side.
 The valid values are in range 0 - 50. Values will be clamped to the valid range.
 By default is 0.
 */
@property (nonatomic, assign) CGFloat faceTopPadding;

/// Face bottom padding controls the amount of background returned on bottom face side.
/**
 Bottom padding in percent of found face height to control how much extra space needs to be added from bottom side.
 The valid values are in range 0 - 50. Values will be clamped to the valid range.
 By default is 0.
 */
@property (nonatomic, assign) CGFloat faceBottomPadding;

///It returs only MRZ fields

/**
 It will not consider other settings like barcodes, face paddings if user set it "YES".
 By default is NO.
 */
@property (nonatomic, assign) BOOL readMRZOnly;

/**
 If it sets to YES, it will replace MRZ characters with alternative characters to match the chesum.
 By default is NO.
 */
@property (nonatomic, assign) BOOL autoCorrectMRZ;

@end
