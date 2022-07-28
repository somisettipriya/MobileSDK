//
//  KFXImageProcessorConfiguration.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#ifndef KEDIMAGEPROCESSORCONFIGURATION
#define KEDIMAGEPROCESSORCONFIGURATION 1

#import "kfxKEDBoundingTetragon.h"

typedef enum {
    ROTATE_NONE,
    ROTATE_90,
    ROTATE_180,
    ROTATE_270,
    ROTATE_AUTO
} KFXRotateType;

typedef enum {
    BITONAL = 1,
    GRAYSCALE = 8,
    COLOR = 24,
} KFXColorDepth;

//! Cropping Options enumeration
/**
 Use this enumeration to specify the type of cropping you want to perform on the image. The following options can be specified:\n
 * CROP_NONE to not crop an image.\n
 * CROP_AUTO to automatically crop to the edges of the page found in the image, assuming the image has page edges.\n
 * CROP_TETRAGON to indicate you want the image cropped to a user supplied tetragon, as provided in the croppingTetragon property.\n
 */
typedef enum {
    CROP_NONE,
    CROP_AUTO,
    CROP_TETRAGON,
} KFXCropType;

typedef enum {
    DESKEW_NONE,
    DESKEW_BY_DOCUMENT_EDGES,
    DESKEW_BY_DOCUMENT_CONTENT,
} KFXDeskewType;

typedef enum {
    TARGET_FRAME_CROP_OFF,
    TARGET_FRAME_CROP_ON
} KFXTargetFrameCropType;

//! The Dimensions of a Document
/**
 Represents the dimensions of a document. If the length of at least one of the edges of the document to be found are known ahead of time, they can be specified here to aid with edge detection, and also helps algorithms better estimate the output image DPI. You need not set both short and long edges; the algorithm uses one or both if present.
 */
@interface KFXDocumentDimensions : NSObject <NSCoding, NSCopying>

//! The Short Edge of a Document
/**
 Represents the length of the shortest edge of the document to be found in inches. If you set it to 0.0, the library will not use this parameter.
 Default: 0.0
 */
@property (assign, nonatomic) float shortEdge;

//! The Long Edge of a Document
/**
 Represents the length of the longest edge of the document to be found in inches. If you set it to 0.0, the library will not use this parameter.
 Default: 0.0
 */
@property (assign, nonatomic) float longEdge;

//! Init with Short and Long Edges
/**
 Init with short and long edges.
 */
- (instancetype)initWithShortEdge:(float)shortEdge andLongEdge:(float)longEdge;

@end

//! Image Processor Configuration Specifies Image Processing Options
/**
 Specifies Image Processing Options.
 */
@interface KFXImageProcessorConfiguration : NSObject <NSCoding, NSCopying>

//! Rotate automatically or by 90 degree options
/**
 Use this property to set the desired rotate type.
 DEFAULT: ROTATE_NONE
 */
@property (assign, nonatomic) KFXRotateType rotateType;

//! Desired Output ColorDepth
/**
 Use this property to set the desired output color depth type.
 Default: COLOR
 */
@property (assign, nonatomic) KFXColorDepth outputColorDepth;

//! Crop image to a user specified option
/**
 Use this property to set the desired crop type.
 Default: CROP_NONE
 */
@property (assign, nonatomic) KFXCropType cropType;

//! Pre-crop image using the targetFrame coordinates from the input image.
/**
 If TARGET_FRAME_CROP_ON is specified, the image will be pre-cropped to the coordinates in the targetFrame property of the input image (which is normaly set when the input image is captured using one of the library's Capture Experiences). Other specified cropping options will be performed subsequently.
 Default: TARGET_FRAME_CROP_OFF
 */
@property (assign, nonatomic) KFXTargetFrameCropType targetFrameCropType;

//! Deskew image to user specified option
/**
 Use this property to set the desired deskew type.
 Default: DESKEW_NONE
 */
@property (assign, nonatomic) KFXDeskewType deskewType;

//! The document dimensions
/**
 If the dimensions of the document to be found are known ahead of time, they can be specified here to aid with edge detection. These are not required.
 Default (0.0, 0.0)
 */
@property (strong, nonatomic) KFXDocumentDimensions* documentDimensions;

//! Desired output image DPI
/**
 Use this property to set the desired output image DPI (Dots Per Inch). If you set it to 0, then the library will automatically estimate the output image DPI and indicate it in the output object.
 Default: 0
 */
@property (assign, nonatomic) int outputDPI;

/// @cond HIDE
@property (strong, nonatomic) NSString* advancedConfiguration;
/// @endcond

//! IPP String containing secondary processing operations
/**
 The ippString that will be used for a secondary processing operation.
 */
@property (strong, nonatomic, readonly) NSString* ippString;

// ==========================================================
//! Tetragon corner points defining the image cropping limits.
/**
 Use this object to specify the corner points of a tetragon (or rectangle) for cropping an image. If this object contains any point coordinates that are non-zero, the image processing (IP) engine will not perform automatic page detection, but will use these coordinate points instead. If the bounding rectangle coordinates are all 0, then no manual cropping is performed by the image processing engine.
 
 */
@property (strong, nonatomic) kfxKEDBoundingTetragon *croppingTetragon;

//! Init with IPP string
/**
 Creates a new image processor configuration based on a legacy image perfection operation string. Applicable tokens will be converted into configuration properties. Remaining tokens will be stored in the ippString property, and used in a secondary processing operation.
 */
- (instancetype)initWithIppString:(NSString*)ippString;

@end

#endif

