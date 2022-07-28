/// @cond NODOXYGEN
//
//  kfxKEDOcrRegion.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, KEDOcrRegionType)
{
    REGION_PIXELS = 0,
    REGION_PERCENT
};


@interface kfxKEDOcrRegion : NSObject

// ==========================================================
// regionType
/*
 Specifies the units used in defining the OCR region.
 */
@property (nonatomic, assign) int regionType;

// ==========================================================
// regionTop
/*
 Specifies the top coordinate of the region. The units are specified in the regionType property.
 */
@property (nonatomic, assign) int regionTop;

// ==========================================================
// regionLeft
/*
 Specifies the left coordinate of the region. The units are specified in the regionType property.
 */
@property (nonatomic, assign) int regionLeft;

// ==========================================================
// regionWidth
/*
 Specifies the width of the region. The units are specified in the regionType property.
 */
@property (nonatomic, assign) int regionWidth;

// ==========================================================
// regionHeight
/*
 Specifies the height of the region. The units are specified in the regionType property.
 */
@property (nonatomic, assign) int regionHeight;


@end
/// @endcond
