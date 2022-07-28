//
//  API Reference
//  kfxCheckCaptureParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxIParameters.h>

@class kfxCheckData;

//! An enumeration containing the possible check side values.
/**
 Use one of the values of this enumeration to set the check side for detection.
 */
typedef NS_ENUM (NSInteger, kfxCheckSide)
{
    kfxCheckSide_Front,
    kfxCheckSide_Back
};

/// @cond EXTRACTION
//! An enumeration containing the possible check country values.
/**
 Use one of the values of this enumeration to set the country.
 */
typedef NS_ENUM (NSInteger, kfxCheckCountry)
{
    kfxCheckCountry_NotSpecified,
    kfxCheckCountry_UnitesStates,
    kfxCheckCountry_Canada,
    kfxCheckCountry_Singapore,
    kfxCheckCountry_HongKong,
    kfxCheckCountry_Australia,
    kfxCheckCountry_UnitedKingdom
};
/// @endcond
//! The check capture view controller parameters.
/**
 Encapsulates all parameters related to check capture@if EXTRACTION, processing and extraction. @else &nbsp;and processing. @endif
 
 @see kfxIParameters
 */
@interface kfxCheckCaptureParameters : kfxIParameters <NSCopying>

/// A check side value that determines check detection functionality.
/**
 The supported modes are:
 kfxCheckSide_Front:  Front check side.
 kfxCheckSide_Back:  Back check side.
 
 The default value is kfxCheckSide_Front.
 
 @see kfxCheckSide
 */
@property (nonatomic, assign) kfxCheckSide checkSide;

///@cond EXTRACTION
/// Data for reverse side of the check.
/**
 This data will be used for extraction along with the image for the current side of the check.
 The field is used when capturing both sides of the check.
 
 @see kfxCheckData
 */
@property (nonatomic, strong) kfxCheckData* reverseSideCheck;

/// A value that determines country.
/**
 This value is used for the extraction.
 
 Specify one of the available values from kfxCheckCountry enumeration.
 The default value is kfxCheckCountry_NotSpecified.
 
 @see kfxCheckCountry
 */
@property (nonatomic, assign) kfxCheckCountry country;
///@endcond
@end
