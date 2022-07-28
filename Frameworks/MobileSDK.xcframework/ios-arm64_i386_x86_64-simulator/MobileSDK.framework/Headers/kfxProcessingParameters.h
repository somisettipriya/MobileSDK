//
//  API Reference
//  kfxProcessingParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

//! An enumeration containing the possible processing type values.
/**
 Use one of the values of this enumeration to set the processing type.
 */
typedef NS_ENUM (NSInteger, kfxProcessingType)
{
    kfxProcessingType_Off,
    kfxProcessingType_OnDevice
};

//! The image processing parameters class.
/**
 The parameters object allows the user to customize image processing functionality.
 The behavior and default values for some parameters could vary across capture view controllers, and details are specified in target document capture view controller parameters class.
 
 @see kfxIParameters
 */
@interface kfxProcessingParameters : NSObject <NSCopying>

/// A processing type value.
/**
 The supported modes are:
 kfxProcessingType_Off:  processing is disabled.
 kfxProcessingType_OnDevice:  processing is performed on device. If extraction is enabled, this must be on. Processing is required if extraction is enabled.
 
 The default value is kfxProcessingType_OnDevice.
 
 @see kfxExtractionParameters
 */
@property (nonatomic, assign) kfxProcessingType processingType;

/// An image processing operation string
/**
 App specific definition of the encoded imaged processing (IP) options desired. The string is composed of a concatenation of individual IP tokens, each of which enables an option. Please refer to the developers guide for a list of IP tokens.
 To use the default processing string, set this property to nil. The default string used depends on the target capture view controller.
 The default value is nil.
 */
@property (nonatomic, copy) NSString* operations;

/// Specify image processor to use MRZ page detection for cropping process or not.
/**
 Set the property to YES to enable MRZ page detection during document processing.
 The default value is NO.
 */
@property (nonatomic, assign) BOOL useMRZPageDetection;

/// Specify image processor to run target frame cropping prior to page detection.
/**
 Set the property to YES to enable target frame cropping during document processing.
 The default value is NO.
 */
@property (nonatomic, assign) BOOL useTargetFrameCrop;

@end
